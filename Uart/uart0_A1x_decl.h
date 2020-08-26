/* Last 04.09.2002
   Edit 04.09.2002 
   Head uart0_a1x_decl.h  for   UART0_A1x.c
   Ver 0.01  */

/* UART0 Defines PORTC signal DTR0, DSR0, CTS0, RTS0 */
#define DTR0 PD4    // output
#define DSR0 PD6    // input
#define CTS0 PD3    // output
#define RTS0 PD5    // input
#define PORT_FLOW_O  PORTD
#define PORT_FLOW_I  PIND
#define PORT_FLOW_D  DDRD
  
/* UART0 Buffer Defines */
#define RX_BUFFER_SIZE_UART0 32 /* 1,2,4,8,16,32,64,128 or 256 bytes */
#define RX_BUFFER_MASK_UART0 ( RX_BUFFER_SIZE_UART0 - 1 )
#define TX_BUFFER_SIZE_UART0 32 /* 1,2,4,8,16,32,64,128 or 256 bytes */
#define TX_BUFFER_MASK_UART0 ( TX_BUFFER_SIZE_UART0 - 1 )

#if ( RX_BUFFER_SIZE_UART0 & RX_BUFFER_MASK_UART0 )
#message "RX buffer size is not a power of 2"
#endif

/* UART0 Array Errors Define */
#define Rx_Tx_Err_SIZE_UART0 5

/* Static Variables in Flash*/
 __flash const unsigned int fSpeedBaud_UART0 = 9600;// 110...56700
 __flash const unsigned char fModeU2X0 = 0;         // 0,1
 __flash const unsigned char fModeCHR90 = 0;        // 0,1
 __flash const unsigned char fCheckParity_UART0 = 0;// 0,1,2,3,4
 __flash const unsigned char fSizeBit_UART0 = 1;    // 0,1
 /*
  fSizeBit_UART0 = 0 Rx/Tx 7-bits   High bits b6=1 
  fSizeBit_UART0 = 1 Rx/Tx 8-bits 
 */
 __flash const unsigned char fContrStream_UART0 = 0;// 0,1
 __flash const unsigned char fEnb_DTR0 = 1;         // 0,1  
 __flash const unsigned char fBit_DTR0 = 1;         // 0,1
 __flash const unsigned char fEnb_DSR0 = 1;         // 0,1
 __flash const unsigned char fBit_DSR0 = 1;         // 0,1
 __flash const unsigned char fEnb_RTS0 = 1;         // 0,1
 __flash const unsigned char fBit_RTS0 = 1;         // 0,1
 __flash const unsigned char fEnb_CTS0 = 1;         // 0,1
 __flash const unsigned char fBit_CTS0 = 1;         // 0,1
 __flash const unsigned char fSym_XON = 17;         // 0...255 symbol <DC1>
 __flash const unsigned char fSym_XOFF= 19;         // 0...255 symbol <DC3>
 __flash const unsigned char fEnb_XON_XOFF_Tx_UART0 = 1; // 0,1
 __flash const unsigned char fCount_XOFF_Tx_UART0 = 0; // 0,1,2,3,4,5
 __flash const unsigned char fEnb_XON_XOFF_Rx_UART0 = 1; // 0,1
 __flash const unsigned char fCount_XOFF_Rx_UART0 = 0; // 0,1,2,3,4,5
 __flash const unsigned char fEnb_Echo_UART0 = 1 ;   // 0,1      
 __flash const unsigned char fModeMPCM0 = 0;        // 0,1
 __flash const unsigned char fEnb_Err_UART0 = 0;    // 0,1


/* Status AX.x in RAM*/
static volatile unsigned char A1x_y = 0;          // 0...255 for UART0 
static volatile unsigned char A2x_y = 2;          // 0...255 for KEY

/* Static Variables in RAM*/
static volatile unsigned int SpeedBaud_UART0;            // 110...56700
static volatile unsigned char ModeU2X0;         // 0,1
static volatile unsigned char ModeCHR90;        // 0,1

static volatile unsigned char CheckParity_UART0;// 0,1,2,3,4
/*    
CheckParity_UART0=0   No control    
CheckParity_UART0=1   Parity        
CheckParity_UART0=2   Odd           
CheckParity_UART0=3   Mark          
CheckParity_UART0=4   Space           
*/
static volatile unsigned char SizeBit_UART0 = 0;    // 0,1,2 
 /*
  fSizeBit_UART0 = 0 Rx/Tx 5-bits   High bits b6=1, b5=1, b4=1
  fSizeBit_UART0 = 0 Rx/Tx 7-bits   High bits b6=1 
  fSizeBit_UART0 = 0 Rx/Tx 8-bits 
 */
static volatile unsigned char ContrStream_UART0;// 0,1
static volatile unsigned char Enb_DTR0;         // 0,1  
static volatile unsigned char Bit_DTR0;         // 0,1
static volatile unsigned char Enb_DSR0;         // 0,1
static volatile unsigned char Bit_DSR0;         // 0,1
static volatile unsigned char Enb_RTS0;         // 0,1
static volatile unsigned char Bit_RTS0;         // 0,1
static volatile unsigned char Enb_CTS0;         // 0,1
static volatile unsigned char Bit_CTS0;         // 0,1
static volatile unsigned char Sym_XON;          // 0...255
static volatile unsigned char Sym_XOFF;         // 0...255
static volatile unsigned char Enb_XON_XOFF_Tx_UART0;// 0,1
static volatile unsigned char Count_XOFF_Rx_UART0;  // 0,1,2,3,4,5 
static volatile unsigned char Enb_XON_XOFF_Rx_UART0;// 0,1
static volatile unsigned char Count_XOFF_Tx_UART0;  // 0,1,2,3,4,5
static volatile unsigned char Enb_Echo_UART0;   // 0,1      
static volatile unsigned char ModeMPCM0;        // 0,1
static volatile unsigned char Enb_Err_UART0;    // 0,1
static volatile __io struct       // Declare type structure
        { unsigned char uh0:4 ,
                        uh1:4 ;
        } UBRH @ 0x20; 

/* Declare variables in EEPROM */
#pragma type_attribute=__eeprom
unsigned char S3e,S4e,S5e,S16e,S18e,S21e,S22e,S23e,S39e,S51e;

/* Static Variables */
static volatile unsigned char RxBuf_UART0[RX_BUFFER_SIZE_UART0];
static volatile unsigned char RxHead_UART0;
static volatile unsigned char RxTail_UART0;
static volatile unsigned char TxBuf_UART0[TX_BUFFER_SIZE_UART0];
static volatile unsigned char TxHead_UART0;
static volatile unsigned char TxTail_UART0;

/* Static Variables */
static volatile unsigned int Rx_Tx_Err_UART0[Rx_Tx_Err_SIZE_UART0];
/* Array Erros Rx
 Rx_Tx_Err_UART0[1] - FE0
 Rx_Tx_Err_UART0[2] - OR0
 Rx_Tx_Err_UART0[3] - Error Pariry    
 Rx_Tx_Err_UART0[4] - Buf Rx Full
 Rx_Tx_Err_UART0[5] - Buf Tx Full */
static volatile unsigned long Count_Rx_UART0;
static volatile unsigned long Count_Rx_Err_UART0;

static volatile unsigned long Count_Tx_UART0;
static volatile unsigned long Count_Tx_Err_UART0;

static char test[40]; // test array for test fgets()
