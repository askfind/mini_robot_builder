/*                      - SSCANF.C -

   The ANSI "sscanf" function.

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "stdarg.h"
#include "stdlib.h"
#include "stdio.h"
#include "icclbutl.h"   /* Contains low-level declarations */

int sscanf(const char *line, const char *format,...)
{
  va_list ap;
  int conversions;
  
  if (*line)
  {
    va_start(ap, format);
    conversions = _formatted_read(&line, &format, ap);
    va_end(ap);
    return conversions;
  }
  else
  {
    return EOF;
  }
}

