/*			- STRCPY_P.C -

   A variant of the ANSI "strcpy" function.
	   
   Version: 1.03 [IANP] (from strcpy 3.20)

*/

#include "pgmspace.h"

char *strcpy_P (char *s1, PGM_P s2 )
  {
    char *v = s1;
    while ( *s1++ = *s2++ )		/* Copy s2 to s1 */
      ;
    return (v);
  }

