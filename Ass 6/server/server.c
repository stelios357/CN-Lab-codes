#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/socket.h> // for sockets Apis
#include<netinet/in.h>

int main(){


	char serverData[255] = "HEllO client";

	int servSockD;

	servSockD = socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in servAddr;

	servAddr.sin_family = AF_INET;

	servAddr.sin_port = htons(9001);

	servAddr.sin_addr.s_addr = INADDR_ANY;

	bind(servSockD,(struct sockaddr*)&servAddr,sizeof(servAddr));

	listen(servSockD,1);

	int clentSocket;

	clentSocket = accept(servSockD,NULL,NULL);

	send(clentSocket,serverData,sizeof(serverData),0);

	close(servSockD);


}
