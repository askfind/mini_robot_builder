/*                      - PRINTF.C -

   The ANSI "printf" function.

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $    

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "stdarg.h"
#include "stdio.h"
#include "icclbutl.h"

static void put_one_char(char c, void *dummy)
{
  putchar (c);
  (void)dummy;  /* Warning on this line OK (Optimized Away) */
}

int printf(const char *format, ...)                    /* Our main entry */
{
  va_list ap;
  int nr_of_chars;

  va_start(ap, format);      /* Variable argument begin */
  nr_of_chars = _formatted_write(format, put_one_char, (void *) 0, ap);
  va_end(ap);                /* Variable argument end */
  return nr_of_chars;        /* According to ANSI */
}

