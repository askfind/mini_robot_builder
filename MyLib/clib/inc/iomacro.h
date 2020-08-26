/**************************************************************
 **             - iomacro.h -
 **
 **     This file defines the Special Function Register Macros
 **     for Atmel AT90S.
 **
 **     Used with iccAVR and aAVR.
 **
 **     Copyright IAR Systems 1999. All rights reserved.
 **
 **     $Name: $
 **
 **************************************************************/

#ifndef __IOMACRO_H
#define __IOMACRO_H

#define TID_GUARD(proc) ((__TID__ & 0x7FF0) != ((90 << 8) | ((proc) << 4)))

#if !(__IAR_SYSTEMS_ICC__ > 2) && !defined(__IAR_SYSTEMS_ASM__)
#error This file should only be compiled with iccavr or aavr.
#endif /* !(__IAR_SYSTEMS_ICC__ > 2) && !defined __IAR_SYSTEMS_ASM__ */

/* The assembler uses a special set of macros... */
#ifdef __IAR_SYSTEMS_ASM__

/* Byte sized SFRs */
#define SFR_B_BITS(_NAME,_ADDR,_A,_B,_C,_D,_E,_F,_G,_H)\
	sfrb	_NAME = _ADDR
#define SFR_B2_BITS(_NAME1,_NAME2,_ADDR,_A,_B,_C,_D,_E,_F,_G,_H)\
	ASMSFRB2 _NAME1, _NAME2, _ADDR

ASMSFRB2 MACRO
	sfrb	\1 = \3
	sfrb	\2 = \3
	ENDM


/* Word sized SFRs, needs to be expanded into an assembler macro first. */
#define SFR_W_BITS(_NAME, _ADDR, _A,_B,_C,_D,_E,_F,_G,_H, _I,_J,_K,_L,_M,_N,_O,_P)\
	ASMSFRW	_NAME, _ADDR

ASMSFRW	MACRO
	sfrw	\1  = \2
	sfrb	\1L = (\2+0)
	sfrb	\1H = (\2+1)
	ENDM

#endif /* __IAR_SYSTEMS_ASM__ */

#ifdef __ICCAVR__

#define __BYTEBITS(_NAME,_A,_B,_C,_D,_E,_F,_G,_H) \
unsigned char _NAME ## _ ## _A:1, \
              _NAME ## _ ## _B:1, \
              _NAME ## _ ## _C:1, \
              _NAME ## _ ## _D:1, \
              _NAME ## _ ## _E:1, \
              _NAME ## _ ## _F:1, \
              _NAME ## _ ## _G:1, \
              _NAME ## _ ## _H:1;

#define SFR_B_BITS(_NAME, _ADDR, _A,_B,_C,_D,_E,_F,_G,_H) \
    __io union { \
      unsigned char   _NAME;           /* The sfrb as 1 byte */ \
      struct {                        /* The sfrb as 8 bits */ \
        __BYTEBITS(_NAME, _A,_B,_C,_D,_E,_F,_G,_H) \
      };  \
    } @ _ADDR;
#define SFR_B2_BITS(_NAME1, _NAME2, _ADDR, _A,_B,_C,_D,_E,_F,_G,_H) \
    __io union { \
      unsigned char   _NAME1;           /* The sfrb as 1 byte */ \
      unsigned char   _NAME2;           /* The sfrb as 1 byte */ \
      struct {                        /* The sfrb as 8 bits */ \
        __BYTEBITS(_NAME1, _A,_B,_C,_D,_E,_F,_G,_H) \
      };  \
      struct {                        /* The sfrb as 8 bits */ \
        __BYTEBITS(_NAME2, _A,_B,_C,_D,_E,_F,_G,_H) \
      };  \
    } @ _ADDR;
#define SFR_B_BITS_EXT(_NAME, _ADDR, _A,_B,_C,_D,_E,_F,_G,_H) \
    __tiny __no_init volatile union { \
      unsigned char   _NAME;           /* The sfrb as 1 byte */ \
      struct {                        /* The sfrb as 8 bits */ \
        __BYTEBITS(_NAME, _A,_B,_C,_D,_E,_F,_G,_H) \
      };  \
    } @ _ADDR;
  
#define SFR_W_BITS(_NAME, _ADDR, _A,_B,_C,_D,_E,_F,_G,_H, _I,_J,_K,_L,_M,_N,_O,_P) \
    __io union { \
      unsigned short  _NAME;  /* The sfrw as 1 short */ \
      struct {                /* The sfrw as 16 bits */ \
        __BYTEBITS(_NAME, _A,_B,_C,_D,_E,_F,_G,_H)   /* Bit names defined by user */  \
        __BYTEBITS(_NAME, _I,_J,_K,_L,_M,_N,_O,_P)   /* Bit names defined by user */  \
      };  \
      struct { /* The sfrw as 2 bytes */ \
        unsigned char _NAME ## L; \
        unsigned char _NAME ## H; \
      };  \
      struct {                          /* The sfrw as 2 x 8 bits */ \
        __BYTEBITS(_NAME ## L, Bit0,Bit1,Bit2,Bit3,Bit4,Bit5,Bit6,Bit7)  /* Bit names hard coded to 0-7 */ \
        __BYTEBITS(_NAME ## H, Bit0,Bit1,Bit2,Bit3,Bit4,Bit5,Bit6,Bit7)  /* Bit names hard coded to 0-7 */ \
      };  \
    } @ _ADDR;

#endif /* __ICCAVR__ */

#define SFR_B(_NAME, _ADDR) SFR_B_BITS(_NAME, _ADDR, \
                                    Bit0,Bit1,Bit2,Bit3,Bit4,Bit5,Bit6,Bit7)
#define SFR_B2(_NAME1, _NAME2, _ADDR) SFR_B2_BITS(_NAME1, _NAME2, _ADDR, \
                                    Bit0,Bit1,Bit2,Bit3,Bit4,Bit5,Bit6,Bit7)
#define SFR_B_EXT(_NAME, _ADDR) SFR_B_BITS_EXT(_NAME, _ADDR, \
                                    Bit0,Bit1,Bit2,Bit3,Bit4,Bit5,Bit6,Bit7)

#define SFR_W(_NAME, _ADDR)  SFR_W_BITS(_NAME, _ADDR, \
                                    Bit0,Bit1,Bit2,Bit3,Bit4,Bit5,Bit6,Bit7, \
                                    Bit8,Bit9,Bit10,Bit11,Bit12,Bit13,Bit14,Bit15)

#endif /* __IOMACRO_H */
