/************* UDP CLIENT CODE *******************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
  int udpSocket, nBytes;
  char buffer[1024];
  struct sockaddr_in serverAddr, clientAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size, client_addr_size;
  int i;

  /*Create UDP socket*/
  udpSocket = socket(PF_INET, SOCK_DGRAM, 0);

  /*Configure settings in address struct*/
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(5678);
  serverAddr.sin_addr.s_addr = inet_addr("192.168.1.101");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

   clientAddr.sin_family = AF_INET;
  clientAddr.sin_port = htons(1234);
  clientAddr.sin_addr.s_addr = inet_addr("192.168.1.100");
  memset(clientAddr.sin_zero, '\0', sizeof clientAddr.sin_zero);  

  /*Bind socket with address struct*/
  bind(udpSocket, (struct sockaddr *) &clientAddr, sizeof(clientAddr));

  /*Initialize size variable to be used later on*/
  addr_size = sizeof serverStorage;
  client_addr_size = sizeof serverAddr;

while(1)
{
    	printf("Waiting for message from Xinu\n");
	nBytes = recvfrom(udpSocket,buffer,1024,0,(struct sockaddr *)&serverAddr, &client_addr_size);
	printf("Message Received from Xinu: %s \n Enter value: \n", buffer);
	fgets(buffer,1024,stdin);
	sendto(udpSocket,buffer,nBytes,0,(struct sockaddr *)&serverAddr,client_addr_size);
   
}

  return 0;
}
