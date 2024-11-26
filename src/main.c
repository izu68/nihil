#include "nihil.h"

int main (void)
{
	c_vdp_reset ();
	c_vdp_clear_mem ();
	
	while (1)
	{
		c_vdp_wait_vblank ();
	}
}
