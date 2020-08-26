/****************************************************************************
 **             - ioat94k.h -
 **
 **     This file declares the internal register addresses for AT94k.
 **
 **     Used with iccAVR and aAVR.
 **
 **     Copyright IAR Systems 2000. All rights reserved.
 **
 **     $Name: V2_26B V2_25B $
 **
 ***************************************************************************/

#include "iomacro.h"

#if TID_GUARD(3)
#error This file should only be compiled with iccavr or aavr whith processor option -v3
#endif /* TID_GUARD(3) */

/* Include the SFR part if this file has not been included before,
 * OR this file is included by the assembler (SFRs must be defined in
 * each assembler module). */
#if !defined(__IOAT94K_H) || defined(__IAR_SYSTEMS_ASM__)

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
SFR_B(UBRR0,  0x09) /* UART0 Baud Rate Register */
SFR_B(UCSR0B, 0x0A) /* UART0 Control and Status Register */
SFR_B(UCSR0A, 0x0B) /* UART0 Control and Status Register */
SFR_B(UDR0,   0x0C) /* UART0 I/O Data Register */
SFR_B(PIND,   0x10) /* Input Pins, Port D */
SFR_B(DDRD,   0x11) /* Data Direction Register, Port D */
SFR_B(PORTD,  0x12) /* Data Register, Port D */
SFR_B(FISCR,  0x13) /* FPGA I/O Select Control Register */
SFR_B(FISUA,  0x14) /* I/O Select, Interrupt Mask/Flag Register A */
SFR_B(FISUB,  0x15) /* I/O Select, Interrupt Mask/Flag Register B */
SFR_B(FISUC,  0x16) /* I/O Select, Interrupt Mask/Flag Register C */
SFR_B(FISUD,  0x17) /* I/O Select, Interrupt Mask/Flag Register D */
SFR_B(FPGAX,  0x18) /* FPGA Cache X Address Register */
SFR_B(FPGAY,  0x19) /* FPGA Cache Y Address Register */
SFR_B(FPGAZ,  0x1A) /* FPGA Cache Z Address Register */
SFR_B(FPGAD,  0x1B) /* FPGA Cache Data Register */
SFR_B(TWBR,   0x1C) /* 2-Wire Serial Bit rate Register */
SFR_B(TWSR,   0x1D) /* 2-Wire Serial Status Register */
SFR_B(TWAR,   0x1E) /* 2-Wire Serial Address Register */
SFR_B(TWDR,   0x1F) /* 2-Wire Serial Data Register */
SFR_B(UBRRHI, 0x20) /* UART Baud Register HIgh */
SFR_B(WDTCR,  0x21) /* Watchdog Timer Control Register */
SFR_B(OCR2,   0x22) /* Timer/Counter2 Output Compare Register */
SFR_B(TCNT2,  0x23) /* Timer/Counter2 (8-bit) */
SFR_W(ICR1,   0x24) /* Timer/Counter1 Input Capture Register */
SFR_B(ASSR,   0x26) /* Asynchronous mode StatuS Register */
SFR_B(TCCR2,  0x27) /* Timer/Counter 2 Control Register */
SFR_W(OCR1B,  0x28) /* Timer/Counter1 Output Compare Register */
SFR_W(OCR1A,  0x2A) /* Timer/Counter1 Output Compare Register */
SFR_W(TCNT1,  0x2C) /* Timer/Counter 1 */
SFR_B(TCCR1B, 0x2E) /* Timer/Counter 1 Control and Status Register */
SFR_B(TCCR1A, 0x2F) /* Timer/Counter 1 Control Register */
SFR_B(SFIOR,  0x30) /* Special Function IO Register */
SFR_B(OCR0,   0x31) /* Output Compare Register 0 */
SFR_B(TCNT0,  0x32) /* Timer/Counter 0 */
SFR_B(TCCR0,  0x33) /* Timer/Counter 0 Control Register */
SFR_B(MCUR,   0x35) /* MCU Control/Status Register */
SFR_B(TWCR,   0x36) /* 2-Wire Serial Control Register */
SFR_B(TIFR,   0x38) /* Timer/Counter Interrupt Flag register */
SFR_B(TIMSK,  0x39) /* Timer/Counter Interrupt MaSK register */
SFR_B(SFTCR,  0x3A) /* Software Control Register */
SFR_B(EIMF,   0x3B) /* External Interrupt Mask and Flag register */
SFR_W(SP,     0x3D) /* Stack Pointer */
SFR_B(SREG,   0x3F) /* Status REGister */

#ifndef __IOAT94K_H
#define __IOAT94K_H

/* SFRs are local in assembler modules (so this file may need to be */
/* included in more than one module in the same source file), */
/* but #defines must only be made once per source file. */

/*==============================*/
/* Interrupt Vector Definitions */
/*==============================*/

/* NB! vectors are specified as byte addresses */

#define    RESET_vect          (0x00)
#define    FPGA_INT0           (0x04)
#define    EXT_INT0            (0x08)
#define    FPGA_INT1           (0x0C)
#define    EXT_INT1            (0x10)
#define    FPGA_INT2           (0x14)
#define    EXT_INT2            (0x18)
#define    FPGA_INT3           (0x1C)
#define    EXT_INT3            (0x20)
#define    TIM2_COMP           (0x24)
#define    TIM2_OVF            (0x28)
#define    TIM1_CAPT           (0x2C)
#define    TIM1_COMPA          (0x30)
#define    TIM1_COMPB          (0x34)
#define    TIM1_OVF            (0x38)
#define    TIM0_COMP           (0x3C)
#define    TIM0_OVF            (0x40)
#define    FPGA_INT4           (0x44)
#define    FPGA_INT5           (0x48)
#define    FPGA_INT6           (0x4C)
#define    FPGA_INT7           (0x50)
#define    UART0_RXC           (0x54)
#define    UART0_DRE           (0x58)
#define    UART0_TXC           (0x5C)
#define    FPGA_INT8           (0x60)
#define    FPGA_INT9           (0x64)
#define    FPGA_INT10          (0x68)
#define    FPGA_INT11          (0x6C)
#define    UART1_RXC           (0x70)
#define    UART1_DRE           (0x74)
#define    UART1_TXC           (0x78)
#define    FPGA_INT12          (0x7C)
#define    FPGA_INT13          (0x80)
#define    FPGA_INT14          (0x84)
#define    FPGA_INT15          (0x88)
#define    TWS_INT             (0x8C)

#ifdef __IAR_SYSTEMS_ASM__
#ifndef ENABLE_BIT_DEFINITIONS
#define  ENABLE_BIT_DEFINITIONS
#endif /* ENABLE_BIT_DEFINITIONS */
#endif /* __IAR_SYSTEMS_ASM__ */

#ifdef ENABLE_BIT_DEFINITIONS

/* Bit definitions for use with the IAR Assembler
   The Register Bit names are represented by their bit number (0-7).
*/

/* EIMF */
#define    INTF3        7
#define    INTF2        6
#define    INTF1        5
#define    INTF0        4
#define    INT3         3
#define    INT2         2
#define    INT1         1
#define    INT0         0

/* SDCTR */
#define    FMXOR        3
#define    WDTS         2
#define    DBG          1
#define    SRST         0

/* Timer/Counter Interrupt MaSK register */
#define    TOIE1        7
#define    OCIE1A       6
#define    OCIE1B       5
#define    TOIE2        4
#define    TICIE1       3
#define    OCIE2        2
#define    TOIE0        1
#define    OCIE0        0

/* Timer/Counter Interrupt Flag Register */
#define    TOV1         7
#define    OCF1A        6
#define    OCF1B        5
#define    OCFTW        4
#define    TOV2         3
#define    ICF1         2
#define    TOV0         1
#define    OCIF0        0

/* TWCR */
#define    TWINT       7
#define    TWEA        6
#define    TWSTA       5
#define    TWSTO       4
#define    TWWC        3
#define    TWEN        2
#define    TWIE        0

/* MCU Control/Status Register */
#define    SE             5
#define    SM1            4
#define    SM0            3
#define    PORF           2
#define    WDRF           1
#define    EXTRF          0

/* Timer/Counter 0 Control Register */
#define    FOC0         7
#define    PWM0         6
#define    COM01        5
#define    COM00        4
#define    CTC0         3
#define    CS02         2
#define    CS01         1
#define    CS00         0

/* SIFOR */
#define    PSR2         1
#define    PSR10        0

/* Timer/Counter 1 Control Register */
#define    COM1A1       7
#define    COM1A0       6
#define    COM1B1       5
#define    COM1B0       4
#define    FOC1A        3
#define    FOC1B        2
#define    PWM11        1
#define    PWM10        0

/* Timer/Counter 1 Control and Status Register */
#define    ICNC1        7
#define    ICES1        6
#define    ICPE         5
#define    CTC1         3
#define    CS12         2
#define    CS11         1
#define    CS10         0

/* Timer/Counter 2 Control register */
#define    FOC2         7
#define    PWM2         6
#define    COM21        5
#define    COM20        4
#define    CTC2         3
#define    CS22         2
#define    CS21         1
#define    CS20         0

/* Timer/Counter 2 Asynchronous Control & Status Register */
#define    AS20         3
#define    TCN2UB       2
#define    OCR2UB       1
#define    TCR2UB       0

/* Watchdog Timer Control Register */
#define    WDTOE        4
#define    WDE          3
#define    WDP2         2
#define    WDP1         1
#define    WDP0         0

/* FISCR */
#define    FIADR        7
#define    XFIS1        1
#define    XFIS0        0

/* FISUD ... FISUA */
#define    FIF0         4
#define    FIF1         5
#define    FIF2         6
#define    FIF3         7
#define    FIF4         4
#define    FIF5         5
#define    FIF6         6
#define    FIF7         7
#define    FIF8         4
#define    FIF9         5
#define    FIF10        6
#define    FIF11        7
#define    FIF12        4
#define    FIF13        5
#define    FIF14        6
#define    FIF15        7

#define    FINT0        0
#define    FINT1        1
#define    FINT2        2
#define    FINT3        3
#define    FINT4        0
#define    FINT5        1
#define    FINT6        2
#define    FINT7        3
#define    FINT8        0
#define    FINT9        1
#define    FINT10       2
#define    FINT11       3
#define    FINT12       0
#define    FINT13       1
#define    FINT14       2
#define    FINT15       3

/* Data Register, Port D */
#define    PD7          7
#define    PD6          6
#define    PD5          5
#define    PD4          4
#define    PD3          3
#define    PD2          2
#define    PD1          1
#define    PD0          0

/* Data Register, Port D */
#define    PORTD7       7
#define    PORTD6       6
#define    PORTD5       5
#define    PORTD4       4
#define    PORTD3       3
#define    PORTD2       2
#define    PORTD1       1
#define    PORTD0       0

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

/* Data Register, Port E */
#define    PORTE7       7
#define    PORTE6       6
#define    PORTE5       5
#define    PORTE4       4
#define    PORTE3       3
#define    PORTE2       2
#define    PORTE1       1
#define    PORTE0       0

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

/* UART 0 Status Register */
#define    RXC0          7
#define    TXC0          6
#define    UDRE0         5
#define    FE0           4
#define    OVR0          3

/* UART 0 Control Register */
#define    RXCIE0        7
#define    TXCIE0        6
#define    UDRIE0        5
#define    RXEN0         4
#define    TXEN0         3
#define    CHR90         2
#define    RXB80         1
#define    TXB80         0

/* UART 1 Status Register */
#define    RXC1          7
#define    TXC1          6
#define    UDRE1         5
#define    FE1           4
#define    OVR1          3

/* UART 1 Control Register */
#define    RXCIE1        7
#define    TXCIE1        6
#define    UDRIE1        5
#define    RXEN1         4
#define    TXEN1         3
#define    CHR91         2
#define    RXB81         1
#define    TXB81         0

/* Pointer definition */
#define    XL       r26
#define    XH       r27
#define    YL       r28
#define    YH       r29
#define    ZL       r30
#define    ZH       r31

/* Constants */
#define    RAMEND   0x3FFF    /* Last On-Chip SRAM Location */
#define    XRAMEND  0x3FFF
#define    E2END    0x0000
#define    FLASHEND 0x7FFF

#endif /* ENABLE_BIT_DEFINITIONS */
#endif /* __IOAT94K_H (define part) */

#pragma language=default

#endif /* __IOAT94K_H (SFR part) */
