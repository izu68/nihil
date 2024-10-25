#include "nihil.h"

extern const char bruji_pal[];
extern const char bruji_tiles[];
int main ( void )
{
	c_vdp_reset ();
	c_vdp_clearmem ();
	c_vdp_write_cram_cpu ( 0, ( void* ) bruji_pal );
	c_vdp_write_vram_cpu_l ( 0x0000, 160, ( void* ) bruji_tiles );

	c_vdp_enable_display ();
	
	while ( 1 )
	{
		c_vdp_wait_vblank ();
	}
}
