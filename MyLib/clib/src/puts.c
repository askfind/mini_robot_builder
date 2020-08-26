/*                      - PUTS.C -

   The ANSI "puts" function.

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $    

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "stdio.h"

int puts(const char *s)  
{
  while (*s)
  {
    if (!( putchar(*s++)))
      return EOF;
  }
  putchar('\n');
  return 1;
}
          
