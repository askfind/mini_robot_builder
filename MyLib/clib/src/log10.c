/*                      - LOG10.C -

   The ANSI "log10" function.

   The coefficients are #2705 from Hart & Cheney. (19.38D)

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $    

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "math.h"
#include "iccfloat.h"
#include "float.h"
#include "errno.h"

double log10(double arg)
{
#ifdef _INTRINSIC
  return log10(arg);
#else
  if (arg <= 0.0)
  {
    if (arg == 0.0)
    {
      errno = ERANGE;
      return -HUGE_VAL;
    }
    errno = EDOM;
    return __EDOM_VALUE;
  }

  return log(arg) * (1.0 / __LN10);
#endif
}



