/****************************************************************************
 **             - iotiny15.h -
 **
 **     This file declares the internal register addresses for ATtiny15.
 **
 **     Used with aAVR.
 **
 **     Copyright IAR Systems 2000. All rights reserved.
 **
 **     $Name: V2_26B V2_25B V2.21H V2.21G V2_25A V2_21B $
 **
 ***************************************************************************/

#include "iomacro.h"

#ifdef __IAR_SYSTEMS_ICC__
#error This compiler currently does not support the ATtiny15.
#endif /* __IAR_SYSTEMS_ICC__ */

#if TID_GUARD(0)
#error This file should only be compiled with aavr whith processor option -v0
#endif /* TID_GUARD(0) */

/* Include the SFR part if this file has not been included before,
 * OR this file is included by the assembler (SFRs must be defined in
 * each assembler module). */
#if !defined(__IOTINY15_H) || defined(__IAR_SYSTEMS_ASM__)

#pragma language=extended

/*==========================*/
/* Predefined SFR Addresses */
/*==========================*/

SFR_B(SREG,   0x3F) /* Status REGister */
SFR_B(GIMSK,  0x3B) /* General Interrupt MaSK register */
SFR_B(GIFR,   0x3A) /* General Interrupt Flag Register */
SFR_B(TIMSK,  0x39) /* Timer/Counter Interrupt MaSK register */
SFR_B(TIFR,   0x38) /* Timer/Counter Interrupt Flag register */
SFR_B(MCUCR,  0x35) /* MCU general Control Register */
SFR_B(MCUSR,  0x34) /* MCU Status Register */
SFR_B(TCCR0,  0x33) /* Timer/Counter 0 Control Register */
SFR_B(TCNT0,  0x32) /* Timer/Counter 0 */
SFR_B(OSCCAL, 0x31) /* The System Clock Oscillator Calibration Register */
SFR_B(TCCR1,  0x30) /* The Timer/Counter1 Control Register*/
SFR_B(TCNT1,  0x2F) /* The Timer/Counter1 */
SFR_B(OCR1A,  0x2E) /* Timer/Counter1 Output Compare RegisterA */
SFR_B(OCR1B,  0x2D) /* Timer/Counter1 Output Compare RegisterB */
SFR_B(SFIOR,  0x2C) /* The Special Function IO Register */
SFR_B(WDTCR,  0x21) /* Watchdog Timer Control Register */
SFR_B(EEAR,   0x1E) /* EEPROM Address Register */
SFR_B(EEDR,   0x1D) /* EEPROM Data Register */
SFR_B(EECR,   0x1C) /* EEPROM Control Register */
SFR_B(PORTB,  0x18) /* Data Register, Port B */
SFR_B(DDRB,   0x17) /* Data Direction Register, Port B */
SFR_B(PINB,   0x16) /* Input Pins, Port B */
SFR_B(ACSR,   0x08) /* Analog Comparator Control and Status Register */
SFR_B(ADMUX,  0x07) /* The ADC Multiplexer Selection Register */
SFR_B(ADCSR,  0x06) /* The ADC Control and Status Register */
SFR_W(ADC,    0x05) /* The ADC Data Register Word */

#ifndef __IOTINY15_H
#define __IOTINY15_H

/* SFRs are local in assembler modules (so this file may need to be */
/* included in more than one module in the same source file), */
/* but #defines must only be made once per source file. */

/*==============================*/
/* Interrupt Vector Definitions */
/*==============================*/

/* NB! vectors are specified as byte addresses */

#define    RESET_vect           (0x00)
#define    INT0_vect            (0x02)
#define    PCINT_vect           (0x04)
#define    TIMER1_COMP_vect     (0x06)
#define    TIMER1_OVF_vect      (0x08)
#define    TIMER0_OVF_vect      (0x0A)
#define    EE_RDY_vect          (0x0C)
#define    ANA_COMP_vect        (0x0E)
#define    ADC_vect             (0x10)
 
#ifdef __IAR_SYSTEMS_ASM__   
#ifndef ENABLE_BIT_DEFINITIONS
#define  ENABLE_BIT_DEFINITIONS
#endif /* ENABLE_BIT_DEFINITIONS */
#endif /* __IAR_SYSTEMS_ASM__ */

#ifdef ENABLE_BIT_DEFINITIONS

/* Bit definitions for use with the IAR Assembler   
   The Register Bit names are represented by their bit number (0-7).
*/
 
/* MCU Status Register */
#define    WDRF     3
#define    BORF     2
#define    EXTRF    1
#define    PORF     0

/* General Interrupt MaSK register */
#define    INT0     6
#define    PCIE     5
 
/* General Interrupt Flag Register */
#define    INTF0    6
#define    PCIF     5
 
/* Timer/Counter Interrupt MaSK register */
#define    OCIE1    6
#define    TOIE1    2
#define    TOIE0    1
 
/* Timer/Counter Interrupt Flag Register */
#define    OCF1     6
#define    TOV1     2
#define    TOV0     1
 
/* MCU general Control Register */
#define    PUD      6
#define    SE       5
#define    SM1      4
#define    SM0      3
#define    ISC01    1
#define    ISC00    0

/* The Special Function IO Register */
#define    FOC1A    2
#define    PSR1     1
#define    PSR0     0
 
/* Timer/Counter 0 Control Register */
#define    CS02     2
#define    CS01     1
#define    CS00     0

/* The Timer/Counter1 Control Register*/
#define    CTC1     7
#define    PWM1     6
#define    COM1A1   5
#define    COM1A0   4
#define    CS13     3
#define    CS12     2
#define    CS11     1
#define    CS10     0
 
/* Watchdog Timer Control Register */
#define    WDTOE    4
#define    WDE      3
#define    WDP2     2
#define    WDP1     1
#define    WDP0     0
 
/* The EEPROM Control Register */
#define    EERIE    3
#define    EEMWE    2
#define    EEWE     1
#define    EERE     0
 
/* Analog Comparator Control and Status Register */
#define    ACD      7
#define    ACBG     6
#define    ACO      5
#define    ACI      4
#define    ACIE     3
#define    ACIS1    1
#define    ACIS0    0
 
/* The ADC Multiplexer Selection Register */
#define    REFS1    7
#define    REFS0    6
#define    ADLAR    5
#define    MUX2     2
#define    MUX1     1
#define    MUX0     0
 
/* The ADC Control and Status Register */
#define    ADEN     7
#define    ADSC     6
#define    ADFR     5
#define    ADIF     4
#define    ADIE     3
#define    ADPS2    2
#define    ADPS1    1
#define    ADPS0    0
 
/* Data Register, Port B */
#define    PB4      4
#define    PB3      3
#define    PB2      2
#define    PB1      1
#define    PB0      0
 
/* Data Register, Port B */
#define    PORTB4   4
#define    PORTB3   3
#define    PORTB2   2
#define    PORTB1   1
#define    PORTB0   0
 
/* Data Direction Register, Port B */
#define    DDB4     4
#define    DDB3     3
#define    DDB2     2
#define    DDB1     1
#define    DDB0     0
 
/* Input Pins, Port B */
#define    PINB5    5
#define    PINB4    4
#define    PINB3    3
#define    PINB2    2
#define    PINB1    1
#define    PINB0    0
 
/* Pointer definition */
#define    ZL     R30
#define    ZH     R31
 
/* Constants */
#define RAMEND    0x0000
#define XRAMEND   0x0000
#define E2END     0x0000
#define FLASHEND  0x03FF

#endif /* ENABLE_BIT_DEFINITIONS */ 
#endif /* __IOTINY15_H (define part) */

#pragma language=default

#endif /* __IOTINY15_H (SFR part) */
