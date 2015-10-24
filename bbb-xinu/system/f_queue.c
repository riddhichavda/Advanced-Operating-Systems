/* queue.c - enqueue, dequeue */

#include <f_queue.h>


/*------------------------------------------------------------------------
 *  enqueue  -  Insert a process at the tail of a queue
 *------------------------------------------------------------------------
 */
pid32	feq(
	  pid32		pid,	/* ID of process to insert	*/
	  queue* q		/* ID of queue to use		*/
	  
	  
	)
{
	//printf("front %d\n", q->front);
	//printf("rear %d\n", q->rear);
	/*if(q->front == -1 && q->rear == -1){
		q->front = (q->front + 1)%QUEUE_SIZE;
		q->rear = (q->front + 1)%QUEUE_SIZE;
		q->parray[q->rear] = pid;
	}else{
		q->parray[++q->rear] = pid;
	}*/

	if(q->count == QUEUE_SIZE){
		return (pid32)SYSERR;
	}

	q->rear = (q->rear + 1)%QUEUE_SIZE;
	q->parray[q->rear] = pid;
	q->count++;

	//printf("exit front %d\n", q->front);
	//printf("exit rear %d\n", q->rear);
	return pid;
}


/*------------------------------------------------------------------------
 *  dequeue  -  Remove and return the first process on a list
 *------------------------------------------------------------------------
 */
pid32	fdq(
	  queue* q	/* ID of queue to use		*/
	  
	)
{
	if(q->count == 0){
		return (pid32)SYSERR;
	}
	pid32 pid;
	pid = q->parray[q->front];
	q->front = (q->front + 1)%QUEUE_SIZE;
	q->count--;
	return pid;
}

int	fisempty(
	  queue* q	/* ID of queue to use		*/
	  
	)
{
	if(q->count == 0){
		return 1;
	}
	return 0;
}
