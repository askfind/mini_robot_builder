/**************************************************************
 **             - INAVR.H -
 **
 **     Backwards compatibility macros for iccAVR
 **
 **     Used with iccAVR.
 **
 **     Copyright IAR Systems 1999. All rights reserved.
 **
 **     $Name: V2_26B V2_25B V2.21H V2.21G V2_25A $
 **
 **************************************************************/

#ifndef __COMP_A90_H
#define __COMP_A90_H

#ifdef __ICCAVR__

#define tiny     __tiny
#define near     __near
#define far      __far
#define huge     __huge

#define flash    const __flash
#define farflash const __farflash

#define nearfunc  __nearfunc
#define farfunc   __farfunc

#define sfrb     int int int Cannot use sfrb keyword in iccAVR;
#define sfrw     int int int Cannot use sfrw keyword in iccAVR;

#define monitor   __monitor
#define C_task    __C_task
#define no_init   __no_init

#ifndef _CLI
#define _CLI() __disable_interrupt()
#endif

#ifndef disable_interrupt
#define disable_interrupt()  __disable_interrupt()
#endif

#ifndef _SEI
#define _SEI() __enable_interrupt()
#endif

#ifndef enable_interrupt
#define enable_interrupt() __enable_interrupt()
#endif

#ifndef _NOP
#define _NOP() __no_operation()
#endif

#ifndef _SLEEP
#define _SLEEP() __sleep()
#endif

#ifndef _LPM
#define _LPM(ADDR) __load_program_memory(ADDR)
#endif

#ifdef __HAS_ELPM__
#ifndef _ELPM
#define _ELPM(ADDR) __extended_load_program_memory(ADDR)
#endif
#endif

#ifndef _WDR
#define _WDR() __watchdog_reset()
#endif

#ifndef _OPC
#define _OPC(opCode) __insert_opcode(opCode)
#endif

#ifndef _EEPUT
#define _EEPUT(V,A) __EEPUT(V,A)
#endif

#ifndef _EEGET
#define _EEGET(V,A) __EEGET(V,A)
#endif

#endif /* __ICCAVR__ */

#endif /* __COMP_A90_H */
