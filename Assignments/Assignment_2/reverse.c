#include <stdio.h>
#include <fcntl.h>
#include <tlpi_hdr.h>

// Takes 3 inputs: filename, starting byte position, # of bytes to read
int main(int argc, char *argv[]){

  // Errors if there are not 3 inputs
  if(argc < 2){
    usageErr("%s ----- Error: Illegal number of inputs\n", argv[0]);
  }
  int fd, cc;

  // Attempts to open file
  fd = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

  // Errors if file could not be opened
  if (fd == -1){
    errMsg(" for open on file %s.\n", argv[1]);
  }
  // Successfully opened file
  else{
    fprintf(stderr, "Successfully opened file %s.\n\n", argv[1]);

    // Assigns variables to inputs
    char *filename, *rname;
    int numMove, numRead, fileSize;
    filename = argv[1];
    rname = argv[2];
    fileSize = sizeof(filename);


    // Creates output buffer equal to size of the file
    unsigned char outputBuffer[fileSize];

    // Gets size in bytes
    numMove = lseek(fd, 0, SEEK_END);
    numRead = read(fd, outputBuffer, fileSize);

    fflush(stdout);

    write(1, outputBuffer, fileSize);

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
