#include <prodcons.h>
uint future_cons(future *fut) {
  
  int i, status;
  
  while(1)
{
  status = future_get(fut, &i);


  if (status < 1)
  {
   continue;
  }
 
  else if (status == 1) {
   printf("Consumed Value : %d \n",i);    //restore(im);
    break;

  }

 } 
  future_free(fut);
  return OK;
}
