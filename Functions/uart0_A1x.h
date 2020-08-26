/* Last 27.08.2002
   Edit 02.09.2002 
   Head uart0_a1x.h  for   UART0_A1x.c
   Ver 0.01  */

#ifndef __MACROS_H
#define __MACROS_H      1

/* FOR ATMEL AVR and TINY AVR ONLY! */


#ifndef BIT
#define BIT(x)  (1 << (x))
#endif

/* Set and clear bits in I/O registers can also be declared as macros */
#ifndef SetBit
#define SetBit(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#endif
#ifndef ClrBit
#define ClrBit(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#endif
/* Macro for testing of a single bit in an I/O location*/
/* Macro for testing of a single bit in an I/O location*/
#ifndef CheckBit
#define CheckBit(ADDRESS,BIT) (ADDRESS & (1<<BIT))
#endif
/* Use of bit-mask for status bits*/
/* Define bit macros, note that they are similar to the I/O macros*/
#ifndef SETBIT
#define SETBIT(x,y) (x |= (y)) /* Set bit y in byte x*/
#endif
#ifndef CLEARBIT
#define CLEARBIT(x,y) (x &= (~y)) /* Clear bit y in byte x*/
#endif
#ifndef CHECKBIT
#define CHECKBIT(x,y) (x & (y)) /* Check bit y in byte x*/
#endif

#ifndef _asm
#define _asm    asm                     /* old style */

#define WDR()   asm("wdr")
#define SEI()   asm("sei")
#define CLI()   asm("cli")
#define NOP()   asm("nop")
#define _WDR()  asm("wdr")
#define _SEI()  asm("sei")
#define _CLI()  asm("cli")
#define _NOP()  asm("nop")

#endif
#endif

/* Declare for UART0_A1x.c */
#define FQCK 3686400  // Frequencies Crystal MGh

/* Old Prototypes
void InitUART( unsigned char baudrate );
unsigned char ReceiveByte( void );
void TransmitByte( unsigned char data );*/

        /* Prototypes Functions for UART0_A1x.c */

        /*-----------------*/
        /*  Reset  UART0   */

        void    Reset_UART0 ( void );   // Clear Arrs and Variables

        /*--------------------------------*/
        /*  Copy Sets Variable UART0 mode */

        void   CopySetsRom_UART0(void);       // Sets is Default
        void   CopySetsEEPROM_UART0(void);    // Sets is Profile EEPROM

        /*------------------*/
        /*  Init UART0 mode */

        void    Init_S_UART0  ( unsigned int SpeedBaund );  // speed  UART0
        void    Init_2S_UART0 ( unsigned char ModeU2X0 );        // baud*2 UART0
        void    Init_P_UART0  ( unsigned char CheckParity ); // control parity
        void    Init_CHR9_UART0 ( unsigned char ModeCHR90 );     // Rx/Tx 8 or 9 bits
        void    Init_MPCM_UART0 ( unsigned char ModeMPCM0 );     // Mode Multi-processor Com port


        /*--------------------------*/
        /* Received Byte for Rx_Buf */

   int     ReceiveByteUART0 ( void );         // if int = -1 then ERROR
                                              // else int = read data

        /*---------------------------*/
        /* Transmited Byte to Tx_Buf */

    int    TransmitByteUART0 ( unsigned char data );  // if int = -1 then ERROR
                                                      // else int = data

        /*-------------------------------------------*/
        /* "Enable_Err_Count_UART0" Enable counter   */
        /*         errors for Tx_Rx  UART            */
    void   Enable_Err_Count_UART0 ( void );   // End_Err_UART0 = 1

        /*---------------------------------------------*/
        /* "Disable_Err_Count_UART0" Disable counter   */
        /*        errors for Tx_Rx  UART               */
    void   Disable_Err_Count_UART0 ( void );   // End_Err_UART0 = 0

        /*-------------------------------*/
        /* Read Arry Tx_Rx_Err for UART  */
    int    Read_Tx_Rx_Err_UART0 ( void );    // Type strings table Error
                                             // if int = -1 ERROR

        /*-------------------------*/
        /* "Echo On UART0"         */
    void   Echo_ON_UART0( void );   // Set Echo = 1 Mode 'ON'


        /*---------------------------*/
        /* "Echo OFF UART0"          */
    void   Echo_OFF_UART0( void );  // Set Echo = 0 Mode 'OFF'

        /*-------------------------*/
        /* "Break UART0" for UART  */
    void   Break_UART0( void );                  // Set pin AVR TXD = MARK ( Low )

        /*---------------*/
        /* "Dis UART0"   */
    void   Dis_UART0( void );

        /*---------------*/
        /* "Dis Rx UART0"   */
    void   Dis_Rx_UART0( void );

        /*------------------*/
        /* "Dis Tx UART0"   */
    void   Dis_Tx_UART0( void );
    
        /*---------------------*/
        /*  "Enb UART0"        */
   void    Enb_UART0( void );
   
        /*---------------------*/
        /*  "Enb Rx UART0"        */
   void    Enb_Rx_UART0( void );
   
        /*---------------------*/
        /*  "Enb Tx UART0"        */
   void    Enb_Tx_UART0( void );

         /*---------------------------------*/
         /*  "DTR ON CONTROLL UART0"        */
   void     DTR_ON_CONTR_UART0( void );     // Control DTR ON
         /*---------------------------------*/
         /*  "DTR OFF CONTROL UART0"        */
   void     DTR_OFF_CONTR_UART0( void );    // Control DTR OFF
         /*---------------------------------*/
         /*  "DTR SET UART0"                */
   void     DTR_SET_UART0( void );          // Set DTR = 1
         /*---------------------------------*/
         /*  "DTR CLR UART0"                */
   void     DTR_CLR_UART0( void );          // Set DTR = 0

        /*-----------------------------*/
        /* "RTS_ON_CONTR_UART0"        */
   void     RTS_ON_CONTR_UART0( void );    // Control RTS ON
        /*-------------------------------*/
        /*  "RTS_OFF_CONTR_UART0"        */
   void     RTS_OFF_CONTR_UART0( void );   // Control RTS OFF
         /*------------------------------*/
        /*  "RTS_SET_UART0"              */
   void     RTS_SET_UART0( void );         // Set RTS = 1
        /*--------------------------------------*/
        /*  "RTS_CLR_UART0"       */
   void     RTS_CLR_UART0( void );         // Set RTS = 0

        /*--------------------------*/
        /*  "DSR_ON_CONTR_UART0"    */
   void     DSR_ON_CONTR_UART0( void );    // Control DSR ON
         /*-------------------------*/
        /*  "DSR_OFF_CONTR_UART0"   */
   void     DSR_OFF_CONTR_UART0( void );   // Control DSR OFF
         /*-------------------------*/
        /*  "DSR_SET_UART0"         */
   void     DSR_SET_UART0( void );         // Set DSR = 1
        /*---------------------*/
        /*  "DSR_CLR_UART0"    */
   void     DSR_CLR_UART0( void );         // Set DSR = 0


        /*--------------------------------*/
        /* "XON_XOFF_ON_CONTR_Rx_UART0"   */
   void     XON_XOFF_ON_CONTR_Rx_UART0( void );  // XON/XOFF  Rx = 1 Enable
        /*---------------------------------*/
        /* "XON_XOFF_OFF_CONTR_Rx_UART0"   */
   void     XON_XOFF_OFF_CONTR_Rx_UART0( void ); // XON/XOFF Rx = 0 Disable

        /*--------------------------------*/
        /* "XON_XOFF_ON_CONTR_Tx_UART0"   */
   void     XON_XOFF_ON_CONTR_Tx_UART0( void );  // XON/XOFF  Tx = 1 Enable
        /*--------------------------------------*/
        /* "XON_XOFF_OFF_CONTR_Tx_UART0"   */
   void     XON_XOFF_OFF_CONTR_Tx_UART0( void ); // XON/XOFF Tx = 0 Disable

/*********************************/
/*   New function UART0_RX(void) */
void   New_UART0_RX(void);

/*--------------------------------------------*/       
/* Function Transmit UART0 and Controls Stream */
int TransmitByte_UART0( unsigned char data );

/*--------------------*/
/* Function IncErrArr */
void IncErrArr_UART0 ( int pos );

/*----------------------*/
/* Function CheckParity */
unsigned char CheckParity(unsigned char byte);

/*  Functions prototype   */
/*   Eof  UART0_A1x.h     */
/**************************/
