      // Calculate parity
unsigned char CalculParity(unsigned char Byte,unsigned char cPEx )  
  {
    //unsigned char tmphead;
    unsigned char cTmp;
    //unsigned char cByte;
    unsigned char cPE;
    //unsigned char cPERx;
    volatile unsigned char FlgErr;
    int i;
    int j;
    int k;  
      switch(CheckParity_UART0)      // Test mode parity=?
         {
        case 0:              // No parity
        break;
 
        case 1:             // mode parity: yes "1" 
        case 2:             // mode parity: no  "1" 
              j=1;
              k=0;
                for (i=1;i<=8;i++)
                    {
                    cTmp = Byte & j;
                        if ( cTmp != 0)
                        {
                        k++;
                        };
                     j = j*2;   
                    };
      
                cTmp = (char) (k % 2);
                      
                    if ( (cTmp == 1) && (CheckParity_UART0 == 1) )
                      {
                      cPE = 1;
                        if ( cPE != cPERx )
                        {
                         FlgErr = 1;  // Error parity
                            if ( Enb_Err_UART0 == 1 )
                            {
                            Rx_Tx_Err_UART0[3]++;
                            };
                         };
                      };
                    if ( (cTmp == 1) && (CheckParity_UART0 == 2) )
                      {
                      cPE = 0;
                        if ( cPE != cPERx )
                        {
                         FlgErr = 1;  // Error parity
                            if ( Enb_Err_UART0 == 1 )
                            {
                            Rx_Tx_Err_UART0[3]++;
                             };
                         };
                      };
                    if ( (cTmp == 0) && (CheckParity_UART0 == 1) )
                      {
                      cPE = 0;
                        if ( cPE != cPERx )
                        {
                         FlgErr = 1;  // Error parity
                                    if ( Enb_Err_UART0 == 1 )
                                    {
                                    Rx_Tx_Err_UART0[3]++;
                                    };
                         };                      
                      };                            
                    if ( (cTmp == 0) && (CheckParity_UART0 == 2) )
                      {
                      cPE = 1;
                        if ( cPE != cPERx )
                        {
                         FlgErr = 1;
                                if ( Enb_Err_UART0 == 1 )
                                {
                                Rx_Tx_Err_UART0[3]++;
                                };
                         };
                 };
         break;
         default:
         ;
         break;
        };          
  return FlgErr;
  }
  