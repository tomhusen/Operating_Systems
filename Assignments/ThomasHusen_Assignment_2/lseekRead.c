#include <stdio.h>
#include <fcntl.h>
#include <tlpi_hdr.h>

// Takes 3 inputs: filename, starting byte position, # of bytes to read
int main(int argc, char *argv[]){

  // Errors if there are not 3 inputs
  if(argc < 3){
    usageErr("%s ----- Error: Illegal number of inputs\n", argv[0]);
  }
  int fd, cc;

  // Attempts to open file
  fd = open(argv[1], O_RDONLY);

  // Errors if file could not be opened
  if (fd == -1){
    errMsg(" for open on file %s.\n", argv[1]);
  }
  // Successfully opened file
  else{
    fprintf(stderr, "Successfully opened file %s.\n\n", argv[1]);

    // Formats inputs, and declares some variables
    char *filename;
    filename = argv[1];
    int s, n, numMove, numRead, numRem;

    // Converts the Command Line arguments into integers
    s = atoi(argv[2]);
    n = atoi(argv[3]);
    // Creates output buffer equal to size of the file
    unsigned char outputBuffer[sizeof(s)];

    numMove = lseek(fd, s, SEEK_SET);
    // Forces standard output
    fflush(stdout);
    // Will keep track of number of char read
    int count = 0;
    // How many characters remaining
    numRem = n;
    /* This loop works by checking if there are characters remaining to be read.
    if there are, then it checks if there are less than 64 of them. If there are
    less than 64 remaining then it will just read those 0-64 and output them. If
    there are more than 64, it will read up to 64, output those, and then decrement
    the number remaining by the amount it was able to read. If it cannot read
    anymore characters or it reaches the end of the file it will exit the while */
    while(numRem > 0){
      if(numRem <= 64) n = numRem;
      if(numRem > 64) n = 64;
      numRead = read(fd, outputBuffer, n);
      if(numRead > 0){
        write(1, outputBuffer, numRead);
        printf("\n");
        count += numRead;
      }
      numRem -= numRead;
      if(numRead == 0) numRem = 0;
    }

    // Output for reference
    printf("\n\n\n**** INFO BELOW FOR REFERENCE ONLY ****\n");
    printf("**** Number of bytes read = %d\n", count);
    printf("**** Number of bytes moved = %d\n", numMove);
    printf("**** Name of file = %s\n", filename);
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
