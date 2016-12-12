#include <stdio.h> 
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE *file1;
	int fifo_server,fifo_client;
	char str[256];
	char *buf;
	char *choice;
	printf("Welcome to a simple chat application\n\n");
	if(fork() == 0){   
		while(1){
			fifo_server=open("fifo_server",O_RDWR);
			fgets(str, 256, stdin);
			write(fifo_server,str,strnlen(buf, 256));
		}    
	}
	else{
		while(1){
			fifo_client = open("fifo_client",O_RDWR);
			read(fifo_client,choice,sizeof(choice));
			printf("%s\n",choice);
		}
	}
	close(fifo_server); 
	close(fifo_client);  
}
