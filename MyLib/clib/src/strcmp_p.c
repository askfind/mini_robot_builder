/*			- STRCMP_P.C -

   A variant of the ANSI "strcmp" function.
	   
   Version: 1.03 [IANP] (from strcmp 3.20)
	   
*/

#include "pgmspace.h"
 
int strcmp_P (const char *s1, PGM_P s2)
  {
    while (*s1 == *s2)
      {
        if ( !*s1++ )
	  {
            return ( 0 );
	  }
	s2++;
      }
    return ( *(unsigned char *)s1 - (unsigned char) *s2 );
  }
