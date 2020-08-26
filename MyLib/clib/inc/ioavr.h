/**************************************************************
 **             - IO_AVR.H -
 **
 **     I/O definitions for iccAVR
 **
 **     Used with iccAVR.
 **
 **     Copyright IAR Systems 2001. All rights reserved.
 **
 **     $Name: $
 **
 **************************************************************/

#ifndef __IO_AVR_H
#define __IO_AVR_H

#ifndef __ICCAVR__
#error This file should only be compiled with iccAVR
#endif /* __ICCAVR__ */

#if defined(__AT90tiny22__)
#include "iotiny22.h"
#elif defined(__AT90S2313__)
#include "io2313.h"
#elif defined(__AT90S2323__)
#include "io2323.h"
#elif defined(__AT90S2333__)
#include "io2333.h"
#elif defined(__AT90S2343__)
#include "io2343.h"
#elif defined(__AT90S4414__)
#include "io4414.h"
#elif defined(__AT90S4433__)
#include "io4433.h"
#elif defined(__AT90S4434__)
#include "io4434.h"
#elif defined(__AT90S8515__)
#include "io8515.h"
#elif defined(__AT90S8534__)
#include "io8534.h"
#elif defined(__AT90S8535__)
#include "io8535.h"
#elif defined(__AT90Mega103__)
#include "iom103.h"
#elif defined(__AT90Mega161__)
#include "iom161.h"
#elif defined(__AT90Mega603__)
#include "iom603.h"
#elif defined(__AT90Mega83__)
#include "iom83.h"
#elif defined(__AT90Mega163__)
#include "iom163.h"
#elif defined(__AT90Mega323__)
#include "iom323.h"
#elif defined(__AT90Mega16__)
#include "iom16.h"
#elif defined(__AT90Mega128__)
#include "iom128.h"
#elif defined(__AT94Kxx__)
#include "ioat94k.h"
#elif defined(__AT90Mega8__)
#include "iom8.h"
#else
#error This file, should only be compiled with "--cpu" set
#endif

#endif /* __IO_AVR_H */
