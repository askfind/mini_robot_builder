/*                      - STRCAT.C -

   The ANSI "strcat" function.
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $
           
   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "string.h"

char *strcat(char *s, const char *t )
{
#ifdef _INTRINSIC
  return strcat(s, t);
#else
  char *v = s;

  while (*s)                /* Find end of s */
  {
    s++;
  }
  
  while (*s++ = *t++)       /* Copy t right after s */
    ;
  
  return v;
#endif
}

