/****************************************************************************
 **             - io2333.h -
 **
 **     This file declares the internal register addresses for AT90S2333.
 **
 **     Used with iccAVR and aAVR.
 **
 **     Copyright IAR Systems 1999. All rights reserved.
 **
 **     $Name: V2_26B $
 **
 ***************************************************************************/

#include "iomacro.h"

#if TID_GUARD(0)
#error This file should only be compiled with iccavr or aavr whith processor option -v0
#endif /* TID_GUARD(0) */

/* Include the SFR part if this file has not been included before,
 * OR this file is included by the assembler (SFRs must be defined in
 * each assembler module). */
#if !defined(__IO2333_H) || defined(__IAR_SYSTEMS_ASM__)

#pragma language=extended

/*==========================*/
/* Predefined SFR Addresses */
/*==========================*/

SFR_B(UBRRH,  0x03) /* UART Baud Rate Register high */
SFR_W(ADC,    0x04) /* ADC Data register */
SFR_B(ADCSR,  0x06) /* ADC Control and Status Register */
SFR_B(ADMUX,  0x07) /* ADC MUX */
SFR_B(ACSR,   0x08) /* Analog Comparator Control and Status Register */
SFR_B(UBRR,   0x09) /* UART Baud Rate Register */
SFR_B(UCSRB,  0x0A) /* UART Control and Status Register */
SFR_B(UCSRA,  0x0B) /* UART Control and Status Register */
SFR_B(UDR,    0x0C) /* UART I/O Data Register */
SFR_B(SPCR,   0x0D) /* SPI Control Register */
SFR_B(SPSR,   0x0E) /* SPI Status Register */
SFR_B(SPDR,   0x0F) /* SPI I/O Data Register */
SFR_B(PIND,   0x10) /* Input Pins, Port D */
SFR_B(DDRD,   0x11) /* Data Direction Register, Port D */
SFR_B(PORTD,  0x12) /* Data Register, Port D */
SFR_B(PINC,   0x13) /* Input Pins, Port C */
SFR_B(DDRC,   0x14) /* Data Direction Register, Port C */
SFR_B(PORTC,  0x15) /* Data Register, Port C */
SFR_B(PINB,   0x16) /* Input Pins, Port B */
SFR_B(DDRB,   0x17) /* Data Direction Register, Port B */
SFR_B(PORTB,  0x18) /* Data Register, Port B */
SFR_B(EECR,   0x1C) /* EEPROM Control Register */
SFR_B(EEDR,   0x1D) /* EEPROM Data Register */
SFR_B(EEAR,   0x1E) /* EEPROM Address Register */
SFR_B(WDTCR,  0x21) /* Watchdog Timer Control Register */
SFR_W(ICR1,   0x26) /* T/C 1 Input Capture Register */
SFR_W(OCR1,   0x2A) /* Output Compare Register 1 */
SFR_W(TCNT1,  0x2C) /* Timer/Counter 1 */
SFR_B(TCCR1B, 0x2E) /* Timer/Counter 1 Control and Status Register */
SFR_B(TCCR1A, 0x2F) /* Timer/Counter 1 Control Register */
SFR_B(TCNT0,  0x32) /* Timer/Counter 0 */
SFR_B(TCCR0,  0x33) /* Timer/Counter 0 Control Register */
SFR_B(MCUSR,  0x34) /* MCU Status Register */
SFR_B(MCUCR,  0x35) /* MCU general Control Register */
SFR_B(TIFR,   0x38) /* Timer/Counter Interrupt Flag register */
SFR_B(TIMSK,  0x39) /* Timer/Counter Interrupt MaSK register */
SFR_B(GIFR,   0x3A) /* General Interrupt Flag Register */
SFR_B(GIMSK,  0x3B) /* General Interrupt MaSK register */
SFR_B(SP,     0x3D) /* Stack Pointer */
SFR_B(SREG,   0x3F) /* Status REGister */

#ifndef __IO2333_H
#define __IO2333_H

/* SFRs are local in assembler modules (so this file may need to be */
/* included in more than one module in the same source file), */
/* but #defines must only be made once per source file. */

/*                              */
/* Interrupt Vector Definitions */
/*                              */

/* NB! vectors are specified as byte addresses */

#define RESET_vect        (0x00)
#define INT0_vect         (0x02)
#define INT1_vect         (0x04)
#define TIMER1_CAPT1_vect (0x06)
#define TIMER1_COMP_vect  (0x08)
#define TIMER1_OVF_vect   (0x0A)
#define TIMER0_OVF_vect   (0x0C)
#define SPI_STC_vect      (0x0E)
#define UART_RX_vect      (0x10)
#define UART_UDRE_vect    (0x12)
#define UART_TX_vect      (0x14)
#define ADC_vect          (0x16)
#define EE_RDY_vect       (0x18)
#define ANA_COMP_vect     (0x1A)

#ifdef __IAR_SYSTEMS_ASM__   
#ifndef ENABLE_BIT_DEFINITIONS
#define  ENABLE_BIT_DEFINITIONS
#endif /* ENABLE_BIT_DEFINITIONS */
#endif /* __IAR_SYSTEMS_ASM__ */

#ifdef ENABLE_BIT_DEFINITIONS


/* Bit definitions for use with the IAR Assembler   
   The Register Bit names are represented by their bit number (0-7).
*/    
 
/* MCU general Status Register */    
#define    WDRF        3
#define    BORF        2
#define    EXTRF       1
#define    PORF        0
 
/* General Interrupt MaSK register */
#define    INT1        7
#define    INT0        6
 
/* General Interrupt Flag Register */
#define    INTF1       7
#define    INTF0       6                   
 
/* Timer/Counter Interrupt MaSK register */
#define    TOIE1       7
#define    OCIE1       6 
#define    TICIE1      3
#define    TOIE0       1
 
/* Timer/Counter Interrupt Flag register */
#define    TOV1         7
#define    OCF1         6
#define    ICF1         3
#define    TOV0         1
 
/* MCU general Control Register */ 
#define    SE           5
#define    SM           4
#define    ISC11        3
#define    ISC10        2
#define    ISC01        1
#define    ISC00        0
 
/* Timer/Counter 0 Control Register */
#define    CS02         2
#define    CS01         1
#define    CS00         0
 
/* Timer/Counter 1 Control Register */
#define    COM11        7
#define    COM10        6
#define    PWM11        1
#define    PWM10        0
 
/* Timer/Counter 1 Control and Status Register */
#define    ICNC1        7
#define    ICES1        6
#define    CTC1         3
#define    CS12         2
#define    CS11         1
#define    CS10         0
 
/* Watchdog Timer Control Register */                         
#define    WDTOE        4
#define    WDE          3
#define    WDP2         2
#define    WDP1         1
#define    WDP0         0    
 
/* EEPROM Control Register */
#define    EERIE        3
#define    EEMWE        2
#define    EEWE         1
#define    EERE         0
 
/* SPI Control Register */
#define    SPIE     	7	
#define    SPE     	6
#define    DORD     	5
#define    MSTR     	4
#define    CPOL     	3
#define    CPHA     	2
#define    SPR1     	1
#define    SPR0     	0

/* SPI Status Register */
#define    SPIF    	7
#define    WCOL     	6
 
/* UART Status Register */
#define    RXC      	7
#define    TXC      	6
#define    UDRE     	5
#define    FE       	4
#define    OVR       	3
#define    MPCM    	0
 
/* UART Control Register */
#define    RXCIE    	7
#define    TXCIE    	6
#define    UDRIE    	5
#define    RXEN     	4
#define    TXEN     	3
#define    CHR9     	2
#define    RXB8     	1
#define    TXB8     	0
 
/* Analog Comparator Control and Status Register */
#define    ACD      	7
#define    AINBG      	6
#define    ACO      	5
#define    ACI      	4
#define    ACIE     	3
#define    ACIC     	2
#define    ACIS1    	1
#define    ACIS0    	0

/* ADC MUX */
#define    ACDBG      	6
#define    MUX2 	2
#define    MUX1     	1
#define    MUX0     	0

/* ADC Control and Status Register */
#define    ADEN     	7
#define    ADSC     	6
#define    ADFR     	5
#define    ADIF     	4
#define    ADIE     	3
#define    ADPS2    	2
#define    ADPS1    	1
#define    ADPS0    	0  
 
/* Data Register, Port B */  
#define    PB5      5
#define    PB4      4
#define    PB3      3
#define    PB2      2
#define    PB1      1
#define    PB0      0
 
/* Data Direction Register, Port B */
#define    DDB5     5
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
 
/* Data Register, Port C */
#define    PC5      5
#define    PC4      4
#define    PC3      3
#define    PC2      2
#define    PC1      1
#define    PC0      0
 
/* Data Direction Register, Port C */
#define    DDC5     5
#define    DDC4     4
#define    DDC3     3
#define    DDC2     2
#define    DDC1     1
#define    DDC0     0
 
/* Input Pins, Port C */
#define    PINC5    5
#define    PINC4    4
#define    PINC3    3
#define    PINC2    2
#define    PINC1    1
#define    PINC0    0
 
/* Data Register, Port D */
#define    PD7      7
#define    PD6      6
#define    PD5      5
#define    PD4      4
#define    PD3      3
#define    PD2      2
#define    PD1      1
#define    PD0      0
 
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
#define    PIND7     7
#define    PIND6     6
#define    PIND5     5
#define    PIND4     4
#define    PIND3     3
#define    PIND2     2
#define    PIND1     1
#define    PIND0     0
 
/* Pointer definition   */
#define    XL     R26
#define    XH     R27
#define    YL     R28
#define    YH     R29
#define    ZL     R30
#define    ZH     R31
 
/* Contants */
#define    RAMEND   0xDF    /*Last On-Chip SRAM location*/
#define    XRAMEND  0xDF
#define    E2END    0x7F
#define    FLASHEND 0x07FF
 
#endif /* ENABLE_BIT_DEFINITIONS */
#endif /* __IO2333_H (define part) */

#pragma language=default

#endif /* __IO2333_H (SFR part) */
