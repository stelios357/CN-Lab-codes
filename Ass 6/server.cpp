//• Include standard libraries:
#include <stdio.h>
#include<stdlib.h>

//• Include libraries for definition of socket functions.
#include<sys/types.h>
#include<sys/socket.h> //for socket APIs
#include<netinet/in.h> //structure for storing address information
int main(){
	
//create a string to hold data to be sent to client
char serverData[255] = "Hello cleint";

//create server socket similar to what was done in client program
int servSockD;
servSockD = socket(AF_INET, SOCK_STREAM, 0);

//define server address
struct sockaddr_in servAddr;
servAddr.sin_family = AF_INET;
servAddr.sin_port = htons(9001);
servAddr.sin_addr.s_addr = INADDR_ANY;

//bind socket to the specified IP and port
bind(servSockD, (struct sockaddr*) &servAddr, sizeof(servAddr));

//listen for connections
listen(servSockD, 1);

/* Here, the second parameter is the number of connections waiting for this
particular socket, keep it 1 for this example. For network applications that deal
with lots of traffic, this number is important. */
//create an integer to hold client socket.

int clientSocket;
clientSocket = accept(servSockD, NULL, NULL);
//send messages to client socket
send(clientSocket, serverData, sizeof(serverData), 0);
//close the socket
pclose(servSockD);
}
