/*                      - STRNCMP.C -

   The ANSI "strncmp" function.
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "string.h"

int strncmp(const char *s1, const char *s2, size_t n)
{
#ifdef _INTRINSIC
  return strncmp(s1, s2, n);
#else
  while (n && *s1 == *s2++)
  {
    if (!*s1++)
    {
      return 0;
    }
    n--;
  }
  return n ? *(unsigned char *)s1 - *(unsigned char *)(s2 - 1) : 0;
#endif
}

