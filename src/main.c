#include "nihil.h"

extern const char bruji_pal[];
int main ( void )
{
	c_vdp_reset ();
	c_vdp_clearmem ();
	c_vdp_write_cram_cpu ( 0, ( void* ) bruji_pal );
	
	while ( 1 )
	{
		c_vdp_wait_vblank ();
	}
}
