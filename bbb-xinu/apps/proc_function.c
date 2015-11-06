#include<proc_function.h>
void proc_function() 
{
	int h=0;	
	while(h < 30)
	{	
		h++;			
	}
	printf("Produced value : %d \n",h);	
	own_kill(currpid);
 }
