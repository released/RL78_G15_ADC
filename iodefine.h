/******************************************************************************/
/* DISCLAIMER                                                                 */
/* This software is supplied by Renesas Electronics Corporation and is only   */
/* intended for use with Renesas products. No other uses are authorized.This  */
/* software is owned by Renesas Electronics Corporation and is protected      */
/* under all applicable laws, including copyright laws.                       */
/* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES          */
/* REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING  */
/* BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR */
/* PURPOSE AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY           */
/* DISCLAIMED.                                                                */
/* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS     */
/* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE       */
/* LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL      */
/* DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS    */
/* AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.           */
/* Renesas reserves the right, without notice, to make changes to this        */
/* software and to discontinue the availability of this software.             */
/* By using this software, you agree to the additional terms and conditions   */
/* found by accessing the following link:                                     */
/* www.renesas.com/disclaimer                                                 */
/*                                                                            */
/* Device     : RL78/R5F12068                                                 */
/* File Name  : iodefine.h                                                    */
/* Abstract   : Definition of Special Function Register (SFR)                 */
/* History    : V1.00  [Device File version]                                  */
/* Options    : -df=C:\Program Files (x86)\Renesas Electronics\CS+\CC\Device\ */
/*              RL78\Devicefile\DR5F12068.DVF -o=D:\SourceCode\Renesas\CS+\St */
/*              udy_RL78_F15_SelfTest\iodefine.h -f                           */
/* Date       : 2024/2/29                                                     */
/* Version    : V1.19.00.01  [df2iodef.exe version]                           */
/* This is a typical example.                                                 */
/*                                                                            */
/******************************************************************************/
#ifndef __R5F12068IODEFINE_HEADER__
#define __R5F12068IODEFINE_HEADER__

typedef struct
{
    unsigned char no0:1;
    unsigned char no1:1;
    unsigned char no2:1;
    unsigned char no3:1;
    unsigned char no4:1;
    unsigned char no5:1;
    unsigned char no6:1;
    unsigned char no7:1;
} __bitf_T;

typedef struct
{
    unsigned char no0:1;
    unsigned char no1:1;
    unsigned char no2:1;
    unsigned char no3:1;
    unsigned char no4:1;
    unsigned char no5:1;
    unsigned char no6:1;
    unsigned char no7:1;
    unsigned char no8:1;
    unsigned char no9:1;
    unsigned char no10:1;
    unsigned char no11:1;
    unsigned char no12:1;
    unsigned char no13:1;
    unsigned char no14:1;
    unsigned char no15:1;
} __bitf_T2;



#define ADM2         (*(volatile __near unsigned char  *)0x10)
#define ADM2_bit     (*(volatile __near __bitf_T *)0x10)
#define ADTYP        (((volatile __near __bitf_T *)0x10)->no0)
#define ADTES        (*(volatile __near unsigned char  *)0x13)
#define PU0          (*(volatile __near unsigned char  *)0x30)
#define PU0_bit      (*(volatile __near __bitf_T *)0x30)
#define PU2          (*(volatile __near unsigned char  *)0x32)
#define PU2_bit      (*(volatile __near __bitf_T *)0x32)
#define PU4          (*(volatile __near unsigned char  *)0x34)
#define PU4_bit      (*(volatile __near __bitf_T *)0x34)
#define PU12         (*(volatile __near unsigned char  *)0x3C)
#define PU12_bit     (*(volatile __near __bitf_T *)0x3C)
#define POM0         (*(volatile __near unsigned char  *)0x50)
#define POM0_bit     (*(volatile __near __bitf_T *)0x50)
#define POM2         (*(volatile __near unsigned char  *)0x52)
#define POM2_bit     (*(volatile __near __bitf_T *)0x52)
#define POM4         (*(volatile __near unsigned char  *)0x54)
#define POM4_bit     (*(volatile __near __bitf_T *)0x54)
#define PMC0         (*(volatile __near unsigned char  *)0x60)
#define PMC0_bit     (*(volatile __near __bitf_T *)0x60)
#define PMC2         (*(volatile __near unsigned char  *)0x62)
#define PMC2_bit     (*(volatile __near __bitf_T *)0x62)
#define NFEN0        (*(volatile __near unsigned char  *)0x70)
#define NFEN0_bit    (*(volatile __near __bitf_T *)0x70)
#define NFEN1        (*(volatile __near unsigned char  *)0x71)
#define NFEN1_bit    (*(volatile __near __bitf_T *)0x71)
#define ISC          (*(volatile __near unsigned char  *)0x73)
#define ISC_bit      (*(volatile __near __bitf_T *)0x73)
#define PIOR2        (*(volatile __near unsigned char  *)0x75)
#define PIOR0        (*(volatile __near unsigned char  *)0x77)
#define PIOR1        (*(volatile __near unsigned char  *)0x79)
#define PIOR3        (*(volatile __near unsigned char  *)0x7C)
#define HIOTRM       (*(volatile __near unsigned char  *)0xA0)
#define HOCODIV      (*(volatile __near unsigned char  *)0xA8)
#define FSSET        (*(volatile __near unsigned char  *)0xBE)
#define FLPMC        (*(volatile __near unsigned char  *)0xC0)
#define FSSQ         (*(volatile __near unsigned char  *)0xC1)
#define FSSQ_bit     (*(volatile __near __bitf_T *)0xC1)
#define FLAPL        (*(volatile __near unsigned char  *)0xC2)
#define FLAPH        (*(volatile __near unsigned char  *)0xC3)
#define FLSEDL       (*(volatile __near unsigned char  *)0xC4)
#define FLSEDH       (*(volatile __near unsigned char  *)0xC5)
#define FSASTL       (*(volatile __near unsigned char  *)0xC6)
#define FSASTL_bit   (*(volatile __near __bitf_T *)0xC6)
#define FSASTH       (*(volatile __near unsigned char  *)0xC7)
#define FSASTH_bit   (*(volatile __near __bitf_T *)0xC7)
#define FLWLL        (*(volatile __near unsigned char  *)0xC8)
#define FLWLH        (*(volatile __near unsigned char  *)0xC9)
#define FLWHL        (*(volatile __near unsigned char  *)0xCA)
#define FLWHH        (*(volatile __near unsigned char  *)0xCB)
#define PER0         (*(volatile __near unsigned char  *)0xF0)
#define PER0_bit     (*(volatile __near __bitf_T *)0xF0)
#define TAU0EN       (((volatile __near __bitf_T *)0xF0)->no0)
#define SAU0EN       (((volatile __near __bitf_T *)0xF0)->no2)
#define IICA0EN      (((volatile __near __bitf_T *)0xF0)->no4)
#define ADCEN        (((volatile __near __bitf_T *)0xF0)->no5)
#define CMPEN        (((volatile __near __bitf_T *)0xF0)->no6)
#define TMKAEN       (((volatile __near __bitf_T *)0xF0)->no7)
#define OSMC         (*(volatile __near unsigned char  *)0xF3)
#define BCDADJ       (*(volatile __near unsigned char  *)0xFE)
#define SSR00        (*(volatile __near unsigned short *)0x100)
#define SSR00L       (*(volatile __near unsigned char  *)0x100)
#define SSR01        (*(volatile __near unsigned short *)0x102)
#define SSR01L       (*(volatile __near unsigned char  *)0x102)
#define SIR00        (*(volatile __near unsigned short *)0x108)
#define SIR00L       (*(volatile __near unsigned char  *)0x108)
#define SIR01        (*(volatile __near unsigned short *)0x10A)
#define SIR01L       (*(volatile __near unsigned char  *)0x10A)
#define SMR00        (*(volatile __near unsigned short *)0x110)
#define SMR01        (*(volatile __near unsigned short *)0x112)
#define SCR00        (*(volatile __near unsigned short *)0x118)
#define SCR01        (*(volatile __near unsigned short *)0x11A)
#define SE0          (*(volatile __near unsigned short *)0x120)
#define SE0L         (*(volatile __near unsigned char  *)0x120)
#define SE0L_bit     (*(volatile __near __bitf_T *)0x120)
#define SS0          (*(volatile __near unsigned short *)0x122)
#define SS0L         (*(volatile __near unsigned char  *)0x122)
#define SS0L_bit     (*(volatile __near __bitf_T *)0x122)
#define ST0          (*(volatile __near unsigned short *)0x124)
#define ST0L         (*(volatile __near unsigned char  *)0x124)
#define ST0L_bit     (*(volatile __near __bitf_T *)0x124)
#define SPS0         (*(volatile __near unsigned short *)0x126)
#define SPS0L        (*(volatile __near unsigned char  *)0x126)
#define SO0          (*(volatile __near unsigned short *)0x128)
#define SOE0         (*(volatile __near unsigned short *)0x12A)
#define SOE0L        (*(volatile __near unsigned char  *)0x12A)
#define SOE0L_bit    (*(volatile __near __bitf_T *)0x12A)
#define SOL0         (*(volatile __near unsigned short *)0x134)
#define SOL0L        (*(volatile __near unsigned char  *)0x134)
#define TCR00        (*(volatile __near unsigned short *)0x180)
#define TCR01        (*(volatile __near unsigned short *)0x182)
#define TCR02        (*(volatile __near unsigned short *)0x184)
#define TCR03        (*(volatile __near unsigned short *)0x186)
#define TCR04        (*(volatile __near unsigned short *)0x188)
#define TCR05        (*(volatile __near unsigned short *)0x18A)
#define TCR06        (*(volatile __near unsigned short *)0x18C)
#define TCR07        (*(volatile __near unsigned short *)0x18E)
#define TMR00        (*(volatile __near unsigned short *)0x190)
#define TMR01        (*(volatile __near unsigned short *)0x192)
#define TMR02        (*(volatile __near unsigned short *)0x194)
#define TMR03        (*(volatile __near unsigned short *)0x196)
#define TMR04        (*(volatile __near unsigned short *)0x198)
#define TMR05        (*(volatile __near unsigned short *)0x19A)
#define TMR06        (*(volatile __near unsigned short *)0x19C)
#define TMR07        (*(volatile __near unsigned short *)0x19E)
#define TSR00        (*(volatile __near unsigned short *)0x1A0)
#define TSR00L       (*(volatile __near unsigned char  *)0x1A0)
#define TSR01        (*(volatile __near unsigned short *)0x1A2)
#define TSR01L       (*(volatile __near unsigned char  *)0x1A2)
#define TSR02        (*(volatile __near unsigned short *)0x1A4)
#define TSR02L       (*(volatile __near unsigned char  *)0x1A4)
#define TSR03        (*(volatile __near unsigned short *)0x1A6)
#define TSR03L       (*(volatile __near unsigned char  *)0x1A6)
#define TSR04        (*(volatile __near unsigned short *)0x1A8)
#define TSR04L       (*(volatile __near unsigned char  *)0x1A8)
#define TSR05        (*(volatile __near unsigned short *)0x1AA)
#define TSR05L       (*(volatile __near unsigned char  *)0x1AA)
#define TSR06        (*(volatile __near unsigned short *)0x1AC)
#define TSR06L       (*(volatile __near unsigned char  *)0x1AC)
#define TSR07        (*(volatile __near unsigned short *)0x1AE)
#define TSR07L       (*(volatile __near unsigned char  *)0x1AE)
#define TE0          (*(volatile __near unsigned short *)0x1B0)
#define TE0L         (*(volatile __near unsigned char  *)0x1B0)
#define TE0L_bit     (*(volatile __near __bitf_T *)0x1B0)
#define TS0          (*(volatile __near unsigned short *)0x1B2)
#define TS0L         (*(volatile __near unsigned char  *)0x1B2)
#define TS0L_bit     (*(volatile __near __bitf_T *)0x1B2)
#define TT0          (*(volatile __near unsigned short *)0x1B4)
#define TT0L         (*(volatile __near unsigned char  *)0x1B4)
#define TT0L_bit     (*(volatile __near __bitf_T *)0x1B4)
#define TPS0         (*(volatile __near unsigned short *)0x1B6)
#define TO0          (*(volatile __near unsigned short *)0x1B8)
#define TO0L         (*(volatile __near unsigned char  *)0x1B8)
#define TOE0         (*(volatile __near unsigned short *)0x1BA)
#define TOE0L        (*(volatile __near unsigned char  *)0x1BA)
#define TOE0L_bit    (*(volatile __near __bitf_T *)0x1BA)
#define TOL0         (*(volatile __near unsigned short *)0x1BC)
#define TOL0L        (*(volatile __near unsigned char  *)0x1BC)
#define TOM0         (*(volatile __near unsigned short *)0x1BE)
#define TOM0L        (*(volatile __near unsigned char  *)0x1BE)
#define IICCTL00     (*(volatile __near unsigned char  *)0x230)
#define IICCTL00_bit (*(volatile __near __bitf_T *)0x230)
#define SPT0         (((volatile __near __bitf_T *)0x230)->no0)
#define STT0         (((volatile __near __bitf_T *)0x230)->no1)
#define ACKE0        (((volatile __near __bitf_T *)0x230)->no2)
#define WTIM0        (((volatile __near __bitf_T *)0x230)->no3)
#define SPIE0        (((volatile __near __bitf_T *)0x230)->no4)
#define WREL0        (((volatile __near __bitf_T *)0x230)->no5)
#define LREL0        (((volatile __near __bitf_T *)0x230)->no6)
#define IICE0        (((volatile __near __bitf_T *)0x230)->no7)
#define IICCTL01     (*(volatile __near unsigned char  *)0x231)
#define IICCTL01_bit (*(volatile __near __bitf_T *)0x231)
#define DFC0         (((volatile __near __bitf_T *)0x231)->no2)
#define SMC0         (((volatile __near __bitf_T *)0x231)->no3)
#define DAD0         (((volatile __near __bitf_T *)0x231)->no4)
#define CLD0         (((volatile __near __bitf_T *)0x231)->no5)
#define WUP0         (((volatile __near __bitf_T *)0x231)->no7)
#define IICWL0       (*(volatile __near unsigned char  *)0x232)
#define IICWH0       (*(volatile __near unsigned char  *)0x233)
#define SVA0         (*(volatile __near unsigned char  *)0x234)
#define P0           (*(volatile __near unsigned char  *)0xFF00)
#define P0_bit       (*(volatile __near __bitf_T *)0xFF00)
#define P2           (*(volatile __near unsigned char  *)0xFF02)
#define P2_bit       (*(volatile __near __bitf_T *)0xFF02)
#define P4           (*(volatile __near unsigned char  *)0xFF04)
#define P4_bit       (*(volatile __near __bitf_T *)0xFF04)
#define P12          (*(volatile __near unsigned char  *)0xFF0C)
#define P12_bit      (*(volatile __near __bitf_T *)0xFF0C)
#define P13          (*(volatile __near unsigned char  *)0xFF0D)
#define P13_bit      (*(volatile __near __bitf_T *)0xFF0D)
#define SDR00        (*(volatile __near unsigned short *)0xFF10)
#define SIO00        (*(volatile __near unsigned char  *)0xFF10)
#define TXD0         (*(volatile __near unsigned char  *)0xFF10)
#define SDR01        (*(volatile __near unsigned short *)0xFF12)
#define RXD0         (*(volatile __near unsigned char  *)0xFF12)
#define SIO01        (*(volatile __near unsigned char  *)0xFF12)
#define TDR00        (*(volatile __near unsigned short *)0xFF18)
#define TDR01        (*(volatile __near unsigned short *)0xFF1A)
#define TDR01L       (*(volatile __near unsigned char  *)0xFF1A)
#define TDR01H       (*(volatile __near unsigned char  *)0xFF1B)
#define ADCR         (*(volatile __near unsigned short *)0xFF1E)
#define ADCRH        (*(volatile __near unsigned char  *)0xFF1F)
#define PM0          (*(volatile __near unsigned char  *)0xFF20)
#define PM0_bit      (*(volatile __near __bitf_T *)0xFF20)
#define PM2          (*(volatile __near unsigned char  *)0xFF22)
#define PM2_bit      (*(volatile __near __bitf_T *)0xFF22)
#define PM4          (*(volatile __near unsigned char  *)0xFF24)
#define PM4_bit      (*(volatile __near __bitf_T *)0xFF24)
#define PM12         (*(volatile __near unsigned char  *)0xFF2C)
#define PM12_bit     (*(volatile __near __bitf_T *)0xFF2C)
#define ADM0         (*(volatile __near unsigned char  *)0xFF30)
#define ADM0_bit     (*(volatile __near __bitf_T *)0xFF30)
#define ADCE         (((volatile __near __bitf_T *)0xFF30)->no0)
#define ADCS         (((volatile __near __bitf_T *)0xFF30)->no7)
#define ADS          (*(volatile __near unsigned char  *)0xFF31)
#define ADS_bit      (*(volatile __near __bitf_T *)0xFF31)
#define EGP0         (*(volatile __near unsigned char  *)0xFF38)
#define EGP0_bit     (*(volatile __near __bitf_T *)0xFF38)
#define EGN0         (*(volatile __near unsigned char  *)0xFF39)
#define EGN0_bit     (*(volatile __near __bitf_T *)0xFF39)
#define IICA0        (*(volatile __near unsigned char  *)0xFF50)
#define IICS0        (*(volatile __near unsigned char  *)0xFF51)
#define IICS0_bit    (*(volatile __near __bitf_T *)0xFF51)
#define SPD0         (((volatile __near __bitf_T *)0xFF51)->no0)
#define STD0         (((volatile __near __bitf_T *)0xFF51)->no1)
#define ACKD0        (((volatile __near __bitf_T *)0xFF51)->no2)
#define TRC0         (((volatile __near __bitf_T *)0xFF51)->no3)
#define COI0         (((volatile __near __bitf_T *)0xFF51)->no4)
#define EXC0         (((volatile __near __bitf_T *)0xFF51)->no5)
#define ALD0         (((volatile __near __bitf_T *)0xFF51)->no6)
#define MSTS0        (((volatile __near __bitf_T *)0xFF51)->no7)
#define IICF0        (*(volatile __near unsigned char  *)0xFF52)
#define IICF0_bit    (*(volatile __near __bitf_T *)0xFF52)
#define IICRSV0      (((volatile __near __bitf_T *)0xFF52)->no0)
#define STCEN0       (((volatile __near __bitf_T *)0xFF52)->no1)
#define IICBSY0      (((volatile __near __bitf_T *)0xFF52)->no6)
#define STCF0        (((volatile __near __bitf_T *)0xFF52)->no7)
#define COMPMDR      (*(volatile __near unsigned char  *)0xFF60)
#define COMPMDR_bit  (*(volatile __near __bitf_T *)0xFF60)
#define C0ENB        (((volatile __near __bitf_T *)0xFF60)->no0)
#define C0MON        (((volatile __near __bitf_T *)0xFF60)->no3)
#define C1ENB        (((volatile __near __bitf_T *)0xFF60)->no4)
#define C1MON        (((volatile __near __bitf_T *)0xFF60)->no7)
#define COMPFIR      (*(volatile __near unsigned char  *)0xFF61)
#define COMPFIR_bit  (*(volatile __near __bitf_T *)0xFF61)
#define COMPOCR      (*(volatile __near unsigned char  *)0xFF62)
#define COMPOCR_bit  (*(volatile __near __bitf_T *)0xFF62)
#define C0IE         (((volatile __near __bitf_T *)0xFF62)->no0)
#define C0OE         (((volatile __near __bitf_T *)0xFF62)->no1)
#define C0OP         (((volatile __near __bitf_T *)0xFF62)->no2)
#define C1IE         (((volatile __near __bitf_T *)0xFF62)->no4)
#define C1OE         (((volatile __near __bitf_T *)0xFF62)->no5)
#define C1OP         (((volatile __near __bitf_T *)0xFF62)->no6)
#define SPDMD        (((volatile __near __bitf_T *)0xFF62)->no7)
#define TDR02        (*(volatile __near unsigned short *)0xFF64)
#define TDR03        (*(volatile __near unsigned short *)0xFF66)
#define TDR03L       (*(volatile __near unsigned char  *)0xFF66)
#define TDR03H       (*(volatile __near unsigned char  *)0xFF67)
#define TDR04        (*(volatile __near unsigned short *)0xFF68)
#define TDR05        (*(volatile __near unsigned short *)0xFF6A)
#define TDR06        (*(volatile __near unsigned short *)0xFF6C)
#define TDR07        (*(volatile __near unsigned short *)0xFF6E)
#define ITMC         (*(volatile __near unsigned short *)0xFF90)
#define CMC          (*(volatile __near unsigned char  *)0xFFA0)
#define CSC          (*(volatile __near unsigned char  *)0xFFA1)
#define CSC_bit      (*(volatile __near __bitf_T *)0xFFA1)
#define HIOSTOP      (((volatile __near __bitf_T *)0xFFA1)->no0)
#define MSTOP        (((volatile __near __bitf_T *)0xFFA1)->no7)
#define OSTC         (*(volatile __near unsigned char  *)0xFFA2)
#define OSTC_bit     (*(volatile __near __bitf_T *)0xFFA2)
#define OSTS         (*(volatile __near unsigned char  *)0xFFA3)
#define CKC          (*(volatile __near unsigned char  *)0xFFA4)
#define CKC_bit      (*(volatile __near __bitf_T *)0xFFA4)
#define MCM0         (((volatile __near __bitf_T *)0xFFA4)->no4)
#define MCS          (((volatile __near __bitf_T *)0xFFA4)->no5)
#define CKS0         (*(volatile __near unsigned char  *)0xFFA5)
#define CKS0_bit     (*(volatile __near __bitf_T *)0xFFA5)
#define PCLOE0       (((volatile __near __bitf_T *)0xFFA5)->no7)
#define RESF         (*(volatile __near unsigned char  *)0xFFA8)
#define WDTE         (*(volatile __near unsigned char  *)0xFFAB)
#define IF0          (*(volatile __near unsigned short *)0xFFE0)
#define IF0L         (*(volatile __near unsigned char  *)0xFFE0)
#define IF0L_bit     (*(volatile __near __bitf_T *)0xFFE0)
#define IF0H         (*(volatile __near unsigned char  *)0xFFE1)
#define IF0H_bit     (*(volatile __near __bitf_T *)0xFFE1)
#define WDTIIF       (((volatile __near __bitf_T *)0xFFE0)->no0)
#define PIF0         (((volatile __near __bitf_T *)0xFFE0)->no1)
#define PIF1         (((volatile __near __bitf_T *)0xFFE0)->no2)
#define PIF2         (((volatile __near __bitf_T *)0xFFE0)->no3)
#define PIF3         (((volatile __near __bitf_T *)0xFFE0)->no4)
#define PIF4         (((volatile __near __bitf_T *)0xFFE0)->no5)
#define PIF5         (((volatile __near __bitf_T *)0xFFE0)->no6)
#define STIF0        (((volatile __near __bitf_T *)0xFFE0)->no7)
#define CSIIF00      (((volatile __near __bitf_T *)0xFFE0)->no7)
#define IICIF00      (((volatile __near __bitf_T *)0xFFE0)->no7)
#define SRIF0        (((volatile __near __bitf_T *)0xFFE1)->no0)
#define CSIIF01      (((volatile __near __bitf_T *)0xFFE1)->no0)
#define IICIF01      (((volatile __near __bitf_T *)0xFFE1)->no0)
#define SREIF0       (((volatile __near __bitf_T *)0xFFE1)->no1)
#define TMIF01H      (((volatile __near __bitf_T *)0xFFE1)->no2)
#define TMIF00       (((volatile __near __bitf_T *)0xFFE1)->no3)
#define TMIF01       (((volatile __near __bitf_T *)0xFFE1)->no4)
#define ADIF         (((volatile __near __bitf_T *)0xFFE1)->no5)
#define PIF6         (((volatile __near __bitf_T *)0xFFE1)->no6)
#define PIF7         (((volatile __near __bitf_T *)0xFFE1)->no7)
#define IF1          (*(volatile __near unsigned short *)0xFFE2)
#define IF1L         (*(volatile __near unsigned char  *)0xFFE2)
#define IF1L_bit     (*(volatile __near __bitf_T *)0xFFE2)
#define IF1H         (*(volatile __near unsigned char  *)0xFFE3)
#define IF1H_bit     (*(volatile __near __bitf_T *)0xFFE3)
#define TMIF03H      (((volatile __near __bitf_T *)0xFFE2)->no0)
#define IICAIF0      (((volatile __near __bitf_T *)0xFFE2)->no1)
#define TMIF02       (((volatile __near __bitf_T *)0xFFE2)->no2)
#define TMIF03       (((volatile __near __bitf_T *)0xFFE2)->no3)
#define ITIF         (((volatile __near __bitf_T *)0xFFE2)->no4)
#define TMIF04       (((volatile __near __bitf_T *)0xFFE2)->no5)
#define TMIF05       (((volatile __near __bitf_T *)0xFFE2)->no6)
#define TMIF06       (((volatile __near __bitf_T *)0xFFE2)->no7)
#define TMIF07       (((volatile __near __bitf_T *)0xFFE3)->no0)
#define CMPIF0       (((volatile __near __bitf_T *)0xFFE3)->no1)
#define CMPIF1       (((volatile __near __bitf_T *)0xFFE3)->no2)
#define MK0          (*(volatile __near unsigned short *)0xFFE4)
#define MK0L         (*(volatile __near unsigned char  *)0xFFE4)
#define MK0L_bit     (*(volatile __near __bitf_T *)0xFFE4)
#define MK0H         (*(volatile __near unsigned char  *)0xFFE5)
#define MK0H_bit     (*(volatile __near __bitf_T *)0xFFE5)
#define WDTIMK       (((volatile __near __bitf_T *)0xFFE4)->no0)
#define PMK0         (((volatile __near __bitf_T *)0xFFE4)->no1)
#define PMK1         (((volatile __near __bitf_T *)0xFFE4)->no2)
#define PMK2         (((volatile __near __bitf_T *)0xFFE4)->no3)
#define PMK3         (((volatile __near __bitf_T *)0xFFE4)->no4)
#define PMK4         (((volatile __near __bitf_T *)0xFFE4)->no5)
#define PMK5         (((volatile __near __bitf_T *)0xFFE4)->no6)
#define STMK0        (((volatile __near __bitf_T *)0xFFE4)->no7)
#define CSIMK00      (((volatile __near __bitf_T *)0xFFE4)->no7)
#define IICMK00      (((volatile __near __bitf_T *)0xFFE4)->no7)
#define SRMK0        (((volatile __near __bitf_T *)0xFFE5)->no0)
#define CSIMK01      (((volatile __near __bitf_T *)0xFFE5)->no0)
#define IICMK01      (((volatile __near __bitf_T *)0xFFE5)->no0)
#define SREMK0       (((volatile __near __bitf_T *)0xFFE5)->no1)
#define TMMK01H      (((volatile __near __bitf_T *)0xFFE5)->no2)
#define TMMK00       (((volatile __near __bitf_T *)0xFFE5)->no3)
#define TMMK01       (((volatile __near __bitf_T *)0xFFE5)->no4)
#define ADMK         (((volatile __near __bitf_T *)0xFFE5)->no5)
#define PMK6         (((volatile __near __bitf_T *)0xFFE5)->no6)
#define PMK7         (((volatile __near __bitf_T *)0xFFE5)->no7)
#define MK1          (*(volatile __near unsigned short *)0xFFE6)
#define MK1L         (*(volatile __near unsigned char  *)0xFFE6)
#define MK1L_bit     (*(volatile __near __bitf_T *)0xFFE6)
#define MK1H         (*(volatile __near unsigned char  *)0xFFE7)
#define MK1H_bit     (*(volatile __near __bitf_T *)0xFFE7)
#define TMMK03H      (((volatile __near __bitf_T *)0xFFE6)->no0)
#define IICAMK0      (((volatile __near __bitf_T *)0xFFE6)->no1)
#define TMMK02       (((volatile __near __bitf_T *)0xFFE6)->no2)
#define TMMK03       (((volatile __near __bitf_T *)0xFFE6)->no3)
#define ITMK         (((volatile __near __bitf_T *)0xFFE6)->no4)
#define TMMK04       (((volatile __near __bitf_T *)0xFFE6)->no5)
#define TMMK05       (((volatile __near __bitf_T *)0xFFE6)->no6)
#define TMMK06       (((volatile __near __bitf_T *)0xFFE6)->no7)
#define TMMK07       (((volatile __near __bitf_T *)0xFFE7)->no0)
#define CMPMK0       (((volatile __near __bitf_T *)0xFFE7)->no1)
#define CMPMK1       (((volatile __near __bitf_T *)0xFFE7)->no2)
#define PR00         (*(volatile __near unsigned short *)0xFFE8)
#define PR00L        (*(volatile __near unsigned char  *)0xFFE8)
#define PR00L_bit    (*(volatile __near __bitf_T *)0xFFE8)
#define PR00H        (*(volatile __near unsigned char  *)0xFFE9)
#define PR00H_bit    (*(volatile __near __bitf_T *)0xFFE9)
#define WDTIPR0      (((volatile __near __bitf_T *)0xFFE8)->no0)
#define PPR00        (((volatile __near __bitf_T *)0xFFE8)->no1)
#define PPR01        (((volatile __near __bitf_T *)0xFFE8)->no2)
#define PPR02        (((volatile __near __bitf_T *)0xFFE8)->no3)
#define PPR03        (((volatile __near __bitf_T *)0xFFE8)->no4)
#define PPR04        (((volatile __near __bitf_T *)0xFFE8)->no5)
#define PPR05        (((volatile __near __bitf_T *)0xFFE8)->no6)
#define STPR00       (((volatile __near __bitf_T *)0xFFE8)->no7)
#define CSIPR000     (((volatile __near __bitf_T *)0xFFE8)->no7)
#define IICPR000     (((volatile __near __bitf_T *)0xFFE8)->no7)
#define SRPR00       (((volatile __near __bitf_T *)0xFFE9)->no0)
#define CSIPR001     (((volatile __near __bitf_T *)0xFFE9)->no0)
#define IICPR001     (((volatile __near __bitf_T *)0xFFE9)->no0)
#define SREPR00      (((volatile __near __bitf_T *)0xFFE9)->no1)
#define TMPR001H     (((volatile __near __bitf_T *)0xFFE9)->no2)
#define TMPR000      (((volatile __near __bitf_T *)0xFFE9)->no3)
#define TMPR001      (((volatile __near __bitf_T *)0xFFE9)->no4)
#define ADPR0        (((volatile __near __bitf_T *)0xFFE9)->no5)
#define PPR06        (((volatile __near __bitf_T *)0xFFE9)->no6)
#define PPR07        (((volatile __near __bitf_T *)0xFFE9)->no7)
#define PR01         (*(volatile __near unsigned short *)0xFFEA)
#define PR01L        (*(volatile __near unsigned char  *)0xFFEA)
#define PR01L_bit    (*(volatile __near __bitf_T *)0xFFEA)
#define PR01H        (*(volatile __near unsigned char  *)0xFFEB)
#define PR01H_bit    (*(volatile __near __bitf_T *)0xFFEB)
#define TMPR003H     (((volatile __near __bitf_T *)0xFFEA)->no0)
#define IICAPR00     (((volatile __near __bitf_T *)0xFFEA)->no1)
#define TMPR002      (((volatile __near __bitf_T *)0xFFEA)->no2)
#define TMPR003      (((volatile __near __bitf_T *)0xFFEA)->no3)
#define ITPR0        (((volatile __near __bitf_T *)0xFFEA)->no4)
#define TMPR004      (((volatile __near __bitf_T *)0xFFEA)->no5)
#define TMPR005      (((volatile __near __bitf_T *)0xFFEA)->no6)
#define TMPR006      (((volatile __near __bitf_T *)0xFFEA)->no7)
#define TMPR007      (((volatile __near __bitf_T *)0xFFEB)->no0)
#define CMPPR00      (((volatile __near __bitf_T *)0xFFEB)->no1)
#define CMPPR01      (((volatile __near __bitf_T *)0xFFEB)->no2)
#define PR10         (*(volatile __near unsigned short *)0xFFEC)
#define PR10L        (*(volatile __near unsigned char  *)0xFFEC)
#define PR10L_bit    (*(volatile __near __bitf_T *)0xFFEC)
#define PR10H        (*(volatile __near unsigned char  *)0xFFED)
#define PR10H_bit    (*(volatile __near __bitf_T *)0xFFED)
#define WDTIPR1      (((volatile __near __bitf_T *)0xFFEC)->no0)
#define PPR10        (((volatile __near __bitf_T *)0xFFEC)->no1)
#define PPR11        (((volatile __near __bitf_T *)0xFFEC)->no2)
#define PPR12        (((volatile __near __bitf_T *)0xFFEC)->no3)
#define PPR13        (((volatile __near __bitf_T *)0xFFEC)->no4)
#define PPR14        (((volatile __near __bitf_T *)0xFFEC)->no5)
#define PPR15        (((volatile __near __bitf_T *)0xFFEC)->no6)
#define STPR10       (((volatile __near __bitf_T *)0xFFEC)->no7)
#define CSIPR100     (((volatile __near __bitf_T *)0xFFEC)->no7)
#define IICPR100     (((volatile __near __bitf_T *)0xFFEC)->no7)
#define SRPR10       (((volatile __near __bitf_T *)0xFFED)->no0)
#define CSIPR101     (((volatile __near __bitf_T *)0xFFED)->no0)
#define IICPR101     (((volatile __near __bitf_T *)0xFFED)->no0)
#define SREPR10      (((volatile __near __bitf_T *)0xFFED)->no1)
#define TMPR101H     (((volatile __near __bitf_T *)0xFFED)->no2)
#define TMPR100      (((volatile __near __bitf_T *)0xFFED)->no3)
#define TMPR101      (((volatile __near __bitf_T *)0xFFED)->no4)
#define ADPR1        (((volatile __near __bitf_T *)0xFFED)->no5)
#define PPR16        (((volatile __near __bitf_T *)0xFFED)->no6)
#define PPR17        (((volatile __near __bitf_T *)0xFFED)->no7)
#define PR11         (*(volatile __near unsigned short *)0xFFEE)
#define PR11L        (*(volatile __near unsigned char  *)0xFFEE)
#define PR11L_bit    (*(volatile __near __bitf_T *)0xFFEE)
#define PR11H        (*(volatile __near unsigned char  *)0xFFEF)
#define PR11H_bit    (*(volatile __near __bitf_T *)0xFFEF)
#define TMPR103H     (((volatile __near __bitf_T *)0xFFEE)->no0)
#define IICAPR10     (((volatile __near __bitf_T *)0xFFEE)->no1)
#define TMPR102      (((volatile __near __bitf_T *)0xFFEE)->no2)
#define TMPR103      (((volatile __near __bitf_T *)0xFFEE)->no3)
#define ITPR1        (((volatile __near __bitf_T *)0xFFEE)->no4)
#define TMPR104      (((volatile __near __bitf_T *)0xFFEE)->no5)
#define TMPR105      (((volatile __near __bitf_T *)0xFFEE)->no6)
#define TMPR106      (((volatile __near __bitf_T *)0xFFEE)->no7)
#define TMPR107      (((volatile __near __bitf_T *)0xFFEF)->no0)
#define CMPPR10      (((volatile __near __bitf_T *)0xFFEF)->no1)
#define CMPPR11      (((volatile __near __bitf_T *)0xFFEF)->no2)


#define INTWDTI                         0x0004
#define INTP0                           0x0006
#define INTP1                           0x0008
#define INTP2                           0x000A
#define INTP3                           0x000C
#define INTP4                           0x000E
#define INTP5                           0x0010
#define INTCSI00                        0x0012
#define INTIIC00                        0x0012
#define INTST0                          0x0012
#define INTCSI01                        0x0014
#define INTIIC01                        0x0014
#define INTSR0                          0x0014
#define INTSRE0                         0x0016
#define INTTM01H                        0x0018
#define INTTM00                         0x001A
#define INTTM01                         0x001C
#define INTAD                           0x001E
#define INTP6                           0x0020
#define INTP7                           0x0022
#define INTTM03H                        0x0024
#define INTIICA0                        0x0026
#define INTTM02                         0x0028
#define INTTM03                         0x002A
#define INTIT                           0x002C
#define INTTM04                         0x002E
#define INTTM05                         0x0030
#define INTTM06                         0x0032
#define INTTM07                         0x0034
#define INTCMP0                         0x0036
#define INTCMP1                         0x0038
#define INTFL                           0x003A

#endif
