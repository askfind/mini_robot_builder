/* Test Programm C++
*/
#include <stdio.h>
#include <iom161.h>
#include <inavr.h>
#include <iostream.h>


#pragma language=extended
volatile char c_var;
volatile int  i_var;
volatile static char cTest;
volatile static int iTest;

//*********************************

typedef union  
  { int i,j;
  } U;

enum day 
  { sp1 , sp2, sp3 } workday;
  
struct s
  { 
    char tag; 
    struct
    { long l ;
      float f; 
    };
  } st ;
  
typedef struct ByteErr
  { 
    unsigned char Byte;
    unsigned char Err;
     
  } Byte_Err ;
    
static volatile __io struct
 {
  unsigned char  in_read:1;
  unsigned char  out_read:1;
  unsigned char  err:1;
  unsigned char  change:1;
  unsigned char  reserv:4;
  } bit_reg @ 0x04;

 
__no_init volatile  struct
 {
  unsigned char  in_read:1;
  unsigned char  out_read:1;
  unsigned char  err:1;
  unsigned char  change:1;
  unsigned char  reserv:4;
  } bit_test ;
  
#pragma type_attribute=__eeprom 
const int  ep_i_var=55 ;
#pragma type_attribute=__eeprom 
 char  ep_c_var;
#pragma type_attribute=__eeprom 
unsigned int ep_a_var[10];

volatile static ByteErr BR[10];

/***********************************
 *    Derived class declaration    *
 ***********************************/
class MyBuf : public streambuf
{

};


void main(void)
{

volatile unsigned int p;
volatile ByteErr TempR;
char xx[128];
volatile  int i;
// enum
workday = sp1;
if (workday == sp1)
workday = sp2;
else
workday = sp3;
workday = sp1;
//typedef  myspeed t_sd;


//

for (i=0;i < 128;i++)
{
 xx[i]= 0;
};

MyBuf TxBuf;
TxBuf.pubsetbuf(xx,128);
//
for (i=1;i<20;i++)
{ 
iTest = TxBuf.sputc('H'+i);
};

//
cTest = TxBuf.sgetc();
//


MyBuf RxBuf;
RxBuf.pubsetbuf(xx,128);

//cout << "Hello\n";
loop:

// New type variable 
st.tag = 10;
st.l= 1234567;
st.f = 1.67;

TempR.Byte = 'A';
TempR.Err  = 1;
BR[1].Byte = 'V';
BR[1].Err = 'H';
//
i_var = 4;
i_var = ep_i_var ;
ep_c_var = 't';
ep_a_var[1] = '1';

bit_reg.in_read = 1;
bit_reg.in_read = 0;
bit_test.in_read = 0;
bit_test.in_read = 1;

goto loop; 
}
