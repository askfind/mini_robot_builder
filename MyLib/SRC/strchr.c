/*                      - STRCHR.C -

   The ANSI "strchr" function.
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "string.h"
 
char *strchr(const char *s, int c)
{
#ifdef _INTRINSIC
  return strchr(s, c);
#else
  do
  {
    if (*s == (char)c)
    {
      return (char *)s;
    }
  }
  while (*s++);
  
  return NULL;
#endif
}

