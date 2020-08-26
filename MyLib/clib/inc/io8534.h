/****************************************************************************
 **             - io8534.h -
 **
 **     This file declares the internal register addresses for AT90S8534.
 **
 **     Used with iccAVR and aAVR.
 **
 **     Copyright IAR Systems 1999. All rights reserved.
 **
 **     $Name: V2_26B V2_25B V2.21H V2.21G V2_25A V2_21B $
 **
 ***************************************************************************/

#include "iomacro.h"

#if TID_GUARD(1)
#error This file should only be compiled with iccavr or aavr whith processor option -v1
#endif /* TID_GUARD(1) */

/* Include the SFR part if this file has not been included before,
 * OR this file is included by the assembler (SFRs must be defined in
 * each assembler module). */
#if !defined(__IO8534_H) || defined(__IAR_SYSTEMS_ASM__)

#pragma language=extended

/*==========================*/
/* Predefined SFR Addresses */
/*==========================*/

SFR_W(ADC,    0x04) /* ADC Data register */
SFR_B(ADCSR,  0x06) /* ADC Control and Status Register */
SFR_B(ADMUX,  0x07) /* ADC MUX */
SFR_B(GIPR,   0x10) /* General Interrupt Pin register */
SFR_B(DDRA,   0x1A) /* Data Direction Register, Port A */
SFR_B(PORTA,  0x1B) /* Data Register, Port A */
SFR_B(EECR,   0x1C) /* EEPROM Control Register */
SFR_B(EEDR,   0x1D) /* EEPROM Data Register */
SFR_W(EEAR,   0x1E) /* EEPROM Address Register */
SFR_W(TCNT1,  0x2C) /* Timer/Counter 1 */
SFR_B(TCCR1,  0x2E) /* Timer/Counter 1 Control and Status Register */
SFR_B(TCNT0,  0x32) /* Timer/Counter 0 */
SFR_B(TCCR0,  0x33) /* Timer/Counter 0 Control Register */
SFR_B(MCUCR,  0x35) /* MCU general Control Register */
SFR_B(TIFR,   0x38) /* Timer/Counter Interrupt Flag register */
SFR_B(TIMSK,  0x39) /* Timer/Counter Interrupt MaSK register */
SFR_B(GIFR,   0x3A) /* General Interrupt Flag Register */
SFR_B(GIMSK,  0x3B) /* General Interrupt MaSK register */
SFR_W(SP,     0x3D) /* Stack Pointer */
SFR_B(SREG,   0x3F) /* Status REGister */

#ifndef __IO8534_H
#define __IO8534_H

/* SFRs are local in assembler modules (so this file may need to be */
/* included in more than one module in the same source file), */
/* but #defines must only be made once per source file. */

/*                              */
/* Interrupt Vector Definitions */
/*                              */

/* NB! vectors are specified as byte addresses */

#define RESET_vect      (0x00)
#define INT0_vect       (0x02)
#define INT1_vect       (0x04)
#define TIMER1_OVF_vect (0x06)
#define TIMER0_OVF_vect (0x08)
#define ADC_vect        (0x0A)
#define EE_RDY_vect     (0x0C)

#ifdef __IAR_SYSTEMS_ASM__   
#ifndef ENABLE_BIT_DEFINITIONS
#define  ENABLE_BIT_DEFINITIONS
#endif /* ENABLE_BIT_DEFINITIONS */
#endif /* __IAR_SYSTEMS_ASM__ */

#ifdef ENABLE_BIT_DEFINITIONS


/* Bit definitions for use with the IAR Assembler   
   The Register Bit names are represented by their bit number (0-7).
*/    
 
/* General Interrupt MaSK register */
#define    INT1        7
#define    INT0        6
 
/* General Interrupt Flag Register */
#define    INTF1       7
#define    INTF0       6    

/* General Interrupt Pin register */
#define    IPIN1       3
#define    IPIN0       2    
 
/* Timer/Counter Interrupt MaSK register */
#define    TOIE1       2
#define    TOIE0       0
 
/* Timer/Counter Interrupt Flag register */
#define    TOV1         2
#define    TOV0         0
 
/* MCU general Control Register */ 
#define    SE           6
#define    SM           5
#define    ISC1         2
#define    ISC0         0
 
/* Timer/Counter 0 Control Register */
#define    CS02         2
#define    CS01         1
#define    CS00         0
 
/* Timer/Counter 1 Control and Status Register */
#define    CS12         2
#define    CS11         1
#define    CS10         0
 
/* EEPROM Control Register */
#define    EERIE        3
#define    EEMWE        2
#define    EEWE         1
#define    EERE         0
 
/* Data Register, Port A */ 
#define    PA6      6
#define    PA5      5
#define    PA4      4
#define    PA3      3
#define    PA2      2
#define    PA1      1
#define    PA0      0
                                     
/* Data Direction Register, Port A */
#define    DDA6     6
#define    DDA5     5
#define    DDA4     4
#define    DDA3     3
#define    DDA2     2
#define    DDA1     1
#define    DDA0     0
 
/* ADC MUX */
#define    MUX2     2
#define    MUX1     1
#define    MUX0     0

/* ADC Control and Status Register */
#define    ADEN     7
#define    ADSC     6
#define    ADFR     5
#define    ADIF     4
#define    ADIE     3
#define    ADPS2    2
#define    ADPS1    1
#define    ADPS0    0  
 
/* Pointer definition   */
#define    XL     r26
#define    XH     r27
#define    YL     r28
#define    YH     r29
#define    ZL     r30
#define    ZH     r31
 
/* Contants */
#define    RAMEND   0x15F    /*Last On-Chip SRAM location*/
#define    XRAMEND  0x15F
#define    E2END    0x1FF
#define    FLASHEND 0x1FFF

#endif /* ENABLE_BIT_DEFINITIONS */
#endif /* __IO8534_H (define part) */

#pragma language=default

#endif /* __IO8534_H (SFR part) */
