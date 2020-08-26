/*                      - FREXP.C -

   The ANSI "frexp" function.
     
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $    
           
   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "math.h"
#include "iccfloat.h"

double frexp(double x, int *i)
{
#ifdef _INTRINSIC
  return frexp(x, i);
#else
  if (x == 0.0)
  {
    *i = 0;
    return 0;
  }
    
  /* Extract the exponent via an intrinsic */
  *i = __dgetexp(x);
    
  /* Let the double be normalized to [0.5,1.0[ */
  x = __dnormexp(x);
  return x;
#endif    
}

