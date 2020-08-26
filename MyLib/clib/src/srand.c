/*                      - SRAND.C -

   The ANSI "srand" function.
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "stdlib.h"

extern unsigned long int __next_rand;
 
void srand(unsigned int seed)
{
  __next_rand = seed;
}

