/* Last 18.09.2002
   Edit 23.09.2002
   Head Key_Disp_Contr_a2x.h  for   Key_Disp_Contr_A2x.c
   Ver 0.02  */

#ifndef __MACROS_H
#define __MACROS_H      1

#ifndef BIT
#define BIT(x)  (1 << (x))
#endif

/* Set and clear bits in I/O registers can also be declared as macros */
#ifndef SetBit
#define SetBit(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#endif
#ifndef ClrBit
#define ClrBit(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#endif
/* Macro for testing of a single bit in an I/O location*/
/* Macro for testing of a single bit in an I/O location*/
#ifndef CheckBit
#define CheckBit(ADDRESS,BIT) (ADDRESS & (1<<BIT))
#endif
/* Use of bit-mask for status bits*/
/* Define bit macros, note that they are similar to the I/O macros*/
#ifndef SETBIT
#define SETBIT(x,y) (x |= (x |=(1<<y))) /* Set bit y in byte x*/
#endif
#ifndef CLEARBIT
#define CLEARBIT(x,y) (x &= (~(1<<y))) /* Clear bit y in byte x*/
#endif
#ifndef CHECKBIT
#define CHECKBIT(x,y) (x & ((1<<y))) /* Check bit y in byte x*/
#endif

#ifndef _asm
#define _asm    asm                     /* old style */

#define WDR()   asm("wdr")
#define SEI()   asm("sei")
#define CLI()   asm("cli")
#define NOP()   asm("nop")
#define _WDR()  asm("wdr")
#define _SEI()  asm("sei")
#define _CLI()  asm("cli")
#define _NOP()  asm("nop")

#endif
#endif

/* Declare for Key_Contr_A2x.c */
#define FQCK_KEY_CONTROL 3686400  // Frequencies Crystal MGh

/* Declare for Transitive Process */
#define TRANS_KEY 10

/* Display len indicator 16 pos */
#define DISP_LEN 16
#define DISP_PORT_OUT   PORTA // define PORT output PORTA bits for indicator
#define DISP_PORT_CONT  DDRA  // control register port
#define DISP_PORT_IN    PINA  // define PORT input PORTA

/* select posicion indicator */
#define DISP_POS_OUT   PORTB
#define DISP_POS_CONT  DDRB
#define DISP_POS_IN    PINB
#define DISP_POS_0      PB4   // pb0 adress posicion indicator
#define DISP_POS_1      PB5   // pb1 adress posicion indicator
#define DISP_POS_2      PB6   // pb2 adress posicion indicator
#define DISP_POS_3      PB7   // pb3 adress posicion indicator

/* KEY CONTROL 4 x 4 = 16 */
#define H_KEY 4
#define V_KEY 4
#define SEL0  PC4 // Bit output PORTC
#define SEL1  PC5 // Bit output PORTC
#define SEL2  PC6 // Bit output PORTC
#define SEL3  PC7 // Bit output PORTC
#define KEY_PORT_OUT  PORTC // define PORT output PC7-PC4 scan-code
#define KEY_PORT_CONT DDRC  // control register port
#define KEY_PORT_IN   PINC  // define PORT input PC3-PC0 scan-code

/* Buffer Scan Code Defines */
#define BUFFER_SIZE_KEY  8
#define BUFFER_SIZE_SCN0 BUFFER_SIZE_KEY /* 1,2,4,8,16,32,64,128 or 256 bytes */
#define BUFFER_MASK_SCN0 (BUFFER_SIZE_SCN0 - 1 )
#define BUFFER_SIZE_SCN1 BUFFER_SIZE_KEY /* 1,2,4,8,16,32,64,128 or 256 bytes */
#define BUFFER_MASK_SCN1 (BUFFER_SIZE_SCN1 - 1 )
#define BUFFER_SIZE_SCN2 BUFFER_SIZE_KEY /* 1,2,4,8,16,32,64,128 or 256 bytes */
#define BUFFER_MASK_SCN2 (BUFFER_SIZE_SCN2 - 1 )
#define BUFFER_SIZE_SCN3 BUFFER_SIZE_KEY /* 1,2,4,8,16,32,64,128 or 256 bytes */
#define BUFFER_MASK_SCN3 (BUFFER_SIZE_SCN3 - 1 )

/* Status KEY_CONTRL A2x */
static volatile unsigned char A21_y = 0;
static volatile unsigned char c_y1 =0;

/* Static Variables Array for calculate state key */
static volatile unsigned char SCN0[BUFFER_SIZE_SCN0];
static volatile unsigned char Head_SCN0;
static volatile unsigned char SCN1[BUFFER_SIZE_SCN1];
static volatile unsigned char Head_SCN1;
static volatile unsigned char SCN2[BUFFER_SIZE_SCN2];
static volatile unsigned char Head_SCN2;
static volatile unsigned char SCN3[BUFFER_SIZE_SCN3];
static volatile unsigned char Head_SCN3;

/* 16 KEY */
static volatile unsigned char  SUM_SCN0;  // KEY 0
static volatile unsigned char  SUM_SCN1;  // KEY 1
static volatile unsigned char  SUM_SCN2;  // KEY 2
static volatile unsigned char  SUM_SCN3;  // KEY 3
static volatile unsigned char  SUM_SCN4;  // KEY 4
static volatile unsigned char  SUM_SCN5;  // KEY 5
static volatile unsigned char  SUM_SCN6;  // KEY 6
static volatile unsigned char  SUM_SCN7;  // KEY 7
static volatile unsigned char  SUM_SCN8;  // KEY 8
static volatile unsigned char  SUM_SCN9;  // KEY 9
static volatile unsigned char  SUM_SCN10;  // KEY 10
static volatile unsigned char  SUM_SCN11;  // KEY 11
static volatile unsigned char  SUM_SCN12;  // KEY 12
static volatile unsigned char  SUM_SCN13;  // KEY 13
static volatile unsigned char  SUM_SCN14;  // KEY 14
static volatile unsigned char  SUM_SCN15;  // KEY 15

/* New status KEY Control */
static volatile unsigned char NEW_SCN0;
static volatile unsigned char NEW_SCN1;
static volatile unsigned char NEW_SCN2;
static volatile unsigned char NEW_SCN3;

/* Array return evens KEY Control */
static volatile unsigned char EVEN_M00[4]; // 0 - return calculate event M00
static volatile unsigned char EVEN_M01[4]; // 1 - return calculate event M01
static volatile unsigned char EVEN_M10[4]; // 2 - return calculate event M10
static volatile unsigned char EVEN_M11[4]; // 3 - return calculate event M11

static volatile unsigned char EVEN_M00_SUM;// Log add for all return calculate event M00
static volatile unsigned char EVEN_M01_SUM;// Log add for all return calculate event M01
static volatile unsigned char EVEN_M10_SUM;// Log add for all return calculate event M10
static volatile unsigned char EVEN_M11_SUM;// Log add for all return calculate event M11


/* Old status KEY Control */
static volatile unsigned char OLD_SCN0;
static volatile unsigned char OLD_SCN1;
static volatile unsigned char OLD_SCN2;
static volatile unsigned char OLD_SCN3;

/* Static Variables Enable/Disable for state key */
static volatile unsigned char M00[H_KEY]; // event 0->0
static volatile unsigned char M01[H_KEY]; // event 0->1
static volatile unsigned char M10[H_KEY]; // event 1->0
static volatile unsigned char M11[H_KEY]; // event 1->1

/* Variable for Timer 0 */
static volatile unsigned char mTC_0; // Period for Timer

static volatile unsigned int  iTest;
static volatile unsigned char cTest;

/* Status A2.2 Display Control */
static volatile unsigned char  A22_y;

/* Static Variables for A2.2 display control */
static volatile unsigned char DS[DISP_LEN];  // Array Symbols
static volatile unsigned char DAN[DISP_LEN]; // Code types
static volatile unsigned char DST[DISP_LEN]; // Comparate Counter
                                           // symbols interrupt TIMER 0
static volatile unsigned int  COUNT_TIME;  // Counter intterupt TIMER 0
static volatile unsigned char  DISP_POS;   // 0..15

/*------------------------------------------*/
/* Prototypes Functions for Key_Contr_A2x.c */

/*-----------------*/
/*  Reset  A2x    */
void Reset_KEY_CONTR ( void );   // Clear Arrs and Variables

/*---------------------------*/
/*  Start Timer 0 for  A2x    */
void Start_Timer0 ( void );

/*---------------------------*/
/*  Stop Timer 0 for  A2x    */
void Stop_Timer0 ( void );

/*---------------------------*/
/*  Init Timer 0 for  A2x    */
void    Init_Timer0 ( void );

/*   Eof  Key_Contr_A2x.h     */
/******************************/
