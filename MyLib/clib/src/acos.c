/*                      - ACOS.C -

   The ANSI "acos" function.

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $    

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/


#include "math.h"
#include "float.h"
#include "errno.h"

double acos(double arg)
{
#ifdef _INTRINSIC
  return acos(arg);
#else

  /* Check argument */
  if (fabs(arg) > 1.0)
  {
    errno = EDOM;         
    return __EDOM_VALUE;
  }
  return __PIO2 - asin(arg);
#endif
}

