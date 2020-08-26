#include "iom161.h"
#include "stdio.h"
#include "uart0_A1x.h"
#include "uart0_A1x_decl.h"


/*********************************/
/*   New function UART0_RX(void) */
//#pragma vector=UART0_RX_vect
//static __interrupt void UART0_RX(void)
void   New_UART0_RX(void)  // debugerd
  {  
    unsigned char tmphead;
    unsigned char cTmp;
    unsigned char cByte;
    //unsigned char cPE;
    unsigned char cPERx;
    volatile unsigned char FlgErr;
   
    FlgErr = 0;  // '0' - No Errors Rx    

    //cTmp = UCSR0A & 0x10;  // Test bit FE0=?
    if ( (UCSR0A & 0x10) != 0 )
      {
      FlgErr = 1;         // '1' - Rx byte yes Error
      IncErrArr_UART0(1); // increment Rx_Tx_Err_UART0[1] 
      };
          
    //cTmp = UCSR0A & 0x08; // Test bit OE0=?       
     if ( (UCSR0A & 0x08 != 0) )  
      {
      FlgErr = 1;
      IncErrArr_UART0(2); // increment Rx_Tx_Err_UART0[2] 
          };

     cByte = UDR0;                  // Read Byte Rx from UDR0
     cPERx = (UCSR0B & 0x02) >> 1;  // Read 9 Bit Rx

     //FlgErr = CalculParity(cByte,cPERx);

     cTmp = CheckParity( cByte) ;
     if ( cPERx == 1 )
        {
        cTmp = 0xff - cTmp;     // Calculate parity and cPERx
        };             
      /* return 
         if cTmp = 0   then parity    (cByte and cPERx) 
         if cTmp = 255 then no parity 
      */ 
       
    /* Check buffer Rx */ 
     if ( FlgErr == 0 )  // No Errors for Rx
        {
        /* calculate buffer index */
        tmphead = ( RxHead_UART0 + 1 ) & RX_BUFFER_MASK_UART0;
        RxHead_UART0 = tmphead; /* store new index */
        if ( tmphead == RxTail_UART0 )
                {
                IncErrArr_UART0(4); // increment Rx_Tx_Err_UART0[4] 
                };
        RxBuf_UART0[tmphead] = cByte; /* store received data in buffer */
        if ( Enb_Err_UART0 == 1 )
          {
          Count_Rx_UART0++;   
          };
        }
        else        // Yes Errors Rx for UART0
        {
        if ( Enb_Err_UART0 == 1 )
          {
          Count_Rx_Err_UART0++;   
          };        
        };
  }        
/* End  New function UART0_RX(void) */
/************************************/

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
  New_UART0_RX();
  /* End Test */
  i++;
  /* Test Modul for A1x.c */
  };
}
