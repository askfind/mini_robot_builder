/*                      - STRCMP.C -

   The ANSI "strcmp" function.
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $
           
   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "string.h"
 
int strcmp(const char *s1, const char *s2)
{
#ifdef _INTRINSIC
  return strcmp(s1, s2);
#else
  while (*s1 == *s2)
  {
    if (!*s1++)
    {
      return 0;
    }
    s2++;
  }
  return  *(unsigned char *)s1 - *(unsigned char *)s2;
#endif
}

