/*                      - STRCOLL.C -

   The ANSI "strcoll" function.  Note: without "locale" == strcmp.
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $
           
   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "string.h"
 
int strcoll(const char *s1, const char *s2)
{
  return strcmp(s1, s2);
}


