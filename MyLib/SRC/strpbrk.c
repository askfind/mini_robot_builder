/*                      - STRPBRK.C -

   The ANSI "strpbrk" function.
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "string.h"
 
char *strpbrk(const char *s1, const char *s2)
{
#ifdef _INTRINSIC
  return strpbrk(s1, s2);
#else
  char *v;

  while (*s1)
  {
    v = (char *)s2;
    while (*v)
    {
      if (*s1 == *v++) 
      {
        return (char *)s1;
      }
    }
    s1++;
  }
  return 0;
#endif
}



