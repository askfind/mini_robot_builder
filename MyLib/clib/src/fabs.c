/*                      - FABS.C -

   The ANSI "fabs" function.
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $    
           
   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "math.h"
#include "iccfloat.h"
 
double fabs(double x)
{
#ifdef _INTRINSIC
  return fabs(x);
#else
  return x < 0.0 ? -x : x;
#endif
}

