/*********************************************
* Programm:       SCAN_CMD.c                 *
*                                            *
*  Note:  For projekt MINIROBIT BUILDING     *
*                                            *
* Name:  Module Code adapted from Atmel AVR  *
*        Application for Amega161            *
*                                            *
*                                            *
* Edit data:     01.10.02£. 16:06:23         *
* Last data:     14.10.02£. 13:33:25         *
* Version:       0.02                        *
**********************************************/

#include "iom161.h"
#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "scan_cmd.h"
#include "c:\AVR_CC\UART_MOD\uart0_A1x_ext_func.h"


static volatile int point_err;

 /* Debug test SCAN_CMD for module */
#define TEST_SCAN_CMD

#ifdef TEST_SCAN_CMD

 /* main - a simple test program*/
void main( void )
     {
        static unsigned char cRet;
        volatile long int l_i;
        volatile unsigned int i,j;
        static int iByte, iRet;
        volatile char cFlg;
        int flgerr = 0;
        int point_dict;
        char *p;
        char *pt;

        MODE_OUT_MSG = 1;  // full print message errors

        /*-----------------------*/
        /* 2. Init UART0         */
        Reset_UART0();
        Init_S_UART0(57600); // 57600 default

        /*-------------------*/
        /* 4. Begin programm */
        _SEI(); // enable global interrupt

        iRet = printf("Test ver 0.02 for Scan_CMD \n\r");

        l_i=0;
        i = 0;
        cRet = 0;

        /* line string test */
        iRet = sprintf(BUF_TEST,"print1,2\n");
        /*ERR 1 test test_cmd_s() */
        iRet = test_cmd_s(BUF_TEST, &point_err);
        out_err_msg(BUF_TEST,iRet, &point_err, 866);

        /* line string test */
        iRet = sprintf(BUF_TEST,"print1,2\n");
        /*ERR 2 test test_cmd_s() */
        iRet = test_cmd_s(BUF_TEST, &point_err);
        out_err_msg(BUF_TEST,iRet, &point_err, 866);

        /* line string test */
        iRet = sprintf(BUF_TEST,"print(1,2\n");
        /*ERR 3 test test_cmd_s() */
        iRet = test_cmd_s(BUF_TEST, &point_err);
        out_err_msg(BUF_TEST,iRet, &point_err, 866);

        /* line string test */
        iRet = sprintf(BUF_TEST,"print)1,2(\n");
        /*ERR 4 test test_cmd_s() */
        iRet = test_cmd_s(BUF_TEST, &point_err);
        out_err_msg(BUF_TEST,iRet, &point_err, 866);

        /* line string test */
        iRet = sprintf(BUF_TEST,"view(1)\n");
        /*ERR 5 test test_cmd_s() */
        iRet = test_cmd_s(BUF_TEST, &point_err);
        out_err_msg(BUF_TEST,iRet, &point_err, 866);

        iRet = printf("\n\r'Ok\n\rEnd Test out_err_msg() \n\r");


        /* test Read from Dictionary CMD */
        cRet = Dict_CMD[0].pars;
        cRet = cRet+0;

        /* read name from Dictionary CMD */
        for (i=0;i<=((BUFFER_SIZE_CMD/2)-1);i++)
        {
        BUF_TEST[i] = Dict_CMD[1].name[i]; ;
        };

        /* read name from Dictionary CMD */
        for (i=0;i<=((BUFFER_SIZE_CMD)-1);i++)
        {
        BUF_TEST[i] = Dict_CMD[1].info_name[i]; ;
        };

        /* init test array test[] */
        Head_CMD = 0;
        for (i=0;i<=(BUFFER_SIZE_CMD-1);i++)
        {
        BUF_TEST[i] = 0;
        };

        /*test strlen_uc() */
        iRet = strlen_c(BUF_TEST);

        /*test strchr_uc() */
        p = strchr_c(BUF_TEST,'(');
        iRet = *p;

        /*test strcat_uc() */
        p = strcat_c(BUF_TEST,BUF_CMD);

        /* test strcmp_uc*/
        p = strcpy(BUF_CMD, BUF_TEST); // Copy BUF_TEST
        iRet = strcmp_c(BUF_TEST,BUF_CMD); // Comparate str1 and str2


        /* Read command and call functions */

    /* Begin */
    do
     {

        /* test new function getchar() and prints stdin */
        /* Reset point for BUFFER BUF_CMD */
        Head_CMD = 0; // point begin
        memset(BUF_CMD, 0, BUFFER_SIZE_CMD);    // erase buffer
        memset(BUF_TEST, 0, BUFFER_SIZE_CMD);   // erase buffer

        /* Output welcome */
        if (MODE_OUT_MSG == 1)
         {
         iRet = printf("%c ",'>');
         };


        do
         {
          /* Input from stdin */
          iByte = getchar_K();     // new size buffer 40 yes
          /* Save elements BUF_CMD */
          BUF_CMD[Head_CMD] = (unsigned char) iByte;
          Head_CMD++;
            if ( Head_CMD > (BUFFER_SIZE_CMD-1) )
             {
              Head_CMD--; // end buffer
             };
            if (iByte == 0x0A)  // ^J LF
             {
              /* char end string command */
              iRet = printf("\r");
             };
         }
        while ( iByte != 0x0A);

        /* copy string BUF_CDM to BUF_TEST */
        p = strcpy(BUF_TEST, BUF_CMD);

        /* erase '\n' and '\r' */
        p = strtok (BUF_TEST,"\n\r");

        /* test print buffers */

     /* test print BUF_CMD
        iRet = printf("BUF_CMD: ");
        iRet = printf("%s", BUF_CMD);
        iRet = printf("\n\r");
     */

     /* test BUF_TEST
        iRet = printf("BUF_TEST: ");
        iRet = printf("%s", BUF_TEST);
        iRet = printf("\n\r");
     */

        /* test syntax command and output message */
        flgerr = test_cmd_s(BUF_TEST, &point_err);

        /* if ERROR then Print message error */
         if (flgerr > 0)
         {
          if (MODE_OUT_MSG == 1)
          {
          out_err_msg(BUF_TEST, flgerr, &point_err, 866);
          }
          else
          {
          iRet = printf("%d",flgerr);
          };
         };

    if ( flgerr == 0)
     {
        /* test name, counter parametrs and range */
         iRet = strlen_c(BUF_TEST);
         j = 0; //counter symbols ','
         for (i=0;i<=iRet;i++)
         {
          if (BUF_TEST[i] == ',' )
          {
          j++;  // increment counter
          };
         }; // return j counter symbol ','

     /* test
        iRet = printf("\n\r Count',': ");
        iRet = printf("%d",j);
        iRet = printf("\n\r");
     */


        iRet = 0;       // erase point Dict_CMD

         do
          {
          p = strtok(BUF_TEST,"(),");

          /* name in dict_CMD[] and name BUF_TEST */
                for (i=0;i<=((COUNT_CMD)-1);i++)
                {
                        flgerr = 0; // erase flag
                        for (j=0;j<=((BUFFER_SIZE_CMD/2)-1);j++)
                        {
                                if ( Dict_CMD[i].name[j] == 0)
                                {
                                  if ( j == 0)
                                  {
                                  flgerr = flgerr | 1 ;
                                  };
                                  if ( BUF_TEST[j] != 0)
                                  {
                                  flgerr = flgerr | 1 ;
                                  };
                                break;
                                };

                                if ( BUF_TEST[j] != Dict_CMD[i].name[j])
                                {
                                flgerr = flgerr | 1 ;
                                };
                        };
                   if (flgerr == 0)
                   {
                   point_dict = i; // store pointer for Name Function of Dict_CMD
                   break;    // EXIT for
                   };
                flgerr = 255;     // No name command in Dict_CMD[i]
                };

          if ( flgerr == 255)
          {
                if (MODE_OUT_MSG == 1)
                {
                point_err = 0;  // print '^' position
                out_err_msg(BUF_TEST, flgerr, &point_err, 866);
                }
                else
                {
                iRet = printf("%d", flgerr);
                };
                break; // EXIT do
          };

          /* read parametrs from BUF_TEST */
          j = 0; // counter parametrs

          /* test */
          // iRet = printf("\n\r MODE_OUT_MSG= %d",MODE_OUT_MSG)

          for (i=0;i<=CMD_PAR_MAX-1;i++) //  erase id=0
          {
          CMD_PAR[i].id = 0;
          };  // end for

       /* test
          iRet = printf("\n\r ->");
          iRet = printf("%s", p);
          iRet = printf("\n\r");
       */
          for (i=0;i<=(CMD_PAR_MAX-1);i++)  // read parameter
          {
          p = strtok(NULL,",)\n"); // Read next parametr
                if ( p == 0)
                {
                break; // EXIT for
                };
                CMD_PAR[i].id = (char) i;              // store id parameter
                pt = strcpy( CMD_PAR[i].par, p);       // store parametr
                j++;                                   // increment counter

       /* test print
          iRet = strlen_c( p );
          iRet = printf("\n\r MODE_OUT_MSG= %d",MODE_OUT_MSG)
          iRet = printf("\n\r~ len= %d", iRet);
          iRet = printf("\n\r~ point= %d", p);
          iRet = printf(" %s", p);
          iRet = printf("~ \n\r");
          iRet = printf("j= %d ~",j);
          iRet = printf("\n\r");
       */

          }; // end for

       /* test print
          iRet = Dict_CMD[point_dict].pars - (char)j;
          iRet = printf("~ sub= %d",( Dict_CMD[point_dict].pars - (char)j ));
          iRet = printf("\n\r pars=  %d", Dict_CMD[point_dict].pars);
          iRet = printf("\n\r j= %d ",j);
          iRet = printf("~  \n\r");
       */

          if ( ( Dict_CMD[point_dict].pars - (char)j != 0 ) || (p != 0) )
          {
          flgerr = 254;     // Errors counter parametrs in Dict_CMD[i]
          };
                if ( p!= 0) // end function strtok()
                {
                do
                {
                p = strtok(NULL,",)\n"); // Read next parametr
                }
                while(p);
                };

          if ( flgerr == 254)
          {
                if (MODE_OUT_MSG == 1)
                {
                point_err++ ;  // position print symbol '^' to On parameters
                out_err_msg(BUF_CMD, flgerr, &point_err, 866);
                }
                else
                {
                iRet = printf("%d", flgerr);
                };
                break; // EXIT do
          };


          if (flgerr == 0)      //
          {
          /* Call function from Dict_CMD */
          switch( point_dict ) // number function
          {
          case 0: // x()
                DDRA = 0xff;  // mode output
                PORTA = 0x00; // ON lingh
          break;
          case 1: // y()
                DDRA = 0xff;  // mode output
                PORTA = 0xff; // OFF lingh
          break;
          case 2: // z()
          break;
          case 3: // list()  - print names function
                iRet = printf("\n\r- Dictionary functions for KEY_DISP ver 0.01 -");
                for (i=0;i<=COUNT_CMD-1;i++)
                {
                        iRet = printf("\n\r\t");
                        for (j=0;j<=BUFFER_SIZE_CMD/2-1;j++)
                        {
                        if (Dict_CMD[i].name[j]==0) break; // EXIT for j
                        iRet = printf("%c", Dict_CMD[i].name[j]);
                        };
                iRet = printf("() - ");
                        for (j=0;j<=BUFFER_SIZE_CMD/2-1;j++)
                        {
                        if (Dict_CMD[i].info_name[j]==0) break; // EXIT for j
                        iRet = printf("%c", Dict_CMD[i].info_name[j]);
                        };
                };
                iRet = printf("\n\r\n\r\n\r");
          break;
          case 4: // view()
          break;
          case 5: // print()
          break;
          default:
          break;
          };

                if (MODE_OUT_MSG == 1)
                {
                iRet = printf("Ok!\n\r");
                }
                else
                {
                iRet = printf("%d", flgerr);
                };

          break;        // EXIT do
          };
          }

          while(1); // forever

     };  /* End if (flgerr == 0) */

        // ?? output message error if flgerr > 0
        // ?? call function

     }
    while ( 1 );  /* forever */
  }

#endif