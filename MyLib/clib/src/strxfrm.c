/*  - STRXFRM.C -

   The ANSI "strxfrm" function.

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $
                    
   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "string.h"

size_t strxfrm(char *s1, const char *s2, size_t n)
{
  strncpy(s1,s2,n);     
  return strlen(s2);
}
