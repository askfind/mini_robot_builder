/*                      - VSPRINTF.C -

   The ANSI "vsprintf" function.

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "stdarg.h"
#include "stdio.h"
#include "icclbutl.h"

static void put_c_in_string(char c, void *ptr)  /* Low-level output */
{
  *(*(char **) ptr)++ = c;
}

int vsprintf(char *s, const char *format, va_list ap)
{
  int nr_of_chars;
  
  nr_of_chars = _formatted_write(format, put_c_in_string, (void *) &s, ap);
  *s = '\0';                  /* String should be terminated with NUL */
  return nr_of_chars;       /* According to ANSI */
}



