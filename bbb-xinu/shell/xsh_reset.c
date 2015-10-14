#include <xinu.h>
#include <stdio.h>
shellcmd xsh_reset(int nargs, char *args[])
{
	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
		printf("Use: %s [file...]\n\n", args[0]);
		printf("Description:\n");
		printf("\tWelcome to the world of XINU\n");
		return 0;
	
	}	
	volatile uint32 *prm_rstctrl= (volatile uint32 *) 0x44E00F00;
	*prm_rstctrl = 0x01;
	return 0;
}
