int main ( void )
{
	__asm__ volatile
	(
		"bsr	vdp_reset\n"
		"bsr	vdp_clearmem"
	);
	__asm__ volatile
	(
		"move.b	#0x00, 0xA130F0\n"
		"move.b #0x01, 0xA13070\n"
		"move.b #0x03, 0xA13073\n"
		"move.b #0xFF, 0xA130F0"
	);
	
	while ( 1 )
	{
		__asm__ volatile
		(
		"bsr	vdp_wait_vblank"
		);
	}
}
