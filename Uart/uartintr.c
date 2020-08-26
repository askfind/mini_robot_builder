/* Code adapted from Atmel AVR Application Note AVR306
 * Interrupt mode driver for UART.
 */

#include "iom161.h"
#include "macros.h"
#include "uart.h"
#include <stdio.h>
//#include "iostream.h"
//#include "yfuns.h"
//#undef __putchar
//#undef __getchar


/* IMPORTANT: these vector numbers are for 8515! If you use other devices
 * you must change them to the different set of numbers.
 *
 * UART_RX_interrupt set to UART, Rx Complete
 * UART_TX_interrupt set to UART Data Register Empty
 */

/* Debug test module */
#define TEST  

/* UART0 Buffer Defines */
#define UART0_RX_BUFFER_SIZE 128 /* 1,2,4,8,16,32,64,128 or 256 bytes */
#define UART0_RX_BUFFER_MASK ( UART0_RX_BUFFER_SIZE - 1 )
#define UART0_TX_BUFFER_SIZE 128 /* 1,2,4,8,16,32,64,128 or 256 bytes */
#define UART0_TX_BUFFER_MASK ( UART0_TX_BUFFER_SIZE - 1 )

//#if ( UART0_RX_BUFFER_SIZE & UART0_RX_BUFFER_MASK )
//#error RX buffer size is not a power of 2
//#endif

/* Static Variables */
static unsigned char UART0_RxBuf[UART0_RX_BUFFER_SIZE];
static volatile unsigned char UART0_RxHead;
static volatile unsigned char UART0_RxTail;
static unsigned char UART0_TxBuf[UART0_TX_BUFFER_SIZE];
static volatile unsigned char UART0_TxHead;
static volatile unsigned char UART0_TxTail;
// New putchar
//static volatile __io unsigned char _PORTA @ 0x1B ;
//static volatile __io unsigned char _DDRA  @ 0x1A;
//static volatile __io unsigned char _PINA  @ 0x19;   


/* initialize UART */
void InitUART0( unsigned char baudrate )
	{
	unsigned char x;
	UBRR0 = baudrate; /* set the baud rate */
	/* enable UART receiver and transmitter, and
	receive interrupt */
	UCSR0B = ( (1<<RXCIE0) | (1<<RXEN0) | (1<<TXEN0) );
	x = 0; /* flush receive buffer */
	UART0_RxTail = x;
	UART0_RxHead = x;
	UART0_TxTail = x;
	UART0_TxHead = x;
	}


#pragma vector=UART0_RX_vect
static __interrupt void UART0_RX(void)
{
      
        unsigned char data;
	unsigned char tmphead;
 // !! Add store register SREG to STEK	
        asm (" PUSH R0 \n");
	data = UDR0; /* read the received data */
	/* calculate buffer index */
	tmphead = ( UART0_RxHead + 1 ) & UART0_RX_BUFFER_MASK;
	UART0_RxHead = tmphead; /* store new index */
	if ( tmphead == UART0_RxTail )
		{
		/* ERROR! Receive buffer overflow */
		}
	UART0_RxBuf[tmphead] = data; /* store received data in buffer */
 // !! Add restore register SREG from STEK
        asm (" POP R0 \n");
}

/* interrupt handlers */


#pragma vector=UART0_UDRE_vect
static __interrupt void UART0_UDRE(void)
{
	unsigned char tmptail;

        asm (" PUSH R0 \n");

	/* check if all data is transmitted */
	if ( UART0_TxHead != UART0_TxTail )
		{
		/* calculate buffer index */
		tmptail = ( UART0_TxTail + 1 ) & UART0_TX_BUFFER_MASK;
		UART0_TxTail = tmptail; /* store new index */
		//PORTA = ~UART0_TxBuf[tmptail]; /* test */
		UDR0 = UART0_TxBuf[tmptail]; /* start transmition */
		}
	else
		{
		UCSR0B &= ~(1<<UDRIE0); /* disable UDRE interrupt */
		};
        asm (" POP R0 \n");		
	}

/* Read and write functions */
unsigned char ReceiveByte( void )
	{
	unsigned char tmptail;

	while ( UART0_RxHead == UART0_RxTail ) /* wait for incomming data */
		;
	tmptail = ( UART0_RxTail + 1 ) & UART0_RX_BUFFER_MASK;/* calculate buffer index */
	UART0_RxTail = tmptail; /* store new index */
	return UART0_RxBuf[tmptail]; /* return data */
	}

void TransmitByte( unsigned char data )
	{
	unsigned char tmphead;
	/* calculate buffer index */
	tmphead = ( UART0_TxHead + 1 ) & UART0_TX_BUFFER_MASK; 
		/* wait for free space in buffer */

	while ( tmphead == UART0_TxTail )
		;
	UART0_TxBuf[tmphead] = data; /* store data in buffer */
	UART0_TxHead = tmphead; /* store new index */
	UCSR0B |= (1<<UDRIE0); /* enable UDRE interrupt */
	}

unsigned char DataInReceiveBuffer( void )
	{
	return ( UART0_RxHead != UART0_RxTail ); 
		/* return 0 (FALSE) if the receive buffer is empty */
	}



#ifdef TEST
/* main - a simple test program*/
void main( void )
	{

	volatile unsigned char cByte;
	volatile int iByte=1;
	volatile int iRet;
	volatile unsigned char * msg=" ";
	InitUART0( 23 ); /* set the baudrate to 9600 bps using a 3,6864 MHz crystal */
	_SEI(); /* enable interrupts => enable UART interrupts */
	while ( 1 ) /* forever */
		{

		//TestBuf.sputc( ) ;
		//iRet =  fputc(cByte,stdout) ;
		// !! Yes iRet =  putchar(cByte);
                cByte = ReceiveByte();
                *msg = cByte;
                iByte = (int) cByte;
		TransmitByte(cByte); /* echo the received character */
		//iRet = puts("Test puts\n");		
                //putchar((int)cByte);
		iRet = printf("%c", cByte);
		//iRet = printf("Hello");
                // Yes !! Test
                //iByte =  __getchar();
                //iRet  =  __putchar(iByte);
		//iRet = (int)&cout;
		//iRet = (int)&cin ;
                //cout << "Start test stream standart" << cin;
           }
	}
#endif
