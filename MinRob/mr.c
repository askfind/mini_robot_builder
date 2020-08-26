/************************************************************
 * Name:    Mini Robot for buildings , EC++ version         *
 * **********************************************************   
 *                                                          *
 * Version:             0.01                                *
 * Date create:         30.07.2002  12:00                   *
 * Last edit:           15.08.2002  23:05                   *
 *                                                          *
 * File:                mr.c                                *
 *                                                          *  
 ************************************************************/
#include <stdio.h>
#include "iom161.h"
#include <inavr.h>
#include "mc_def.h"
/* enable use of extended keywords */
#pragma language=extended

 /***********************************
 *       Global variables          *
 ***********************************/
volatile static  unsigned int Test;
//
static volatile  unsigned int   gl_speed = 9600; // default baund speed 9600 bps 
static volatile  unsigned int   gl_parity = 0;   //         parity NO check 
//
static volatile  unsigned int   gl_test_Rx = 0;   // Mode Test Rx 
                                                  // Counter Errors 
volatile static  unsigned int   aErRx[5];         // Array Erros Rx
                                                  // aErRx[1] - FE0
                                                  // aErRx[2] - OR0
                                                  // aErRx[3] - Error Pariry    
                                                  // aErRx[4] - Buf Rx Full
static volatile  unsigned int   gl_test_Tx = 0;   // Mode Test  Tx
volatile static  unsigned int   aErTx[5];         // Array Erros Tx
                                                  // aErRx[1] - empty
                                                  // aErRx[2] - empty
                                                  // aErRx[3] - empty    
                                                  // aErRx[4] - Buf Tx Full
//      
volatile static unsigned int var=0;
volatile static  unsigned char aTest[BufLen];
volatile static  unsigned int ErrTest;
volatile static  unsigned char cTest;  
volatile static  unsigned int  nTestPos;

//  Variables for UART
    volatile static unsigned char ErrRx;
    volatile static unsigned char RxBufPos ;
    volatile static unsigned char RxBuf[BufLen];
    volatile static unsigned char ErrTx;
    volatile static unsigned char TxBufPos ;
    volatile static unsigned char TxBuf[BufLen]; 

// Flag Print Erros Array
   volatile static bool FlgPrint = false;
   volatile static unsigned char p = 0;
//   
static volatile __io unsigned char _GIMSK @ 0x3B;
static volatile __io unsigned char _PORTA @ 0x1B ;
static volatile __io unsigned char _PORTD @ 0x12 ;
static volatile __io unsigned char _DDRD  @ 0x11 ;
static volatile __io unsigned char _SREG  @ 0x3F ;
 /*******************************************
 *     Base class declaration for UART0     *
 ********************************************/ 
 
class Uart0Baseclass
{
  public:
    // Constructor
    //Uart0Baseclass()
    //{};

    // Destructor
    //~Uart0Baseclass()
    //{};
 
    // This method init set for UART0.
    // 
    void InitUart(unsigned int speed, unsigned int parity);
  
    // This method clear the UART0
    void Clear();
    
    //----------------------------------------
    // This method clear the RxBuf
    void ClearRxBuf();
   // This method write on byte the RxBuf
    void WrByteRxBuf(unsigned char Byte);
    // This method write on byte the RxBuf
    unsigned char  RdByteRxBuf(void);
    // This method for RxBuf define Begin Buffer
    // Return - True : Begin Buf, no bytes 
    //        - Fasle : No Begin Buf , yes bytes 
    bool B_RxBuf();
    // This method for RxBuf define End Buffer
    // Return - True : End Buf, full bytes 
    //        - Fasle : No End Buf   
    bool E_RxBuf();

    
    //---------------------------------------
    // This method clear the TxBuf
    void ClearTxBuf();
    // This method write on byte the TxBuf
    void WrByteTxBuf(unsigned char Byte);
    // This method write on byte the TxBuf
    unsigned char  RdByteTxBuf(void);
    // This method for TxBuf define Begin Buffer
    // Return - True : Begin Buf, no bytes 
    //        - Fasle : No Begin Buf , yes bytes 
    bool B_TxBuf();
    // This method for TxBuf define End Buffer
    // Return - True : End Buf, full bytes 
    //        - Fasle : No End Buf   
    bool E_TxBuf();

    // For test method for interrupt
    void testfunc();
    
//*******************************   
// This method interrupt event RX 
#pragma vector=UART0_RX_vect
    static __interrupt void   Uart0_RX()
    {
    volatile unsigned char cTmp;
    volatile unsigned char cByte;
    volatile unsigned char cPE;
    volatile unsigned char cPERx;    
    volatile bool FlgErr;
    volatile int i;
    volatile int j;
    volatile int k;    
    
    FlgErr = false;               // No Errors Rx    


        cTmp = UCSR0A & 0x10;     // Test bit FE0=?
          if ( cTmp != 0 )
          {
            ErrRx = 1;
            FlgErr = true;
            if ( gl_test_Rx == 1)
            {
             aErRx[1]++;
             };
           };
        
        cTmp = UCSR0A & 0x08;     // Test bit OE0=?       
          if ( (cTmp != 0) )  
          {
            ErrRx = 2;
            FlgErr = true;
            if ( gl_test_Rx == 1 )
            {
            aErRx[2]++;
            };
          };
   
     cByte = UDR0;                        // Read Byte Rx from UDR0
     cPERx = (UCSR0B & 0x02) / 2;        // Read 9 Bit Rx

               
      switch(gl_parity)      // Test mode parity=?
        {
        case 0:              // No parity
        break;
 
        case 1:             // mode parity = "1"
        case 2:             // mode parity = ~ "1" 
            if ( true ) // Counters all Errors
            {
              j=1;
              k=0;
              
                for (i=1;i<=8;i++)
                    {
                    cTmp = cByte & j;
                        if ( cTmp != 0)
                        {
                        k++;
                        };
                     j = j*2;   
                    };
      
                cTmp = (char) (k % 2);
                      
                    if ( (cTmp == 1) && (gl_parity == 1) )
                      {
                      cPE = 1;
                        if ( cPE != cPERx )
                        {
                         FlgErr = true;
                         ErrRx = 3;
                            if ( gl_test_Rx == 1 )
                            {
                            aErRx[3]++;
                            };
                         };
                      };
                    if ( (cTmp == 1) && (gl_parity == 2) )
                      {
                      cPE = 0;
                        if ( cPE != cPERx )
                        {
                         FlgErr = true;
                         ErrRx = 3;
                            if ( gl_test_Rx == 1 )
                            {
                            aErRx[3]++;
                             };
                         };
                      };
                    if ( (cTmp == 0) && (gl_parity == 1) )
                      {
                      cPE = 0;
                        if ( cPE != cPERx )
                        {
                         FlgErr = true;
                         ErrRx = 3;
                                    if ( gl_test_Rx == 1 )
                                    {
                                    aErRx[3]++;
                                    };
                         };                      
                      };                            
                    if ( (cTmp == 0) && (gl_parity == 2) )
                      {
                      cPE = 1;
                        if ( cPE != cPERx )
                        {
                         FlgErr = true;
                         ErrRx = 3;
                                if ( gl_test_Rx == 1 )
                                {
                                aErRx[3]++;
                                };
                         };
                 };
                  
            };          
        break;
        };

      // Test End BufRx
      // set FlgErr=true if End BufRx
       if ( (RxBufPos >= (BufLen))  )
          {
            FlgErr = true;
            ErrRx = 4; // Full BufRx
                  if ( gl_test_Rx == 1 )
                  {
                  aErRx[4]++;
                  };
          }
      else
          {
            ;
          };
          

       
      // Write Byte to BufRx  
      if ( FlgErr == false )
      {
      ErrRx = 0 ;   // No Errors Rx 
      

      // Byte Write Rx Buf
            RxBuf[RxBufPos] = cByte;
            RxBufPos = RxBufPos + 1 ;

            if ( (BufLen-RxBufPos) <= 2 ) // RTS0 = 1 stop Tx from PC
            {
            PORTC = PORTC ^ ( 1 ); // RTS0=1 Pins Out bits   
            };
      };
            
 }; 



//*************************************
// This method interrupt event TX Empty
#pragma vector=UART0_TX_vect
   static __interrupt void   Uart0_TX()

    {
    volatile unsigned char cTmp;
    volatile unsigned char cByte;
    volatile unsigned char cPE;
    volatile unsigned char cPERx;    
    volatile bool FlgErr;
    volatile bool Flg1;
    volatile bool Flg2;
    volatile bool Flg3; 
    volatile int i;
    volatile int j;
    volatile int k;   

     //var++;  // test

     
 // Init variable                 
    Flg1 = false;   // BufTxPos = 0
    Flg2 = false;   // DSR = 0;
    Flg3 = false;   // CTS = 0;
    
  // Test status Flg1 for BufTxPos
      if ( TxBufPos <= 0 )
      {
        Flg1 = false;
        }
      else
      {
        Flg1 = true;
        };

  // Test status Flg2 for DSR signal
      cTmp = PORTC & (~(8));
      if (   cTmp == 0 )
      {
        Flg2 = false;
      }
      else 
      {
        Flg2 = true;
        };
  // Test status Flg3 for CTS signal  
        cTmp = PORTC & (~(2));
      if (   cTmp == 0 )
      {
        Flg3 = false;
      }
      else 
      {
        Flg3 = true;
        };
  // Calculate Z=(0..7)
       cTmp = 0;
       if ( Flg1 == true)
       cTmp = cTmp + 4;
       if (Flg2 == true)
       cTmp = cTmp + 2;
       if (Flg3 == true)
       cTmp = cTmp + 1;
       
    _PORTA = (unsigned char) cTmp;
// Execute events Z      
      switch(cTmp)
      {
      case 0:  // Z=0 Disable Tx interrupt       
      case 1:  // Z=1
      case 2:  // Z=2
      case 3:  // Z=3
      UCSR0B = UCSR0B & (~(0x40)); // TXCIE0 = 0 
      break;

      case 4:  // Z=4 Write Byte of BufTx
      cByte=TxBuf[TxBufPos-1];
      TxBufPos = TxBufPos - 1;

          switch(gl_parity) // Calculate 9 bit
          {
          case 0:
          // no 9 bit for Tx
          break;
          case 1:
          //  calculate 9 bit for Tx
              j=1;
              k=0;
              
                for (i=1;i<=8;i++)
                    {
                    cTmp = cByte & j;
                        if ( cTmp != 0)
                        {
                        k++;
                        };
                     j = j*2;   
                    };
                    
                cTmp = (char) (k % 2);
          //  Write 9 bit PE
                if ( cTmp == 0 )
                {
                UCSR0B = UCSR0B & ( ~(0x01));  // Tx 9 bit=0
                }
                else
                {
                UCSR0B = UCSR0B ^ (0x01);     // Tx 9 bit=1           
                };                
          break;
          case 2:
              j=1;
              k=0;
              
                for (i=1;i<=8;i++)
                    {
                    cTmp = cByte & j;
                        if ( cTmp != 0)
                        {
                        k++;
                        };
                     j = j*2;   
                    };
                    
                cTmp = (char) (k % 2);
          // write 9 bit PE
                if ( cTmp == 0 )
                {
                UCSR0B = UCSR0B ^ ( 0x01 );  // Tx 9 bit=1
                }
                else
                {
                UCSR0B = UCSR0B & (~(0x01)); // Tx 9 bit=0           
                };    
          break;     
          };
          UDR0 = cByte;  // Transmit Byte and 9 bit

      break;

      case 5:  // Z=5 Wait CTS=0
      case 6:  // Z=6 Wait DSR=0
      case 7:  // Z=7 Wait CTS=0 and DSR=0
      // ?? What must enable interrupt
      break;
      };
 };

//*******************************
// This method interrupt event TX 
#pragma vector=UART0_UDRE_vect 
    static __interrupt void   Uart0_UDRE()
    {
    _PORTA = Test; // test
      Test++;
     UDR0 = '4'; 
     };
     
private:
    // Registrs for UART0
    volatile char TempVar ;
    static volatile __io unsigned char PORTC @ 0x15 ;
    static volatile __io unsigned char DDRC  @ 0x14 ;
    static volatile __io unsigned char PINC  @ 0x13 ;        
    static volatile __io unsigned char UCSR0A @ 0x0B ;
    static volatile __io unsigned char UCSR0B @ 0x0A ;
    static volatile __io struct
        { unsigned char uh0:4 ,
                        uh1:4 ;
        } UBRRHI @ 0x20;  
    static volatile __io unsigned char UBRR0  @ 0x09 ;
    static volatile __io unsigned char UDR0   @ 0x0C ; 
 };   


 /***********************************
 *    Base class implementation    *
 ***********************************/
//-----------------------------------
// Declare function
  void Uart0Baseclass::InitUart(unsigned int speed, unsigned int parity )
  {
    volatile unsigned char cTmp;
    volatile bool FlErr;
    volatile unsigned long  lTmp;
    volatile unsigned int  i;
    
    //-----------------------
    // Disable all interrupts
    //__disable_interrupt();

    //--------------------
    // Disable Tx and Rx
    // ?? disable interrupt UART0, Clear Errors Tx/Rx, Clear UDR
    UCSR0A = 0x20;  // reset UART Control and Status Registers A
    UCSR0B = 0x02;  // reset UART Control and Status Registers B
    cTmp = UDR0  ;  // reset Errors Flags UART0 Rx

    //-----------------------
    // Resets out pins DTR0=1
    //                 RTS0=1
    cTmp = DDRC ^ ( 1+4 );   // Mode Pins to Out
    DDRC = cTmp; 
    cTmp = PORTC ^ ( 1+4 ); // Pins Out bits
    PORTC = cTmp ;

    //------------------------
    // Enable other interrupts
    //__enable_interrupt();  

    //------------------------
    // Erase Counter Errors
    for (i=1;i<=4;i++)
    {
    aErRx[i] = 0;
    }; 
    
    //-------------------- 
    // Set speed baud UART
    // ?? CASE (300...57600 bps) the calculate const
    // registers
    FlErr = true;  
    cTmp = UCSR0A & 0x02; 
    switch (speed)
      {
      case 300:
      case 600:
      case 1200:
      case 2400:
      case 4800:
      case 9600:
      case 19200:
      case 38400:
      case 57600:
      if ( cTmp == 0)
        {   // calculate UBR for On Speed Mode
         lTmp = (unsigned long)FQCK / 16 / (unsigned long)speed - 1;
         UBRR0 =(unsigned char)lTmp;                  // low byte UBR
         UBRRHI.uh0 = (unsigned char)(lTmp / 256);     // high byte UBR 
         }
      else
        {   // calculate UBR for Double Speed Mode 
         lTmp = (unsigned long)FQCK / 8 / (unsigned long)speed - 1;
         UBRR0 =(unsigned char)lTmp;                  // low byte UBR
         UBRRHI.uh0 = (unsigned char)(lTmp / 256);     // high byte UBR 
         };   
      break;
      default:
        // if error speed store old speed
        FlErr = false;
      };
      if ( FlErr == true )
        {
        gl_speed = speed; 
        };
        
    //---------------------------------------------
    // Set control parity chek
    // For parity=0  no check parity bit9=(1 or 0);
    //     parity=1  check parity set bit9
    //     parity=2  check no parity set bit9
    FlErr = true;  
    // ?? CASE (0,1,2) the calculate parity
    switch (parity)
      {
      case 0:
      cTmp = UCSR0B;                // read Status 
      cTmp = cTmp & (~( 4 + 1 ) );  // Tx/Rx Mode 8 bits and 9 bits = 0
      UCSR0B = cTmp;     
      break;
      case 1:
      case 2:
      cTmp = UCSR0B;        // read Sattus 
      cTmp = cTmp ^ ( 4 + 1 );  // Tx/Rx Mode 9 bits and 9 bits = 1
      UCSR0B = cTmp;
      break;
      default:
        // if error parity store old parity
        FlErr = false;
      };
      if ( FlErr == true )
        {
        gl_parity = parity; 
        };
        
        //----------------------------------
        // Enable iterrupts Tx/Rx
        // Sets bits Rts0 and Dtr0 for UART0

        //      RXCIE0,TXCIE0,RXEN0,TXEN0=1 
        UCSR0B = UCSR0B ^ ( 128+64+16+8);  //

        PORTC = PORTC & (~(4+1) ); // DTR=0 and RTS=0 Pins Out bits
 }

//-----------------------------------
// Declare function
  void Uart0Baseclass::Clear()
  {
    // Clear All Registers for UART0 and Stop Resiverd/Transmits
    //__disable_interrupt();
    UCSR0A=0x20;
    UCSR0B=0x02;
    UBRRHI.uh0=0x00;
    UBRR0=0x0;
    TempVar = UDR0; // Clear ERROR Resiverd
    //__enable_interrupt();
 }

//-----------------------------------
// Declare function
  void Uart0Baseclass::ClearRxBuf() 
  {
  unsigned int i;
  //?? Define disable Rx interrupt
  //__disable_interrupt();
  for (i=0; i <= BufLen-1 ; i++)
    {RxBuf[i]=0xFF;
     RxBufPos=0 ;
    }
  //__enable_interrupt();
  }

//-----------------------------------
// Declare function
  void Uart0Baseclass::WrByteRxBuf(unsigned char Byte) 
{
  //__disable_interrupt();
    if ( RxBufPos >= (BufLen) )
    ;
    else
      { 
      RxBuf[RxBufPos] = Byte;
      RxBufPos = RxBufPos + 1 ;
      };
  //__enable_interrupt();  
 }

//-----------------------------------
// Declare functi-on
bool Uart0Baseclass::B_RxBuf(void)
{
  bool Flag;
  //__disable_interrupt();
  if ( RxBufPos <= 0 )
    {
    Flag = true;
    RxBufPos = 0;
    }
  else
    {
    Flag = false;
   //__enable_interrupt();
     };
  return ( Flag);
}    

//-----------------------------------
// Declare functi-on
  unsigned char Uart0Baseclass::RdByteRxBuf(void) 
{
 unsigned char Byte;
  //__disable_interrupt();
  if ( (BufLen - RxBufPos) > 2 )
    {
     PORTC = PORTC & (~ 1 ); // RTS0=0 Pins Out bits Enable Tx from PC
    };
 
  if ( RxBufPos == 0 )
  ;
  else
      { 
      Byte=RxBuf[RxBufPos-1];
      RxBufPos = RxBufPos - 1;
      }; 
  //__enable_interrupt() ;
return (Byte);
}

//-----------------------------------
// Declare functi-on
bool Uart0Baseclass::E_RxBuf(void)
{
  bool Flag;
  //__disable_interrupt();
  if ( RxBufPos >= (BufLen) )
    {
    Flag = true;
    RxBufPos = BufLen;
    }
  else
    {
    Flag = false;
  //__enable_interrupt();
    };
  return ( Flag);
} 

//-----------------------------------
// Declare function
  void Uart0Baseclass::ClearTxBuf() 
  {
  unsigned int i;
  //?? Define disable Rx interrupt
  //__disable_interrupt();
  for (i=0; i <= BufLen-1 ; i++)
    {TxBuf[i]=0xFF;
     TxBufPos=0;
    }
  //__enable_interrupt();
  }

//-----------------------------------
// Declare function
  void Uart0Baseclass::WrByteTxBuf(unsigned char Byte) 
{
  //__disable_interrupt TXCIE0;
  UCSR0B = UCSR0B & ~(0x40); // TXCIE0 =0 Disable interrupt Tx Complet

    if ( TxBufPos >= (BufLen) )
      ; // ErrTx Buffer Full
    else
      {
        TxBuf[TxBufPos] = Byte;
        TxBufPos = TxBufPos + 1 ;
          
          if (TxBufPos == 1 ) // yes primary byte in BufTx
            {
            TxBufPos = TxBufPos - 1 ;      
            UDR0 = Byte; 
            UCSR0B = UCSR0B & ~(0x40); // TXCIE0 =0 Disable interrupt Tx Complet
            } 
          else 
            {
              if ( TxBufPos != 0 )
              {
              //__enable_interrupt TXC0; 
              UCSR0B = UCSR0B ^ (0x40); // TXCIE0 =1 Enable interrupt Tx Complete      
              };
            };
     }; 

 }

//-----------------------------------
// Declare functi-on
  unsigned char Uart0Baseclass::RdByteTxBuf(void) 
{
 unsigned char Byte;
  //__disable_interrupt TXCIE0;
  UCSR0B = UCSR0B & ~(0x40); // TXCIE0 =0 Disable interrupt Tx Complet

  if ( TxBufPos == 0 )
  ;
  else
      { 
      Byte=TxBuf[TxBufPos-1];
      TxBufPos = TxBufPos - 1;
      }; 
  //__enable_interrupt TXC0; 
     UCSR0B = UCSR0B ^ (0x40); // TXCIE0 =1 Enable interrupt Tx Complete
return (Byte);
}

//-----------------------------------
// Declare functi-on
bool Uart0Baseclass::B_TxBuf(void)
{
  bool Flag;
  //__disable_interrupt TXCIE0;
  UCSR0B = UCSR0B & ~(0x40); // TXCIE0 =0 Disable interrupt Tx Complet
  if ( TxBufPos <= 0 )
    {
    Flag = true;
    TxBufPos = 0;
    }
  else
    {
    Flag = false;
  //__enable_interrupt TXC0; 
     UCSR0B = UCSR0B ^ (0x40); // TXCIE0 =1 Enable interrupt Tx Complete
     };
  return ( Flag);
}    

//-----------------------------------
// Declare functi-on
bool Uart0Baseclass::E_TxBuf(void)
{
  bool Flag;
  //__disable_interrupt TXCIE0;
  UCSR0B = UCSR0B & ~(0x40); // TXCIE0 =0 Disable interrupt Tx Complet
  if ( TxBufPos >= (BufLen) )
    {
    Flag = true;
    TxBufPos = BufLen;
    }
  else
    {
    Flag = false;
  //__enable_interrupt TXC0; 
     UCSR0B = UCSR0B ^ (0x40); // TXCIE0 =1 Enable interrupt Tx Complete
    };
  return ( Flag);
} 
//================================
// test function
void Uart0Baseclass::testfunc(void)
    {
    ;
    }
 
/***********************************
 *    Derived class declaration    *
 ***********************************/
class Uart0 : public Uart0Baseclass
{
public:
  static volatile  unsigned char test ;
};

//************************
// Declaration functions *
//************************

// This method interrupt event TX 
#pragma vector=INT1_vect 
static __interrupt void   Ext_INT1(void)
{
  //_PORTA = UCSR0A;
   _PORTA = var;
   FlgPrint = true;
}

void main()
{
volatile unsigned char iVar = '0';


static volatile __io unsigned char DDRA  @ 0x1A ;
static volatile __io unsigned char PINA  @ 0x19 ;

//*******************************

  //**********************
  // Full reset UART
  Uart0 UartTest;               // Define new type UartTest 
  UartTest.Clear();             // Erase all registers and 
                                // disable interrupts UART0 
  UartTest.ClearRxBuf();        // Erase Buffer Rx
  UartTest.ClearTxBuf();        // Erase Buffer Tx
  UartTest.InitUart(gl_speed, gl_parity);
                                // Sets speed, mode parity UART0
                                // and enable interrupt UART0 Tx and Rx 
                            
  //***********************
  // Proramm 
  DDRA = 0xff;          // Port A  all pins Output

  iVar = _GIMSK ^ 0x80; // Enable INT1
  _GIMSK = iVar;
  _PORTD = _PORTD ^ 0x08 ;   // Port D pin INT1 Input 
  _PORTA = 0x55;
  UCSR0A = UCSR0A ^ 0x40;   // Erase Bit TXC0=0 !!
  //UCSR0B = UCSR0B ^ (0x40); // TXCIE0 =1 Enable interrupt Tx Complete
  __enable_interrupt();


  //UDR0 = '5';


 loop:

   
  //__disable_interrupt();

  //if ( UartTest.E_TxBuf() != true  )
  //  {
  // UartTest.WrByteTxBuf('1');
  //  UartTest.WrByteTxBuf('2');
  //  UartTest.WrByteTxBuf('3');
  //  };



  //======================================================
  // Test On  Read Byte from UART0 and Write Bute to UART0
  // Connect signals DTR,RTS,CTS,DTS
 
  //do
  //_PORTA ++;
  //while ( (UCSR0A & 0x40) == 0 );
  //UCSR0A = UCSR0A ^ (0x40);


  if ( UartTest.B_RxBuf() != true  )
    {
    cTest = UartTest.RdByteRxBuf();
    };

  if ( UartTest.E_TxBuf() != true  )
    {
    UartTest.WrByteTxBuf(cTest);
    }
  else
    {
    aErTx[4]++;   // Error Buf Tx full 
    };

  // Test FlgPrint for print table errors Rx and Tx
    if (FlgPrint == true)
    {
    // Print Table
        // R1
        if ( UartTest.E_TxBuf() != true  )
        {
        UartTest.WrByteTxBuf('R');
        };
        if ( UartTest.E_TxBuf() != true  )
        {
        UartTest.WrByteTxBuf('1');
        };
        if ( UartTest.E_TxBuf() != true  )
        {
        UartTest.WrByteTxBuf('=');
        };
        if ( UartTest.E_TxBuf() != true  )
        {
        cTest = (unsigned char) ( aErRx[1] / 256 );
        UartTest.WrByteTxBuf(cTest);
        };
        if ( UartTest.E_TxBuf() != true  )
        {
        cTest = (unsigned char) ( aErRx[1] % 256 );
        UartTest.WrByteTxBuf(cTest);
        };                        
    //
    FlgPrint = false;
    };
  // ?? module test 2
  goto loop;  
}
