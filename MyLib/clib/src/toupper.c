/*                      - TOUPPER.C -

   The ANSI "toupper" function (also available as a macro).
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $
           
   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "string.h"

#ifdef toupper
#undef toupper
#endif

int toupper(int c)
{
#ifdef _INTRINSIC
  return toupper(c);
#else
  return (c >= 'a' &&  c <= 'z') ? c ^ 0x20 : c;
#endif
}


