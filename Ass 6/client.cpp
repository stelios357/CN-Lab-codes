//• Include standard libraries:
#include <Winsock2.h>
#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>
#include<sys/types.h>


//• Then, create the main() function
int main(){
	//a) Create the socket. We need an integer to hold the socket descriptor.
	int sockD;
	
	//b) Call the socket function whose result will be stored in the declared integer variable sockD.
	sockD = socket(AF_INET, SOCK_STREAM, 0);
	
	/*
	• This creates one of the endpoints (client) of the client/server network communication. For
	the other end (server), a similar function needs to be written.
	• To connect to the other side (server), a connect() function needs to be called. But before
	the connection is established, an address needs to be specified to which to connect. Header
	file netinet.h contains the structure to specify the address and the port number of the remote
	socket.
	• Declare the structure for the address:
	struct sockaddr_in servAddr;
	•First we have to specify the address family (AF_INET). Now it is known that it will be an
	IPv4 address. */
	servAddr.sin_familty = AF_INET;
	
	/*
	• Now, specify the port to which to connect to. We can pass port number as an integer, but
	the structure variable accepts in network byte order only. Thus, the conversion function
	htons() will be used. */
	servAddr.sin_port = htons(9001); //use some unused port number
	
	
	//• Next, specify the actual address. Either local address can be used (eg, 0.0.0.0) or an actual address.
	servAddr.sin_addr.s_addr = INADDR_ANY;
	
	/*• Here sin_addris also a structure, so we need another ‘.’ to get into the fields in the structure.
	IN_ADDR_ANY is defined in the library and has a value 0.0.0.0.
	• Now that the address is defined, connect() function can be called.
	a) First parameter is actual socket: sockD
	b) Second parameter is address: servAddr. This has to be cast into different structure pointer
	(struct sockaddr *). Therefore, pass the address of servAddr structure.
	c) The last parameter is the size of the address.
	• The function connect() returns an integer that signifies whether the connection is successful
	or not. This can be used to do some primitive error handling. If the connection is successful,
	a value 0 is returned. Otherwise, -1 is returned.
	• Thus, the connect() function can be implemented as*/
	
	int connetStatus = connect(sockD, (struct sockaddr*) &servAddr, sizeof(servAddr);
	if (connectStatus == -1)	{
		printf("Error in client program\n");
	}


	/*
	• If the connection is successful, either send or receive data.
	• Suppose, we need to receive the data from the user, recv() function will be used in this
	case.
	a) First parameter to recv() is the socket,
	b) Second parameter is some place to hold the data (suppose a string),
	c) Third parameter is the size of data,
	d) Lastly, there is an optional flag parameter (keep it 0).*/
	
	
	else{
		char strData[255];
		recv(sockD, *strData, sizeof(strData), 0);
		printf("%s", strData);
		
		//• Close the socket: 
		close(sockD);
	}
	
	
	
	
	//This is a basic TCP client that prints data, that it gets from the server. To test it, a TCP server needsto be created.

	return(0);
}

