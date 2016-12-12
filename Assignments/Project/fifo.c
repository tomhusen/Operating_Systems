#include<stdio.h> 
#include<fcntl.h>
#include<stdlib.h>
main()
{
int file1,file2;
int fd;
char str[256];
char temp[4]="how";
char temp1[4];
file1 = mkfifo("/usr/people/classes/CS350/tmp/TESTER_SRV",0777); 
if(file1<0) {
 printf("Error: Could not create Server FIFO \n");
 exit(-1);
 }

file2 = mkfifo("/usr/people/classes/CS350/tmp/TESTER_CLI",0777);

if(file2<0) {
 printf("Error: Could not create Client FIFO \n");
 exit(-1);
 }
printf("Success: Created Server and Client FIFOs!\n ");
}
