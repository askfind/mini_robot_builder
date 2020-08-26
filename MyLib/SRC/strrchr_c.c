/*                      - STRRCHR.C -

   The ANSI "strrchr" function.
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "stdlib.h" 

char *strrchr(const char *s, int c)
{
#ifdef _INTRINSIC
  return strrchr(s, c);
#else
  char *v = NULL;

  while (*s)
  {
    if (*s == (char)c)
      v = (char *)s;
    s++;
  }
  return v;
#endif
}

