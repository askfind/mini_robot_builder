/*              PUTCHAR.C

   The ANSI "putchar" function.

   The putchar function writes the character c to the
   output-stream pointed to by stream. 
   The function returns the character written. If an writing 
   error  occurs the putchar shall return EOF.

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $    

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/


#include <stdio.h>

static volatile __io unsigned char _PORTA @ 0x1B ;
static volatile __io unsigned char _DDRA  @ 0x1A;
static volatile __io unsigned char _PINA  @ 0x19;   

int putchar(int ch)
{

/*
        put your own putchar-function here
*/
   _DDRA  = 0xFF;       // Port A Outs
   _PORTA = (char) ch;  // Byte out to Port A


  return ch;
}



