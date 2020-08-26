/*
*************************************
   Last 03.10.02£. 11:51:13
   Edit 09.10.02£. 14:57:32

   Head SCAN_CMD.h  for   Scan_CMD.c

   Ver 0.01
*************************************
*/

#ifndef __MACROS_H
#define __MACROS_H      1

#ifndef BIT
#define BIT(x)  (1 << (x))
#endif

/* Set and clear bits in I/O registers can also be declared as macros */
#ifndef SetBit
#define SetBit(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#endif
#ifndef ClrBit
#define ClrBit(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#endif
/* Macro for testing of a single bit in an I/O location*/
/* Macro for testing of a single bit in an I/O location*/
#ifndef CheckBit
#define CheckBit(ADDRESS,BIT) (ADDRESS & (1<<BIT))
#endif
/* Use of bit-mask for status bits*/
/* Define bit macros, note that they are similar to the I/O macros*/
#ifndef SETBIT
#define SETBIT(x,y) (x |= (x |=(1<<y))) /* Set bit y in byte x*/
#endif
#ifndef CLEARBIT
#define CLEARBIT(x,y) (x &= (~(1<<y))) /* Clear bit y in byte x*/
#endif
#ifndef CHECKBIT
#define CHECKBIT(x,y) (x & ((1<<y))) /* Check bit y in byte x*/
#endif

#ifndef _asm
#define _asm    asm                     /* old style */

#define WDR()   asm("wdr")
#define SEI()   asm("sei")
#define CLI()   asm("cli")
#define NOP()   asm("nop")
#define _WDR()  asm("wdr")
#define _SEI()  asm("sei")
#define _CLI()  asm("cli")
#define _NOP()  asm("nop")

#endif
#endif

/* Buffer Scan CMD Defines for Stream STDIN */
#define BUFFER_SIZE_CMD  40

static char BUF_CMD[BUFFER_SIZE_CMD+2];
static volatile unsigned char Head_CMD;

static char BUF_TEST[BUFFER_SIZE_CMD+2];
static volatile unsigned char Head_TEST;

/* Buffer Parametrs for Functions from Dic_CMD.name */
#define CMD_PAR_MAX 5
#define PAR_SIZE   10
typedef struct pars
  {
    char id;
    char par[PAR_SIZE] ;
  } pars;

static pars CMD_PAR[CMD_PAR_MAX];

/* Define array dictionary function for KEY_CONTR */
typedef struct dic
  {
    char name[BUFFER_SIZE_CMD/2] ;
    char pars;
    char info_name[BUFFER_SIZE_CMD];
  } dic;

#define COUNT_CMD 6

dic __flash Dict_CMD[COUNT_CMD] = {\
"x",1,"Fuction display X",\
"y",1,"Fuction display Y",\
"z",1,"Fuction display Z",\
"list",0,"Function list functions",\
"view",1,"Fuction view",\
"print",2,"Function print"};

/**************/
/*  Variable  */

static char ERROR_CMD;
static volatile char MODE_OUT_MSG;

/**************************/
/* New prototype function */

// size_t  strlen_c( char *str );
char   *strcat_c( char *str1,char *str2 );
char   *strchr_c( char *str, int n );
int     strcmp_c( char *str1, char *str2 );
int     strcmp_cr( char *str1, char __flash *str2 );
int     strlen_cr( char __flash *str );
int     test_cmd_s( char *str1, volatile int *ps );
void    out_err_msg( char *s1, int id_msg, volatile int *ps, int codepage );