/*                      - STRLEN.C -

   The ANSI "strlen" function.
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $
           
   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "string.h"

size_t strlen(const char *s)
{
#ifdef _INTRINSIC
  return strlen(s);
#else
  char const *p = s;

  while (*p)
    p++;
  return p - s;
#endif
}

