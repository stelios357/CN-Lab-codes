//client
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h> // for sockets Apis
#include<netinet/in.h> // structure for storing address information

int main(){


	int sockD;

	sockD = socket(AF_INET,SOCK_STREAM,0);

	struct 	sockaddr_in servAddr;	
	servAddr.sin_family = AF_INET;

	servAddr.sin_port = htons(9001);// use some unused port number

	servAddr.sin_addr.s_addr = INADDR_ANY;

	int connectStatus =connect(sockD,(struct sockaddr*)&servAddr,sizeof(servAddr));

	if(connectStatus==-1){

		printf("Error in client program\n");
	}

	else{

		char strData[255];

		recv(sockD, (char *)strData,sizeof(strData),0);

		printf("%s\n",strData);

		close(sockD);
	}



	return(0);

}