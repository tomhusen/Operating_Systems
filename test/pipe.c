#include<stdio.h> 
#include<fcntl.h>
#include<stdlib.h>
int main()
{
	int file1,file2;
	int fd;
	char str[256];
	char temp[4];
	char temp1[4];
	file1 = mkfifo("fifo_server",0777); 
	file2 = mkfifo("fifo_client",0777);
	printf("Created Server and Client FIFOs!\n ");
}
