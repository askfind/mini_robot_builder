/****************************************************************************
 **             - iom103.h -
 **
 **     This file declares the internal register addresses for ATmega103.
 **
 **     Used with iccAVR and aAVR.
 **
 **     Copyright IAR Systems 1999. All rights reserved.
 **
 **     $Name: V2_26B V2_25B V2.21H V2.21G V2_25A V2_21B $
 **
 ***************************************************************************/

#include "iomacro.h"

#if TID_GUARD(3)
#error This file should only be compiled with iccavr or aavr whith processor option -v3
#endif /* TID_GUARD(3) */

/* Include the SFR part if this file has not been included before,
 * OR this file is included by the assembler (SFRs must be defined in
 * each assembler module). */
#if !defined(__IOM103_H) || defined(__IAR_SYSTEMS_ASM__)

#pragma language=extended

/*==========================*/
/* Predefined SFR Addresses */
/*==========================*/

SFR_B(PINF,   0x00) /* Input Pins, Port F */
SFR_B(PINE,   0x01) /* Input Pins, Port E */
SFR_B(DDRE,   0x02) /* Data Direction Register, Port E */
SFR_B(PORTE,  0x03) /* Data Register, Port E */
SFR_W(ADC,    0x04) /* ADC Data register */
SFR_B(ADCSR,  0x06) /* ADC Control and Status Register */
SFR_B(ADMUX,  0x07) /* ADC MUX */
SFR_B(ACSR,   0x08) /* Analog Comparator Control and Status Register */
SFR_B(UBRR,   0x09) /* UART Baud Rate Register */
SFR_B(UCR,    0x0A) /* UART Control Register */
SFR_B(USR,    0x0B) /* UART Status Register */
SFR_B(UDR,    0x0C) /* UART I/O Data Register */
SFR_B(SPCR,   0x0D) /* SPI Control Register */
SFR_B(SPSR,   0x0E) /* SPI Status Register */
SFR_B(SPDR,   0x0F) /* SPI I/O Data Register */
SFR_B(PIND,   0x10) /* Input Pins, Port D */
SFR_B(DDRD,   0x11) /* Data Direction Register, Port D */
SFR_B(PORTD,  0x12) /* Data Register, Port D */
SFR_B(PORTC,  0x15) /* Data Register, Port C */
SFR_B(PINB,   0x16) /* Input Pins, Port B */
SFR_B(DDRB,   0x17) /* Data Direction Register, Port B */
SFR_B(PORTB,  0x18) /* Data Register, Port B */
SFR_B(PINA,   0x19) /* Input Pins, Port A */
SFR_B(DDRA,   0x1A) /* Data Direction Register, Port A */
SFR_B(PORTA,  0x1B) /* Data Register, Port A */
SFR_B(EECR,   0x1C) /* EEPROM Control Register */
SFR_B(EEDR,   0x1D) /* EEPROM Data Register */
SFR_W(EEAR,   0x1E) /* EEPROM Address Register */
SFR_B(WDTCR,  0x21) /* Watchdog Timer Control Register */
SFR_B(OCR2,   0x23) /* Timer/Counter2 Output Compare Register */
SFR_B(TCNT2,  0x24) /* Timer/Counter 2 */
SFR_B(TCCR2,  0x25) /* Timer/Counter 2 Control Register */
SFR_W(ICR1,   0x26) /* T/C 1 Input Capture Register */
SFR_W(OCR1B,  0x28) /* Timer/Counter1 Output Compare Register B */
SFR_W(OCR1A,  0x2A) /* Timer/Counter1 Output Compare Register A */
SFR_W(TCNT1,  0x2C) /* Timer/Counter 1 */
SFR_B(TCCR1B, 0x2E) /* Timer/Counter 1 Control and Status Register */
SFR_B(TCCR1A, 0x2F) /* Timer/Counter 1 Control Register */
SFR_B(ASSR,   0x30) /* Timer/Counter 0 Asynchronous Control & Status Register */
SFR_B(OCR0,   0x31) /* Output Compare Register 0 */
SFR_B(TCNT0,  0x32) /* Timer/Counter 0 */
SFR_B(TCCR0,  0x33) /* Timer/Counter 0 Control Register */
SFR_B(MCUSR,  0x34) /* MCU Status Register */
SFR_B(MCUCR,  0x35) /* MCU general Control Register */
SFR_B(TIFR,   0x36) /* Timer/Counter Interrupt Flag register */
SFR_B(TIMSK,  0x37) /* Timer/Counter Interrupt MaSK register */
SFR_B(EIFR,   0x38) /* Èxternal Interrupt Flag Register */
SFR_B(EIMSK,  0x39) /* External Interrupt MaSK register */
SFR_B(EICR,   0x3A) /* External Interrupt Control Register */
SFR_B(RAMPZ,  0x3B) /* RAM Page Z select register */
SFR_B(XDIV,   0x3C) /* XDIV Divide control register */
SFR_W(SP,     0x3D) /* Stack Pointer */
SFR_B(SREG,   0x3F) /* Status REGister */

#ifndef __IOM103_H
#define __IOM103_H

/* SFRs are local in assembler modules (so this file may need to be */
/* included in more than one module in the same source file), */
/* but #defines must only be made once per source file. */

/*==============================*/
/* Interrupt Vector Definitions */
/*==============================*/

/* NB! vectors are specified as byte addresses */
 
#define RESET_vect        (0x00)
#define INT0_vect         (0x04)
#define INT1_vect         (0x08)
#define INT2_vect         (0x0C)
#define INT3_vect         (0x10)
#define INT4_vect         (0x14)
#define INT5_vect         (0x18)
#define INT6_vect         (0x1C)
#define INT7_vect         (0x20)
#define TIMER2_COMP_vect  (0x24)
#define TIMER2_OVF_vect   (0x28)
#define TIMER1_CAPT_vect  (0x2C)
#define TIMER1_COMPA_vect (0x30)
#define TIMER1_COMPB_vect (0x34)
#define TIMER1_OVF_vect   (0x38)
#define TIMER0_COMP_vect  (0x3C)
#define TIMER0_OVF_vect   (0x40)
#define SPI_STC_vect      (0x44)
#define UART_RX_vect      (0x48)
#define UART_UDRE_vect    (0x4C)
#define UART_TX_vect      (0x50)
#define ADC_vect          (0x54)
#define EE_RDY_vect       (0x58)
#define ANA_COMP_vect     (0x5C)

#ifdef __IAR_SYSTEMS_ASM__
#ifndef ENABLE_BIT_DEFINITIONS
#define  ENABLE_BIT_DEFINITIONS
#endif /* ENABLE_BIT_DEFINITIONS */
#endif /* __IAR_SYSTEMS_ASM__ */

#ifdef ENABLE_BIT_DEFINITIONS

/* Bit definitions for use with the IAR Assembler   
   The Register Bit names are represented by their bit number (0-7).
*/                                                

/* XDIV Divide control register*/
#define    XDIVEN       7
#define    XDIV6        6
#define    XDIV5        5
#define    XDIV4        4
#define    XDIV3        3
#define    XDIV2        2
#define    XDIV1        1
#define    XDIV0        0
 
/* RAM Page Z select register */
#define     RAMPZ0      0
 
/* External Interrupt Control Register */ 
#define    ISC71        7
#define    ISC70        6
#define    ISC61        5
#define    ISC60        4
#define    ISC51        3
#define    ISC50        2
#define    ISC41        1
#define    ISC40        0
 
/* External Interrupt MaSK register */
#define    INT7         7
#define    INT6         6   
#define    INT5         5
#define    INT4         4
#define    INT3         3
#define    INT2         2
#define    INT1         1
#define    INT0         0
 
/* Èxternal Interrupt Flag Register */
#define    INTF7        7
#define    INTF6        6
#define    INTF5        5
#define    INTF4        4
 
/* Timer/Counter Interrupt MaSK register */ 
#define    OCIE2        7
#define    TOIE2        6
#define    TICIE1       5
#define    OCIE1A       4
#define    OCIE1B       3
#define    TOIE1        2
#define    OCIE0        1
#define    TOIE0        0
 
/* Timer/Counter Interrupt Flag Register */
#define    OCF2         7
#define    TOV2         6
#define    ICF1         5
#define    OCF1A        4
#define    OCF1B        3
#define    TOV1         2
#define    OCF0         1
#define    TOV0         0      
 
/* MCU general Control Register */
#define    SRE          7
#define    SRW          6
#define    SE           5
#define    SM1          4
#define    SM0          3
 
/* MCU Status Register */ 
#define    EXTRF        1
#define    PORF         0
 
/* Timer/Counter 0 Control Register */
#define    PWM0         6
#define    COM01        5
#define    COM00        4
#define    CTC0         3
#define    CS02         2
#define    CS01         1
#define    CS00         0
 
/* Timer/Counter 0 Asynchronous Control & Status Register */ 
#define    AS0          3
#define    TCN0UB       2
#define    OCR0UB       1
#define    TCR0UB       0 
 
/* Timer/Counter 1 Control Register */ 
#define    COM1A1       7
#define    COM1A0       6
#define    COM1B1       5
#define    COM1B0       4
#define    PWM11        1
#define    PWM10        0
 
/* Timer/Counter 1 Control and Status Register */
#define    ICNC1        7
#define    ICES1        6
#define    CTC1         3
#define    CS12         2
#define    CS11         1
#define    CS10         0
 
/* Timer/Counter 2 Control register */ 
#define    PWM2         6
#define    COM21        5
#define    COM20        4
#define    CTC2         3
#define    CS22         2
#define    CS21         1
#define    CS20         0
 
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
 
/* Data Register, Port A */
#define    PA7          7
#define    PA6          6
#define    PA5          5
#define    PA4          4
#define    PA3          3
#define    PA2          2
#define    PA1          1
#define    PA0          0
 
/* Data Direction Register, Port A */ 
#define    DDA7         7
#define    DDA6         6
#define    DDA5         5
#define    DDA4         4
#define    DDA3         3
#define    DDA2         2
#define    DDA1         1
#define    DDA0         0
   
/* Input Pins, Port A */ 
#define    PINA7        7
#define    PINA6        6
#define    PINA5        5
#define    PINA4        4
#define    PINA3        3
#define    PINA2        2
#define    PINA1        1
#define    PINA0        0
 
/* Data Register, Port B */ 
#define    PB7          7
#define    PB6          6
#define    PB5          5
#define    PB4          4
#define    PB3          3
#define    PB2          2
#define    PB1          1
#define    PB0          0
 
/* Data Direction Register, Port B */
#define    DDB7         7
#define    DDB6         6
#define    DDB5         5
#define    DDB4         4
#define    DDB3         3
#define    DDB2         2
#define    DDB1         1
#define    DDB0         0
                      
/* Input Pins, Port B */
#define    PINB7        7
#define    PINB6        6
#define    PINB5        5
#define    PINB4        4
#define    PINB3        3
#define    PINB2        2
#define    PINB1        1
#define    PINB0        0
 
/* Data Register, Port C */
#define    PC7          7
#define    PC6          6
#define    PC5          5
#define    PC4          4
#define    PC3          3
#define    PC2          2
#define    PC1          1
#define    PC0          0
 
/* Data Register, Port D */
#define    PD7          7
#define    PD6          6
#define    PD5          5
#define    PD4          4
#define    PD3          3
#define    PD2          2
#define    PD1          1
#define    PD0          0
                                          
/* Data Direction Register, Port D */
#define    DDD7         7
#define    DDD6         6
#define    DDD5         5
#define    DDD4         4
#define    DDD3         3
#define    DDD2         2
#define    DDD1         1
#define    DDD0         0
 
/* Input Pins, Port D */
#define    PIND7        7
#define    PIND6        6
#define    PIND5        5
#define    PIND4        4
#define    PIND3        3
#define    PIND2        2
#define    PIND1        1
#define    PIND0        0
 
/* Data Register, Port E */
#define    PE7          7
#define    PE6          6
#define    PE5          5
#define    PE4          4
#define    PE3          3
#define    PE2          2
#define    PE1          1
#define    PE0          0
 
/* Data Direction Register, Port E */
#define    DDE7         7
#define    DDE6         6
#define    DDE5         5
#define    DDE4         4
#define    DDE3         3
#define    DDE2         2
#define    DDE1         1
#define    DDE0         0
 
/* Input Pins, Port E */
#define    PINE7        7
#define    PINE6        6
#define    PINE5        5
#define    PINE4        4
#define    PINE3        3
#define    PINE2        2
#define    PINE1        1
#define    PINE0        0
 
/* Input Pins, Port F */
#define    PINF7        7
#define    PINF6        6
#define    PINF5        5
#define    PINF4        4
#define    PINF3        3
#define    PINF2        2
#define    PINF1        1
#define    PINF0        0
 
/* SPI Status Register */ 
#define    SPIF         7
#define    WCOL         6
 
/* SPI Control Register */
#define    SPIE         7
#define    SPE          6
#define    DORD         5
#define    MSTR         4
#define    CPOL         3
#define    CPHA         2
#define    SPR1         1
#define    SPR0         0
  
/* UART Status Register */
#define    RXC          7
#define    TXC          6
#define    UDRE         5
#define    FE           4
#define    OVR          3
 
/* UART Control Register */
#define    RXCIE        7
#define    TXCIE        6
#define    UDRIE        5
#define    RXEN         4
#define    TXEN         3
#define    CHR9         2
#define    RXB8         1
#define    TXB8         0
 
/* Analog Comparator Control and Status Register */
#define    ACD          7
#define    ACO          5
#define    ACI          4
#define    ACIE         3
#define    ACIC         2
#define    ACIS1        1
#define    ACIS0        0
 
/* ADC Control and status register */
#define    ADEN         7
#define    ADSC         6
#define    ADFR         5
#define    ADIF         4
#define    ADIE         3
#define    ADPS2        2
#define    ADPS1        1
#define    ADPS0        0
 
/* ADC Multiplexer select */
#define    MUX2         2
#define    MUX1         1
#define    MUX0         0
 
/* Pointer definition */
#define    XL       r26
#define    XH       r27
#define    YL       r28
#define    YH       r29
#define    ZL       r30
#define    ZH       r31

/* Constants */
#define    RAMEND   0x0FFF    /* Last On-Chip SRAM Location */
#define    XRAMEND  0xFFFF
#define    E2END    0x0FFF
#define    FLASHEND 0x1FFFF
 
#endif /* ENABLE_BIT_DEFINITIONS */
#endif /* __IOM103_H (define part) */

#pragma language=default

#endif /* __IOM103_H (SFR part) */
