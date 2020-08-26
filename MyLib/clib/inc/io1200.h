/****************************************************************************
 **             - io1200.h -
 **
 **     This file declares the internal register addresses for AT90S1200.
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
#error This compiler does not support the AT90S1200
#endif 
 
#ifdef __IAR_SYSTEMS_ASM__

#if TID_GUARD(0)
#error This file should only be compiled with iccavr or aavr whith processor option -v0
#endif /* TID_GUARD(0) */

/* Include the SFR part if this file has not been included before,
 * OR this file is included by the assembler (SFRs must be defined in
 * each assembler module). */
#if !defined(__IO1200_H) || defined(__IAR_SYSTEMS_ASM__)

#pragma language=extended


/*==========================*/
/* Predefined SFR Addresses */
/*==========================*/

SFR_B(ACSR,   0x08)     /* Analog Comparator Control and Status Register */
SFR_B(PIND,   0x10)     /* Input Pins, Port D */
SFR_B(DDRD,   0x11)     /* Data Direction Register, Port D */
SFR_B(PORTD,  0x12)     /* Data Register, Port D */
SFR_B(PINB,   0x16)     /* Input Pins, Port B */
SFR_B(DDRB,   0x17)     /* Data Direction Register, Port B */
SFR_B(PORTB,  0x18)     /* Data Register, Port B */
SFR_B(EECR,   0x1C)     /* EEPROM Control Register */
SFR_B(EEDR,   0x1D)     /* EEPROM Data Register */
SFR_B(EEAR,   0x1E)     /* EEPROM Address Register */
SFR_B(WDTCR,  0x21)     /* Watchdog Timer Control Register */
SFR_B(TCNT0,  0x32)     /* Timer/Counter 0 */
SFR_B(TCCR0,  0x33)     /* Timer/Counter 0 Control Register */
SFR_B(MCUCR,  0x35)     /* MCU general Control Register */
SFR_B(TIFR,   0x38)     /* Timer/Counter Interrupt Flag register */
SFR_B(TIMSK,  0x39)     /* Timer/Counter Interrupt MaSK register */
SFR_B(GIMSK,  0x3B)     /* General Interrupt MaSK register */
SFR_B(SREG,   0x3F)     /* Status REGister */

#ifndef __IO1200_H
#define __IO1200_H


/* SFRs are local in assembler modules (so this file may need to be */
/* included in more than one module in the same source file), */
/* but #defines must only be made once per source file. */

/*==============================*/
/* Interrupt Vector Definitions */
/*==============================*/

/* NB! vectors are specified as byte addresses */

#define    RESET_vect           (0x00)
#define    INT0_vect            (0x01)
#define    TIMER0_OVF_vect      (0x02)
#define    ANA_COMP_vect        (0x03)


/* Bit definitions for use with the IAR Assembler   
   The Register Bit names are represented by their bit number (0-7).
*/

/* General Interrupt MaSK register */
#define    INT0    6

/* Timer/Counter Interrupt MaSK register */
#define    TOIE0   1
 
/* Timer/Counter Interrupt Flag register */
#define    TOV0    1
 
/* MCU general Control Register */
#define    SE      5
#define    SM      4
#define    ISC01   1
#define    ISC00   0
 
/* Timer/Counter 0 Control Register */
#define    CS02    2
#define    CS01    1
#define    CS00    0
 
/* Watchdog Timer Control Register */
#define    WDE     3
#define    WDP2    2
#define    WDP1    1
#define    WDP0    0
 
/* EEPROM Control Register */
#define    EEWE    1
#define    EERE    0
 
/* Data Register, Port B */
#define    PB7     7
#define    PB6     6
#define    PB5     5
#define    PB4     4
#define    PB3     3
#define    PB2     2
#define    PB1     1
#define    PB0     0
 
/* Data Register, Port B */
#define    PORTB7  7
#define    PORTB6  6
#define    PORTB5  5
#define    PORTB4  4
#define    PORTB3  3
#define    PORTB2  2
#define    PORTB1  1
#define    PORTB0  0
 
/* Data Direction Register, Port B */
#define    DDB7    7
#define    DDB6    6
#define    DDB5    5
#define    DDB4    4
#define    DDB3    3
#define    DDB2    2
#define    DDB1    1
#define    DDB0    0
 
/* Input Pins, Port B */
#define    PINB7   7
#define    PINB6   6
#define    PINB5   5
#define    PINB4   4
#define    PINB3   3
#define    PINB2   2
#define    PINB1   1
#define    PINB0   0
 
/* Data Register, Port D */
#define    PD6     6
#define    PD5     5
#define    PD4     4
#define    PD3     3
#define    PD2     2
#define    PD1     1
#define    PD0     0
 
/* Data Register, Port D */
#define    PORTD6  6
#define    PORTD5  5
#define    PORTD4  4
#define    PORTD3  3
#define    PORTD2  2
#define    PORTD1  1
#define    PORTD0  0
 
/* Data Direction Register, Port D */
#define    DDD6    6
#define    DDD5    5
#define    DDD4    4
#define    DDD3    3
#define    DDD2    2
#define    DDD1    1
#define    DDD0    0
 
/* Input Pins, Port D */
#define    PIND6   6
#define    PIND5   5
#define    PIND4   4
#define    PIND3   3
#define    PIND2   2
#define    PIND1   1
#define    PIND0   0
 
/* Analog Comparator Control and Status Register */
#define    ACD     7
#define    ACO     5
#define    ACI     4
#define    ACIE    3
#define    ACIS1   1
#define    ACIS0   0
 
/* Pointer definition   */
#define    ZL      R30
 
/* Constants */
#define    E2END     0x3F
#define    FLASHEND  0x03FF
 
#endif /* __IO1200_H (define part) */
#endif /* __IO1200_H (SFR part) */
#endif /* __IAR_SYSTEMS_ASM__ (Bit definitions)*/
