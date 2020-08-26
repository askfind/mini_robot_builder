/*                      - ATAN.C -

   The ANSI "atan" function.

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $    

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "math.h"
#include "iccfloat.h"

/*
  atan makes its argument positive and
  calls the inner routine satan.
*/

double atan(double arg)
{
#ifdef _INTRINSIC
  return atan(arg);
#else
  if (arg >= 0.0)
    return __satan(arg);
  else
    return -__satan(arg);
#endif
}
