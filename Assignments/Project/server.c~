#include<stdio.h> 
#include<fcntl.h>
#include<stdlib.h>
main()
{
FILE *file1;
int fifo_server,fifo_client;
char *choice;
char *buf;
if(fork() == 0)
    {
        while(1)
        {   
        fifo_server = open("fifo_server",O_RDWR);
        if(fifo_server<1) {
         printf("Error opening file");
         }

        read(fifo_server,choice,sizeof(choice));
        printf("%s\n",choice);
        close(fifo_server);
        }
        //sleep(3);


    }
else
{
    while(1)
    {   
        buf = malloc(10*sizeof(char));  
        scanf("%s",buf);

        fifo_client = open("fifo_client",O_RDWR);

        if(fifo_client<1) {
         printf("Error opening file");
         }



         write(fifo_client,buf,sizeof(buf)); 
        close(fifo_client);

    }
}

close(fifo_server);
close(fifo_client);
}