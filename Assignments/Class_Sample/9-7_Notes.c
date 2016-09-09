/* Copy the 3 links in "Handouts/class examples" directory      <- Will have .h files and libraries that we need
Create a master directory for this class and each program gets its own sub directory
copy the "Makefile" into each new directory
  within that Makefile we just copied and change GEN_EXE = 'name of new progarm (directory)'
  Create a .c file for the program - (usually by copying an existing program)
  Name the .c file the same as the directory its in
If you have the "Makefile" in that directory you should be able to compile with just 'make' command
*/
#include <stdio.h>
#include <errno.h>

main(int argc, char *argv[]){
  if(argc != 2){
    usageErr("%s <file name> \n)", argv[0]);
  }

  int fd, cc;
  fd = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

  if(fd == -1){
    errMsg(" couldn't open file %s.\n", argv[1];
  }
  else {
    fprintf(stderr, "Successfully opened file %s.\n", argv[1]);
  }
/* Error Catching and stuff within here */

char msg[] = "This is the message.\n";
int msg_len = strlen(msg);
int rwr;
nwr = write(fd, msg, msg_len);
if(nwr == -1){
  errMsg(" couldn't write to the file %s, \n", argv[1]);
}
else {
  fprintf(stderr, "Wrote %d bytes to file %s\n", nwr, argv[1]);
}

cc = close(fd);
if(cc == -1){
  errExit(" couldn't close file %d.\n", argv[1]);
  }
else {
  fprintf(stderr, "Successfully closed file with file descriptor %d.\n", fd);
  }
}
