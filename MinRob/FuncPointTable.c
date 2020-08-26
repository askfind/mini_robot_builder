#include "iom161.h"
#include "stdio.h"

/* Set and clear bits in I/O registers can also be declared as macros */
#define SetBit(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define ClrBit(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
/* Macro for testing of a single bit in an I/O location*/
/* Macro for testing of a single bit in an I/O location*/
#define CheckBit(ADDRESS,BIT) (ADDRESS & (1<<BIT))

/* UART0 Buffer Defines */
#define RX_BUFFER_SIZE_UART0 32 /* 1,2,4,8,16,32,64,128 or 256 bytes */
#define RX_BUFFER_MASK_UART0 ( RX_BUFFER_SIZE_UART0 - 1 )
#define TX_BUFFER_SIZE_UART0 32 /* 1,2,4,8,16,32,64,128 or 256 bytes */
#define TX_BUFFER_MASK_UART0 ( TX_BUFFER_SIZE_UART0 - 1 )

#if ( RX_BUFFER_SIZE_UART0 & RX_BUFFER_MASK_UART0 )
#message "RX buffer size is not a power of 2"
#endif

/* Static Variables */
static volatile unsigned char RxBuf_UART0[RX_BUFFER_SIZE_UART0];
static volatile unsigned char RxHead_UART0;
static volatile unsigned char RxTail_UART0;
static volatile unsigned char TxBuf_UART0[TX_BUFFER_SIZE_UART0];
static volatile unsigned char TxHead_UART0;
static volatile unsigned char TxTail_UART0;

 static volatile unsigned char x=1;
 static volatile unsigned char y=2;


void swap( volatile unsigned char *x, volatile unsigned char *y)
{
unsigned char temp;
temp = *x;
*x = *y;
*y = temp;

}
void  main(void)
{
 int i=0;

 swap( &x, &y);


 for (;;)
 {
/*---------*/
/*  Test 1 */
/*
;
;     26 bytes in segment CODE
;      6 bytes in segment INITTAB
;     32 bytes in segment NEAR_Z
;
;     26 bytes of CODE memory (+ 6 bytes shared)
;     32 bytes of DATA memory
*/

  volatile unsigned char *pointer1 = &RxBuf_UART0[0];
  volatile unsigned char *pointer2 = &RxBuf_UART0[31];
  *pointer1++ = *--pointer2;


/*-----------*/
/*  Test 2   */
/*
;     20 bytes in segment CODE
;      6 bytes in segment INITTAB
;     32 bytes in segment NEAR_Z
;
;     20 bytes of CODE memory (+ 6 bytes shared)
;     32 bytes of DATA memory
*/
//  RxBuf_UART0[0+1] = RxBuf_UART0[31-1];
  i++;
  };
}