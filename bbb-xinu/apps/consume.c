#include <prodcons.h>

void consumer(int count) {
      //Use system call wait() and signal() with predefined semaphores 
      //produced and consumed to synchronize critical section
      //Code to consume values of global variable 'n' until the value
      //of n is less than or equal to count
      //print consumed value e.g. consumed : 8	
	
	while(n <= count)
	{
		wait(produced);
		printf("Consumed value : %d ...\n",n);
		if ( n == count )
		break;
		signal(consumed);
	}
	semdelete(produced);
	semdelete(consumed);
}
