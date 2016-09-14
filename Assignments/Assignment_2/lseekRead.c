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
    int s, n, numMove, numRead;

    // Converts the Command Line arguments into integers
    s = atoi(argv[2]);
    n = atoi(argv[3]);
    // Creates output buffer equal to size of the file
    unsigned char outputBuffer[sizeof(s)];

    // Returns values for lseek() and read()
    numMove = lseek(fd, s, SEEK_SET);
    numRead = read(fd, outputBuffer, n);
    // Forces it to standard output
    fflush(stdout);
    // Writes the buffer out to standard output
    write(1, outputBuffer, numRead);

    // Output for reference
    printf("\n\nnumRead= %d\n", numRead);
    printf("numMove= %d\n", numMove);
    printf("filename= %s\n", filename);
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
