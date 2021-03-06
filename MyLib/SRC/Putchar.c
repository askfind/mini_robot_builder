/*              PUTCHAR.C

   The ANSI "putchar" function.

   The putchar function writes the character c to the
   output-stream pointed to by stream. 
   The function returns the character written. If an writing 
   error  occurs the putchar shall return EOF.

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $    

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include <iom161.h>
#include <stdio.h>
extern void TransmitByte_UART0( unsigned char data);
 
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


