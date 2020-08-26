/****************************************************************************
 **             - iotiny28.h -
 **
 **     This file declares the internal register addresses for ATtiny28.
 **
 **     Used with iccAVR and aAVR.
 **
 **     Copyright IAR Systems 2001. All rights reserved.
 **
 **     $Name: V2_26B $
 **
 ***************************************************************************/

#include "iomacro.h"

#ifdef __IAR_SYSTEMS_ICC__
#error This compiler does not support the ATtiny28
#endif 
 
#ifdef __IAR_SYSTEMS_ASM__

#if TID_GUARD(0)
#error This file should only be compiled with iccavr or aavr whith processor option -v0
#endif /* TID_GUARD(0) */

/* Include the SFR part if this file has not been included before,
 * OR this file is included by the assembler (SFRs must be defined in
 * each assembler module). */
#if !defined(__IOTINY28_H) || defined(__IAR_SYSTEMS_ASM__)

#pragma language=extended


/*==========================*/
/* Predefined SFR Addresses */
/*==========================*/

SFR_B(OSCCAL, 0x00)     /* Oscillator Calibration Register */
SFR_B(WDTCR,  0x01)     /* Watchdog Timer Control Register */
SFR_B(MODCR,  0x02)     /* Modulation Control Register */
SFR_B(TCNT0,  0x03)     /* Timer/Counter 0 */
SFR_B(TCCR0,  0x04)     /* Timer/Counter 0 Control Register */
SFR_B(IFR,    0x05)     /* Interrupt Flag Register */
SFR_B(ICR,    0x06)     /* Interrupt Control Register */
SFR_B(MCUCS,  0x07)     /* MCU general Control and Status Register */
SFR_B(ACSR,   0x08)     /* Analog Comparator Control and Status Register */
SFR_B(PIND,   0x10)     /* Input Pins, Port D */
SFR_B(DDRD,   0x11)     /* Data Direction Register, Port D */
SFR_B(PORTD,  0x12)     /* Data Register, Port D */
SFR_B(PINB,   0x16)     /* Input Pins, Port B */
SFR_B(PINA,   0x19)     /* Input Pins, Port A */
SFR_B(PACR,   0x1A)     /* Control (Data Direction) Register, Port A */
SFR_B(PORTA,  0x1B)     /* Data Register, Port A */
SFR_B(SREG,   0x3F)     /* Status Register */

#ifndef __IOTINY28_H
#define __IOTINY28_H


/* SFRs are local in assembler modules (so this file may need to be */
/* included in more than one module in the same source file), */
/* but #defines must only be made once per source file. */

/*==============================*/
/* Interrupt Vector Definitions */
/*==============================*/

/* NB! vectors are specified as byte addresses */

#define    RESET_vect          (0x00)
#define    INT0_vect           (0x01)
#define    INT1_vect           (0x02)
#define    LOW_LEVEL_vect      (0x03)
#define    TIMER0_OVF_vect     (0x04)
#define    ANA_COMP_vect       (0x05)


/* Bit definitions for use with the IAR Assembler   
   The Register Bit names are represented by their bit number (0-7).
*/

/* Data Register, Port A */
#define    PA3      3
#define    PA2      2
#define    PA1      1
#define    PA0      0

/* Data Register, Port A */
#define    PORTA3   3
#define    PORTA2   2
#define    PORTA1   1
#define    PORTA0   0

/* Control (Data Direction) Register, Port A */
#define    DDA3     3
#define    PA2HC    2
#define    DDA1     1
#define    DDA0     0

/* Input Pins, Port A */
#define    PINA3    3
#define    PINA1    1
#define    PINA0    0

/* Input Pins, Port B */
#define    PINB7    7
#define    PINB6    6
#define    PINB5    5
#define    PINB4    4
#define    PINB3    3
#define    PINB2    2
#define    PINB1    1
#define    PINB0    0

/* Data Register, Port D */
#define    PD7      7
#define    PD6      6
#define    PD5      5
#define    PD4      4
#define    PD3      3
#define    PD2      2
#define    PD1      1
#define    PD0      0

/* Data Register, Port D */
#define    PORTD7   7
#define    PORTD6   6
#define    PORTD5   5
#define    PORTD4   4
#define    PORTD3   3
#define    PORTD2   2
#define    PORTD1   1
#define    PORTD0   0

/* Data Direction Register, Port D */
#define    DDD7     7
#define    DDD6     6
#define    DDD5     5
#define    DDD4     4
#define    DDD3     3
#define    DDD2     2
#define    DDD1     1
#define    DDD0     0

/* Input Pins, Port D */
#define    PIND7    7
#define    PIND6    6
#define    PIND5    5
#define    PIND4    4
#define    PIND3    3
#define    PIND2    2
#define    PIND1    1
#define    PIND0    0

/* Analog Comparator Control and Status Register */
#define    ACD      7
#define    ACO      5
#define    ACI      4
#define    ACIE     3
#define    ACIS1    1
#define    ACIS0    0

/* MCU general Control and Status Register */
#define    PLUPB    7
#define    SE       5
#define    SM       4
#define    WDRF     3
#define    EXTRF    1
#define    PORF     0

/* General Interrupt Control Register */
#define    INT1     7
#define    INT0     6
#define    LLIE     5
#define    TOIE0    4
#define    ISC11    3
#define    ISC10    2
#define    ISC01    1
#define    ISC00    0

/* General Interrupt Flag Register */
#define    INTF1    7
#define    INTF0    6
#define    TOV0     4

/* Timer/Counter 0 Control Register */
#define    FOV0     7
#define    OOM01    4
#define    OOM00    3
#define    CS02     2
#define    CS01     1
#define    CS00     0

/* Modulation Control Register */
#define    ONTIM4   7
#define    ONTIM3   6
#define    ONTIM2   5
#define    ONTIM1   4
#define    ONTIM0   3
#define    MCONF2   2
#define    MCONF1   1
#define    MCONF0   0

/* Watchdog Timer Control Register */
#define    WDTOE    4
#define    WDE      3
#define    WDP2     2
#define    WDP1     1
#define    WDP0     0


/* Pointer definition */
#define    ZL     r30
#define    ZH     r31

/* Contants */
#define    FLASHEND 0x07FF

#endif  /* __IOTINY28_H (define part) */
#endif  /* __IOTINY28_H (SFR part) */
#endif  /* __IAR_SYSTEMS_ASM__ (Bit definitions)*/
