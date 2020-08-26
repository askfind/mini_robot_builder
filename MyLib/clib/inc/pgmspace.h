/*			- PGMSPACE.H -

   Subset of standard I/O and string function declarations,
   modified for strings stored in program address space.

   Version: 1.04 [IDAW]

*/

#ifndef _PGMSPACE_INCLUDED
#define _PGMSPACE_INCLUDED

#include "string.h"

/* PGM_P points into program address space */
#if __HAS_ELPM__
#define	PGM_P      const char __farflash *
#define PGM_VOID_P const void __farflash *
#else
#define	PGM_P      const char __flash *
#define PGM_VOID_P const void __flash *
#endif // __HAS_ELPM__

/* Language extensions are necessary to cope with multiple address spaces */
#pragma language=extended
int	printf_P(PGM_P __format,...);
int 	puts_P(PGM_P __s);
int	scanf_P(PGM_P __format,...);
int	sprintf_P(char *__s,PGM_P __format,...);
int	sscanf_P(const char *__s, PGM_P __format,...);
void *	memcpy_P(void *s1, PGM_VOID_P, size_t n);
int 	strcmp_P(const char *s1, PGM_P s2);
char *	strcpy_P(char *s1, PGM_P s2);
PGM_P	strerror_P(int errnum);
size_t	strlen_P(PGM_P s);
int 	strncmp_P(const char *s1, PGM_P s2, size_t n);
char *	strncpy_P(char *s1, PGM_P s2, size_t n);
#pragma language=default

#endif



