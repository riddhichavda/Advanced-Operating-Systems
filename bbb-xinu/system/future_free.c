#include <future.h>
syscall future_free(future* f)
{	
	intmask	mask;
	mask = disable();
	restore(mask);	
	return freemem((char*)f,sizeof(future));
}
