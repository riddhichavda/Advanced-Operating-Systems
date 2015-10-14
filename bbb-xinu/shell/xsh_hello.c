/* xsh_hello.c - xsh_hello */

#include <xinu.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * xhs_hello - write argument strings to stdout
 *------------------------------------------------------------------------
 */
shellcmd xsh_hello(int nargs, char *args[])
{
	int32	i;			/* walks through args array	*/
	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
		printf("Use: %s [file...]\n\n", args[0]);
		printf("Description:\n");
		printf("\tWelcome to the world of XINU\n");
		
		return 0;
	}
	if (nargs == 2) 
		printf("Hello %s", args[1]);
	else if( nargs == 1)
		printf("Too few arguments");
	else
		printf("Too many arguments");
	
	printf("\n");

	return 0;
}
