#include<stdio.h> 
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
main(){
FILE* file1;
FILE* file2;
int fifo_server,fifo_client;

char *choice;
printf("\nFIFO CHAT! You're the client!\n\n");
if(fork() == 0){
	fifo_server = open("/usr/people/classes/CS350/tmp/TESTER_SRV", O_RDWR);
	if(fifo_server < 1) {
		printf("Error in opening file \n");
		exit(-1);
	}
	file1 = fdopen(fifo_server, "r+");
	while(1){
		char buf[256];
		fgets(buf, 256, stdin);
		write(fifo_server, buf, strlen(buf));
		
	}    

	}
else{
	while(1){
	fifo_client = open("/usr/people/classes/CS350/tmp/TESTER_CLI",O_RDONLY);
	if(fifo_client<1) {
		printf("Error opening file \n");
		exit(1);
	}
		char str[256];
		read(fifo_client, str, sizeof(str));
		printf("\nFrom Server: %s\n", str);
	}
}
close(fifo_server); 
close(fifo_client);  
}
