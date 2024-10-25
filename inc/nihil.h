// -----------------------------------------------------------------
// C Nihil - Assembly method forwarding
// -----------------------------------------------------------------

#ifndef H_NIHIL
#define H_NIHIL

// ================= VDP ===========================================

extern void c_vdp_reset ( void ) __asm__("vdp_reset");
extern void c_vdp_clearmem ( void ) __asm__("vdp_clearmem");
extern void c_vdp_enable_display ( void ) __asm__("vdp_enable_display");
extern void c_vdp_disable_display ( void ) __asm__("vdp_disable_display");
extern void c_vdp_wait_vblank ( void ) __asm__("vdp_wait_vblank");

void c_vdp_write_vram_cpu_w ( 
		unsigned short vram_addr, unsigned short words_num, void* data_ptr )
{
	__asm__ volatile
	(
		"move.w %0, %%d0\n\t"
		"move.w %1, %%d1\n\t"
		"move.l %2, %%a0\n\t"
		"jsr vdp_write_vram_cpu_w"
		:
		: "r" ( vram_addr ), "r" ( words_num ), "r" ( data_ptr )
		: "d0", "d1", "a0"
	);
}

void c_vdp_write_vram_cpu_l ( 
		unsigned short vram_addr, unsigned short longs_num, void* data_ptr )
{
	__asm__ volatile
	(
		"move.w %0, %%d0\n\t"
		"move.w %1, %%d1\n\t"
		"move.l %2, %%a0\n\t"
		"jsr vdp_write_vram_cpu_l"
		:
		: "r" ( vram_addr ), "r" ( longs_num ), "r" ( data_ptr )
		: "d0", "d1", "a0"
	);
}

void c_vdp_write_cram_cpu ( unsigned char pal_num, void* data_ptr ) 
{
    	__asm__ volatile 
	(
        	"move.b	%0, %%d0\n\t"
        	"move.l %1, %%a0\n\t"
        	"jsr vdp_write_cram_cpu"
        	:
        	: "r" ( pal_num ), "r" ( data_ptr )
        	: "d0", "a0"
    	);
}

#endif
