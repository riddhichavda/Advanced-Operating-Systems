#include <future.h>
syscall future_set(future *f, int *value)
{
	
	if(f->state == FUTURE_VALID || f->state == FUTURE_EMPTY)		
	{
		return SYSERR;
	}
	else
	{
		f->value = value;
		f->state = FUTURE_VALID;
		ready(f->pid);
		return OK;
	}
}

