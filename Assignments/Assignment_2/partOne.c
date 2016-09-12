#include <stdio.h>
#include <fcntl.h>
#include <tlpi_hdr.h>

/* Takes 2 inputs - first is name of file, second is message to put into that file */
int main(int argc, char *argv[]){

  /* Errors if there are not 2 inputs */
  if(argc != 2){
    usageErr("%s <file name>\n", argv[0]);
  }
  int fd, cc;
  fd = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

  /* File couldn't be opened */
  if (fd == -1){
    errMsg(" for open on file %s.\n", argv[1]);
  }
  /* Successfully opened file */
  else{
    fprintf(stderr, "Successfully opened file %s.\n", argv[1]);




  char msg[100];
  printf("What message do you want to save in the file: ");
  fgets(msg, sizeof(msg), stdin);

  int msg_len = strlen(msg);
  int nwr;
  nwr = write(fd, msg, msg_len);

  if(nwr == -1){
    errMsg(" couldn't write to the file %s, \n", argv[1]);
  }
  else {
    fprintf(stderr, "Wrote %d bytes to file %s\n", nwr, argv[1]);
  }
}

  cc = close(fd);
  /* Couldn't close file */
  if (cc == -1){
    errExit(" for close on file descriptor %d.\n", fd);
  }
  /* Successfully closed file */
  else{
    fprintf(stderr, "Successfully closed file with file descriptor %d\n", fd);
  }
  exit(EXIT_SUCCESS);
}
