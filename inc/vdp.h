#ifndef VDP_H
#define VDP_H

#include "types.h"

extern void vdp_reset (void);
extern void vdp_clear_mem (void);
extern void vdp_wait_vblank (void);

void c_vdp_write_vram_cpu_w ( word vram_addr, word words_num, void* data_ptr )
{
	__asm__ volatile
	(
		"move.w %0, %%d0\n\t"
		"move.w %1, %%d1\n\t"
		"move.l %2, %%a0\n\t"
		"bsr vdp_write_vram_cpu_w"
		:
		: "r" ( vram_addr ), "r" ( words_num ), "m" ( data_ptr )
		: "d0", "d1", "a0"
	);
}

void c_vdp_write_vram_cpu_l ( word vram_addr, word longs_num, void* data_ptr )
{
	__asm__ volatile
	(
		"move.w %0, %%d0\n\t"
		"move.w %1, %%d1\n\t"
		"move.l %2, %%a0\n\t"
		"bsr vdp_write_vram_cpu_l"
		:
		: "r" ( vram_addr ), "r" ( longs_num ), "m" ( data_ptr )
		: "d0", "d1", "a0"
	);
}

void c_vdp_write_cram_cpu ( byte pal_num, void* data_ptr ) 
{
    	__asm__ volatile 
	(
        	"move.b	%0, %%d0\n\t"
        	"move.l %1, %%a0\n\t"
        	"bsr vdp_write_cram_cpu"
        	:
        	: "r" ( pal_num ), "m" ( data_ptr )
        	: "d0", "a0"
    	);
}

void c_vdp_issue_dma (word length, word dest, void* source)
{
	__asm__ volatile
	(
		"move.w	%0, %%d0\n\t"
		"move.w %1, %%d1\n\t"
		"move.l	%2, %%a0\n\t"
		"bsr	vdp_issue_dma"
		:
		: "r" (length), "r" (dest), "m" (source)
		: "d0", "d1", "a0"
	);
}

#endif
