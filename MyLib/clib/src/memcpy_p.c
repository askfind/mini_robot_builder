/*			- MEMCPY_P.C -

   A variant of the ANSI "memcpy" function.
	   
   Version: 1.03 [IANP] (from memcpy 3.20)

*/

#include "pgmspace.h"
 
void *memcpy_P (void *s1, PGM_VOID_P s2, size_t n)
  {
    char *v;

    v = (char*) s1;
    while (n--)
      {
        *v++ = *(PGM_P)s2;
	s2 = (PGM_P)s2 + 1;
      }
    return (s1);
  }

