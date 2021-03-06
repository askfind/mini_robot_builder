/*                      - STRSTR.C -

   The ANSI "strstr" function.
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "string.h"
 
char *strstr(const char *s1, const char *s2)
{
#ifdef _INTRINSIC
  return strstr(s1, s2);
#else
  int n;

  if (*s2)
  {
    while (*s1)
    {
      for (n=0; *(s1 + n) == *(s2 + n); n++)
      {
        if (!*(s2 + n + 1))
          return (char *)s1;
      }
      s1++;
    }
    return NULL;
  }
  else
    return (char *)s1;
#endif
}




