#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>

#define PORT 9479
#define IP hostname

void error(char *msg)
{
    perror(msg);
    exit(0);
}

struct hostent *serverIPAddress;

struct Socket{
	int sockfd;
} typedef socket;

int netserverinit(char * hostname){
	printf("hostname %s\n",hostname);
	serverIPAddress = gethostbyname(hostname);

    if (serverIPAddress == NULL){
        fprintf(stderr,"ERROR, no such host\n");
        errno=HOST_NOT_FOUND;
        return -1;
    }

    return 0;
}

int netopen(const char *pathname, int flags){

	socket->sockfd = -1;
	socket->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	// try to build a socket .. if it doesn't work, complain and exit
    if (socket->sockfd < 0)
    {
        error("ERROR, creating socket");
    }
    struct sockaddr_in serverAddressInfo;
        /** We now have the IP address and port to connect to on the server, we have to get    **/
    /**   that information into C's special address struct for connecting sockets                     **/
    
    // zero out the socket address info struct .. always initialize!
    bzero((char *) &serverAddressInfo, sizeof(serverAddressInfo));
    
    // set a flag to indicate the type of network address we'll be using
    serverAddressInfo.sin_family = AF_INET;
    
    int portno = PORT;

    // set the remote port .. translate from a 'normal' int to a super-special 'network-port-int'
    serverAddressInfo.sin_port = htons(portno);
    
    // do a raw copy of the bytes that represent the server's IP address in
    //   the 'serverIPAddress' struct into our serverIPAddressInfo struct
    bcopy((char *)serverIPAddress->h_addr, (char *)&serverAddressInfo.sin_addr.s_addr, serverIPAddress->h_length);
    /** We now have a blank socket and a fully parameterized address info struct .. time to connect **/
    
    // try to connect to the server using our blank socket and the address info struct
    //   if it doesn't work, complain and exit

    if (connect(socket->sockfd,(struct sockaddr *)&serverAddressInfo,sizeof(serverAddressInfo)) < 0)
    {
        error("ERROR connecting");
    }
    char * buffer=malloc(strlen(pathname)+15);
    strcpy(buffer,"op");
    strcat(buffer,pathname);
    printf("Socket has connected.\n");
    char buffer[256];
    strcpy(buffer,"Hello");
    send(socket->sockfd,buffer,strlen(buffer),0);
    char * flagsC=malloc(10);
    flagsC=itoa(flags);
    send(socket->sockfd,flagsC,strlen(buffer),0);
    char * fd=malloc(3);
    int ret=recv();
    if(atoi(fd)==1){
    	printf("Error");
    	exit(1);
    }
    printf("file des: %d",fd);
    return 0;

}

ssize_t netread(int fildes, void *buf, size_t nbyte){

	char * message=malloc((int)nbyte+3);

	strcpy(message,"r");
	fildes=files*(-1);
	char * fdc=itoa(fildes);
	strcat(message,fdc);
	char * nbyteStr=itoa((int)nbyte);
	strcat(message,nbyteStr);
	int messlength=strlen(message);
	char * messlc=itoa(messlength);
	buff=malloc((int)nbyte+5+strlen(message));
	strcpy((char*)buf, "?");
	strcat((char*)buf,messlc);
	strcat((char*)buf,"?");
	strcat((char*)buf,message);
	send(socket->sockfd,buf,strlen(buf),0);

}

ssize_t netwrite(int fildes, const void *buf, size_t nbyte){
	char * message=malloc((int)nbyte+3);

	strcpy(message,"w");
	fildes=files*(-1);
	char * fdc=itoa(fildes);
	strcat(message,fdc);
	char * nbyteStr=itoa((int)nbyte);
	strcat(message,(char*)buf);
	int messlength=strlen(message);
	char * messlc=itoa(messlength);
	char * sendbuf=malloc((int)nbyte+5+strlen(message));
	strcpy(sendbuf, "?");
	strcat(sendbuf,messlc);
	strcat(sendbuf,"?");
	strcat(sendbuf,message);
	send(socket->sockfd,buf,strlen(buf),0);


}

 int netclose(int fd){

 }