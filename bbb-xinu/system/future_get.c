#include <future.h>
syscall future_get(future *f, int *value)
{
	
	struct	procent *prptr;
	prptr = &proctab[currpid];
	
	if(f->state == FUTURE_EMPTY)		
	{		
		f->pid = currpid;
		f->state = FUTURE_WAITING;
		
		prptr->prstate = PR_WAIT;
		resched();
		*value = *f->value;
		return OK;
	}
	else if(f->state == FUTURE_WAITING && f->pid != NULL)
	{
		return SYSERR;
	}
	else
	{
		*value = *f->value;
		f->pid = NULL;
		f->state = FUTURE_EMPTY;
		future_free(f);
		return OK;
	}
}

