/*                      - CEIL.C -

   The ANSI "ceil" function.

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $    
                    
   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "math.h"
#include "iccfloat.h"

double ceil(double d)
{
#ifdef _INTRINSIC
  return ceil(d);
#else
  return -floor(-d);
#endif
}

