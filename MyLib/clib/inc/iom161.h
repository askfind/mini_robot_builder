/****************************************************************************
 **             - iom161.h -
 **
 **     This file declares the internal register addresses for ATmega161.
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
#if !defined(__IOM161_H) || defined(__IAR_SYSTEMS_ASM__)

#pragma language=extended

/*==========================*/
/* Predefined SFR Addresses */
/*==========================*/

SFR_B(UBRR1,  0x00) /* UART1 Baud Rate Register */
SFR_B(UCSR1B, 0x01) /* UART1 Control and Status Register */
SFR_B(UCSR1A, 0x02) /* UART1 Control and Status Register */
SFR_B(UDR1,   0x03) /* UART1 I/O Data Register */
SFR_B(PINE,   0x05) /* Input Pins, Port E */
SFR_B(DDRE,   0x06) /* Data Direction Register, Port E */
SFR_B(PORTE,  0x07) /* Data Register, Port E */
SFR_B(ACSR,   0x08) /* Analog Comparator Control and Status Register */
SFR_B(UBRR0,  0x09) /* UART0 Baud Rate Register */
SFR_B(UCSR0B, 0x0A) /* UART0 Control and Status Register */
SFR_B(UCSR0A, 0x0B) /* UART0 Control and Status Register */
SFR_B(UDR0,   0x0C) /* UART0 I/O Data Register */
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
SFR_B(PINA,   0x19) /* Input Pins, Port A */
SFR_B(DDRA,   0x1A) /* Data Direction Register, Port A */
SFR_B(PORTA,  0x1B) /* Data Register, Port A */
SFR_B(EECR,   0x1C) /* EEPROM Control Register */
SFR_B(EEDR,   0x1D) /* EEPROM Data Register */
SFR_W(EEAR,   0x1E) /* EEPROM Address Register */
SFR_B(UBRRHI, 0x20) /* UART Baud Register HIgh */
SFR_B(WDTCR,  0x21) /* Watchdog Timer Control Register */
SFR_B(OCR2,   0x22) /* Timer/Counter2 Output Compare Register */
SFR_B(TCNT2,  0x23) /* Timer/Counter2 (8-bit) */
SFR_W(ICR1,   0x24) /* Timer/Counter1 Input Capture Register */
SFR_B(ASSR,   0x26) /* Asynchronous mode StatuS Register */
SFR_B(TCCR2,  0x27) /* Timer/Counter2 Control Register */
SFR_W(OCR1B,  0x28) /* Timer/Counter1 Output Compare Register B */
SFR_W(OCR1A,  0x2A) /* Timer/Counter1 Output Compare Register A */
SFR_W(TCNT1,  0x2C) /* Timer/Counter1 */
SFR_B(TCCR1B, 0x2E) /* Timer/Counter1 Control Register B */
SFR_B(TCCR1A, 0x2F) /* Timer/Counter1 Control Register A */
SFR_B(SFIOR,  0x30) /* Special Function IO Register */
SFR_B(OCR0,   0x31) /* Timer/Counter0 Output Compare Register */
SFR_B(TCNT0,  0x32) /* Timer/Counter0 (8-bit) */
SFR_B(TCCR0,  0x33) /* Timer/Counter0 Control Register */
SFR_B(MCUSR,  0x34) /* MCU general Status Register */
SFR_B(MCUCR,  0x35) /* MCU general Control Register */
SFR_B(EMCUCR, 0x36) /* Extended MCU general Control Register */
SFR_B(SPMCR,  0x37) /* Store Program Memory Control Register */
SFR_B(TIFR,   0x38) /* Timer/Counter Interrupt Flag Register */
SFR_B(TIMSK,  0x39) /* Timer/Counter Interrupt MaSK Register */
SFR_B(GIFR,   0x3A) /* General Interrupt Flag Register */
SFR_B(GIMSK,  0x3B) /* General Interrupt MaSK register */
SFR_W(SP,     0x3D) /* Stack Pointer */
SFR_B(SREG,   0x3F) /* Status REGister */

#ifndef __IOM161_H
#define __IOM161_H

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
#define TIMER2_COMP_vect  (0x10)
#define TIMER2_OVF_vect   (0x14)
#define TIMER1_CAPT_vect  (0x18)
#define TIMER1_COMPA_vect (0x1C)
#define TIMER1_COMPB_vect (0x20)
#define TIMER1_OVF_vect   (0x24)
#define TIMER0_COMP_vect  (0x28)
#define TIMER0_OVF_vect   (0x2C)
#define SPI_STC_vect      (0x30)
#define UART0_RX_vect     (0x34)
#define UART1_RX_vect     (0x38)
#define UART0_UDRE_vect   (0x3C)
#define UART1_UDRE_vect   (0x40)
#define UART0_TX_vect     (0x44)
#define UART1_TX_vect     (0x48)
#define EE_RDY_vect       (0x4C)
#define ANA_COMP_vect     (0x50)

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
#define WDRF      3
#define BORF      2
#define EXTRF     1
#define PORF      0

/* General Interrupt MaSK register */
#define INT1      7
#define INT0      6
#define INT2      5

/* General Interrupt Flag Register */
#define INTF1     7
#define INTF0     6
#define INTF2     5

/* Timer/Counter Interrupt MaSK register */ 
#define TOIE1     7
#define OCIE1A    6
#define OCIE1B    5
#define TOIE2     4
#define TICIE1    3
#define OCIE2     2
#define TOIE0     1
#define OCIE0     0
 
/* Timer/Counter Interrupt Flag Register */
#define TOV1        7
#define OCF1A       6
#define OCF1B       5
#define TOV2        4
#define ICF1        3
#define OCF2        2
#define TOV0        1      
#define OCF0        0
 
/* MCU general Control Register */
#define SRE         7
#define SRW10       6
#define SE          5
#define SM1         4
#define ISC11       3
#define ISC10       2
#define ISC01       1
#define ISC00       0

/* Extended MCU general Control Register */
#define SM0         7
#define SRL2        6
#define SRL1        5
#define SRL0        4
#define SRW01       3
#define SRW00       2
#define SRW11       1
#define ISC2        0

/* Special Function IO Register */
#define PSR2        1
#define PSR10       0

/* Timer/Counter0 Control Register */
#define FOC0        7
#define PWM0        6
#define COM01       5
#define COM00       4
#define CTC0        3
#define CS02        2
#define CS01        1
#define CS00        0

/* Timer/Counter2 Control Register */
#define FOC2        7
#define PWM2        6
#define COM21       5
#define COM20       4
#define CTC2        3
#define CS22        2
#define CS21        1
#define CS20        0

/* Asyncronous Status Register */
#define AS2         3
#define TCN2UB      2
#define OCR2UB      1
#define TCR2UB      0

/* Timer/Counter 0 Control Register A */ 
#define COM1A1      7
#define COM1A0      6
#define COM1B1      5
#define COM1B0      4
#define FOC1A       3
#define FOC1B       2
#define PWM11       1
#define PWM10       0

/* Timer/Counter 0 Control Register B */ 
#define ICNC1       7
#define ICES1       6
#define CTC1        3
#define CS12        2
#define CS11        1
#define CS10        0

/* Watchdog Timer Control Register */ 
#define WDTOE       4
#define WDE         3
#define WDP2        2
#define WDP1        1
#define WDP0        0
  
/* EEPROM Control Register */
#define EERIE       3
#define EEMWE       2
#define EEWE        1
#define EERE        0

/* SPI Control Register */
#define SPIE        7
#define SPE         6
#define DORD        5
#define MSTR        4
#define CPOL        3
#define CPHA        2
#define SPR1        1
#define SPR0        0

/* SPI Status Register */
#define SPIF        7
#define WCOL        6
#define SPI2X       0

/* UART0 Control and Status Register A */
#define RXC0        7
#define TXC0        6
#define UDRE0       5
#define FE0         4
#define OVR0        3
#define U2X0        1
#define MPCM0       0

/* UART0 Control and Status Register B */
#define RXCIE0      7
#define TXCIE0      6
#define UDRIE0      5
#define RXEN0       4
#define TXEN0       3
#define CHR90       2
#define RXB80       1
#define TXB80       0

/* UART1 Control and Status Register A */
#define RXC1        7
#define TXC1        6
#define UDRE1       5
#define FE1         4
#define OVR1        3
#define U2X1        1
#define MPCM1       0

/* UART1 Control and Status Register B */
#define RXCIE1      7
#define TXCIE1      6
#define UDRIE1      5
#define RXEN1       4
#define TXEN1       3
#define CHR91       2
#define RXB81       1
#define TXB81       0

/* Analog Comparator Control And Status Register */
#define ACD         7
#define AINBG       6
#define ACO         5
#define ACI         4
#define ACIE        3
#define ACIC        2
#define ACIS1       1
#define ACIS0       0

/* SPM Control Register */
#define BLBSET      3
#define PGWRT       2
#define PGERS       1
#define SPMEN       0

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
#define    PE2          2
#define    PE1          1
#define    PE0          0
 
/* Data Direction Register, Port E */
#define    DDE2         2
#define    DDE1         1
#define    DDE0         0
 
/* Input Pins, Port E */
#define    PINE2        2
#define    PINE1        1
#define    PINE0        0
 
/* Pointer definition */
#define    XL       r26
#define    XH       r27
#define    YL       r28
#define    YH       r29
#define    ZL       r30
#define    ZH       r31

/* Constants */
#define    RAMEND   0x045F    /* Last On-Chip SRAM Location */
#define    XRAMEND  0xFFFF
#define    E2END    0x01FF
#define    FLASHEND 0x3FFF
 
#endif /* ENABLE_BIT_DEFINITIONS */
#endif /* __IOM161_H (define part) */

#pragma language=default

#endif /* __IOM161_H (SFR part) */
