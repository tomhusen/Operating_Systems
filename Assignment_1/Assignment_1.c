#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main(){
  char str[100];
  /* Name the file that we want to create/edit */
  printf("What file do you want to open/create: ");
  fgets(str, sizeof(str), stdin);

  /* Open a file obtained from the user command line */
  FILE *fp;
  fp=fopen(str, "w");

/*


  if(access(str, F_OK) != -1){
      printf(" FILE ALREADY EXISTS!\n");
  }
  else{

    */


  char msg[100];
  printf("What message do you want to save in the file: ");
  fgets(msg, sizeof(msg), stdin);
  /* Write the messsage into the file */
  fputs(msg, fp);
  printf("******************\n****SAVED FILE****\n****************** \n");


  /* Closes the file */
  fclose(fp);
  }
