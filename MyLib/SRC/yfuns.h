/* yfuns.h functions header */
#ifndef _YFUNS
#define _YFUNS
#ifndef _YVALS
#include <yvals.h>
#include <stddef.h>
#endif
_STD_BEGIN
		/* process control functions */
#define _Envp	                       (__environ)
#define _Exit(status)	               _exit(status)
		/* stdio functions */
#define _Open(path, smode, mods)       __open(path, smode, mods)
#define _Fclose(str)	               __close((str)->_Handle)
#define _Fread(str, buf, cnt)	       __read((str)->_Handle, buf, cnt)
#define _Fwrite(str, buf, cnt)	       __write((str)->_Handle, buf, cnt)
#define _Lseek(handle, offset, whence) __lseek(handle, offset, whence)
#define _Sbrk(incr)                    __sbrk(incr)

		/* interface declarations */
_EXTERN_C
extern const char *__environ;
__INTRINSIC int    __close(int);
__INTRINSIC int    __open(const char *, int, int);
__INTRINSIC void   _exit(int);
__INTRINSIC void   __exit(int);
__INTRINSIC int    __read(int, unsigned char *, size_t);
__INTRINSIC int    __readchar(int);
__INTRINSIC int    __write(int, const unsigned char *, size_t);
__INTRINSIC int    __writechar(int, unsigned char);
__INTRINSIC long   __lseek(int, long, int);
__INTRINSIC void * __sbrk(int);
__INTRINSIC int    __putchar(int);
__INTRINSIC int    __getchar(void);
_END_EXTERN_C
_STD_END
#endif /* _YFUNS */

/*
 * Copyright (c) 1994 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V2.21:0576 */
