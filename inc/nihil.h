// -----------------------------------------------------------------
// C Nihil - Assembly method forwarding
// -----------------------------------------------------------------

#ifndef H_NIHIL
#define H_NIHIL

// ================= VDP ===========================================

extern void c_vdp_reset ( void ) __asm__("vdp_reset");
extern void c_vdp_clearmem ( void ) __asm__("vdp_clearmem");
extern void c_vdp_wait_vblank ( void ) __asm__("vdp_wait_vblank");


#endif
