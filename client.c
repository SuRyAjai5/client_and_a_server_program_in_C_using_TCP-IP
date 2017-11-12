#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <netdb.h>
#include <stdio.h>
#include <math.h>

void error(char *msg)
{
	perror(msg);
	exit(0);
}

int IsPrime(int number)
{
	 
    int i;
    for ( i = 2; i < number; i++)
    {
        if (number % i == 0 && i != number)
            return 0;
    }
    return 1;
}  

/*  int toint(char str[])
{
    int len = strlen(str);
    int i, num = 0;
    printf("@ To int ");
    for (i = 0; i < len; i++)
    {
        num = num + ((str[len - (i + 1)] - '0') * pow(10, i));
    }
 
   return num;
}  */


int main(int argc, char *argv[])
{
	int sock, length, n;
	struct sockaddr_in server, from;
	
	struct hostent *hp;
    char buffer[256];
	int number;
	int result;

if (argc < 3)
{
	fprintf(stderr,"usage %s hostname port\n", argv[0]);
	exit(0);
}

 
sock = socket(AF_INET, SOCK_DGRAM, 0);

if (sock < 0){
	error("socket");
}

server.sin_family = AF_INET;
hp = gethostbyname(argv[1]);

if (hp==0){
	error("uknown host ");
}
bcopy((char*)hp->h_addr,(char *)&server.sin_addr,hp->h_length);
server.sin_port = htons(atoi(argv[2]));
length = sizeof(server);
int count =0;



  do{
	   

		bzero(buffer,256);
		//fgets(buffer,255,stdin);
	    
            char buf[6] = {'c','o','n','n','e','c','t'};
           	n = sendto(sock, buffer, strlen(buffer),0,&server,length);
			if (n < 0)
			{
				error("ERROR writing to socket");
			}
        
		
		n = recvfrom(sock, buffer,256,0,&from,&length);
		
		
		if (n < 0)
		{
		 error("ERROR reading from socket");
		}
		
		
        number = atoi(buffer);
	   
	    
        printf("Client:===== ");
	    
	   
	  // write(1, buffer, n);
	   
	   result = IsPrime(number);
	   
	   if(result == 1)
	   {
            
         printf("%d is prime:\n ",number);
        
	   }
	   else
	   {
      
		 printf("%d is not prime:\n ",number);  
	   }
       count = count + 1;
       
   }while (result == 0);

return 0;
}