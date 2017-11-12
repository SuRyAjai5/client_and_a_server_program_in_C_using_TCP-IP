#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
void error(char *msg)
{
	perror(msg);
	exit(0);
}

void tostring(char str[], int num)
{
    int i, rem, len = 0, n;
 
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

int main(int argc, char *argv[])
{
	int sock, length, fromlen, n;
	struct sockaddr_in server;
	struct sockaddr_in from;
	char buf[1024];
	int num;
	
   char str[10];
	srand(time(NULL));

	if (argc < 2)
	{
		fprintf(stderr, "ERROR, no port provided\n");
		exit(0);
	}

	sock=socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0)
	{
		error("Opening socket");
	}
		length = sizeof(server);
		bzero(&server,length);
		server.sin_family=AF_INET;
		server.sin_addr.s_addr=INADDR_ANY;
		server.sin_port=htons(atoi(argv[1]));
	
	if (bind(sock,(struct sockaddr *)&server,length)<0)
	{
		error("binding");
	}
	fromlen = sizeof(struct sockaddr_in);
	while (1)
	{
			n = recvfrom(sock,buf,1024,0,(struct sockaddr *)&from,&fromlen);
			if (n < 0)
			{
				error("recvfrom");
			}
			write(1,"Received a data from: ",21);
			write(1,buf,n);
			num= rand() % INT_MAX;
		    printf("Number integer: %d\n", num);
		    tostring(str, num);

		 

			n = sendto(sock,str,17,0,(struct sockaddr *)&from,fromlen);
			if (n < 0)
			{
				error("sendto");
			}
	}
}