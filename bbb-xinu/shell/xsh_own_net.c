#include <own_net.h>
#define MAX_COUNT 2000
int n;                            //Definition for global variable 'n'
future *f_exclusive, *f_shared, *f_queue;     		//Defination for futures

int isNumericCheck(const char *str){
    while(*str != '\0')
    {
        if(*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}

  /*Now global variables will be on Heap so they are accessible to all the processes i.e. consume and produce*/

   shellcmd xsh_own_net(int nargs, char *args[])
   {	
	//initialize count to default value
	int count = MAX_COUNT;
	
	
	if (nargs == 2) {

		if(strncmp(args[1], "--help", 7) == 0)
			{
				printf("Description:\n");
				printf("\t--help\t display this help and exit\n");
				printf("\t-f \tImplementing client server in Xinu using network operations and Futures Implementation\n");
				printf("\t-c\t communication between Xinu and ubuntu\n");
				
				return 0;
			}
		if (strncmp(args[1], "-c", 3) == 0)
			{
				resume( create(xinu_client, 1024, 20, "xinu_client", 0) );
				return 0;
			}

		if(strncmp(args[1], "-f", 3) == 0)
			{

				f_exclusive = future_alloc(FUTURE_EXCLUSIVE);
						 

				resume( create(net_cons, 1024, 20, "fcons1", 1, f_exclusive) );
				resume( create(net_prod, 1024, 20, "fprod1", 1, f_exclusive) );
				sleep(1);	

				
		
		
				return 0;		

			}
		}
   }
