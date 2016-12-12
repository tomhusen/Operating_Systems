#include<stdio.h> 
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
main(){
FILE *file1;
FILE *file2;
int fifo_server,fifo_client;
printf("\nFIFO CHAT! You're the server!\n\n");

if(fork() == 0)
    {
        while(1)
        {   
        fifo_server = open("/usr/people/classes/CS350/tmp/TESTER_SRV",O_RDONLY);
        if(fifo_server<1) {
         printf("Error opening file\n");
         }
		char str[256];
		read(fifo_server, str, sizeof(str));
		printf("\nFrom Client: %s\n", str);
        close(fifo_server);
        }
    }
else
{
	while(1){
	fifo_client = open("/usr/people/classes/CS350/tmp/TESTER_CLI",O_RDWR);        
	if(fifo_client<1) {
        	printf("Error opening file\n");
         }
		char buf[256];
		fgets(buf, 256, stdin);
        	write(fifo_client,buf,sizeof(buf)); 
        	close(fifo_client);

    }
}

close(fifo_server);
close(fifo_client);
}
