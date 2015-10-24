#include <future.h> 

/* sets state of future to FREE */
syscall future_free(future *f){
	intmask mask;
	mask = disable();
	if(f->flag != FUTURE_EXCLUSIVE){
		freemem((char*)f->get_queue, sizeof(queue));
		if(f->flag != FUTURE_SHARED){
			freemem((char*)f->set_queue, sizeof(queue));
		return OK;		
		}		
	}
	freemem((char*)f, sizeof(f));
	restore(mask);
  	return OK;

}
