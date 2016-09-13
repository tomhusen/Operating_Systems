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

    fflush(stdout);

    write(1, outputBuffer, numRead);

    printf("\n\nnumRead= %d\n", numRead);
    printf("numMove= %d\n", numMove);
    printf("filename= %s\n", filename);





    //int i;
    //while(currentPos < n && currentPos != EneOfFile){
    //  i=0
    //  while(i<64){
        // Print to Output
  //    }
      // New line "\n"
      // update current Pos



  // Errors if couldn't write to the file
//  if(nwr == -1){
//    errMsg(" couldn't write to the file %s, \n", argv[1]);
//  }
//  else {
//    fprintf(stderr, "Wrote %d bytes to file %s\n", nwr, argv[1]);
//  }


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
