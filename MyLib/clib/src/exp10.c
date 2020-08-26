/*                      - EXP10.C -

   The non-ANSI "exp10" function.
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $    

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "sysmac.h"
#include "iccext.h"
#include "math.h"
#include "iccfloat.h"
#include "float.h"
#include "errno.h"


#if __FLOAT_SIZE__ == __DOUBLE_SIZE__
#define   maxf     38
#else
#define   maxf     309
#endif


double exp10(double x)
{
#ifdef _INTRINSIC
  return exp10(x);
#else
  if (fabs(x) > maxf)
  {
    errno = ERANGE;
    return x < 0.0 ? 0.0 : HUGE_VAL;
  }
  return exp(x * __LN10);
#endif
}

