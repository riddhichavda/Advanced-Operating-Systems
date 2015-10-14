#include <prodcons.h>
uint future_cons(future *fut) {
  
  int i, status;
  status = future_get(fut, &i);
  if (status < 1) 
  {   
    return -1;
  }
  printf("It consumed %d \n", i);
  future_free(fut);
  return OK;
}
