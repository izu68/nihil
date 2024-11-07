int main ( void )
{
	// Reset vdp and clear VRAM, CRAM and VSRAM
	__asm__ volatile
	(
		"bsr	vdp_reset\n"
		"bsr	vdp_clearmem"
	);
	
	while ( 1 )
	{
		// Wait for vblank
		__asm__ volatile
		(
		"bsr	vdp_wait_vblank"
		);
	}
}
