#include "iom161.h"
#include "stdio.h"
#include "uart0_A1x.h"
#include "uart0_A1x_decl.h"


///*************************************
// This method interrupt event TX Empty
//#pragma vector=UART0_TX_vect
//static __interrupt void   UART0_TX()
void New_UART0_TX(void) 
    {
    unsigned char tmptail;
    unsigned char cTmp;
    unsigned char cByte;
    //volatile unsigned char cPE;
    //volatile unsigned char cPERx;    
    //volatile unsigned char FlgErr;


        /* check if all data is transmitted */
        if ( TxHead_UART0 != TxTail_UART0 )
           {
           /* calculate buffer index */
           tmptail = ( TxTail_UART0 + 1 ) & TX_BUFFER_MASK_UART0;
           TxTail_UART0 = tmptail; /* store new index */
           cByte = TxBuf_UART0[tmptail];    // Byte for Tx UART0
           /* For Modes CheckParity_UART0 */
              switch (CheckParity_UART0)
              {
              case 0:
              break;
              case 1:
              cTmp = CheckParity(cByte);
                if ( cTmp == 0) // cByte parity
                {
                 UCSR0B = UCSR0B & ~(1<<TXB80);  // TXB80 = 0
                };
              break;
              case 2:
              cTmp = CheckParity(cByte);
                if ( cTmp == 0) // cByte parity
                {
                 UCSR0B = UCSR0B | (1<<TXB80);   // TXB80 = 1
                };  
              break;
              default:
              UCSR0B = UCSR0B | (1<<TXB80);   // TXB80 = 1
              break;     
              };
          UDR0 = TxBuf_UART0[tmptail]; /* start transmition */
                }
        else
                {
                UCSR0B &= ~(1<<UDRIE0); /* disable UDRE interrupt */
                };
 }

/**********************/
/* Function IncErrArr */
void IncErrArr_UART0 ( int pos )
{
 if ( Enb_Err_UART0 != 0 )
  {
  Rx_Tx_Err_UART0[pos]++;
  };  
}
/*  End IncErrArr    */
/*********************/


void main(void)
{
  int i;
  for (;;)
  {
   /*--------------------------*/
  /*   Test for function UART0 */
  /*
; 
;      3 bytes in segment ABSOLUTE
;    222 bytes in segment CODE
;      1 byte  in segment EEPROM_I
;      6 bytes in segment INITTAB
;     21 bytes in segment NEAR_F
;     66 bytes in segment NEAR_Z
; 
;    243 bytes of CODE memory (+ 6 bytes shared)
;     66 bytes of DATA memory (+ 3 bytes shared)
;      1 byte  of XDATA memory
;
*/
  New_UART0_TX();
  /* End Test */
  i++;
  /* Test Modul for A1x.c */
  };
}
