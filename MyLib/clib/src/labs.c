/*                      - LABS.C -

   The ANSI "labs" function.
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $    

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "stdlib.h"

long int labs(long int j)
{
#ifdef _INTRINSIC
  return labs(j);
#else
  return j >= 0 ? j : -j;
#endif
}



