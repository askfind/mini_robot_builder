/*                      - ATOI.C -

   The ANSI "atoi" function.
           
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $    

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "ctype.h"
#include "stdlib.h"

int atoi(const char *s)
{
#ifdef _INTRINSIC
  return atoi(s);
#else
  int n;
  unsigned char sign = 0;
  
  while (isspace(*s))
  {
    s++;
  }

  if (*s == '-')
  {
    sign = 1;
    s++;
  }
  else if (*s == '+')
  {
    s++;
  }
  
  n=0;

  while (isdigit(*s))
  {
    n = n * 10 + *s++ - '0';
  }

  return sign ? -n : n;
#endif
}
