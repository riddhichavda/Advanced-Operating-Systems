#include <own_net.h>
#include <stdlib.h>
int string_length(char s[]) {
   int c = 0;
   while (s[c] != '\0')
      c++;
 
   return c;
}
 int xinu_client(void){
  
	int i, buf;				
	int retval;
	char msg[] = "Message!!!!!!"; 
	char inbuf[1500];		
	int32 slot;			/* UDP slot to use		*/
	int32 msglen;			/* length of outgoing message	*/
	uint32 remoteip; /* remote IP address to use	*/
	dot2ip("192.168.1.100", &remoteip);
	uint16 echoport= 1234;		/* port number for UDP echo	*/
	uint16 locport	= 5678;		/* local port to use		*/
	int32 retries	= 3;		/* number of retries		*/
	int32 delay	= 2000;		/* reception delay in ms	*/
	
	slot = udp_register(remoteip, echoport, locport);
	/* Retry sending outgoing datagram and getting response */

	msglen = string_length(msg);
	for (i=0; i<retries; i++) {
		retval = udp_send(slot, msg, (msglen+10));
		printf("Waiting for message from Ubuntu\n"); 
		retval = udp_recv(slot, inbuf, sizeof(inbuf), delay);
		if (retval == TIMEOUT) {
			
			continue;
		} else if (retval == SYSERR) {
			udp_release(slot);
			return 1;
		} else {	
		break;
		}
	}
	printf("Message received from Ubuntu : %s \n", inbuf);
	udp_release(slot);
	return atoi(inbuf);
}
