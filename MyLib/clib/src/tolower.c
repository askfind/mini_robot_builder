/*                      - TOLOWER.C -

   The ANSI "tolower" function (also available as a macro).
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $
           
   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "string.h"

#ifdef tolower
#undef tolower
#endif

int tolower(int c)
{
#ifdef _INTRINSIC
  return tolower(c);
#else
  return (c >= 'A' &&  c <= 'Z') ? c | 0x20 : c;
#endif
}

