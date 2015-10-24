
#include <future.h> 
/*
* using the future_flags as an index
*/



future* future_alloc(int future_flags)
{	
	int *val;
	future *f;
	intmask	mask;
	mask=disable();
	f=(future *)getmem(sizeof(future));
	f->value = (int *)getmem(sizeof(int));
	f->state = FUTURE_EMPTY;
	f->flag = future_flags;

	if(future_flags != FUTURE_EXCLUSIVE){
              	queue *setqueue;
	        queue *getqueue;
		if(future_flags != FUTURE_SHARED){
			setqueue = (queue *)getmem(sizeof(queue));
			setqueue->front = 0;
			setqueue->rear = -1;
			setqueue->count=0;
			f->set_queue = setqueue;
		}
		getqueue = (queue *)getmem(sizeof(queue));
		getqueue->front = 0;
		getqueue->rear = -1;		
		getqueue->count=0;			
		f->get_queue = getqueue;
	}
	
	if(f == SYSERR){
			return SYSERR;
	}
	
	restore(mask);
	return f;
}
