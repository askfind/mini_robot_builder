/*			- STRNCMP_P.C -

   A variant of the ANSI "strncmp" function.
	   
   Version: 1.03 [IANP] (from strncmp 3.20)

*/

#include "pgmspace.h"

int strncmp_P (const char *s1, PGM_P s2, size_t n)
  {
    while (n && *s1 == *s2++)
      {
        if (!*s1++)
	  {
	    return (0);
	  }
        n--;
      }
    return ( n ? *(unsigned char *)s1 - (unsigned char) *(s2 - 1) : 0);
  }

