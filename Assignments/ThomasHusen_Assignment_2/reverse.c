 #include <stdio.h>
#include <fcntl.h>
#include <tlpi_hdr.h>

// Takes 3 inputs: filename, starting byte position, # of bytes to read
int main(int argc, char *argv[]){

  // Errors if there are not 2 inputs
  if(argc < 2){
    usageErr("%s ----- Error: Illegal number of inputs\n", argv[0]);
  }
  int fd, outFile, cc;

  // Attempts to open file
  	fd = open(argv[1], O_RDWR);
   outFile = fopen(argv[2], "w+");

  // Errors if file could not be opened
  if (fd == -1){
    errMsg(" for open on file %s.\n", argv[1]);
  }
  // Successfully opened file
  else{
    fprintf(stderr, "Successfully opened file %s.\n\n", argv[1]);

    // Assigns variables to inputs
    int fileSize;

    // Gets size in bytes
    fileSize = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    unsigned char outBuffer[fileSize];
    read(fd, outBuffer, fileSize);
    char *buf = malloc(fileSize);	
    buf = outBuffer;
    printf("Reversed File: \n");
    
    for(buf+=fileSize;buf>=outBuffer; buf--)  // Print traversing backwards
    printf("%c", *buf);
    printf(outFile, "%c", *buf);
    //write(outFile, outBuffer, fileSize);
	 
	 
	 
    fflush(stdout);
    printf("\n\n");
    printf("Original File: \n");
    write(1, outBuffer, fileSize);
	 printf("\n\n");
		
    // Close file
    cc = close(fd);
  }

  // Errors if file could not be closed
  if (cc == -1){
    errExit(" for close on file descriptor %d.\n", fd);
    exit(EXIT_FAILURE);
  }
  // Successfully closed file
  else{
    fprintf(stderr, "Successfully closed file with file descriptor %d\n", fd);
  }
  // Exit
  exit(EXIT_SUCCESS);
}