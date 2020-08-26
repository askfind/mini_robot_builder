/*                      - MEMSET.C -

   The ANSI "memset" function.
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $    
           
   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "string.h"
 
void *memset(void *s, int c, size_t n)
{
#ifdef _INTRINSIC
  return memset(s, c, n);
#else
  char *v;

  v = s;
  while (n--)
  {
    *v++ = c;
  }
  return s;
#endif
}

