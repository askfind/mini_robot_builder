/*                      - GETCHAR.C -

  The ANSI "getchar" function delivered here is supposed to be tailored
  for the actual target hardware.  This version of getchar contains a simple
  line-editor that can back-space and delete  (In_DELETE), skip line and
  start over again (In_SKIP), as well as recognize end of file (In_EOF).

  $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "stdio.h"

/* Old function low level get char */
// extern char _low_level_get(void);       /* Read one char from I/O */

extern unsigned char ReceiveByte_UART0( void);

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


#define LINE_LENGTH 40          /* Change if you need */

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