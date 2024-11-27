#ifndef KDEBUG_H
#define KDEBUG_H

void c_kdebug_alert (char* str)
{
    	__asm__ volatile 
	(
        	"move.l %0, %%a0\n\t"
        	"bsr kdebug_alert"
        	:
        	: "m" (str)
        	: "a0"
    	);
}


#endif
