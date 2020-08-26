#include "iom161.h"
#include "stdio.h"

/* Set and clear bits in I/O registers can also be declared as macros */
#define SetBit(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define ClrBit(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
/* Macro for testing of a single bit in an I/O location*/
/* Macro for testing of a single bit in an I/O location*/
#define CheckBit(ADDRESS,BIT) (ADDRESS & (1<<BIT))

/* Use of bit-mask for status bits*/
/* Define bit macros, note that they are similar to the I/O macros*/
#define SETBIT(x,y) (x |= (y)) /* Set bit y in byte x*/
#define CLEARBIT(x,y) (x &= (~y)) /* Clear bit y in byte x*/
#define CHECKBIT(x,y) (x & (y)) /* Check bit y in byte x*/

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

typedef struct
{
char sec;
}t;
t global; /* Declare a global structure*/

static char min;

void  main(void)
{
 int i=0;
 for (;;)
 {
/*---------*/
/*  Test 1 */
/*
;     32 bytes in segment CODE
;      6 bytes in segment INITTAB
;      2 bytes in segment NEAR_Z
; 
;     32 bytes of CODE memory (+ 6 bytes shared)
;      2 bytes of DATA memory
*/
t *time = &global; 
if (++time->sec == 60)
{};

if ( ++min == 60)
{};

  i++;
  };
}
