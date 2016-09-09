#include <stdio.h>
#include <fcntl.h>
#include <tlpi_hdr.h>

int main(int argc, char *argv[]){

  /* No input was passed */
  if(argc < 2){
    usageErr("%s No input passed.\n", argv[0]);
  }

  //int file_len = strlen(argv[1]);

  int fd, cc;
  fd = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

  /* File couldn't be opened */
  if (fd == -1){
    errMsg(" for open on file %s.\n", argv[1]);
  }
  /* Successfully opened file */
  else{
    fprintf(stderr, "Successfully opened file %s.\n\n", argv[1]);

  //
  //
  //
  //
  //

  // Gets how long the input string is
  int i;
  int strSize = 0;
  for (i=2; i<argc; i++){
    strSize += strlen(argv[i]);
    if (argc > i+1){
      strSize++;
    }
  }

  // Makes the input into a 'string'
  char *inputStr;
  inputStr = malloc(strSize);
  inputStr[0] = '\0';
  for (i=2; i<argc; i++){
    strcat(inputStr, argv[i]);
    if (argc > i+1){
      strcat(inputStr, " ");
    }
  }

  // Standart output
  printf("%s\n", inputStr);
  int nwr;
  // Saves message in file
  nwr = write(fd, inputStr, strSize);

  // Couldn't write file
  if(nwr == -1){
    errMsg(" couldn't write to the file %s, \n", argv[1]);
  }

  return 0;
}
  cc = close(fd);

  // Couldn't close file
  if (cc == -1){
    errExit(" for close on file descriptor %d.\n", fd);
  }

  //Exit
  exit(EXIT_SUCCESS);
}
