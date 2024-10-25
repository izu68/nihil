#include "nihil.h"

int main ( void )
{
	c_vdp_reset ();
	c_vdp_clearmem ();
	
	while ( 1 )
	{
		c_vdp_wait_vblank ();
	}
}
