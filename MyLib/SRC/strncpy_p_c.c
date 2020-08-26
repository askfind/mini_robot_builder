/*			- STRNCPY_P.C -

   A variant of the ANSI "strncpy" function.
	   
   Version: 1.03 [IANP] (from strncpy 3.20)
	   
*/

#include "pgmspace.h"

char *strncpy_P (char *s1, PGM_P s2, size_t n)
  {
    char *os1;

    os1 = s1;
    while (n--)
      {
	if (!(*s1++ = *s2++))
	  {
	    while (n--)
	      {
	        *s1++ = '\0';
	      }
	    break;
	  }
      }
    return (os1);
  }

