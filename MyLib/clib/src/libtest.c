/*                      - LIBTEST.C -

   Checks that libraries are there and that they work (to some extent).
   Should be compiled, linked and executed with the following sequences
   (here shown for the ICC8051 compiler and library):
           
           icc8051 libtest -r -z

           xlink -rt libtest -f libtest -f lnk8051

           cs8051 aout
            
   $Name: V3_34K V3_34J V3_34I V3_34H V3_34G $         

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/


#ifdef __IAR_SYSTEMS_ICC
#define OUR_SYSTEM
#endif

#include <ctype.h>
#include <math.h>
#include <setjmp.h>
#include <stdarg.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>

#ifdef OUR_SYSTEM

#include <iccext.h>
#include <icclbutl.h>

static void put_c_str(char c, void *ptr)
{
  *(*(char **) ptr)++ = c;
}


int lsscanf (int fp(const char **line,
                    const char **format,
                    va_list ap),
            const char *line,
            const char *format,...)
{
  va_list ap;
  int conversions;
  
  if (*line)
  {
    va_start(ap, format);
    conversions = fp(&line, &format, ap);
    va_end(ap);
    return conversions;
  }
  else
  {
    return EOF;
  }
  }


static int lsprintf(int fp(const char *format,
                           void outputf(char, void *),
                           void *sp,
                           va_list ap),
                    char *s,
                    const char *format,
                    ...)
{
  va_list ap;
  int nr_of_chars;

  va_start(ap, format);
  nr_of_chars = fp(format,put_c_str,(void *) &s, ap);
  va_end(ap);
  *s = '\0';
  return nr_of_chars;
}

char _low_level_get(void)       /* For "getchar" linkage */
{
  return 0;
}

void dummy(void)
{
  char *cp;
  cp = gets(cp);
  getchar();
  scanf(cp);
}


#endif

void main(void)
{

  jmp_buf jumper;
  char carray[80], *cp, *scratch, **endptr = &scratch;
  static int i, j;
  long int uli,li;
  double d;
  float f;
  size_t st;

  div_t dt;
  ldiv_t ldt;

  if (!(i = puts("BEGIN C Library Test")))
    printf("PUTS failed\n");
        
/*------------------------------------------*/
/*            MATH Library Test             */
/*------------------------------------------*/

  if ((i = asin (0.5415) * 1000) != 572)
    printf("ASIN failed\n");

  if ((i = acos (0.5418) * 1000) != 998)
    printf("ACOS failed\n");

  if ((i = atan (9.1) * 100) != 146)
    printf("ATAN failed\n");

  if ((i = atan2 (4.55, 0.5) * 100) != 146)
    printf("ATAN2 failed\n");
  
  if ((i = tan (1.05) * 100) != 174)
    printf("TAN failed\n");
  
  if ((i = cos (2) * (-1000)) != 416)
    printf("COS failed\n");
  
  if ((i = sin (0.5008) * 1000) != 480)
    printf("SIN failed\n");
  
  if ((i = sqrt (4.1)) != 2)
    printf("SQRT failed\n");
  
  if ((i = exp (-2) * 1000) != 135)
    printf("EXP failed\n");
  
  if ((i = ldexp (5,3) ) != 40)
    printf("LDEXP failed\n");
  
  if ((i = fabs (-250)) != 250)
    printf(" FABS failed\n");
  
  if ((i = fmod (1002, 10) != 2))
    printf(" FMOD failed\n");
  
  if ((i = pow (0.31, 5) * 100000) != 286)
    printf("POW failed\n");

#ifdef OUR_SYSTEM
  if ((i = exp10 (-.99) * 100) != 10)
    printf("EXP10 failed\n");
#endif

  if ((i = log (2) * 1000) != 693)
    printf("LOG failed\n");
  
  if ((i = log10 (105) * 100) != 202)
    printf("LOG10 failed\n");

/*------------------------------------------*/
/*            "IS" Library Test             */
/*------------------------------------------*/

  if (!isalnum('4') ||
      !isalnum('a') ||
      isalnum('.'))
    printf("ISALNUM failed\n");

  if (!isalpha('Z') ||
      !isalpha('a') ||
      isalpha ('5') ||
      isalpha('.'))
    printf("ISALPHA failed\n");

  if (iscntrl('Z') ||
      iscntrl('a') ||
      iscntrl ('5') ||
      !iscntrl ('\0') ||
      !iscntrl ('\t') ||
      iscntrl('.'))
    printf("ISCNTRL failed\n");

  if (isdigit('Z') ||
      isdigit('a') ||
      !isdigit ('5') ||
      isdigit ('\0') ||
      isdigit('.'))
    printf("ISDIGIT failed\n");

  if (!isgraph('Z') ||
      !isgraph('a') ||
      !isgraph ('5') ||
      isgraph ('\n') ||
      isgraph ('\0') ||
      !isgraph('.'))
    printf("ISGRAPH failed\n");

  if (islower('Z') ||
      !islower('a') ||
      islower ('5') ||
      islower ('\0') ||
      islower('.'))
    printf("ISLOWER failed\n");
        
  if (!isprint('Z') ||
      !isprint('a') ||
      !isprint ('5') ||
      isprint ('\0') ||
      isprint('\n'))
    printf("ISPRINT failed\n");

  if (ispunct ('A') ||
      !ispunct('.'))
    printf("ISPUNCT failed\n");

  if (isspace('Z') ||
      isspace('a') ||
      isspace ('5') ||
      !isspace ('\t') ||
      !isspace(' '))
    printf("ISSPACE failed\n");

  if (!isupper('Z') ||
      isupper('a') ||
      isupper ('5') ||
      isupper ('\0') ||
      isupper('.'))
    printf("ISUPPER failed\n");

  if (isxdigit('Z') ||
      !isxdigit('a') ||
      !isxdigit ('5') ||
      !isxdigit ('F') ||
      isxdigit('.'))
    printf("ISXDIGIT failed\n");

  if (tolower('Z') != 'z' ||
      tolower('a') != 'a' ||
      tolower ('5') != '5')
    printf("TOLOWER macro failed\n");

#undef tolower
          
  if (tolower('Z') != 'z' ||
      tolower('a') != 'a' ||
      tolower ('5') != '5')
    printf("TOLOWER function failed\n");

  if (toupper('Z') != 'Z' ||
      toupper('a') != 'A' ||
      toupper ('5') != '5')
    printf("TOUPPER macro failed\n");

#undef toupper

  if (toupper('Z') != 'Z' ||
      toupper('a') != 'A' ||
      toupper ('5') != '5')
    printf("TOUPPER function failed\n");

/*------------------------------------------*/
/*            "LONGJMP" Library Test        */
/*------------------------------------------*/
  i = 0;
  if ((j = setjmp(jumper)) && j != 4)
    printf("SETJMP failed\n");
  if (!i++)
    longjmp(jumper,4);
/*------------------------------------------*/
/*            "STRING" Library Test         */
/*------------------------------------------*/

  endptr = NULL; /* If we don't want the result in endptr. */
  if ( d = strtod("-12e+2", endptr) != -1200)
    printf("STRTOD faild\n");

  if ((li = strtol("0x135", endptr, 16)) != 309)
    printf("STRTOL faild\n");

  if ((uli = strtoul("0135", endptr, 0)) != 93)
    printf("STRTOUL faild\n");

  cp = strcpy(carray,"first");
  if (cp != carray)
    printf("STRCPY failed\n");

  if (strlen(carray) != 5)
    printf("STRCPY or STRLEN failed\n");

  if (strcmp(carray,"first"))
    printf("STRCMP failed\n");

  strcat(carray,"next");
  if (strcmp(carray,"firstnext"))
    printf("STRCAT failed\n");

  if (strcmp(carray,"firstnext"))
    printf("STRCAT failed\n");

  if (strncmp(carray,"firstN",5) ||
      !strncmp(carray,"fi",6) ||
      !strncmp(carray,"firstN",6))
    printf("STRNCMP failed\n");

  cp = strncat(carray,"firstN",3);
  if (cp != carray && strcmp(carray,"firstnextfir"))
    printf("STRNCAT failed\n");

  cp = strncpy(carray,"first",3);
  if (cp != carray && strcmp(carray,"fir"))
    printf("STRNCPY failed\n");

  if ( (cp = (char*)memcpy(carray,"678",3)) != carray)
    printf("MEMCPY failed\n");
  if ( (cp = (char*)memmove(carray,"678",3)) != carray)
    printf("MEMMOVE failed\n");
  if ( i = memcmp("123","123",3) != 0)
    printf("MEMCMP faild\n");
  if ( (cp = (char*)memset(carray, 'd',3)) != carray)
    printf("MEMSET failed\n");
  if ( !(cp = (char*)memchr("korv",'r',4)))
    printf("MEMCHR failed\n");
  if ( !(cp = (char*)strchr("korv",'r')))
    printf("STRCHR failed\n");
  if ( st = strcspn("axelar","srt") != 5)
    printf("STRCSPN failed\n");
  if ( !(cp = (char*)strpbrk("klar","lar"))) 
    printf("STRPBRK failed\n");
  if ( !(cp = (char*)strrchr("klar",'a'))) 
    printf("STRRCHR failed\n");
  if ( st = strspn("axel","ax") != 2)
    printf("STRSPN failed\n");
  if ( !(cp = (char*)strstr("klar","la"))) 
    printf("STRSTR failed\n");
  strcpy(carray,"first");
  if (strcoll(carray,"first"))
    printf("STRCOLL failed\n");



/*------------------------------------------*/
/*            Memory Library Test           */
/*------------------------------------------*/
  
  if (!(cp = malloc(sizeof(int) * 8)))
    printf("MALLOC failed\n");
  free(cp);
  if (!(cp = malloc(sizeof(int) * 8)))
    printf("MALLOC failed\n");
  if (!(cp = realloc(cp,sizeof(int) * 10)))
    printf("REALLOC failed\n");
  if (!(cp = calloc(5,sizeof(int))))
    printf("CALLOC failed\n");



        
/*------------------------------------------*/
/*            "IO" Library Test             */
/*------------------------------------------*/
        
  if (atol("466756") != 466756)
    printf("ATOL failed\n");
  
  if (atoi("-456") != -456)
    printf("ATOI failed\n");
  
  if ((i = atof("-0.251e2")) != -25)
    printf("ATOF failed\n");

  if (sscanf(" 6 hufg"," %d %s",&i,carray) != 2)
    printf("SSCANF failed\n");

  if (sprintf(carray,"%d",25) != 2 ||
      strcmp(carray,"25"))
    printf("SPRINTF failed\n");

#ifdef OUR_SYSTEM

  if (!sscanf(" 6"," %f",&f))
    printf("_FORMATTED_READ failed\n");

  if (lsscanf(_formatted_read," 6"," %f",&f) != 1 || f != 6)
    printf("_FORMATTED_READ failed\n");

  if (lsscanf(_formatted_read," 6 hufg"," %d %s",&i,carray) != 2)
    printf("_FORMATTED_READ failed\n");

  if (lsscanf(_medium_read," 6"," %f",&f))
    printf("_MEDIUM_READ failed\n");

  if (lsscanf(_medium_read," 6 hufg"," %d %s",&i,carray) != 2)
    printf("_MEDIUM_READ failed\n");

  if (lsprintf(_small_write,carray,"%2d",5) != 2 ||
      strcmp(carray,"2d") ||
      lsprintf(_small_write,carray,"%d",5) != 1 ||
      strcmp(carray,"5"))
    printf("_SMALL_WRITE failed\n");

  if (lsprintf(_medium_write,carray,"%2d",5) != 2 ||
      strcmp(carray," 5") ||
      lsprintf(_medium_write,carray,"%d",5) != 1 ||
      strcmp(carray,"5") ||
      lsprintf(_medium_write,carray,"%f",5.0) != 34 ||
      strcmp(carray,"FLOATS? wrong formatter installed!"))
    printf("_MEDIUM_WRITE failed\n");

  if (lsprintf(_formatted_write,carray,"%g",5.75) != 4 ||
      strcmp(carray,"5.75"))
    printf("_FORMATTED_WRITE failed\n");

/*------------------------------------------*/
/*            "LIB" Library Test             */
/*------------------------------------------*/

  i = rand();
  srand(1);
  if (i != rand())
    printf("RAND failed\n");
        
  srand(12);
  i = rand();
  srand(12);
  if (i != rand())
    printf("SRAND faild\n");
        
  if ((i = abs(-345)) != 345)
    printf("ABS failed\n");

  if ((li = labs(-345)) != 345)
    printf("LABS failed\n");

  dt = div(35, 8);
  if ((dt.quot != 4) || (dt.rem != 3))
    printf("DIV failed\n");

  ldt = ldiv(35, 8);
  if ((ldt.quot != 4) || (ldt.rem != 3))
    printf("LDIV failed\n");



#endif
        
  printf ("END C Library Test\n");

  abort();
}



