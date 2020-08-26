/*                      - CALLOC.C -

   The ANSI "calloc" function.
           
   Assumes that storage is reserved in a linear place.
   Should be completely CPU-independent.

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $    
           
   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "stdlib.h"

void *calloc(unsigned int k, size_t s)
{
  char *p, *p1;
  unsigned long n = k * s;

  if (p1 = p = malloc((size_t) n))   /* There is available memory */
    while (n--)
      *p1++ = 0;                     /* Zero out area */
  return p;
}



