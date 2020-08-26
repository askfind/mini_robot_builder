/*                      - GETS.C -

   The ANSI "gets" function.

   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $    

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/

#include "stdio.h"

char *gets(char *s)
{
  char *ptr;
  int  c;
  
  ptr = s;
  while ((c = getchar()) != '\n' && c != EOF)
  {
    *ptr++ = c;
  }

  if (c == EOF && ptr == s)
  {
    return 0;
  }

  *ptr = '\0';
  return s;
}
          
