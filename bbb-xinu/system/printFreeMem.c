 #include <xinu.h>
#include <stddef.h>
syscall printFreeMem()
{
	intmask	mask;			/* Saved interrupt mask		*/
	struct	memblk	*prev, *curr;

	mask = disable();

	prev = &memlist;
	curr = memlist.mnext;

	while (curr != NULL) 
	{			/* Search free list	*/
		kprintf("Memory address: %d,\t Block size: %d \n",curr, (uint32)curr->mlength);
		prev = curr;
		curr = curr->mnext;
	}

	restore(mask);
	return OK;
}
