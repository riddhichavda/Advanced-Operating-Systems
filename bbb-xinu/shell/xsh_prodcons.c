#include <prodcons.h>

/* define states */
#define FUTURE_EMPTY	  0
#define FUTURE_WAITING 	  1         
#define FUTURE_VALID 	  2         

/* modes of operation for future*/
#define FUTURE_EXCLUSIVE  1

int n;                 //Definition for global variable 'n'
sid32 produced,consumed;
/*Now global variable n will be on Heap so it is accessible all the processes i.e. consume and produce*/

shellcmd xsh_prodcons(int nargs, char *args[])
{

  int count = 2000;             //local varible to hold count

 //Argument verifications and validations
  produced = semcreate(0);
  consumed = semcreate(1);

  future *f1, *f2, *f3; 
  f1 = future_alloc(FUTURE_EXCLUSIVE);  
  f2 = future_alloc(FUTURE_EXCLUSIVE);
  f3 = future_alloc(FUTURE_EXCLUSIVE);

  if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
	printf("\tFutures implemetation of producer consumer\n");
	printf("\t1.	prodcons --help : Will provide the help menu\n");
	printf("\t2.	prodcons -f : Futures implemetation of producer consumer\n");
	printf("\t3.	prodcons : Normal implementation of producer consumer\n");
	return 0;
  }

if (nargs == 2 && strncmp(args[1], "-f", 3) == 0) {
	resume( create(future_cons, 1024, 20, "fcons1", 1, f1) );
	resume( create(future_prod, 1024, 20, "fprod1", 1, f1) );
	resume( create(future_cons, 1024, 20, "fcons2", 1, f2) );
	resume( create(future_prod, 1024, 20, "fprod2", 1, f2) );
	resume( create(future_cons, 1024, 20, "fcons3", 1, f3) );
	resume( create(future_prod, 1024, 20, "fprod3", 1, f3) );
  }
  //check args[1] if present assign value to count
  else if(nargs == 2 && atoi(args[1]) <= count && atoi(args[1]) > 0)
  {	
	count = atoi(args[1]);
	n = 0;
	resume( create(producer, 1024, 20, "producer", 1, count));
	printf("Now consumer starts \n");
  	resume( create(consumer, 1024, 20, "consumer", 1, count));

  }
  else if( nargs == 1)
  {
	n = 0;
	resume( create(producer, 1024, 20, "producer", 1, count));
	resume( create(consumer, 1024, 20, "consumer", 1, count));
  }

  else
	printf("Count value invalid. Count value must be between 1 to 2000 \n");
   
  return (0);
}
