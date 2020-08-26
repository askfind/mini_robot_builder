/*********************************************
* Programm:       UART0_A1x.c                *
*                                            *
*  Note:  For projekt MINIROBIT BUILDING     *
*                                            *
* Name:  Module Code adapted from Atmel AVR  *
*        Application for Amega161            *
*        Interrupt mode driver for UART0.    *
*                                            *
* Edit data:     27.08.2002                  *
* Last data:     09.09.2002                  *
* Version:       0.01                        *
**********************************************/

#include "iom161.h"
#include "uart0_A1x.h"
#include "uart0_A1x_decl.h"
#include "stdio.h"

/* Debug test UART0 for module */
#define TEST_UART0


/*---------------------*/
/*  Start Rx/Tx UART0  */
void  Enb_UART0(void)       // Enable  Rx/Tx
{
  UCSR0B = UCSR0B | (1<<TXEN0);  // TXEN0 = 1
  UCSR0B = UCSR0B | (1<<RXEN0);  // RXEN0 = 1  
  UCSR0B = UCSR0B | (1<<RXCIE0); // RXCIE0= 1
}
/*-------------------*/
/*  Start Rx UART0  */
void  Enb_Rx_UART0(void)       // Enable  Rx
{
  UCSR0B = UCSR0B | (1<<RXEN0);  // RXEN0 = 1  
  UCSR0B = UCSR0B | (1<<RXCIE0); // RXCIE0= 1
}

/*-------------------*/
/*  Start Tx UART0  */
void  Enb_Tx_UART0(void)       // Enable  Tx
{
  UCSR0B = UCSR0B | (1<<TXEN0);  // TXEN0 = 1
}
/*--------------------*/
/*  Stop Rx/Tx UART0  */
void  Dis_UART0(void)       // Disable  Rx/Tx
{
  UCSR0B = UCSR0B & ~(1<<TXEN0);  // TXEN0 = 0
  UCSR0B = UCSR0B & ~(1<<RXEN0);  // RXEN0 = 0  
  UCSR0B = UCSR0B & ~(1<<RXCIE0); // RXCIE0 = 0
}

/*------------------*/
/*  Stop  Rx UART0  */
void  Dis_Rx_UART0(void)       // Disable  Rx
{
  UCSR0B = UCSR0B & ~(1<<RXEN0);  // RXEN0 = 0  
  UCSR0B = UCSR0B & ~(1<<RXCIE0); // RXCIE0 = 0
}

/*--------------------*/
/*  Stop   Tx UART0  */
void  Dis_Tx_UART0(void)       // Disable  Tx
{
  UCSR0B = UCSR0B & ~(1<<TXEN0);  // TXEN0 = 0
}


/*--------------------------------*/
/*  Copy Sets Variable UART0 mode */
void  CopySetsROM_UART0(void)       // Sets is Default
      {
  SpeedBaud_UART0 = fSpeedBaud_UART0;            
  ModeU2X0 = fModeU2X0;        
  ModeCHR90 = fModeCHR90;        
  CheckParity_UART0 = fCheckParity_UART0;
  SizeBit_UART0 = fSizeBit_UART0;
  ContrStream_UART0 = fContrStream_UART0;
  Enb_DTR0 = fEnb_DTR0;         
  Bit_DTR0 = fBit_DTR0;         
  Enb_DSR0 = fEnb_DSR0;         
  Bit_DSR0 = fBit_DSR0;         
  Enb_RTS0 = fEnb_RTS0;         
  Bit_RTS0 = fBit_RTS0;         
  Enb_CTS0 = fEnb_CTS0;         
  Bit_CTS0 = fBit_CTS0;         
  Sym_XON = fSym_XON;         
  Sym_XOFF= fSym_XOFF;         
  Enb_XON_XOFF_Tx_UART0 = fEnb_XON_XOFF_Tx_UART0;
  Count_XOFF_Tx_UART0 = fCount_XOFF_Tx_UART0;
  Enb_XON_XOFF_Rx_UART0 = fEnb_XON_XOFF_Rx_UART0;
  Count_XOFF_Rx_UART0 = fCount_XOFF_Rx_UART0;
  Enb_Echo_UART0 = fEnb_Echo_UART0 ;  
  ModeMPCM0 = fModeMPCM0;        
  Enb_Err_UART0 = fEnb_Err_UART0;    
  }

/*--------------------------------*/
/*  Copy Sets Variable UART0 mode */      
void  CopySetsEEPROM_UART0(void)    // Sets is Profile EEPROM
      {}

/*------------------*/
/*  Init UART0 mode */
void    Init_S_UART0  ( unsigned int SpeedBaund )  // speed  UART0
        {
    volatile char FlagErr;
    volatile unsigned char cTmp;
    volatile unsigned long lTmp;

    Dis_UART0();        
    FlagErr = 1; // Set Flag Error  
    cTmp = UCSR0A & 0x02; // Real bit mode U2X0 in reg UCSR0A 
    switch (SpeedBaund)
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
         lTmp = (unsigned long)FQCK / 16 / (unsigned long)SpeedBaund - 1;
         UBRR0 =(unsigned char)lTmp;                  // low byte UBR
         UBRH.uh0 = (unsigned char)(lTmp / 256);     // high byte UBR 
         }
      else
        {   // calculate UBR for Double Speed Mode 
         lTmp = (unsigned long)FQCK / 8 / (unsigned long)SpeedBaund - 1;
         UBRR0 =(unsigned char)lTmp;                  // low byte UBR
         UBRH.uh0 = (unsigned char)(lTmp / 256);     // high byte UBR 
         };
      SpeedBaud_UART0 = SpeedBaund;      
      break;
      default:
        // if error speed store old speed
        FlagErr = 0;
      break;
      };
    Enb_UART0();   
    }

void    Init_2S_UART0 ( unsigned char ModeU2X0 )        // baud*2 UART0
        {
        Dis_UART0();
        if ( ModeU2X0 == 0)          // if ModeU2X0=0 then U2X0=0
          {                          // else U2X0=1
          UCSR0A = UCSR0A & ~(0x02);
          Init_S_UART0(SpeedBaud_UART0); // UART0 is 1*SpeedBaund    
          }
        else
          {
          UCSR0A = UCSR0A & ~(0x02);
          Init_S_UART0(SpeedBaud_UART0);
          UCSR0A = UCSR0A | (0x02); // UART0 is 2*SpeedBaund     
          };
        Enb_UART0();  
        }  
void    Init_P_UART0  ( unsigned char Parity ) // control parity
        {
        Dis_UART0();
        switch ( Parity )
          {
          case 0:
          Init_CHR9_UART0(0); // Mode 8 bits
          CheckParity_UART0 = Parity;
          break;
          case 1:
          case 2:
          case 3:
          case 4:
          CheckParity_UART0 = Parity;
              switch ( SizeBit_UART0 )
                    {
                    case 0:
                    Init_CHR9_UART0(0); // Mode 8 bits
                    case 1:
                    Init_CHR9_UART0(1); // Mode 9 bits
                    break;
                    default:
                    Init_CHR9_UART0(0); // Mode 8 bits
                    break;
                    };  
          break;
          default:
          CheckParity_UART0 = 0;
          Init_CHR9_UART0(0); // Mode 8 bits
          break;
          };
        Enb_UART0();  
        }

void    Init_B_UART0  ( unsigned char SizeBit )
        {
        Dis_UART0();
        switch ( SizeBit )
          {
          case 0:
          case 1:
          SizeBit_UART0 = SizeBit;
          break;
          default:
          SizeBit_UART0 = 1;    // SizeBit 8 bits
          break;
          };
        Enb_UART0();  
        }        

void    Init_CHR9_UART0 ( unsigned char Mode )     // Rx/Tx 8 or 9 bits
        {
        switch ( Mode)
          {
          case 0:
            UCSR0B = UCSR0B & ~(0x04); // Mode 8 bit Rx/Tx
            UCSR0B = UCSR0B & ~(0x01); // Set 9 bit = 0 
            ModeCHR90 = Mode;
          break;
          case 1:
            UCSR0B = UCSR0B | (0x04); // Mode 9 bit Rx/Tx
            UCSR0B = UCSR0B | (0x01);  // Set 9 bit = 1
            ModeCHR90 = Mode;
          break;
          default:
            UCSR0B = UCSR0B & ~(0x04); // Mode 8 bit Rx/Tx
            UCSR0B = UCSR0B & ~(0x01); // Set 9 bit = 0 
            ModeCHR90 = 0;
          break;
          };
        }
        
void    Init_MPCM_UART0 ( unsigned char ModeMPCM0 )     // Mode Multi-processor Com port
        {
        Dis_UART0();
        if ( ModeMPCM0 == 0)
        {
       UCSR0A = UCSR0A & ~(0x01); // Mode MPCM0 for Rx/Tx
        }
        else
        {
       UCSR0A = UCSR0A | (0x01); // Mode MPCM0 for Rx/Tx
        };
        Enb_UART0();        
        }

/*------------------------------------------*/
/*               Reset UART                 */
void  Reset_UART0 ( void )   // Reset UART0 Status A1x.y0
      {
    volatile unsigned char cTmp;
    volatile int i;
    /* Sets out pins   DTR0=1, RTS0=1 */
    cTmp = DDRC ^ ( 1+4 );   // Mode Pins to Out
    DDRC = cTmp; 
    cTmp = PORTC ^ ( 1+4 ); // Pins Out bits
    PORTC = cTmp ;
    /* Programm state SYSTEM RESET */ 
    UCSR0B=0x02;              // Disable UART0 Rx/Tx
    cTmp = UDR0;              // Clear ERROR Resiverd
    UCSR0A=0x20;              // Erase Errors
    UBRH.uh0=0x00;           
    UBRR0=0x0;
    /* Erase all variables  */
    /* Erase Buffer Tx */
    for (i=1;i<=TX_BUFFER_SIZE_UART0;i++)
      {
      TxBuf_UART0[i] = 0;         // Buffer Tx Erase
      };
    TxHead_UART0 = 0;             // Head Top
    TxTail_UART0 = 0;             // Tail Top
    /* Erase Buffer Rx */   
    for (i=1;i<=RX_BUFFER_SIZE_UART0;i++)
      {
      RxBuf_UART0[i] = 0;         // Buffer Rx Erase
      };        
    RxHead_UART0 = 0;             // Head Top
    RxTail_UART0 = 0;             // Tail Top
    /* Erase Array Errors Rx/Tx */
    for (i=1;i<=Rx_Tx_Err_SIZE_UART0;i++)
      {
      Rx_Tx_Err_UART0[i] = 0;         // Array Rx_Tx_Err Erase
      }; 
    /* Erase variables */
    Count_Rx_UART0 = 0;
    Count_Tx_UART0 = 0;
    Count_Rx_Err_UART0 = 0;    
    Count_Tx_Err_UART0 = 0;
    /*  */
    SpeedBaud_UART0 = 0;
    ModeU2X0 = 0;
    ModeCHR90 = 0;
    CheckParity_UART0 = 0;
    SizeBit_UART0 = 1;
    ContrStream_UART0 = 0;    
    Enb_DTR0 = 0;
    Bit_DTR0 = 1;
    Enb_DSR0 = 0;
    Bit_DSR0 = 1;
    Enb_RTS0 = 0;
    Bit_RTS0 = 1;
    Enb_CTS0 = 0;
    Bit_CTS0 = 1;
    Enb_XON_XOFF_Tx_UART0 = 0;
    Count_XOFF_Tx_UART0 = 0;
    Enb_XON_XOFF_Rx_UART0 = 0;
    Count_XOFF_Rx_UART0 = 0;
    Enb_Echo_UART0 = 0;
    ModeMPCM0 =0;
    /********************/
    /* New status A1x.y */
    A1x_y = 0;      //  y0 for UART0
    /*----------------*/
    /* ? status A2x ? */
    switch( A2x_y)
    {
      case 1: // if A2x_y == y1 Copy sets from EEPROM
      CopySetsEEPROM_UART0(); 
      break;
      case 2: // if A2x_y == y2 Copy sets from ROM
      CopySetsROM_UART0();      
      break;
      default:
       ;  // Error! "No status A2x"
      break;
      }; 
    /********************/
    /* New status A1x.y */
    A1x_y = 1;      //  y1 for UART0
    /*- ----------------*/
    /* Calculator BAUD  */
    Init_S_UART0(SpeedBaud_UART0); 
 
    /*--------------------*/
    /* Enable Rx/Tx UART0 */ 
  
    // ?? DTR0,RTS0 and enable

    /********************/     
    /* New status A1x.y */
    A1x_y = 2;      //  y2 for UART0
    
    /*--------------------*/
    /* Enable Rx/Tx UART0 */ 
    /********************/
    /* New status A1x.y */
    A1x_y = 3;      //  y3 for UART0
 
    }
    
/*-------------------------------------------*/
/* "Enable_Err_Count_UART0" Enable counter   */
/*         errors for Tx_Rx  UART            */
void   Enable_Err_Count_UART0 ( void )    // Enb_Err_UART0 = 1
    {
    unsigned int i;
    Dis_UART0();
    /* Erase Array Errors Rx/Tx */
    for (i=1;i<=Rx_Tx_Err_SIZE_UART0;i++)
      {
      Rx_Tx_Err_UART0[i] = 0;         // Array Rx_Tx_Err Erase
      }; 
    /* Erase variables */
    Count_Rx_UART0 = 0;
    Count_Tx_UART0 = 0;
    Count_Rx_Err_UART0 = 0;    
    Count_Tx_Err_UART0 = 0;
    /*  */
    Enb_Err_UART0 = 1;   
    Enb_UART0();
    }

/*---------------------------------------------*/
/* "Disable_Err_Count_UART0" Disable counter   */
/*        errors for Tx_Rx  UART               */
void   Disable_Err_Count_UART0 ( void )   // End_Err_UART0 = 0
    {
    Enb_Err_UART0 = 0;    
     }
     
/*-------------------------------*/
/* Read Arry Tx_Rx_Err for UART  */
int    Read_Tx_Rx_Err_UART0 ( void )    // Type strings table Error
     {
static volatile unsigned int Arr_Tmp[Rx_Tx_Err_SIZE_UART0];
unsigned int i;
volatile unsigned int iT;

    /* Rear for Arr Errors */
    for (i=1;i<=Rx_Tx_Err_SIZE_UART0;i++)
      {
      Arr_Tmp[i] = Rx_Tx_Err_UART0[i];
      };
    iT = printf(" \n\r");
    iT = printf("Table Errors Rx/Tx:");
    iT = printf("  ");
    iT = printf("%d", Arr_Tmp[1]);
    iT = printf("  ");
    iT = printf("%d", Arr_Tmp[2]);
    iT = printf("  ");
    iT = printf("%d", Arr_Tmp[3]);
    iT = printf("  ");
    iT = printf("%d", Arr_Tmp[4]);
    iT = printf(" \n\r");
    iT = printf("Table Counters  Rx:");
    iT = printf("  ");
    iT = printf("%ld", Count_Rx_UART0);
    iT = printf("  ");
    iT = printf("%ld", Count_Rx_Err_UART0);            
    iT = printf(" \n\r");
    return 0;                          // if int = -1 ERROR
     }

/*-----------------------------*/
/*  Control stream  UART0 mode */      
void   ControlStream_ON_UART0( void )
{
    ContrStream_UART0 = 1;
}

/*-----------------------------*/
/*  Control stream  UART0 mode */      
void   ControlStream_OFF_UART0( void )
{
    ContrStream_UART0 = 0;
}


/*-------------------------*/
/* "Echo On UART0"         */
void   Echo_ON_UART0( void )   // Set Echo = 1 Mode 'ON'      
      {
      Enb_Echo_UART0 = 1;
      }
      
/*- -------------------------*/
/* "Echo OFF UART0"          */
void   Echo_OFF_UART0( void )  // Set Echo = 0 Mode 'OFF'
      {
      Enb_Echo_UART0 = 0;      
      }

/*-------------------------*/
/* "Break UART0" for UART  */
void   Break_UART0( void )    // Set pin AVR TXD = MARK ( Low )
      {}

/*---------------------------------*/
/*  "DTR ON CONTROLL UART0"        */
void     DTR_ON_CONTR_UART0( void )     // Control DTR ON
      {
      Enb_DTR0 = 1;
      }

/*---------------------------------*/
/*  "DTR OFF CONTROL UART0"        */
void     DTR_OFF_CONTR_UART0( void )    // Control DTR OFF
      {
      Enb_DTR0 = 0;
      }      

/*---------------------------------*/
/*  "DTR SET UART0"                */
void     DTR_SET_UART0( void )          // Set signal DTR = 1
      {
      Bit_DTR0 = 1;
      PORT_FLOW_D = PORT_FLOW_D | ( 1<< DTR0 ); // Pin port output  
       if ( Bit_DTR0 & 0x01 == 0)
       {
       ClrBit( PORT_FLOW_O, DTR0); // pin output set low 0
       }
       else
       {
       SetBit( PORT_FLOW_O, DTR0); // pin output set high 1
       };      
      }

/*---------------------------------*/
/*  "DTR CLR UART0"                */
void     DTR_CLR_UART0( void )          // Set DTR = 0
      {
      Bit_DTR0 = 0;
      PORT_FLOW_D = PORT_FLOW_D | ( 1<< DTR0 ); // Pin port output  
       if ( Bit_DTR0 & 0x01 == 0)
       {
       ClrBit( PORT_FLOW_O, DTR0); // pin output set low 0
       }
       else
       {
       SetBit( PORT_FLOW_O, DTR0); // pin output set high 1
       };
      }      

/*-----------------------------*/
/* "RTS_ON_CONTR_UART0"        */
void     RTS_ON_CONTR_UART0( void )    // Control RTS ON
      {
      Enb_RTS0 =1;
      }
      
/*-----------------------------*/
/*  "RTS_OFF_CONTR_UART0"      */
void     RTS_OFF_CONTR_UART0( void )   // Control RTS OFF
      {
      Enb_RTS0 =0;
      }
      
/*------------------------------*/
/*  "RTS_SET_UART0"             */
void     RTS_SET_UART0( void )        // Set RTS = 1
       {
      Bit_RTS0 = 1;
      PORT_FLOW_D = PORT_FLOW_D  | ( 1<< RTS0 ); // Pin port output  
       if ( Bit_RTS0 & 0x01 == 0)
       {
       ClrBit( PORT_FLOW_O, RTS0); // pin output set low 0
       }
       else
       {
       SetBit( PORT_FLOW_O, RTS0); // pin output set high 1
       }; 
       }

/*------------------------*/
/*  "RTS_CLR_UART0"       */
void     RTS_CLR_UART0( void )         // Set RTS = 0
       {
      Bit_RTS0 = 0;
      PORT_FLOW_D = PORT_FLOW_D  | ( 1<< RTS0 ); // Pin port output  
       if ( Bit_RTS0 & 0x01 == 0)
       {
       ClrBit( PORT_FLOW_O, RTS0); // pin output set low 0
       }
       else
       {
       SetBit( PORT_FLOW_O, RTS0); // pin output set high 1
       };        
       }            

/*--------------------------*/
/*  "DSR_ON_CONTR_UART0"    */
void     DSR_ON_CONTR_UART0( void )    // Control DSR ON
      {
      Enb_DSR0 = 1;
      }

/*-------------------------*/
/* "DSR_OFF_CONTR_UART0"   */
void     DSR_OFF_CONTR_UART0( void )   // Control DSR OFF
      {
      Enb_DSR0 = 0;
      }
      
/*--------------------------*/
/*  "DSR_SET_UART0"         */
void     DSR_SET_UART0( void )         // Set DSR = 1
      {
      Bit_DSR0 = 1;
      }
      
/*---------------------*/
/*  "DSR_CLR_UART0"    */
void     DSR_CLR_UART0( void )         // Set DSR = 0
       {
       Bit_DSR0 = 0;
       }

/*--------------------------*/
/*  "CTS_ON_CONTR_UART0"    */
void     CTS_ON_CONTR_UART0( void )    // Control CTS ON
      {
      Enb_CTS0 = 1;
      }

/*-------------------------*/
/* "CTS_OFF_CONTR_UART0"   */
void     CTS_OFF_CONTR_UART0( void )   // Control CTS OFF
      {
      Enb_CTS0 = 0;
      }
      
/*--------------------------*/
/*  "CTS_SET_UART0"         */
void     CTS_SET_UART0( void )         // Set CTS = 1
      {
      Bit_CTS0 = 1;
      }
      
/*---------------------*/
/*  "CTS_CLR_UART0"    */
void     CTS_CLR_UART0( void )         // Set CTS = 0
       {
       Bit_CTS0 = 0;
       }

/*--------------------------------*/
/* "XON_XOFF_ON_CONTR_Rx_UART0"   */
void     XON_XOFF_ON_CONTR_Rx_UART0( void )  // XON/XOFF  Rx = 1 Enable
        {
        Count_XOFF_Rx_UART0 = 0;
        Enb_XON_XOFF_Rx_UART0 = 1;        
        }    

/*---------------------------------*/
/* "XON_XOFF_OFF_CONTR_Rx_UART0"   */
void     XON_XOFF_OFF_CONTR_Rx_UART0( void ) // XON/XOFF Rx = 0 Disable
        {
        Count_XOFF_Rx_UART0 = 0;
        Enb_XON_XOFF_Rx_UART0 = 0;        
        }
/*--------------------------------*/
/* "XON_XOFF_ON_CONTR_Tx_UART0"   */
void     XON_XOFF_ON_CONTR_Tx_UART0( void )  // XON/XOFF  Tx = 1 Enable
        {
        Count_XOFF_Tx_UART0 = 0;
        Enb_XON_XOFF_Tx_UART0 = 1;         
        }
        
/* "XON_XOFF_OFF_CONTR_Tx_UART0"   */
void     XON_XOFF_OFF_CONTR_Tx_UART0( void ) // XON/XOFF Tx = 0 Disable
        {
        Count_XOFF_Tx_UART0 = 0;
        Enb_XON_XOFF_Tx_UART0 = 0;         
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

/****************************/
/* Read and write functions */
unsigned char ReceiveByte_UART0( void )
        {
        unsigned char tmptail;
        unsigned char cByte;
      
        while ( RxHead_UART0 == RxTail_UART0 ) /* wait for incomming data */
                ;
        tmptail = ( RxTail_UART0 + 1 ) & RX_BUFFER_MASK_UART0;/* calculate buffer index */
        RxTail_UART0 = tmptail; /* store new index */
        cByte = RxBuf_UART0[tmptail];
      
        return cByte; /* return data */
        }

void TransmitByte_UART0( unsigned char data )
        {
        unsigned char tmphead;
        /* calculate buffer index */
        tmphead = ( TxHead_UART0 + 1 ) & TX_BUFFER_MASK_UART0;
                /* wait for free space in buffer or Enable Transmit */
        while ( tmphead == TxTail_UART0 )
                ;
        TxBuf_UART0[tmphead] = data; /* store data in buffer */
        TxHead_UART0 = tmphead; /* store new index */
        UCSR0B |= (1<<UDRIE0); /* enable UDRE interrupt */
        }

unsigned char DataInReceiveBuffer( void )
        {
        return ( RxHead_UART0 != RxTail_UART0 );
                /* return 0 (FALSE) if the receive buffer is empty */
        }
/******************/
/* New putchar    */       

int putchar(int ch)
{
/*
        put your own putchar-function here
*/

  TransmitByte_UART0((unsigned char) ch);
  return ch;
}

/*************************************/
/* Function interrupt UART0_RX(void) */
#pragma vector=UART0_RX_vect
static __interrupt void UART0_RX(void)
  {  
    unsigned char tmphead;
    unsigned char cTmp;
    unsigned char cByte;
    unsigned char cPERx;
    volatile unsigned char FlgErr;
    volatile int dTest;

/* if enable flow control stream */
      switch (ContrStream_UART0)
       {
        case 0:
        break;
        default:
          switch (Enb_DTR0)
            {
            case 1:
            PORT_FLOW_D = PORT_FLOW_D | ( 1<< DTR0 ); // Pin port output  
              if ( Bit_DTR0 & 0x01 == 0)
              {
              ClrBit( PORT_FLOW_O, DTR0); // pin output set low 0 
              }
              else
              {
              SetBit( PORT_FLOW_O, DTR0); // pin output set high 1
              };
            break;
            default:
            break;
            };
        break;
       };    

      switch (ContrStream_UART0)
       {
        case 0:
        break;
        default:
          switch (Enb_DSR0)
            {
            case 1:
            PORT_FLOW_D = PORT_FLOW_D & ~( 1<< DSR0 ); // Pin port input  
            Bit_DSR0 = ( (PORT_FLOW_I & ( 1<<DSR0)) >> DSR0 ); // Calculate bit
            break;
            default:
            break;
            };
          switch (Enb_CTS0)  
            {
            case 1:
            PORT_FLOW_D = PORT_FLOW_D & ~( 1<< CTS0 ); // Pin port input  
            Bit_CTS0 = ( (PORT_FLOW_I & ( 1<<CTS0)) >> CTS0 ); // Calculate bit    
            break;
            default:
            break;
            };
        break;
       };
    
    FlgErr = 0;  //  if FlgErr=0 then  NO Errors Rx    

    //cTmp = UCSR0A & 0x10;  // Test bit FE0=?
    if ( (UCSR0A & 0x10) != 0 )
      {
      FlgErr = 1;         // '1' - Rx byte yes Error
      IncErrArr_UART0(1); // increment Rx_Tx_Err_UART0[1] 
      };
          
     cByte = UDR0;                  // Read Byte Rx from UDR0

    //cTmp = UCSR0A & 0x08; // Test bit OE0=?       
     if ( (UCSR0A & 0x08 != 0) )  
      {
      FlgErr = 1;
      IncErrArr_UART0(2); // increment Rx_Tx_Err_UART0[2] 
          };

    /* Calcul Parity for cByte and comperate Bit Parity   */
    switch ( SizeBit_UART0)
     {
     case 0:    // Size 7 bits
     cTmp = CheckParity7( cByte) ;
     cPERx = cByte & (1<<7);  // Read 8 Bit cByte Rx
     cPERx = (cPERx>>7);      // cPERx = 0 or 1 
     break;
     case 1:
     cTmp = CheckParity8( cByte) ;
     cPERx = (UCSR0B & 0x02) >> 1;  // Read 9 Bit Rx cPEx =0 or 1
     break;
     default:
     break;     
     };         
      /* return 
         if cTmp = 0   then parity cByte  
         if cTmp = 255 then no parity 
      cPEx =0 or 1
      */ 

       switch (CheckParity_UART0)
     {
     case 0:
     break;
     case 1:  // Parity E
     cTmp = cTmp & 0x01;
     if (cPERx != cTmp)
     {
     FlgErr =1;
     IncErrArr_UART0(3);   // increment Rx_Tx_Err_UART0[3]
     };
     break;
     case 2:  // Parity O
      cTmp = ~cTmp & 0x01;   
       if (cPERx != cTmp)
          {
          FlgErr =1;
          IncErrArr_UART0(3);   // increment Rx_Tx_Err_UART0[3]
          };
     break;
     case 3:
     if (cPERx != 1)  // Control Mark
     {
     FlgErr =1;
     IncErrArr_UART0(3);   // increment Rx_Tx_Err_UART0[3]
     };
     break;
     case 4:
     if (cPERx != 0)  // Control Space
     {
     FlgErr =1;
     IncErrArr_UART0(3);   // increment Rx_Tx_Err_UART0[3]
     };     
     break;
     default:
     break;     
     };
       
    /* Check buffer Rx */ 
     if ( FlgErr == 0 )  // No Errors for Rx
        {
        /* calculate buffer index */
        tmphead = ( RxHead_UART0 + 1 ) & RX_BUFFER_MASK_UART0;
  
        if ( tmphead == RxTail_UART0 )
                {
                IncErrArr_UART0(4); // increment Rx_Tx_Err_UART0[4] 
                }
        else
        RxHead_UART0 = tmphead; /* store new index */
        {
           switch (ContrStream_UART0) // Begin Switch ContrStream_UART0
                {
                 case 0:
                 break;
                 case 1:  // Yes control stream
                      if ( RxHead_UART0 > (RX_BUFFER_SIZE_UART0-4) )
                        {
                                  /* Signal DTR0 = 0 Stop Tx from PC IBM */
                                  /* if enable flow control stream */
                                  switch (Enb_RTS0)
                                  {
                                  case 1:
                                  PORT_FLOW_D = PORT_FLOW_D  | ( 1<< RTS0 ); // Pin port output  
                                  SetBit( PORT_FLOW_O, RTS0); // pin output set hing 1 
                                  Bit_RTS0 = 1;
                                  break;
                                  default:
                                  break;
                                  };
                         }
                       else
                       {
                                /* Signal DTR0 = 0 Stop Tx from PC IBM */
                                /* if enable flow control stream */
                                switch (Enb_RTS0)
                                 {
                                case 1:
                                PORT_FLOW_D = PORT_FLOW_D | ( 1<< RTS0 ); // Pin port output  
                                ClrBit( PORT_FLOW_O, RTS0); // pin output set high 1
                                Bit_RTS0 = 0;
                                break;
                                default:
                                break;
                                 };        

                       };  // End if                 
 
                      switch(Enb_XON_XOFF_Rx_UART0) // Begin Switch Enb_XON_XOFF_Rx_UART0
                        {
                        case 0:
                        break;
                        case 1:
                              if ( RxHead_UART0 > (RX_BUFFER_SIZE_UART0-4) )
                              {
                                  switch( Count_XOFF_Rx_UART0)
                                  {
                                  case 0:
                                  TransmitByte_UART0(Sym_XOFF);
                                  Count_XOFF_Rx_UART0++;
                                  break; 
                                  case 1:
                                  case 2:
                                  case 3:
                                  case 4:
                                  Count_XOFF_Rx_UART0++;  //increment counter 
                                  break;
                                  case 5:
                                  TransmitByte_UART0(Sym_XOFF);
                                  Count_XOFF_Rx_UART0 = 1;
                                  break;
                                  default:
                                  TransmitByte_UART0(Sym_XOFF);
                                  Count_XOFF_Rx_UART0 = 1;
                                  break;
                                  };
                              }
                              else
                              {
                                switch( Count_XOFF_Rx_UART0)
                                {
                                case 0:
                                break;  
                                default:
                                TransmitByte_UART0(Sym_XON);
                                Count_XOFF_Rx_UART0 = 0;
                                break;
                                };
                              };   
                        break;
                        default:
                        break;
                        };  //// End Switch ( Enb_XON_XOFF_Rx_UART0 )
                      
                 break;
                 default:
                 break;
                 };  // End Switch ( ContrStream_UART0 )
        };
        if ( FlgErr == 0)
        {      
        RxBuf_UART0[tmphead] = cByte; /* store received data in buffer */
          
          switch (ContrStream_UART0)
           {
           case 1:
             switch (Enb_XON_XOFF_Tx_UART0)
              {
              case 0:
              break;
              case 1:
                if ( cByte == Sym_XOFF)
                {
                Count_XOFF_Tx_UART0 = 1;  // Disable Transmit
                };
                if ( cByte == Sym_XON)
                {
                Count_XOFF_Tx_UART0 = 0;  // Enable Transmit
                };
              break;
              default:
              break;
              };
           break;
           default:
           break;
           }; 
        };

        /* if Mode Echo then Tx Byte*/
         if ( Enb_Echo_UART0 == 1)
         {
         TransmitByte_UART0(cByte);         
         };
        
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
/* End function interrupt UART0_RX(void) */
/*****************************************/


/****************************************/
/* This method interrupt event TX Empty */
#pragma vector=UART0_UDRE_vect
static __interrupt void UART0_UDRE(void)
    {
    unsigned char tmptail;
    unsigned char cTmp;
    unsigned char cByte;
    unsigned char cPEx;
    unsigned char EnbTx;
        
    EnbTx = 1;  // Yes Enable Tx    

/* if enable flow control stream for signal DTR0 */
      switch (ContrStream_UART0) // Begin  switch (ContrStream_UART0)
       {
        case 1:
          switch (Enb_DTR0)// Begin switch (Enb_DTR0)
            {
            case 1:
            PORT_FLOW_D = PORT_FLOW_D | ( 1<< DTR0 ); // Pin port output  
              if ( Bit_DTR0 & 0x01 == 0)
              {
              ClrBit( PORT_FLOW_O, DTR0); // pin output set low 0
               }
              else
              {
              SetBit( PORT_FLOW_O, DTR0); // pin output set high 1
              };
            break;
            default:
            break;
            };// End switch (Enb_DTR0)
        break;
        default:
        break;
       };// Begin  switch (ContrStream_UART0)

/* if enable flow control stream */
      switch (ContrStream_UART0) // Begin switch (ContrStream_UART0)
       {
        case 1:
          switch (Enb_RTS0)
            {
            case 1:
            PORT_FLOW_D = PORT_FLOW_D | ( 1<< RTS0 ); // Pin port output  
              if ( Bit_RTS0 & 0x01 == 0)
              {
              ClrBit( PORT_FLOW_O, RTS0); // pin output set low 0
               }
              else
              {
              SetBit( PORT_FLOW_O, RTS0); // pin output set high 1
              };
            break;
            default:
            break;
            };
        break;
        default:
        break;
       }; // End switch switch (ContrStream_UART0)   

    /* if enable flow control stream */
      switch (ContrStream_UART0)// Begin  switch (ContrStream_UART0) 
       {
        case 1:
          switch (Enb_DSR0)
            {
            case 1:
            PORT_FLOW_D = PORT_FLOW_D & ~( 1<< DSR0 ); // Pin port input  
            Bit_DSR0 = ( (PORT_FLOW_I & ( 1<<DSR0)) >> DSR0 ); // Calculate bit
            break;
            default:
            break;
            };
          switch (Enb_CTS0)  
            {
            case 1:
            PORT_FLOW_D = PORT_FLOW_D & ~( 1<< CTS0 ); // Pin port input  
            Bit_CTS0 = ( (PORT_FLOW_I & ( 1<<CTS0)) >> CTS0 ); // Calculate bit    
            break;
            default:
            break;
            };
        break;
        default:
        break;
       };// End  switch (ContrStream_UART0) 
    
    /* ?? Test Controls stream UART0 */
    
    switch ( ContrStream_UART0 )
      {
      case 1:
        if (Enb_XON_XOFF_Tx_UART0 == 1)
        {
          switch (Count_XOFF_Tx_UART0)
            {
            case 0:
            break;
            default:
            EnbTx = 0;  // Disable Tx software flow
            break;
            };
        };    
        if ( Enb_CTS0 == 1)
        {
          switch (Bit_CTS0)
            {
            case 1:
            EnbTx = 0;  // Disable Tx hardware flow
            break;
            default:
            break;
            };            
         };   
         if (Enb_DSR0 == 1)
         {
          switch (Bit_DSR0)
            {
            case 1:
            EnbTx = 0;  // Disable Tx hardware flow
            break;
            default:
            break;
            }; 
          };  
         if (Enb_RTS0 == 1)
         { 
          switch (Bit_RTS0)
            {
            case 1:
            EnbTx = 0;  // Disable Tx hardware flow
            break;
            default:
            break;
            };
          };  
          if (Enb_DTR0 == 1)
          {
          switch (Bit_DTR0)
            {
            case 1:
            EnbTx = 0;  // Disable Tx hardware flow
            break;
            default:
            break;
            };
          };                            
      break;
      default:
      break;
      }; 
       
#ifdef TEST_UART0
  DDRA  = 0xFF;
  PORTA = (unsigned char) ~( (Bit_DTR0<<3) | (Bit_RTS0<<2) | (Bit_CTS0<<1) | Bit_DSR0); //TxBuf_UART0[TxTail_UART0 + 1] ;
#endif        

     /* Enable Yes then  Transmit Byte */
     if ( EnbTx == 1 )
     {
        /* check if all data is transmitted */
        if ( TxHead_UART0 != TxTail_UART0 )
           {
           /* calculate buffer index */
           tmptail = ( TxTail_UART0 + 1 ) & TX_BUFFER_MASK_UART0;
           TxTail_UART0 = tmptail; /* store new index */
           cByte = TxBuf_UART0[tmptail];    // Byte for Tx UART0

           /* Calculate Parity for mode SizeBit */
          switch ( SizeBit_UART0)
              {
              case 0:
              cTmp = CheckParity7( cByte) ;
              break;
              case 1:
              cTmp = CheckParity8( cByte) ;
              break;
              default:
              cTmp = CheckParity8( cByte) ;
              break;     
              };         

           /* For Modes CheckParity_UART0 */
              switch (CheckParity_UART0)
              {
              case 0:
              break;
              case 1:
                if ( cTmp == 0) // cByte parity
                {
                 UCSR0B = UCSR0B & ~(1<<TXB80);  // TXB80 = 0
                }
                else
                {
                UCSR0B = UCSR0B | (1<<TXB80);   // TXB80 = 1
                };
              break;
              case 2:

                if ( cTmp == 0) // cByte parity
                {
                 UCSR0B = UCSR0B | (1<<TXB80);   // TXB80 = 1
                }
                else
                {
                 UCSR0B = UCSR0B & ~(1<<TXB80);  // TXB80 = 0                
                };  
              break;
              case 3: // Mark
              UCSR0B = UCSR0B | (1<<TXB80);   // TXB80 = 1
              break;
              case 4: // Space
              UCSR0B = UCSR0B & ~(1<<TXB80);  // TXB80 = 0 
              break;
              default:
              UCSR0B = UCSR0B | (1<<TXB80);   // TXB80 = 1
              break;     
              };
          /* Set bits for mode SizeBit */
              cPEx = UCSR0B & 0x01;    // Calculate bit TXB80    
                                       // cPEx = 0 or 1 
          switch ( SizeBit_UART0)
              {
              case 0: // Mode data size 7 bits
              cTmp = cByte | (0x80);     // b7=1
                if ( cPEx == 0)
                {
                 ClrBit(cTmp,7);   
                }
                else
                {
                 SetBit(cTmp,7);  
                 }; 
              break;
              case 1: // Mode data size 7 bits
              cTmp = cByte;   
              break;
              default:
              break;     
              };
            UDR0 = cTmp; /* start transmition */
            }
        else
            {
            UCSR0B &= ~(1<<UDRIE0); /* disable UDRE interrupt */
            };
      }
      else
      {
      UCSR0B &= ~(1<<UDRIE0); /* disable UDRE interrupt */
      };          
 }
/* This method interrupt event TX Empty */
/****************************************/

#ifdef TEST_UART0
/* main - a simple test program*/
void main( void )
        {
        volatile long int l_i;
        volatile unsigned char cByte;
        volatile int iByte;
        volatile int iRet;
        unsigned int i;
        Reset_UART0();    
        Init_S_UART0(57600); // 9600 default
        Init_2S_UART0(0);
        Init_B_UART0(1);  // Size Bits '8'        
        Init_P_UART0(1);  // Parity    'E'
                          // Stop Bit  '1'
        Echo_ON_UART0(); // Set Echo
        ControlStream_ON_UART0();      // Flow Control ON  
        XON_XOFF_OFF_CONTR_Rx_UART0(); // Software Control OFF
        XON_XOFF_OFF_CONTR_Tx_UART0(); // Enable Tx Control
        /* Enable control hardware flow all signals */
         DSR_OFF_CONTR_UART0();  // Hardware Flow Control DSR
         DTR_OFF_CONTR_UART0();  // Hardware Flow Control DTR
         CTS_OFF_CONTR_UART0();  // Hardware Flow Control CTS
         RTS_OFF_CONTR_UART0();  // Hardware Flow Control RTS
         RTS_CLR_UART0();       // RTS0=0 Request to send
         DTR_CLR_UART0();       // DTR0=0 Data Terminal Ready
         CTS_CLR_UART0();
         DSR_CLR_UART0();
        /***********/

        Enable_Err_Count_UART0();
        i = 0;

        _SEI(); /* enable interrupts => enable UART interrupts */
        iRet = printf("Test ver 0.01 for file 'A1x.c' UART0 \n\r");
        if (Enb_XON_XOFF_Rx_UART0 !=  0)
        {
        iRet = printf("%c",Sym_XON);
        Count_XOFF_Rx_UART0 = 0;
        };                            // Enable Tx for Computer
        while ( 1 ) /* forever */
                {
                if (DataInReceiveBuffer()!=0)
                {
                //cByte = ReceiveByte();
                //iRet = printf("%c",cByte); // yes
                  if ( i > 50)  // if 20 symbols Rx and Tx
                  {
                  //iRet = Read_Tx_Rx_Err_UART0();                
                  i = 1;
                  };
                i++;
                };

                //iByte = (int) cByte;
                //putchar((int)cByte); // yes
                //TransmitByte(cByte); /* echo the received character */
                //putchar((int)cByte); // yes
                //iRet = sprintf(p,"%ld",Count_Rx_UART0); // yes
                //iRet = puts(p); // yes             
                //iRet = printf("\n\r Test main i="); // yes
                //iRet = printf("%d", i); // yes
                //iRet = printf("%ld",Count_Rx_UART0); // yes
            };
        }
#endif

