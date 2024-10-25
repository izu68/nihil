// -----------------------------------------------------------------
// C Nihil - Assembly method forwarding
// -----------------------------------------------------------------

#ifndef H_NIHIL
#define H_NIHIL

// ================= VDP ===========================================

extern void c_vdp_reset ( void ) __asm__("vdp_reset");
extern void c_vdp_clearmem ( void ) __asm__("vdp_clearmem");
extern void c_vdp_wait_vblank ( void ) __asm__("vdp_wait_vblank");

void c_vdp_write_cram_cpu ( int palette_number, void* data_pointer ) 
{
    __asm__ volatile (
        "move.b	%0, %%d0\n\t"
        "move.l %1, %%a0\n\t"
        "jsr vdp_write_cram_cpu"
        :
        : "r" ( palette_number ), "r" ( data_pointer )
        : "d0", "a0"
    );
}

#endif
