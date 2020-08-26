/**************************************************************
 **             - __segment_init.c -
 **
 **     Segment initialization that must be
 **     performed before main is called.
 **
 **     Used with iccAVR.
 **
 **     Copyright 1999 IAR Systems. All rights reserved.
 **
 **     $Revision: 1.1 $
 **
 **************************************************************/
#ifndef __SEGMENT_INIT_H_INCLUDED
#define __SEGMENT_INIT_H_INCLUDED

#pragma language=extended

#define PROC_OPT ((__TID__ >> 4) & 0x000F)

#if PROC_OPT > 1
/* Processor options 2 ... 6 has > 64k flash memory. */
typedef char __hugeflash *SrcPtr_Type;
#else
/* Processor options 0 and 1 has <= 8K flash memory. */
typedef char __flash *SrcPtr_Type;
#endif /* PROC_OPT */

#if (PROC_OPT == 0) || (PROC_OPT == 2)
/* We have tiny (8-bit) index pointers */
typedef char __tiny  *DstPtr_Type;
typedef unsigned char Counter_Type;
#elif (PROC_OPT == 1) || (PROC_OPT == 3) || (PROC_OPT == 5)
/* We have normal (16-bit) index registers */
typedef char __near  *DstPtr_Type;
typedef unsigned int  Counter_Type;
#elif (PROC_OPT == 4) || (PROC_OPT == 6)
/* We have huge (24-bit) index registers */
typedef char __huge  *DstPtr_Type;
typedef unsigned long Counter_Type;
#else
#error Unknown processor option used!!!
#endif /*PROC_OPT */

/* A SegmentInitBlock_Type record describes one block */
/* that should be initialized during system startup.  */
/* The INITTAB segment contains an unspecified number */
/* of SegmentInitBlock_Type records.                  */
typedef struct
  {
    /* If Src is equal to Dst then the block pointed to  */
    /* by Dst should be cleared. If Src is not equal to  */
    /* Dst then Src points to data that should be copied */
    /* to the block pointed to by Dst.                   */
    SrcPtr_Type   Src;

    /* Dst points to the block that should be   */
    /* initialized, either by setting all bytes */
    /* to 0 or copying data from the block      */
    /* pointed to by Src.                       */
    DstPtr_Type   Dst;

    /* Cnt determines the size of the block     */
    /* pointed to by Dst is.                    */
    Counter_Type  Cnt;
  } SegmentInitBlock_Type;

#pragma language=default

#endif /* __SEGMENT_INIT_H_INCLUDED */
