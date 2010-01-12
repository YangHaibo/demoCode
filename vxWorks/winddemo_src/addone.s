/**************************************************************************
*
* Module:       addone.s
*
* Description:  This module contains assembly code for the 
*               Wind River Demonstration Program.
*
*               addone()
*               --------
*               Assembly routine to increment a passed in value. 
*               Illustrates C-to-Assembly traversing
*
* Project:      Wind River Demonstration Program
*
*               Copyright (c) 2003 Wind River Systems, Inc.
*
****************************************************************************/

#define _ASMLANGUAGE

#include "vxWorks.h"
#ifndef CPU_FAMILY
#error build error: -DCPU=yourCPU missing
#endif

    	.text
		.align 4

/*
*   Increment the passed in parameter by one.
*/

#if (CPU_FAMILY==PPC)

        .globl  addone
addone:
    addi    r3,r3,1 # increment parameter...
    bclr    20,0    # go back


#elif (CPU_FAMILY==SIMNT || \
	CPU_FAMILY==SIMLINUX || \
	CPU_FAMILY==SIMPENTIUM || \
	CPU_FAMILY==I80X86 )
	
        .globl  addone
addone:
	movl           	4(%esp), %eax
	incl			%eax
	ret            


#elif (CPU_FAMILY==SIMSPARCSUNOS || \
	CPU_FAMILY==SIMSPARCSOLARIS)

#include "arch/simsolaris/asmSimsolaris.h"

        .global GTEXT(addone)
FUNC_LABEL(addone)
	retl            # deferred return, return value follows
	add %o0,1,%o0   # increment parameter... 


#elif (CPU_FAMILY==MIPS)

    .globl  addone
	.ent	addone
addone:
	addi	v0, a0, 1	# increment parameter...
	jr		ra
	nop
	
	.end	addone


#elif (CPU_FAMILY==SH)

#error "Code is not tested for SH family. Please check, if OK remove this line!"
	.global	_addone
	.align	_ALIGN_TEXT
	.type	_addone,@function
_addone:
	add.l   #1,r0
	rts;
	movt	r0


#elif (CPU_FAMILY==ARM)

#error "Code is not tested for ARM family. Please check, if OK remove this line!"
	.globl	FUNC(addone)
_ARM_FUNCTION_CALLED_FROM_C(addone)
	ADD	r1, #1
#if (ARM_THUMB)
	BX	lr
#else
	MOV	pc, lr
#endif


#else
#error Unknown CPU Family
#endif
