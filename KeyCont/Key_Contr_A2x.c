/*********************************************
* Programm:       Key_Disp_Contr_A2x.c       *
*                                            *
*  Note:  For projekt MINIROBIT BUILDING     *
*                                            *
* Name:  Module Code adapted from Atmel AVR  *
*        Application for Amega161            *
*        KEY CONTROLS Driver                 *
*        DISPLAY CONTROLS Driver                                    *
* Edit data:     17.09.2002                  *
* Last data:     01.10.2002                  *
* Version:       0.02                        *
**********************************************/

#include "iom161.h"
#include "key_contr_A2x.h"
#include "Code_ASCII_A2x.h"
#include "stdio.h"
#include "ctype.h"
#include "c:\AVR_CC\UART_MOD\uart0_A1x_ext_func.h"
#include "c:\AVR_CC\Functions\scan_cmd.h"


/* Debug test KEY_CONTR for module */
#define TEST_KEY_CONTR

/*--------------------------*/
/*  Reset  DISP_CONTR_A2.2  */
void Reset_DISP_CONTR ( void ) // Clear Arrs and Variables
    {
    volatile unsigned char cTmp;
    volatile int i;
   /* Status DISP_CONTRL y=0 Reset */
    A22_y = 0;
   /* Erase Array and Variabke */
   for (i=0;i<=DISP_LEN-1;i++)
      {
      DS[i] = '1';             // Erase Arr
      DAN[i] = 0xA0;        // ( Test A0= No Animation) Erase Arr
      DST[i] = 5;              // Erase Arr
      };

    COUNT_TIME = 0;
    DISP_POS = 0;
    /* Port Disp OUTPUT */
    DISP_PORT_CONT = 0xff;  // All bits Port DISP output
    /* y0 -> y1 */
    A22_y = 1;           // New Status A2.2 Enable display indicator
  }

/*  END Reset  DISP_CONTR_A2.2  */
/*------------------------------*/

/*----------------------------------------------*/
/*  Write Symbol to Indicator  DISP_CONTR_A2.2  */
void Wr_Sym_Disp ( char id_pos ) // Clear Arrs and Variables
{
  unsigned char cTmp;
  unsigned char cBits;
  unsigned char cFl;

  /* 1. Off Led Indicator */
  DISP_PORT_CONT = 0xff;  // All bits Port DISP output
  DISP_PORT_OUT = (DISP_PORT_OUT | 0xff);    // Off Indicator Posicion
  /* 2. New Posicion Indicator */
   DISP_POS = (id_pos + 1);   // New posicion indndicator
   if ( DISP_POS > DISP_LEN-1)    // if posicion > size buffer indicator
   {
   DISP_POS = 0;
   };
  /* 3. Calculate animacion Symbols */

    /* 3.1 Test Bits High  0=symbol ASCII or 1=Field Bits */
    cTmp = (DAN[DISP_POS] & ~(0x1F) ) >> 7 ;
    switch (cTmp)
    {
    case 0:   // Code symbols to bits
    cBits = CodeASCII[ DS[DISP_POS] & 0x7f ];  // Bits To Output PORT DISPLAY
    break;
    default: //  Code = Bits output
    cBits = DS[DISP_POS]; // Bits To Output PORT DISPLAY
    break;
    };

    /* 3.2 Test Bits b6,b5  Type Animacion */
    cTmp = (DAN[DISP_POS] &  ~(0x1F) ) >> 5 ;
    cTmp = cTmp & ~(0x4); // Clr bits
    switch (cTmp)
    {
    case 0:   // Indicator OFF
    cBits = 0xFF;
    break;
    case 2:  // Indicator ON-OFF if 0 < DST[...] < COUNT_TIME
      cFl = (COUNT_TIME / 100 / DST[DISP_POS]+0.5); //
      if ( (cFl & 0x01) == 0 )
        {
        cBits = cBits; // Indicator ON
        }
        else
        {
        cBits = 0xFF; // Indicator OFF
        };
    break;
    default:
    cBits = cBits; // Indicator ON
    break;
    };
/* 4. Write Fields Bits to Port Indicator */
  /* 4.1 Write Fields Bits to Port Indicator */
  SetBit( DISP_POS_CONT, DISP_POS_0); // Mode Bit port disp output
  SetBit( DISP_POS_CONT, DISP_POS_1); // Mode Bit port disp output
  SetBit( DISP_POS_CONT, DISP_POS_2); // Mode Bit port disp output
  SetBit( DISP_POS_CONT, DISP_POS_3); // Mode Bit port disp output
    if ( (DISP_POS & 0x01) == 0)  // test p0
    {
    ClrBit(DISP_POS_OUT, DISP_POS_0);
    }
    else
    {
    SetBit(DISP_POS_OUT, DISP_POS_0);
    };
    if ( (DISP_POS & 0x02) == 0)  // test p1
    {
    ClrBit(DISP_POS_OUT, DISP_POS_1);
    }
    else
    {
    SetBit(DISP_POS_OUT, DISP_POS_1);
    };
    if ( (DISP_POS & 0x04) == 0) // test p2
    {
    ClrBit(DISP_POS_OUT, DISP_POS_2);
    }
    else
    {
    SetBit(DISP_POS_OUT, DISP_POS_2);
    };
    if ( (DISP_POS & 0x08) == 0)  // test p3
    {
    ClrBit(DISP_POS_OUT, DISP_POS_3);
    }
    else
    {
    SetBit(DISP_POS_OUT, DISP_POS_3);
    };
   /* 4.2 Write Fields Bits to Port Indicator */
   DISP_PORT_CONT = 0xff;  // All bits Port DISP output
   DISP_PORT_OUT = cBits;   // Output Indicator Posicion

}
/*  END Reset  DISP_CONTR_A2.2  */
/*------------------------------*/


/*--------------------------*/
/*  Reset  KEY_CONTR_A2.1   */
void Reset_KEY_CONTR ( void ) // Clear Arrs and Variables
     {
    volatile unsigned char cTmp;
    volatile int i;

   /* Status KEY_CONTRL y=0 Reset */
    A21_y = 0;

   /* Erase Array and Variabke */

    for (i=0;i<=BUFFER_SIZE_SCN0-1;i++)
      {
      SCN0[i] = 0 ;         // Erase Arr
      SCN1[i] = 0 ;         // Erase Arr
      SCN2[i] = 0 ;         // Erase Arr
      SCN3[i] = 0 ;         // Erase Arr
       };

    Head_SCN0 = 0;
    Head_SCN1 = 0;
    Head_SCN2 = 0;
    Head_SCN3 = 0;

    SUM_SCN0 = 0;
    SUM_SCN1 = 0;
    SUM_SCN2 = 0;
    SUM_SCN3 = 0;
    SUM_SCN4 = 0;
    SUM_SCN5 = 0;
    SUM_SCN6 = 0;
    SUM_SCN7 = 0;
    SUM_SCN8 = 0;
    SUM_SCN9 = 0;
    SUM_SCN10 = 0;
    SUM_SCN11 = 0;
    SUM_SCN12 = 0;
    SUM_SCN13 = 0;
    SUM_SCN14 = 0;
    SUM_SCN15 = 0;

    NEW_SCN0 = 0;
    NEW_SCN1 = 0;
    NEW_SCN2 = 0;
    NEW_SCN3 = 0;

    OLD_SCN0 = 0;
    OLD_SCN1 = 0;
    OLD_SCN2 = 0;
    OLD_SCN3 = 0;


    for (i=0;i<=H_KEY-1;i++)
      {
      M00[i] = 1 ;         // Disable All event Scan Code
      M01[i] = 1 ;         // Enable  All event Scan Code
      M10[i] = 1 ;         // Enable  All event Scan Code
      M11[i] = 1 ;         // Disable All event Scan Code
       };
    A21_y = 1;    // New status A2x
    c_y1 = 0;     // Variable for transitive process
                  // for input status KEY
     }
/*  END Reset  KEY_CONTR_A2.1   */
/*------------------------------*/


/*---------------------------*/
/*  Start Timer 0 for  A2x    */
void Start_Timer0 ( void )
     {
     SetBit(TIMSK,TOIE0);     // enable Overflow interrupt
     TCCR0 = TCCR0 | 0x03;    // CK/64
     /*  Set mTC_0 */
     mTC_0 = 0x8D;            // 1 mc for ZQ=7,3728 MGh
     /* Set period Timer0 */
     TCNT0 = mTC_0;   // Set counter Timer0
     }

/*---------------------------*/
/*  Stop Timer 0 for  A2x    */
void Stop_Timer0 ( void )
     {
     ClrBit(TIMSK,TOIE0);     // disable Overflow interrupt
     TCCR0 = TCCR0 & ~(0x07); // Stop Timer0
     }

/*---------------------------*/
/*  Init Timer 0 for  A2x    */
void Init_Timer0 ( void )
     {
     /* Disable interrupt */
     Stop_Timer0();           // Stop

     SetBit(SFIOR,PSR10);     // Reset Prescaler for Timer 0 and 1
     ClrBit(SFIOR,PSR10);

     /* Set Mode Timer0 */
     ClrBit(TCCR0,COM00);     // disconnectedfrom output pin OC0
     ClrBit(TCCR0,COM01);     //
     ClrBit(TCCR0,FOC0);      // No Compare
     ClrBit(TCCR0,PWM0);      // No pulse modulator
     ClrBit(TCCR0,CTC0);      // Clear
     /* Enable intrrupt and start Timer0 */
     }

/*---------------------------*/
/*  Calculate status KEY     */
void Cal_Key_Contr ( void )
  {
    volatile unsigned char i;
    unsigned char scan;

  /*************************/
  /*  Output puls bit SEL0 */
   SetBit(KEY_PORT_CONT,SEL0); // Bit port to output
   SetBit(KEY_PORT_OUT, SEL0);     // Output "1" SEL0
   for (i=0;i<50;i++)
    {
     ClrBit(KEY_PORT_OUT, SEL0);     // Output "0" SEL0
    };
   SetBit(KEY_PORT_OUT, SEL0);     // Output "1" SEL0
  /* 2. Input scan-code for SEL0 */
   KEY_PORT_CONT = KEY_PORT_CONT & ~( 8+4+2+1); // PORT input
   scan = KEY_PORT_IN & 0x0F; // scan port SEL0
  /* 3. Calcumate mediam */
  SUM_SCN0 = SUM_SCN0 - (SCN0[Head_SCN0]& 0x01 );
  SUM_SCN0 = SUM_SCN0 + (scan & 0x01);
  SUM_SCN1 = SUM_SCN1 - ((SCN0[Head_SCN0]& 0x02)>>1);
  SUM_SCN1 = SUM_SCN1 + ((scan & 0x02)>>1);
  SUM_SCN2 = SUM_SCN2 - ((SCN0[Head_SCN0]& 0x04)>>2);
  SUM_SCN2 = SUM_SCN2 + ((scan & 0x04)>>2);
  SUM_SCN3 = SUM_SCN3 - ((SCN0[Head_SCN0] & 0x08)>>3);
  SUM_SCN3 = SUM_SCN3 + ((scan & 0x08)>>3);


  SCN0[Head_SCN0] = scan;

  Head_SCN0 = (Head_SCN0+1) & BUFFER_MASK_SCN0;

  OLD_SCN0 = NEW_SCN0;
  NEW_SCN0 = 0;
  i = (unsigned char)( SUM_SCN0 / BUFFER_SIZE_KEY);
  NEW_SCN0 = NEW_SCN0 | i;
  i = (unsigned char)( SUM_SCN1 / BUFFER_SIZE_KEY );
  NEW_SCN0 = NEW_SCN0 | (i<<1);
  i = (unsigned char)( SUM_SCN2 / BUFFER_SIZE_KEY);
  NEW_SCN0 = NEW_SCN0 | (i<<2);
  i = (unsigned char)( SUM_SCN3 / BUFFER_SIZE_KEY );
  NEW_SCN0 = NEW_SCN0 | (i<<3);

  /***************************/
  /* Output puls bit SEL1 */
  SetBit(KEY_PORT_CONT,SEL1); // Bit port to output
   SetBit(KEY_PORT_OUT, SEL1);     // Output "1" SEL1
   for (i=0;i<50;i++)
    {
     ClrBit(KEY_PORT_OUT, SEL1);     // Output "0" SEL1
    };
   SetBit(KEY_PORT_OUT, SEL1);     // Output "1" SEL1
  /*  Input scan-code for SEL1 */
   KEY_PORT_CONT = KEY_PORT_CONT & ~( 8+4+2+1); // PORT input
   scan = KEY_PORT_IN & 0x0F; // scan port SEL1
  /*  Calcumate mediam */
  SUM_SCN4 = SUM_SCN4 - (SCN1[Head_SCN1]& 0x01 );
  SUM_SCN4 = SUM_SCN4 + (scan & 0x01);
  SUM_SCN5 = SUM_SCN5 - ((SCN1[Head_SCN1]& 0x02)>>1);
  SUM_SCN5 = SUM_SCN5 + ((scan & 0x02)>>1);
  SUM_SCN6 = SUM_SCN6 - ((SCN1[Head_SCN1]& 0x04)>>2);
  SUM_SCN6 = SUM_SCN6 + ((scan & 0x04)>>2);
  SUM_SCN7 = SUM_SCN7 - ((SCN1[Head_SCN1] & 0x08)>>3);
  SUM_SCN7 = SUM_SCN7 + ((scan & 0x08)>>3);

  SCN1[Head_SCN1] = scan;

  Head_SCN1 = (Head_SCN1+1) & BUFFER_MASK_SCN1;

  OLD_SCN1 = NEW_SCN1;
  NEW_SCN1 = 0;
  i = (unsigned char)( SUM_SCN4 / BUFFER_SIZE_KEY);
  NEW_SCN1 = NEW_SCN1 | i;
  i = (unsigned char)( SUM_SCN5 / BUFFER_SIZE_KEY );
  NEW_SCN1 = NEW_SCN1 | (i<<1);
  i = (unsigned char)( SUM_SCN6 / BUFFER_SIZE_KEY);
  NEW_SCN1 = NEW_SCN1 | (i<<2);
  i = (unsigned char)( SUM_SCN7 / BUFFER_SIZE_KEY );
  NEW_SCN1 = NEW_SCN1 | (i<<3);

  /************************/
  /* Output puls bit SEL2 */
   SetBit(KEY_PORT_CONT,SEL2); // Bit port to output
   SetBit(KEY_PORT_OUT, SEL2);     // Output "1" SEL2
   for (i=0;i<50;i++)
    {
     ClrBit(KEY_PORT_OUT, SEL2);     // Output "0" SEL2
    };
   SetBit(KEY_PORT_OUT, SEL2);     // Output "1" SEL2
  /* 2. Input scan-code for SEL2 */
   KEY_PORT_CONT = KEY_PORT_CONT & ~( 8+4+2+1); // PORT input
   scan = KEY_PORT_IN & 0x0F; // scan port SEL2
  /* 3. Calcumate mediam */
  SUM_SCN8 = SUM_SCN8 - (SCN2[Head_SCN2]& 0x01 );
  SUM_SCN8 = SUM_SCN8 + (scan & 0x01);
  SUM_SCN9 = SUM_SCN9 - ((SCN2[Head_SCN2]& 0x02)>>1);
  SUM_SCN9 = SUM_SCN9 + ((scan & 0x02)>>1);
  SUM_SCN10 = SUM_SCN10 - ((SCN2[Head_SCN2]& 0x04)>>2);
  SUM_SCN10 = SUM_SCN10 + ((scan & 0x04)>>2);
  SUM_SCN11 = SUM_SCN11 - ((SCN2[Head_SCN2] & 0x08)>>3);
  SUM_SCN11 = SUM_SCN11+ ((scan & 0x08)>>3);


  SCN2[Head_SCN2] = scan;

  Head_SCN2 = (Head_SCN2+1) & BUFFER_MASK_SCN0;

  OLD_SCN2 = NEW_SCN2;
  NEW_SCN2 = 0;
  i = (unsigned char)( SUM_SCN8 / BUFFER_SIZE_KEY);
  NEW_SCN2 = NEW_SCN2 | i;
  i = (unsigned char)( SUM_SCN9 / BUFFER_SIZE_KEY );
  NEW_SCN2 = NEW_SCN2 | (i<<1);
  i = (unsigned char)( SUM_SCN10 / BUFFER_SIZE_KEY);
  NEW_SCN2 = NEW_SCN2 | (i<<2);
  i = (unsigned char)( SUM_SCN11 / BUFFER_SIZE_KEY );
  NEW_SCN2 = NEW_SCN2 | (i<<3);

  /*************************/
  /*  Output puls bit SEL3 */
   SetBit(KEY_PORT_CONT,SEL3); // Bit port to output
   SetBit(KEY_PORT_OUT, SEL3);     // Output "1" SEL3
   for (i=0;i<50;i++)
    {
     ClrBit(KEY_PORT_OUT, SEL3);     // Output "0" SEL3
    };
   SetBit(KEY_PORT_OUT, SEL3);     // Output "1" SEL3
  /* 2. Input scan-code for SEL0 */
   KEY_PORT_CONT = KEY_PORT_CONT & ~( 8+4+2+1); // PORT input
   scan = KEY_PORT_IN & 0x0F; // scan port SEL3
  /* 3. Calcumate mediam */
  SUM_SCN12 = SUM_SCN12 - (SCN3[Head_SCN3]& 0x01 );
  SUM_SCN12 = SUM_SCN12 + (scan & 0x01);
  SUM_SCN13 = SUM_SCN13 - ((SCN3[Head_SCN3]& 0x02)>>1);
  SUM_SCN13 = SUM_SCN13 + ((scan & 0x02)>>1);
  SUM_SCN14 = SUM_SCN14 - ((SCN3[Head_SCN3]& 0x04)>>2);
  SUM_SCN14 = SUM_SCN14 + ((scan & 0x04)>>2);
  SUM_SCN15 = SUM_SCN15 - ((SCN3[Head_SCN3] & 0x08)>>3);
  SUM_SCN15 = SUM_SCN15 + ((scan & 0x08)>>3);

  SCN3[Head_SCN3] = scan;

  Head_SCN3 = (Head_SCN3+1) & BUFFER_MASK_SCN0;

  OLD_SCN3 = NEW_SCN3;
  NEW_SCN3 = 0;
  i = (unsigned char)( SUM_SCN12 / BUFFER_SIZE_KEY);
  NEW_SCN3 = NEW_SCN3 | i;
  i = (unsigned char)( SUM_SCN13 / BUFFER_SIZE_KEY );
  NEW_SCN3 = NEW_SCN3 | (i<<1);
  i = (unsigned char)( SUM_SCN14 / BUFFER_SIZE_KEY);
  NEW_SCN3 = NEW_SCN3 | (i<<2);
  i = (unsigned char)( SUM_SCN15 / BUFFER_SIZE_KEY );
  NEW_SCN3 = NEW_SCN3 | (i<<3);

  /* Return vector [type   event, scan-code] */
    if ( ((NEW_SCN2 & 0x01) - (OLD_SCN2 & 0x01)) > 0 )
    {
    //DDRA = 0xFF;
    //PORTA = ~((unsigned char) PORTA);
    };
  }
/*  END Calculate status KEY */
/*---------------------------*/

/*-----------------------------*/
/*  Calculate events KEY  0->0 */
unsigned char Key_Event_00 ( unsigned char sel ) // sel = [0,1,2,3]
  {
  unsigned char tmp;
  switch (sel)
  {
  case 0:
  /* calculate event */
  tmp = (( ~(NEW_SCN0) & ~OLD_SCN0 ) & M00[sel]) & 0x0F;
  EVEN_M00[sel] = tmp;
  break;
  case 1:
  tmp = (( ~(NEW_SCN1) & ~OLD_SCN1 ) & M00[sel]) & 0x0F;
  EVEN_M00[sel] = tmp;
  break;
  case 2:
  tmp = (( ~(NEW_SCN2) & ~OLD_SCN2 ) & M00[sel]) & 0x0F;
  EVEN_M00[sel] = tmp;
  break;
  case 3:
  tmp = (( ~(NEW_SCN3) & ~OLD_SCN3 ) & M00[sel]) & 0x0F;
  EVEN_M00[sel] = tmp;
  break;
  default:
  tmp = 0;
  break;
  };
 return ( tmp);
  }

/*  END Calculate events KEY 0->0 */
/*--------------------------------*/

/*-----------------------------*/
/*  Calculate events KEY  0->1 */
unsigned char Key_Event_01 ( unsigned char sel )// sel = [0,1,2,3]
  {
  unsigned char tmp;
  switch (sel)
  {
  case 0:
  /* calculate event */
  tmp = (( (NEW_SCN0) & ~OLD_SCN0 ) & M01[sel]) & 0x0F;
  EVEN_M01[sel] = tmp;
  break;
  case 1:
  tmp = (( (NEW_SCN1) & ~OLD_SCN1 ) & M01[sel]) & 0x0F;
  EVEN_M01[sel] = tmp;
  break;
  case 2:
  tmp = (( (NEW_SCN2) & ~OLD_SCN2 ) & M01[sel]) & 0x0F;
  EVEN_M01[sel] = tmp;
  break;
  case 3:
  tmp = (( (NEW_SCN3) & ~OLD_SCN3 ) & M01[sel]) & 0x0F;
  EVEN_M01[sel] = tmp;
  break;
  default:
  tmp = 0;
  break;
   };
return ( tmp);
  }

/*  END Calculate events KEY 0->1 */
/*--------------------------------*/

/*-----------------------------*/
/*  Calculate events KEY  1->0 */
unsigned char Key_Event_10 ( unsigned char sel )// sel = [0,1,2,3]
  {
  unsigned char tmp;
  switch (sel)
  {
  case 0:
  /* calculate event */
  tmp = (( ~(NEW_SCN0) & OLD_SCN0 ) & M10[sel]) & 0x0F;
  EVEN_M10[sel] = tmp;
  break;
  case 1:
  tmp = (( ~(NEW_SCN1) & OLD_SCN1 ) & M10[sel]) & 0x0F;
  EVEN_M10[sel] = tmp;
  break;
  case 2:
  tmp = (( ~(NEW_SCN2) & OLD_SCN2 ) & M10[sel]) & 0x0F;
  EVEN_M10[sel] = tmp;
  break;
  case 3:
  tmp = (( ~(NEW_SCN3) & OLD_SCN3 ) & M10[sel]) & 0x0F;
  EVEN_M10[sel] = tmp;
  break;
  default:
  tmp = 0;
  break;
   };
 return ( tmp);
  }

/*  END Calculate events KEY 1->0 */
/*--------------------------------*/

/*-----------------------------*/
/*  Calculate events KEY  1->1 */
unsigned char Key_Event_11 ( unsigned char sel )// sel = [0,1,2,3]
  {
  unsigned char tmp;
  switch (sel)
  {
  case 0:
  /* calculate event */
  tmp = (( (NEW_SCN0) & OLD_SCN0 ) & M11[sel]) & 0x0F;
  EVEN_M11[sel] = tmp;
  break;
  case 1:
  tmp = (( (NEW_SCN1) & OLD_SCN1 ) & M11[sel]) & 0x0F;
  EVEN_M11[sel] = tmp;
  break;
  case 2:
  tmp = (( (NEW_SCN2) & OLD_SCN2 ) & M11[sel]) & 0x0F;
  EVEN_M11[sel] = tmp;
  break;
  case 3:
  tmp = (( (NEW_SCN3) & OLD_SCN3 ) & M11[sel]) & 0x0F;
  EVEN_M11[sel] = tmp;
  break;
  default:
  tmp = 0;
  break;
  };
 return ( tmp);
  }
/*  END Calculate events KEY 1->1 */
/*--------------------------------*/


/*----------------------------*/
/* Interrupt Timer 0 Overflow */
#pragma vector=TIMER0_OVF_vect
  static __interrupt void Overflow_Timer0(void)
  {
  unsigned char tmp;
  unsigned char i;

#ifdef TEST_KEY_CONTR
  /* test pulse time */
  DDRA = 0xFF;
  ClrBit (PORTA,PA0);
#endif

  switch (A21_y)  // Select for status A2x
    {
    case 0: // Reset and Init Timer0
    break;
    case 1: // Transitive process A2x
    Cal_Key_Contr();
      if (c_y1 > TRANS_KEY)
        {
        A21_y = 2;  // change status
        };
    c_y1++;
    break;
    case 2:
    // Event
    Cal_Key_Contr();
    break;
    default:
    break;
    };

  tmp = 0;
  for (i=0;i<=3;i++)
  {
  tmp = Key_Event_00(i);
  tmp = tmp | tmp;
  };
  EVEN_M00_SUM = tmp;   // if tmp = 0 then no Events

  tmp = 0;
  for (i=0;i<=3;i++)
  {
  tmp = Key_Event_01(i);
  tmp = tmp | tmp;
  };
  EVEN_M01_SUM = tmp;   // if tmp = 0 then no Events

  tmp = 0;
  for (i=0;i<=3;i++)
  {
  tmp = Key_Event_10(i);
  tmp = tmp | tmp;
  };
  EVEN_M10_SUM = tmp;   // if tmp = 0 then no Events

  tmp = 0;
  for (i=0;i<=3;i++)
  {
  tmp = Key_Event_11(i);
  tmp = tmp | tmp;
  };
  EVEN_M11_SUM = tmp;   // if tmp = 0 then no Events


  if (tmp != 0) // test YES Events
  {
  // DDRA = 0xFF;
  // PORTA = ~(PORTA);
  };            // end test


  Wr_Sym_Disp(DISP_POS); // Output Indicator

#ifdef TEST_KEY_CONTR
  /* test pulse time */
  DDRA = 0xFF;
  SetBit (PORTA,PA0);
#endif
  cTest++;
  //DDRA = 0xFF;
  //ClrBit (PORTA,PA0);
  PORTA = ~(cTest);
  //PORTA = ~( TCNT0 - mTC_0);
  //PORTA = ~( (cTest & 0xf0) | (PORTA & 0x0F));
  //PORTA = ~(tmp);

  /* Increment counter interrupt Timer 0 */
  COUNT_TIME++;

  /* Corect TIME0 */
  TCNT0 = mTC_0+TCNT0;
  }
/* END Interrupt Timer 0 Overflow */
/*--------------------------------*/

/*---------------------------------------*/
/*  Init SPI Inteface for KEY_CONTR A2x  */
void Init_SPI ( void)
{
 /* Disable Interrupt SPI */
 ClrBit (SPCR,SPIE);
 ClrBit (SPCR,SPE);

 SetBit (SPCR, MSTR); // Mode Master
 SetBit (SPCR, CPOL); // Mode SCK 1_0_1
 SetBit (SPCR, CPHA);

 ClrBit (SPSR, SPI2X);// "0"  Fcl/128
 SetBit (SPCR, SPR1); // "1"
 SetBit (SPCR, SPR0); // "1"

 /* Enable Interrupt SPI */
 SetBit (SPCR,SPE);
 SetBit (SPCR,SPIE);
}
/*  END Init SPI Inteface for KEY_CONTR A2x  */
/*-------------------------------------------*/

/*---------------*/
/* Interrupt SPI */
#pragma vector=SPI_STC_vect
  static __interrupt void SPI_STC(void)
  {
  SPDR = 'U';

   cTest++;
  //DDRA = 0xFF;
  //PORTA = ~(cTest);
  }
/* END Interrupt SPI  */
/*--------------------*/

#ifdef TEST_KEY_CONTR
/* main - a simple test program*/
void main( void )
        {
        static volatile unsigned char c_y1;
        volatile long int l_i;
        volatile unsigned char cByte;
        volatile int iByte;
        volatile int iRet;
        volatile unsigned int i;

        _CLI();  // disable global interrupt


        /*----------------------------------------*/
        // 1. Init_SPI(); // test init SPI inteface


        /*-----------------------*/
        /* 2. Init UART0         */
        Reset_UART0();
        Init_S_UART0(57600); // 57600 default
        Init_2S_UART0(0);
        Init_B_UART0(1);  // Size Bits '8'
        Init_P_UART0(0);  // Parity    'N'
                          // Stop Bit  '1'
        Echo_OFF_UART0(); // Set Echo
        ControlStream_OFF_UART0();     // Flow Control OFF
        XON_XOFF_OFF_CONTR_Rx_UART0(); // Disable Software Control OFF
        XON_XOFF_OFF_CONTR_Tx_UART0(); // Disable Tx Control
        /* Enable control hardware flow all signals */
         DSR_OFF_CONTR_UART0();  // Disable Hardware Flow Control DSR
         DTR_OFF_CONTR_UART0();  // Disable Hardware Flow Control DTR
         CTS_OFF_CONTR_UART0();  // Disable Hardware Flow Control CTS
         RTS_OFF_CONTR_UART0();  // Disable Hardware Flow Control RTS
         RTS_CLR_UART0();       // RTS0=0 Request to send
         DTR_CLR_UART0();       // DTR0=0 Data Terminal Ready
         CTS_CLR_UART0();
         DSR_CLR_UART0();
        /* Enable error counters*/
        Enable_Err_Count_UART0();
        i = 0;

        /*-------------------------*/
        /* 3. Set A2.1 KEY_CONTR   */
        Reset_KEY_CONTR();
        c_y1 = 0; // temp variable status A21_y1=1 c_y1 = 0...4
        /* Set A2.2 DISP_CONTR */
        Reset_DISP_CONTR ();
        /* Init Timer0 */
        Init_Timer0();

        /*-------------------*/
        /* 4. Begin programm */
        _SEI(); // enable global interrupt
        /* Start Timer0 */
        Start_Timer0();
        iRet = printf("Test ver 0.02 for file 'A2x.c' KEY_CONTR \n\r");
        
        //SPDR = 'U'; // For start and interrupt Transmit On Byte 8 bits

        i=0;

        while ( 1 ) /* forever */
                {
                /* test new function getchar() and prints stdin */
                /* Reset point for BUFFER BUF_CMD */
                Head_CMD = 0; // point begin
                do 
                { 
                  iByte = getchar_K();     // new size buffer 40 yes
                  iRet = printf("%c",toupper( (unsigned char) iByte));
                  /* Save elements BUF_CMD */
                  BUF_CMD[Head_CMD] = (unsigned char) iByte;
                  Head_CMD++;
                        if ( Head_CMD > (BUFFER_SIZE_CMD-1) )
                        {
                         Head_CMD--; // end buffer
                        };
                  
                  if (iByte == 0x0A)  // ^J LF  
                  {
                  iRet = printf("\r");                  
                  };
                }
                while ( iByte != 0x0A);
                /*test print strings */
                for (i=0;i<BUFFER_SIZE_CMD-1;i++)
                {
                iRet = printf("%c",BUF_CMD[i]);
                };
                
                /*
                cByte = (unsigned char) i;
                iRet = printf("%c",' '); // yes
                iRet = printf("%c",cByte); // yes
                */

                /* test init variables */
                i++;
                cByte = 'a';
                iByte = 0;
                iRet = 0;
                l_i = 0;
                };
        }
#endif
