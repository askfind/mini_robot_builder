/************************************************************
 * Name:    Mini Robot for buildings , C version            *
 * Libray   minilib.r90                                                         *
 * **********************************************************
 *                                                          *
 * Version:             0.01                                *
 * Date create:         03.10.02£. 08:30:59                 *
 * Last edit:           07.10.02£. 20:43:52                 *
 *                                                          *
 * File:                Minilib.c                           *
 *                                                          *
 * Microcontroller      AMega161                            *
 *                                                          *
 ************************************************************/

#include <iom161.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "minilib.h"

extern void TransmitByte_UART0( unsigned char data);
extern unsigned char ReceiveByte_UART0( void);


 /*              PUTCHAR.C

   The ANSI "putchar" function.

   The putchar function writes the character c to the
   output-stream pointed to by stream.
   The function returns the character written. If an writing
   error  occurs the putchar shall return EOF.

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

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


/*                      - GETCHAR.C -

  The ANSI "getchar" function delivered here is supposed to be tailored
  for the actual target hardware.  This version of getchar contains a simple
  line-editor that can back-space and delete  (In_DELETE), skip line and
  start over again (In_SKIP), as well as recognize end of file (In_EOF).

  $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

/* Old function low level get char */
// extern char _low_level_get(void);       /* Read one char from I/O */

/* New function lovel get char */
unsigned char _low_level_get(void)    /* Should be supplied by user */
{
unsigned char Byte;
Byte = ReceiveByte_UART0();
return (Byte);
}

static void put_message( char *s)
{
  while (*s)
    putchar(*s++);
}


#define LINE_LENGTH 38          /* Change if you need */

#define In_DELETE 0x7F          /* ASCII <DEL> */
#define In_BS 0x08              /* ASCII <BS> */
#define In_EOL '\r'             /* ASCII <CR> */
#define In_SKIP '\3'            /* ASCII control-C */
#define In_EOF '\x1A'           /* ASCII control-Z */

#define Out_DELETE "\x8 \x8"    /* VT100 backspace and clear */
#define Out_SKIP "^C\n"         /* ^C and new line */
#define Out_EOF "^Z"            /* ^Z and return EOF */

int getchar_K(void)
{
  static unsigned char io_buffer[LINE_LENGTH + 2];     /* Where to put chars */
  static int ptr;                             /* Pointer in buffer */
  unsigned char c;

  for (;;)
  {
    if (io_buffer[ptr])
      return (io_buffer[ptr++]);
    ptr = 0;
    for (;;)
    {
      if ((c = _low_level_get()) == In_EOF && !ptr)
      {
        put_message(Out_EOF);
        return EOF;
      }
      if (c == In_DELETE)
      {
        if (ptr)
        {
          ptr--;
          put_message(Out_DELETE);
        }
      }
      else if ( c == In_BS )
      {
      if (ptr)
        {
          ptr--;
          put_message(Out_DELETE);
        }
       }
      else if (c == In_SKIP)
      {
        put_message(Out_SKIP);
        ptr = LINE_LENGTH + 1;  /* Where there always is a zero... */
        break;
      }
      else if (c == In_EOL)
      {
        putchar(io_buffer[ptr++] = '\n');
        io_buffer[ptr] = 0;
        ptr = 0;
        break;
      }
      else if (ptr < LINE_LENGTH)
      {
        if (c >= ' ')
        {
          putchar(io_buffer[ptr++] = c);
        }
      }
      else
      {
        putchar('\7');
      }
    }
  }
}

/*                      - STRLEN_C.C -
   03.10.02£. 09:13:48
   New edit "strlen_c" function

   The ANSI "strlen" function.

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

// #include "string.h"

int strlen_c( char *s)
{
#ifdef _INTRINSIC
  return strlen_c(s);
#else
  char *p = s;

  while (*p)
    p++;
  return p - s;
#endif
}

/*                      - STRLEN_CR.C -

   Data Create  07.10.02£. 12:08:41
   Last Edit    07.10.02£. 12:08:45

   New edit "strlen_cr" function

   The ANSI "strlen" function.

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

// #include "string.h"

int strlen_cr( char __flash *s)
{
#ifdef _INTRINSIC
  return strlen_cr(s);
#else
  int i = 0;
  int r;
  r = printf("%s", s);
  while ( *s != 0 )
  {
    i++;
    s++;
  };
  return (int)i;
#endif
}

/*                      - STRCAT_UC.C -
   03.10.02£. 09:32:10
   New edit "strcat_c"

   The ANSI "strcat" function.

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

// #include "string.h"

char *strcat_c(char *s, char *t )
{
#ifdef _INTRINSIC
  return strcat_c(s, t);
#else
  char *v = s;

  while (*s)                /* Find end of s */
  {
    s++;
  }

  while (*s++ = *t++)       /* Copy t right after s */
    ;

  return v;
#endif
}

/*                      - STRCHR_UC.C -
   03.10.02£. 11:22:18
   New edit "strchr_c"  function

   The ANSI "strchr" function.

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

// #include "string.h"

char *strchr_c( char *s, int c)
{
#ifdef _INTRINSIC
  return strchr_c(s, c);
#else
  do
  {
    if (*s == (char)c)
    {
      return (char *)s;
    }
  }
  while (*s++);

  return NULL;
#endif
}

/*                      - STRCMP_C.C -
   03.10.02£. 11:48:41
   New edit "strcmp_c" function

   The ANSI "strcmp" function.

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

// #include "string.h"

int strcmp_c( char *s1, char *s2)
{
#ifdef _INTRINSIC
  return strcmp_c(s1, s2);
#else
  while (*s1 == *s2)
  {
    if (!*s1++)
    {
      return 0;
    }
    s2++;
  }
  return  *(unsigned char *)s1 - *(unsigned char *)s2;
#endif
}


/*                      - STRCMP_RC.C -
   03.10.02£. 12:09:19
   New edit "strcmp_cr" function

   The ANSI "strcmp" function.

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

// #include "string.h"

int strcmp_cr( char *s1, char __flash *s2)
{
#ifdef _INTRINSIC
  return strcmp_cr(s1, s2);
#else
  while (*s1 == *s2)
  {
    if (!*s1++)
    {
      return 0;
    }
    s2++;
  }
  return  *(unsigned char *)s1 - *(unsigned char *)s2;
#endif
}

/***********************************/
/*                      - test_cmd -
   Data Create  03.10.02£. 15:00:41
   Last Edit    03.10.02£. 15:00:45

   The "test_cmd" function.

   $Name: V0_01$

   Copyright 2002 Vasiev Vladimir  All rights reserved.
*/
#define STR2_SIZE 3
#define STR3_SIZE 3

int  test_cmd_s( char *s1, volatile int *ps )
{

int i;
int j;
// int k;
int l;
// int r;

char str2[STR2_SIZE];
int  str3[STR3_SIZE];

unsigned char flgerr = 0;

        /* begin do */
        do
        {
/*******/    /************************/
/*     */    /*  Erase space left    */
/*******/    /*  rpad(s1)            */
              // ??

/*******/    /************************/
/*  A  */    /* ? test  strlen(<s1>) */
/*******/    /*                      */
                l = strlen(s1);
                if (l == 0)
                {
                flgerr = 1;     // Error 1 "String NULL"
                break;          // EXIT do
                };

/*******/    /************************/
/*  B  */    /* <s1> -p1-> <str2>    */
/*******/    /*                      */
                memset( str2, '\0', STR2_SIZE); // <> space str2
                memset( str3, '\0', STR3_SIZE); // <> space str3

                j = 0;                          // counter symbols
                for (i=0;i<=(l-1);i++)
                {
                 if ( (s1[i] == '(') || (s1[i] == ')') )
                 {
                  str3[j] = i;    // Store pointer for message '^'
                  if ( j > 2 )   // ? test counter Symbols '(' or ')'
                  {
                  flgerr = 2;     // Error 2 "Symbols '(' or ')' > 2"
                  break;          // EXIT for
                  };
                  str2[j] = s1[i];   // Store symbols '(' or ')'
                  j++;                  // Increment counter symbols
                 };
                };
                if ( j != 2 )   // ? test counter Symbols '(' or ')'
                 {
                 flgerr = 3;     // Error 2 "Symbols '(' or ')' # 2"
                 };
                if ( flgerr !=0 )
                 {
                 break;          // EXIT do
                 };

/*******/    /**************************/
/*  C  */    /* ? test <str2> = <'()'> */
/*******/    /*                        */
                if ( strcmp_c( str2,"()" ) != 0 )
                {
                  flgerr = 4;     // Error 4 "Sintax error '(' or ')'
                  break;          // EXIT do
                };  //

/*******/    /***********************************************/
/* C.1 */    /* ? test strlen(<str1>) = position str3[] ')' */
/*******/    /*                                             */
                if ( ( strlen_c(s1) - 1 ) != str3[1] )
                {
                  flgerr = 7;           // Error 7 "Sintax error
                  str3[0] = str3[1];    // new error position
                  str3[0]++;
                  break;                // EXIT do
                };  //

/*******/    /***********************************/
/*  D  */    /* ? test <str1>[0] = alpha or '_' */
/*******/    /*                                 */
                if ( ( isalpha( (int)s1[0] ) ) == 0 )
                {
                   if ( s1[0] != '_')
                   {
                   memset( str3, '\0', STR3_SIZE); // <> space str3
                   str3[0]=0;           // pointer for message '^'
                   flgerr = 5;          // Error 5 "Sintax error no alpha or '_'
                   break;               // EXIT do
                   };
                };

/*******/    /**************************************************/
/*  E  */    /* ? test <str1>[1..l] # ' ' or '\' or '/' or '|' */
/*******/    /*                                                */
                for (i=1;i<=(str3[0]-1);i++)
                {
                   switch (s1[i])
                   {
                   case ' ':
                   case '/':
                   case 0x5c:  // '\'
                   case '|':
                   case ',':
                   case '.':
                   case '*':
                   case 0x27:  // '''
                   case 0x22:  // '"'
                      flgerr = 6;
                      break;
                   default:
                      break;
                   };
                   if ( flgerr != 0)  {break;};       // EXIT for
                };
                   if ( flgerr != 0)
                   {
                   memset( str3, '\0', STR3_SIZE); // <> space str3
                   str3[0] = i;         // pointer for message '^'
                   flgerr = 6;          // Error 6 "Sintax error symbol  ' \|/'
                   break;               // EXIT do
                   };


/*******/    /****************************/
/*  F  */    /* Return "No syntax error" */
/*******/    /*                          */
                if ( flgerr == 0)
                {
                break;
                };
        }
        while (1); // forever

        *ps = str3[0];    // store pointer to error symbol

return ( flgerr ); // return flgerr = 0  NO  syntax error
                   //        flgerr > 0  YES syntax error
}

/***********************************/
/*                      - out_err_msg -
   Data Create  04.10.02£. 14:50:46
   Last Edit    07.10.02£. 09:54:29

   The "out_err_msg" function.

   $Name: V0_01$

   Copyright 2002 Vasiev Vladimir  All rights reserved.
*/

void  out_err_msg( char *s1, int id_err, volatile int *ps, int codepage )
{

int i;
int j;
int r;
char *p;

/*******/    /*******************************/
/*  0  */    /*  Erase symbols '\n' and '\r'*/
/*******/    /*                             */
                p = strtok(s1,"\n\r");

/*******/    /************************/
/*  A  */    /*  Print command       */
/*******/    /*                      */
                r = printf("\n\r%s",s1);

/*******/    /************************/
/*  B  */    /*  Print point '^'     */
/*******/    /*                      */
                r = printf("\n\r");
                for (i=0;i<=(*ps-1);i++)
                {
                r = printf("%c",' ');
                };
                r = printf("%c",'^');

/*******/    /*********************************/
/*  C  */    /*  Find err_msg in dict_err_msg */
/*******/    /*                               */
                r = 0;                          // flag print
                for (i=0;i<=(COUNT_ERR-1);i++)
                {
                  if ( dict_err_msg[i].id_err == id_err )
                  {
                  r = printf ("\n\r");
                      for (j=0;j<=(MSG_SIZE-1);j++)
                        {
                        if ( dict_err_msg[i].msg_codepage != codepage)  // future case ?? 866,1251
                        {                                           // converted
                        s1[j] = dict_err_msg[i].msg_us[j]; ;
                        }
                        else
                        {
                        s1[j] = dict_err_msg[i].msg_ru[j]; ;
                        };
                        r = printf ("%c", s1[j]);
                        };
                  r = printf ("\n\r");
                  };
                };
                if ( r == 0 )
                {
                  r = printf ("\rNo message error: "); // r # 0
                  r = printf ("%d",id_err);
                  r = printf ("\r");
                  r = sprintf (s1, "No message error ");
                };

/*******/    /******************************/
/*  D  */    /*  Print err_mgs on codepage */
/*******/    /*                            */
                // ??

}
