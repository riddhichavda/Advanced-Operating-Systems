#ifndef _F_QUEUE_H_
#define _F_QUEUE_H_

#define QUEUE_SIZE 50	
#include <xinu.h>
typedef struct fqueue
{
   int parray[QUEUE_SIZE];		
   int front;		
   int rear;
   int count;
} queue;

#endif
