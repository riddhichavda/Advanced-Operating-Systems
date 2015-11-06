
#include <proc_function.h>

struct	procent *prptr;	
char	*stack_ptr;
uint32	stacklen;
int n;

shellcmd xsh_memmanage(int nargs, char *args[])
{	pid32 proc_id;
	char    *local_ptr;
	int p=1024,i,j;
	if(nargs > 2)
	{
		printf("Too many arguments.\nType memmanage --help for details.\n");
		return 0;
	}

	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0)
	{
		printf("Description:\n");
		printf("\t--help\t display this help and exit\n");
		printf("\t\tMemory management\n");
		return 0;
	}
	else
	{
		if(nargs == 1)
		{
			//9.1			
			printFreeMem();
			//9.4 heap
			i=own_getmem(sizeof(int));
			printFreeMem();
			//9.4 stack
			proc_id=own_create(proc_function, p, 20, "proc_function");
			printFreeMem();
			//9.7
			prptr = &proctab[proc_id];
			stack_ptr = prptr->prstkptr;
			stacklen = prptr->prstklen;
			local_ptr = stack_ptr;
			for(j=0;j<stacklen;j++)
			{
				*local_ptr = 'a';				
				local_ptr--;
			}
			resume(proc_id);
			printf("Total stack memory allocated: %d \n",p);
			printf("Total stack memory used: %d \n",n);
			printf("Maximum stack size left when the process exits: %d \n",p-n);
			return 0;
	
		}
	}
	return 0;
}			
	

