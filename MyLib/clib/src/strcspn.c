/*                      - STRCSPN.C -

   The ANSI "strcspn" function.
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "string.h"
 
size_t strcspn(const char *s1, const char *s2)
{
#ifdef _INTRINSIC
  return strcspn(s1, s2);
#else
  char *v;
  size_t n = 0;

  while (*s1)
  {
    v = (char *)s2;
    while (*v)
    {
      if (*v++ == *s1)
        return n;
    }
    s1++;
    n++;
  }
  return n;
#endif
}

