        /* Call Prototypes Functions for KEY_CONTR_A2x.c */

        /*-----------------*/
        /*  Reset  UART0   */

extern   void    Reset_UART0 ( void );   // Clear Arrs and Variables

        /*--------------------------------*/
        /*  Copy Sets Variable UART0 mode */

extern   void   CopySetsRom_UART0(void);       // Sets is Default
extern   void   CopySetsEEPROM_UART0(void);    // Sets is Profile EEPROM

        /*------------------*/
        /*  Init UART0 mode */

extern  void    Init_S_UART0  ( unsigned int SpeedBaund );  // speed  UART0
extern  void    Init_2S_UART0 ( unsigned char ModeU2X0 );   // baud*2 UART0
extern  void    Init_P_UART0  ( unsigned char CheckParity ); // control parity
extern  void    Init_B_UART0  ( unsigned char SizeBit );     // Size Bits Rx/Tx
extern  void    Init_CHR9_UART0 ( unsigned char ModeCHR90 ); // Rx/Tx 8 or 9 bits
extern  void    Init_MPCM_UART0 ( unsigned char ModeMPCM0 ); // Mode Multi-processor Com port


        /*--------------------------*/
        /* Received Byte for Rx_Buf */

extern   int     ReceiveByteUART0 ( void );         // if int = -1 then ERROR
                                              // else int = read data

        /*---------------------------*/
        /* Transmited Byte to Tx_Buf */
    /*
extern    void TransmitByte_UART0( unsigned char data );
    */

extern    int    TransmitByteUART0 ( unsigned char data );  // if int = -1 then ERROR
                                                      // else int = data


        /*-------------------------------------------*/
        /* "Enable_Err_Count_UART0" Enable counter   */
        /*         errors for Tx_Rx  UART            */
extern    void   Enable_Err_Count_UART0 ( void );   // End_Err_UART0 = 1

        /*---------------------------------------------*/
        /* "Disable_Err_Count_UART0" Disable counter   */
        /*        errors for Tx_Rx  UART               */
extern    void   Disable_Err_Count_UART0 ( void );   // End_Err_UART0 = 0

        /*-------------------------------*/
        /* Read Arry Tx_Rx_Err for UART  */
extern    int    Read_Tx_Rx_Err_UART0 ( void );    // Type strings table Error
                                             // if int = -1 ERROR

        /*-----------------------------*/
        /*  Control stream  UART0 mode */
extern    void   ControlStream_ON_UART0( void );   // Set Echo = 1 Mode 'ON'

        /*-----------------------------*/
        /*  Control stream  UART0 mode */
extern    void   ControlStream_OFF_UART0( void );   // Set Echo = 1 Mode '

        /*-------------------------*/
        /* "Echo On UART0"         */
extern    void   Echo_ON_UART0( void );   // Set Echo = 1 Mode 'ON'


        /*---------------------------*/
        /* "Echo OFF UART0"          */
extern    void   Echo_OFF_UART0( void );  // Set Echo = 0 Mode 'OFF'

        /*-------------------------*/
        /* "Break UART0" for UART  */
extern    void   Break_UART0( void );                  // Set pin AVR TXD = MARK ( Low )

        /*---------------*/
        /* "Dis UART0"   */
extern    void   Dis_UART0( void );

        /*---------------*/
        /* "Dis Rx UART0"   */
extern    void   Dis_Rx_UART0( void );

        /*------------------*/
        /* "Dis Tx UART0"   */
extern    void   Dis_Tx_UART0( void );

        /*---------------------*/
        /*  "Enb UART0"        */
extern   void    Enb_UART0( void );

        /*---------------------*/
        /*  "Enb Rx UART0"        */
extern   void    Enb_Rx_UART0( void );

        /*---------------------*/
        /*  "Enb Tx UART0"        */
extern   void    Enb_Tx_UART0( void );

         /*---------------------------------*/
         /*  "DTR ON CONTROLL UART0"        */
extern   void     DTR_ON_CONTR_UART0( void );     // Control DTR ON
         /*---------------------------------*/
         /*  "DTR OFF CONTROL UART0"        */
extern   void     DTR_OFF_CONTR_UART0( void );    // Control DTR OFF
         /*---------------------------------*/
         /*  "DTR SET UART0"                */
extern   void     DTR_SET_UART0( void );          // Set DTR = 1
         /*---------------------------------*/
         /*  "DTR CLR UART0"                */
extern   void     DTR_CLR_UART0( void );          // Set DTR = 0

        /*-----------------------------*/
        /* "RTS_ON_CONTR_UART0"        */
extern   void     RTS_ON_CONTR_UART0( void );    // Control RTS ON
        /*-------------------------------*/
        /*  "RTS_OFF_CONTR_UART0"        */
extern   void     RTS_OFF_CONTR_UART0( void );   // Control RTS OFF
         /*------------------------------*/
        /*  "RTS_SET_UART0"              */
extern   void     RTS_SET_UART0( void );         // Set RTS = 1
        /*--------------------------------------*/
        /*  "RTS_CLR_UART0"       */
extern   void     RTS_CLR_UART0( void );         // Set RTS = 0

        /*--------------------------*/
        /*  "DSR_ON_CONTR_UART0"    */
extern   void     DSR_ON_CONTR_UART0( void );    // Control DSR ON
         /*-------------------------*/
        /*  "DSR_OFF_CONTR_UART0"   */
extern   void     DSR_OFF_CONTR_UART0( void );   // Control DSR OFF
         /*-------------------------*/
        /*  "DSR_SET_UART0"         */
extern   void     DSR_SET_UART0( void );         // Set DSR = 1
        /*---------------------*/
        /*  "DSR_CLR_UART0"    */
extern   void     DSR_CLR_UART0( void );         // Set DSR = 0

        /*--------------------------*/
        /*  "CTS_ON_CONTR_UART0"    */
extern   void     CTS_ON_CONTR_UART0( void );    // Control DSR ON
         /*-------------------------*/
        /*  "CTS_OFF_CONTR_UART0"   */
extern   void     CTS_OFF_CONTR_UART0( void );   // Control DSR OFF
         /*-------------------------*/
        /*  "CTS_SET_UART0"         */
extern   void     CTS_SET_UART0( void );         // Set DSR = 1
        /*---------------------*/
        /*  "CTS_CLR_UART0"    */
extern   void     CTS_CLR_UART0( void );         // Set DSR = 0


        /*--------------------------------*/
        /* "XON_XOFF_ON_CONTR_Rx_UART0"   */
extern   void     XON_XOFF_ON_CONTR_Rx_UART0( void );  // XON/XOFF  Rx = 1 Enable
        /*---------------------------------*/
        /* "XON_XOFF_OFF_CONTR_Rx_UART0"   */
extern   void     XON_XOFF_OFF_CONTR_Rx_UART0( void ); // XON/XOFF Rx = 0 Disable

        /*--------------------------------*/
        /* "XON_XOFF_ON_CONTR_Tx_UART0"   */
extern   void     XON_XOFF_ON_CONTR_Tx_UART0( void );  // XON/XOFF  Tx = 1 Enable
        /*--------------------------------------*/
        /* "XON_XOFF_OFF_CONTR_Tx_UART0"   */
extern   void     XON_XOFF_OFF_CONTR_Tx_UART0( void ); // XON/XOFF Tx = 0 Disable

/*--------------------------------------------*/
/* Function Transmit UART0 and Controls Stream */
extern void TransmitByte_UART0( unsigned char data );

/*--------------------*/
/* Function IncErrArr */
extern void IncErrArr_UART0 ( int pos );

/*----------------------*/
/* Function CheckParity */
extern unsigned char CheckParity7(unsigned char byte);

/*----------------------*/
/* Function CheckParity */
extern unsigned char CheckParity8(unsigned char byte);

/*----------------------*/
/* Function CheckParity */
extern int getchar_K(void);

/*  Call Functions prototype   */
/*   Eof  for KEY_CONTR A2x.h  */
/*******************************/
