#include <prodcons.h>
void producer(int count) {
      //Use system call wait() and signal() with predefined semaphores produced and consumed to synchronize critical section
	
      //Code to produce values less than equal to count, 
      //produced value should get assigned to global variable 'n'.
      //print produced value e.g. produced : 8	

			
	while(n < count)
	{
		wait(consumed);	
		n++;			
		printf("Produced value : %d \n",n);
		signal(produced);	
	}
 }
