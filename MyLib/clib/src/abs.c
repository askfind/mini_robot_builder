/*                      - ABS.C -

   The ANSI "abs" function.
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $    

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "stdlib.h"

int abs(int j)
{
#ifdef _INTRINSIC
  return abs(j);
#else
  return j >= 0 ? j : -j;
#endif
}


