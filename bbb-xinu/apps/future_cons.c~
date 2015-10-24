#include<prodcons.h>
#include<f_queue.h>
uint future_cons(future *fut) {

	
	int i, status;

	//printf("in consumer");
	status = future_get(fut, &i);

	if (status < 1) {
		printf("future_get failed\n");
		return -1;
	}
	
	printf("it produced %d (Consumer PID : %d)\n", i, currpid);
	if(fut->flag == FUTURE_EXCLUSIVE){
		//printf("exc cleaning\n");
		future_free(fut);		
		//printf("exc cleaned\n");
	}
	if(fisempty(fut->get_queue)){
		//printf("cleaning\n");
		future_free(fut);
		//printf("cleaned\n");
	}
	
	return OK;
}
