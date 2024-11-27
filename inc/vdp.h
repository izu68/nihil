#ifndef VDP_H
#define VDP_H

#include "types.h"

extern void vdp_reset (void);
extern void vdp_clear_mem (void);
extern void vdp_wait_vblank (void);

void c_vdp_write_vram_cpu (u16 size_words, u16 dest, void* data_ptr)
{
	__asm__ volatile
	(
		"move.w %0, %%d0\n\t"
		"move.w %1, %%d1\n\t"
		"move.l %2, %%a0\n\t"
		"bsr vdp_write_vram_cpu"
		:
		: "r" ( dest ), "r" ( size_words ), "m" ( data_ptr )
		: "d0", "d1", "a0"
	);
}

void c_vdp_write_vram_cpu_l (u16 size_longs, u16 dest, void* data_ptr)
{
	__asm__ volatile
	(
		"move.w %0, %%d0\n\t"
		"move.w %1, %%d1\n\t"
		"move.l %2, %%a0\n\t"
		"bsr vdp_write_vram_cpu_l"
		:
		: "r" ( dest ), "r" ( size_longs ), "m" ( data_ptr )
		: "d0", "d1", "a0"
	);
}

void c_vdp_write_cram_cpu (u8 pal_num, void* data_ptr) 
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

void c_vdp_issue_dma (u16 size_bytes, u16 dest, void* source)
{
	__asm__ volatile
	(
		"move.w	%0, %%d0\n\t"
		"move.w %1, %%d1\n\t"
		"move.l	%2, %%a0\n\t"
		"bsr	vdp_issue_dma"
		:
		: "r" (size_bytes), "r" (dest), "m" (source)
		: "d0", "d1", "a0"
	);
}

#endif
