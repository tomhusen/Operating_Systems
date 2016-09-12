#include <stdio.h>
#include <fcntl.h>
#include <tlpi_hdr.h>

// Takes 3 inputs: filename, starting byte position, # of bytes to read
int main(int argc, char *argv[]){

  // Errors if there are not 3 inputs
  if(argc != 3){
    usageErr("%s <file name>\n", argv[0]);
  }
  int fd, cc;
  //attempts to open file
  fd = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

  // Errors if file could not be opened
  if (fd == -1){
    errMsg(" for open on file %s.\n", argv[1]);
  }
  // Successfully opened file
  else{
    fprintf(stderr, "Successfully opened file %s.\n", argv[1]);

    // Converts string inputs for starting pos, and # of bytes to integers
    char *filename;
    filename = argv[1];
    int s, n;
    s = atoi(argv[2]);
    n = atoi(argv[3]);

    // Errors if pointer could not be moved
    if(lseek(filename, s, SEEK_SET) == -1){
      fprintf(stderr, "Error moving pointer %s\n", argv[1]);
    }

    int i;
    while(currentPos < n && currentPos != EneOfFile){
      i=0
      while(i<64){
        // Print to Output
      }
      // New line "\n"
      // update current Pos
    }

  }







  int msg_len = strlen(msg);
  int nwr;
  nwr = write(fd, msg, msg_len);

  // Errors if couldn't write to the file
  if(nwr == -1){
    errMsg(" couldn't write to the file %s, \n", argv[1]);
  }
  else {
    fprintf(stderr, "Wrote %d bytes to file %s\n", nwr, argv[1]);
  }
}

  // Close file
  cc = close(fd);
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
