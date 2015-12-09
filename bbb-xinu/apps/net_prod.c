#include<own_net.h>
uint net_prod(future *fut) 
{

	int i, j;
	j = xinu_client(); 
	future_set(fut, &j);
	return OK;
}
