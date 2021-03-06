/*                      - STRNCPY.C -

   The ANSI "strncpy" function.
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $
           
   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "string.h"

char *strncpy(char *s1, const char *s2, size_t n)
{
#ifdef _INTRINSIC
  return strncpy(s1, s2, n);
#else
  char *os1;

  os1 = s1;
  while (n--)
  {
    if (!(*s1++ = *s2++))
    {
      while (n--)
      {
        *s1++ = '\0';
      }
      break;
    }
  }
  return os1;
#endif
}

