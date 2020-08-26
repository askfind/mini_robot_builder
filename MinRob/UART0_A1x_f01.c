#include "iom161.h"
#include "stdio.h"
#include "uart0_A1x.h"
#include "uart0_A1x_decl.h"



void TransmitByte( unsigned char data )
        {
        unsigned char tmphead;
        /* calculate buffer index */
        //tmphead = ( TxHead_UART0 + 1 ) & TX_BUFFER_MASK_UART0;
        tmphead = (TxHead_UART0+1) & TX_BUFFER_MASK_UART0;
                /* wait for free space in buffer */

        while ( tmphead == TxTail_UART0 )
                ;
        TxBuf_UART0[tmphead] = data; /* store data in buffer */
        TxHead_UART0 = tmphead; /* store new index */
        UCSR0B |= (1<<UDRIE0); /* enable UDRE interrupt */
        }

void main(void)
{
  int i;
  unsigned char data='U'; 
  for (;;)
  {
   /*--------------------------*/
  /*   Test for function UART0 */
  /*

  void TransmitByte( unsigned char data )

      1 byte  in segment ABSOLUTE
     48 bytes in segment CODE
      1 byte  in segment EEPROM_I
      6 bytes in segment INITTAB
     21 bytes in segment NEAR_F
     43 bytes in segment NEAR_Z
 
     69 bytes of CODE memory (+ 6 bytes shared)
     43 bytes of DATA memory (+ 1 byte shared)
      1 byte  of XDATA memory
  */
  TransmitByte(data);
  /* End Test */
  i++;
  /* Test Modul for A1x.c */
  };
}
