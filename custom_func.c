/*_____ I N C L U D E S ____________________________________________________*/
#include <stdio.h>

#include "inc_main.h"

#include "misc_config.h"
#include "custom_func.h"

/*_____ D E C L A R A T I O N S ____________________________________________*/

struct flag_32bit flag_PROJ_CTL;
#define FLAG_PROJ_TIMER_PERIOD_1000MS                 	(flag_PROJ_CTL.bit0)
#define FLAG_PROJ_TIMER_PERIOD_SPECIFIC                 (flag_PROJ_CTL.bit1)
#define FLAG_PROJ_TRIG_BTN1                 	        (flag_PROJ_CTL.bit2)
#define FLAG_PROJ_TRIG_BTN2                    		    (flag_PROJ_CTL.bit3)
#define FLAG_PROJ_TRIG_ADC_CH                           (flag_PROJ_CTL.bit4)
#define FLAG_PROJ_REVERSE5                              (flag_PROJ_CTL.bit5)
#define FLAG_PROJ_REVERSE6                              (flag_PROJ_CTL.bit6)
#define FLAG_PROJ_REVERSE7                              (flag_PROJ_CTL.bit7)


#define FLAG_PROJ_TRIG_1                                (flag_PROJ_CTL.bit8)
#define FLAG_PROJ_TRIG_2                                (flag_PROJ_CTL.bit9)
#define FLAG_PROJ_TRIG_3                                (flag_PROJ_CTL.bit10)
#define FLAG_PROJ_TRIG_4                                (flag_PROJ_CTL.bit11)
#define FLAG_PROJ_TRIG_5                                (flag_PROJ_CTL.bit12)
#define FLAG_PROJ_REVERSE13                             (flag_PROJ_CTL.bit13)
#define FLAG_PROJ_REVERSE14                             (flag_PROJ_CTL.bit14)
#define FLAG_PROJ_REVERSE15                             (flag_PROJ_CTL.bit15)

/*_____ D E F I N I T I O N S ______________________________________________*/

volatile unsigned int counter_tick = 0;
volatile unsigned int btn_counter_tick = 0;

#define BTN_PRESSED_LONG                                (2500)

// #define VBG_VOLTAGE                                     (0.815)  // v
#define VBG_VOLTAGE                                     (815)  // mv

/*G15 V_BGR : 0.815 V*/
unsigned long vdd_Vbgr = 0;
unsigned short adc_buffer[11] = {0};

// #define ENABLE_BUTTON
#define ENABLE_LOG_ADC

#define CTRL_IO                                         (P2_bit.no2)

/*_____ M A C R O S ________________________________________________________*/

/*_____ F U N C T I O N S __________________________________________________*/
extern volatile uint32_t g_tau0_ch4_width;

void set_TIMER_PERIOD_SPECIFIC(void)
{
    FLAG_PROJ_TIMER_PERIOD_SPECIFIC = 1;
}

void reset_TIMER_PERIOD_SPECIFIC(void)
{
    FLAG_PROJ_TIMER_PERIOD_SPECIFIC = 0;
}

bool Is_TIMER_PERIOD_SPECIFIC_Trig(void)
{
    return FLAG_PROJ_TIMER_PERIOD_SPECIFIC;
}

void set_TIMER_PERIOD_1000MS(void)
{
    FLAG_PROJ_TIMER_PERIOD_1000MS = 1;
}

void reset_TIMER_PERIOD_1000MS(void)
{
    FLAG_PROJ_TIMER_PERIOD_1000MS = 0;
}

bool Is_TIMER_PERIOD_1000MS_Trig(void)
{
    return FLAG_PROJ_TIMER_PERIOD_1000MS;
}

unsigned int btn_get_tick(void)
{
	return (btn_counter_tick);
}

void btn_set_tick(unsigned int t)
{
	btn_counter_tick = t;
}

void btn_tick_counter(void)
{
	btn_counter_tick++;
    if (btn_get_tick() >= 60000)
    {
        btn_set_tick(0);
    }
}

unsigned int get_tick(void)
{
	return (counter_tick);
}

void set_tick(unsigned int t)
{
	counter_tick = t;
}

void tick_counter(void)
{
	counter_tick++;
    if (get_tick() >= 60000)
    {
        set_tick(0);
    }
}

void delay_ms(unsigned int ms)
{
	#if 1
    unsigned int tickstart = get_tick();
    unsigned int wait = ms;
	unsigned int tmp = 0;
	
    while (1)
    {
		if (get_tick() > tickstart)	// tickstart = 59000 , tick_counter = 60000
		{
			tmp = get_tick() - tickstart;
		}
		else // tickstart = 59000 , tick_counter = 2048
		{
			tmp = 60000 -  tickstart + get_tick();
		}		
		
		if (tmp > wait)
			break;
    }
	
	#else
	TIMER_Delay(TIMER0, 1000*ms);
	#endif
}

void Timer_1ms_IRQ(void)
{
    tick_counter();

    if ((get_tick() % 1000) == 0)
    {
        set_TIMER_PERIOD_1000MS();
    }

    if ((get_tick() % 100) == 0)
    {
        set_TIMER_PERIOD_SPECIFIC();
    }

    if ((get_tick() % 50) == 0)
    {

    }	

    #if defined (ENABLE_BUTTON)
    Button_Process_long_counter();
    #endif
}


// unsigned short ADC_To_Voltage(unsigned short adc_value)
// {
// 	unsigned long volt = 0;

// 	// volt = (unsigned long) (vdd_Vbgr*adc_value)/1024;
// 	volt = (unsigned long) (vdd_Vbgr*adc_value) >> 10;
	
//     // printf(",0x%4X(%5d,%5d),",adc_value,adc_value , volt);

// 	return (unsigned short) volt;	
// }

void GetADC(e_ad_channel_t ch)
{
    unsigned short tmp_buffer = 0;

    // R_Config_ADC_Set_ADChannel(ch);
    FLAG_PROJ_TRIG_ADC_CH = 0;
    R_Config_ADC_Start();
    while(!FLAG_PROJ_TRIG_ADC_CH);
    R_Config_ADC_Get_Result_10bit(&tmp_buffer);
    R_Config_ADC_Stop();
    FLAG_PROJ_TRIG_ADC_CH = 0;

    adc_buffer[ch] = tmp_buffer;    

    // printf_tiny("ch[%d]:0x%04X\r\n",ch,adc_buffer[ch]);

}

/*
    COPY FROM R_Config_ADC_Create
    channel : 1
    P02
*/
void ADC_Channel_config_Init(void)
{
    volatile uint16_t w_count;

    ADCEN = 1U;    /* supply AD clock */
    ADMK = 1U;    /* disable INTAD interrupt */
    ADIF = 0U;    /* clear INTAD interrupt flag */
    /* Set INTAD priority */
    ADPR1 = 1U;
    ADPR0 = 1U;
    /* Set ANI1 pin */
    PMC0 |= 0x04U;
    PM0 |= 0x04U;
    ADM0 = _00_AD_CONVERSION_CLOCK_8 | _00_AD_TIME_MODE_NORMAL_1;
    ADM2 = _00_AD_RESOLUTION_10BIT;
    ADS = _01_AD_INPUT_CHANNEL_1;

    ADCE = 1U;

    /* Reference voltage stability wait time, 0.125us */
    for (w_count = 0U; w_count < AD_WAITTIME_B; w_count++ )
    {
        NOP();
    }
    
    // R_Config_ADC_Start();
}

void GetVREF(void)
{
    unsigned short tmp_buffer = 0;
    unsigned short adc_resolution = 1024;

    /*
        VDD = VBG * adc_resolution / ConversionResult
        VDD/VBG = adc_resolution / ConversionResult
    
    */
    // R_Config_ADC_Set_ADChannel(ADINTERREFVOLT);
    FLAG_PROJ_TRIG_ADC_CH = 0;
    R_Config_ADC_Start();    // to get ADC internal vref channel
    while(!FLAG_PROJ_TRIG_ADC_CH);
    R_Config_ADC_Get_Result_10bit(&tmp_buffer);
    R_Config_ADC_Stop();
    FLAG_PROJ_TRIG_ADC_CH = 0;

    vdd_Vbgr = (unsigned long) VBG_VOLTAGE*adc_resolution/tmp_buffer;

    // printf_tiny("Read VREF:%d(0x%04X),",tmp_buffer,tmp_buffer);
    // printf_tiny("VBGR:%4dmv\r\n",vdd_Vbgr);
}

/*
    COPY FROM R_Config_ADC_Create
    channel : internal reference voltage
*/
void ADC_VREF_config_Init(void)
{    
    volatile uint16_t w_count;

    ADCEN = 1U;    /* supply AD clock */
    ADMK = 1U;    /* disable INTAD interrupt */
    ADIF = 0U;    /* clear INTAD interrupt flag */
    /* Set INTAD priority */
    ADPR1 = 1U;
    ADPR0 = 1U;
    ADM0 = _00_AD_CONVERSION_CLOCK_8 | _00_AD_TIME_MODE_NORMAL_1;
    ADM2 = _00_AD_RESOLUTION_10BIT;
    ADS = _0D_AD_INPUT_INTERREFVOLT;

    ADCE = 1U;

    /* Reference voltage stability wait time, 0.125us */
    for (w_count = 0U; w_count < AD_WAITTIME_B; w_count++ )
    {
        NOP();
    }

    // R_Config_ADC_Start();  
}

/*
    base on formula : 
    R1 : 0.1
    R2 : 300K
    I load : 50mA ~ 500mA , enable I/O
    Vo = I load * R1 * (R2 / 5K)
    Vo = 50mA * 0.1 * (300K/5K) = 50mA * 0.1 * 60 = 300mv
    Vo = 500mA * 0.1 * (300K/5K) = 50mA * 0.1 * 60 = 3000mv

*/

void ADC_Process(void)
{    
    unsigned int mv = 0;

    // get ADC channel
    GetADC(ADCHANNEL1);
    mv = (vdd_Vbgr*adc_buffer[ADCHANNEL1]) >> 10;

    /*detect I/O */
    if ((mv >= 300) && (mv <= 3000))
    {
        CTRL_IO = 1;
    }
    else
    {    
        CTRL_IO = 0;
    }
    	
    #if defined (ENABLE_LOG_ADC)   //ADC debug log
    {
        printf_tiny("VREF:%d,",vdd_Vbgr);
        printf_tiny("ch[%d]:0x%04X",ADCHANNEL1,adc_buffer[ADCHANNEL1]);
        printf_tiny("(%d mv)", mv );
        printf_tiny("\r\n");
    }
    #endif

    
}

void ADC_init(void)
{    
    CTRL_IO = 0;

    // init internal vref channel
    ADC_VREF_config_Init();
    // get VREF
    GetVREF();

    // init normal adc channel
    ADC_Channel_config_Init();
}

void ADC_Process_in_IRQ(void)
{
    FLAG_PROJ_TRIG_ADC_CH = 1;
}

/*
    G15 target board
    LED1 connected to P66, LED2 connected to P67
*/
void LED_Toggle(void)
{
    // PIN_WRITE(2,0) = ~PIN_READ(2,0);
    // PIN_WRITE(2,1) = ~PIN_READ(2,1);
    P2_bit.no0 = ~P2_bit.no0;
    P2_bit.no1 = ~P2_bit.no1;
}

void loop(void)
{
	// static unsigned int LOG1 = 0;

    if (Is_TIMER_PERIOD_1000MS_Trig())
    {
        reset_TIMER_PERIOD_1000MS();

        // printf_tiny("log(timer):%4d\r\n",LOG1++);
        // LED_Toggle();             
    }

    if (Is_TIMER_PERIOD_SPECIFIC_Trig())
    {
        reset_TIMER_PERIOD_SPECIFIC();
        ADC_Process();  // P02        
    }    


    #if defined (ENABLE_BUTTON)
    Button_Process_in_polling();
    #endif
    
}

#if defined (ENABLE_BUTTON)
// G15 EVB , P137/INTP0 , set both edge 
void Button_Process_long_counter(void)
{
    if (FLAG_PROJ_TRIG_BTN2)
    {
        btn_tick_counter();
    }
    else
    {
        btn_set_tick(0);
    }
}

void Button_Process_in_polling(void)
{
    static unsigned char cnt = 0;

    if (FLAG_PROJ_TRIG_BTN1)
    {
        FLAG_PROJ_TRIG_BTN1 = 0;
        printf_tiny("BTN pressed(%d)\r\n",cnt);

        if (cnt == 0)   //set both edge  , BTN pressed
        {
            FLAG_PROJ_TRIG_BTN2 = 1;
        }
        else if (cnt == 1)  //set both edge  , BTN released
        {
            FLAG_PROJ_TRIG_BTN2 = 0;
        }

        cnt = (cnt >= 1) ? (0) : (cnt+1) ;
    }

    if ((FLAG_PROJ_TRIG_BTN2 == 1) && 
        (btn_get_tick() > BTN_PRESSED_LONG))
    {         
        printf_tiny("BTN pressed LONG\r\n");
        btn_set_tick(0);
        FLAG_PROJ_TRIG_BTN2 = 0;
    }
}

// G15 EVB , P137/INTP0
void Button_Process_in_IRQ(void)    
{
    FLAG_PROJ_TRIG_BTN1 = 1;
}
#endif

void UARTx_Process(unsigned char rxbuf)
{    
    if (rxbuf > 0x7F)
    {
        printf_tiny("invalid command\r\n");
    }
    else
    {
        printf_tiny("press:%c(0x%02X)\r\n" , rxbuf,rxbuf);   // %c :  C99 libraries.
        switch(rxbuf)
        {
            case '1':
                FLAG_PROJ_TRIG_1 = 1;
                break;
            case '2':
                FLAG_PROJ_TRIG_2 = 1;
                break;
            case '3':
                FLAG_PROJ_TRIG_3 = 1;
                break;
            case '4':
                FLAG_PROJ_TRIG_4 = 1;
                break;
            case '5':
                FLAG_PROJ_TRIG_5 = 1;
                break;

            case 'X':
            case 'x':
                RL78_soft_reset(7);
                break;
            case 'Z':
            case 'z':
                RL78_soft_reset(1);
                break;
        }
    }
}

/*
    Reset Control Flag Register (RESF) 
    BIT7 : TRAP
    BIT6 : 0
    BIT5 : 0
    BIT4 : WDCLRF
    BIT3 : 0
    BIT2 : 0
    BIT1 : IAWRF
    BIT0 : LVIRF
*/
// void check_reset_source(void)
// {
//     /*
//         Internal reset request by execution of illegal instruction
//         0  Internal reset request is not generated, or the RESF register is cleared. 
//         1  Internal reset request is generated. 
//     */
//     uint8_t src = RESF;
//     printf_tiny("Reset Source <0x%08X>\r\n", src);

//     #if 1   //DEBUG , list reset source
//     if (src & BIT0)
//     {
//         printf_tiny("0)voltage detector (LVD)\r\n");       
//     }
//     if (src & BIT1)
//     {
//         printf_tiny("1)illegal-memory access\r\n");       
//     }
//     if (src & BIT2)
//     {
//         printf_tiny("2)EMPTY\r\n");       
//     }
//     if (src & BIT3)
//     {
//         printf_tiny("3)EMPTY\r\n");       
//     }
//     if (src & BIT4)
//     {
//         printf_tiny("4)watchdog timer (WDT) or clock monitor\r\n");       
//     }
//     if (src & BIT5)
//     {
//         printf_tiny("5)EMPTY\r\n");       
//     }
//     if (src & BIT6)
//     {
//         printf_tiny("6)EMPTY\r\n");       
//     }
//     if (src & BIT7)
//     {
//         printf_tiny("7)execution of illegal instruction\r\n");       
//     }
//     #endif

// }

/*
    7:Internal reset by execution of illegal instruction
    1:Internal reset by illegal-memory access
*/
//perform sofware reset
void _reset_by_illegal_instruction(void)
{
    static const unsigned char illegal_Instruction = 0xFF;
    void (*dummy) (void) = (void (*)(void))&illegal_Instruction;
    dummy();
}
void _reset_by_illegal_memory_access(void)
{
    // #if 1
    // const unsigned char ILLEGAL_ACCESS_ON = 0x80;
    // IAWCTL |= ILLEGAL_ACCESS_ON;            // switch IAWEN on (default off)
    // *(__far volatile char *)0x00000 = 0x00; //write illegal address 0x00000(RESET VECTOR)
    // #else
    // signed char __far* a;                   // Create a far-Pointer
    // IAWCTL |= _80_CGC_ILLEGAL_ACCESS_ON;    // switch IAWEN on (default off)
    // a = (signed char __far*) 0x0000;        // Point to 0x000000 (FLASH-ROM area)
    // *a = 0;
    // #endif
}

void RL78_soft_reset(unsigned char flag)
{
    switch(flag)
    {
        case 7: // do not use under debug mode
            _reset_by_illegal_instruction();        
            break;
        case 1:
            _reset_by_illegal_memory_access();
            break;
    }
}

// retarget printf
int __far putchar(int c)
{
    // G15 , UART0
    STMK0 = 1U;    /* disable INTST0 interrupt */
    TXD0 = (unsigned char)c;
    while(STIF0 == 0)
    {

    }
    STIF0 = 0U;    /* clear INTST0 interrupt flag */
    return c;
}

void hardware_init(void)
{
    // const unsigned char indicator[] = "hardware_init";
    BSP_EI();
    R_Config_UART0_Start();         // UART , P03 , P04
    R_Config_TAU0_1_Start();        // TIMER

    #if defined (ENABLE_BUTTON)
    R_Config_INTC_INTP0_Start();    // BUTTON , P137 
    #endif

    ADC_init();                     // ADC : P02/AIN1
    
    // check_reset_source();
    // printf("%s finish\r\n\r\n",__func__);
    printf_tiny("%s finish\r\n\r\n",__func__);
}
