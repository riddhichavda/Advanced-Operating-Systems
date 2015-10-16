#include <future.h>
syscall future_set(future *f, int *value)
{
	intmask	mask;
	mask = disable();
	if(f->state == FUTURE_VALID || f->state == FUTURE_EMPTY)		
	{		
		restore(mask);		
		return SYSERR;
	}
	else
	{	
		f->value = *value;
		f->state = FUTURE_VALID;
		restore(mask);
		return OK;
	}
}

