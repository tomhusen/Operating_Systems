/*************************************************************************\
*                  Copyright (C) Michael Kerrisk, 2016.                   *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU General Public License as published by the   *
* Free Software Foundation, either version 3 or (at your option) any      *
* later version. This program is distributed without any warranty.  See   *
* the file COPYING.gpl-v3 for details.                                    *
\*************************************************************************/

/* Listing 18-2 */

/* list_files.c

   Demonstrate the use of opendir() and related functions to list files
   in a directory.

   Walk through each directory named on the command line (current directory
   if none are specified) to display a list of the files it contains.

    Usage: list_files [dir...]
*/

// *******************************************
// Last edited by: Thomas Husen - October 2016
// *******************************************


#if defined(__APPLE__)
        /* Darwin requires this header before including <dirent.h> */
#include <sys/types.h>
#endif
#include <dirent.h>
#include "tlpi_hdr.h"

static void             /* List all files in directory 'dirpath' */
listFiles(const char *dirpath, Boolean hidden)
{
    // printf("listFiles Function Boolean: %d\n\n", hidden);
    DIR *dirp;
    struct dirent *dp;
    Boolean isCurrent;          /* True if 'dirpath' is "." */

    isCurrent = strcmp(dirpath, ".") == 0;

    dirp = opendir(dirpath);
    if (dirp  == NULL) {
        errMsg("opendir failed on '%s'", dirpath);
        return;
    }

    /* For each entry in this directory, print directory + filename */
    printf("\nFiles in directory: %s\n", dirpath);
    for (;;) {
        errno = 0;              /* To distinguish error from end-of-directory */
        dp = readdir(dirp);
        if (dp == NULL)
            break;

        char *fileName = dp->d_name;

        /* Only executes if there is no -a option. So by default will show only
        files that are not hidden - by default . and .. are also not displayed */
        if(hidden == 0){
          // test = 1 if the file is hiddden
          int test = (fileName[0] == '.' && strcmp(fileName, ".") != 0 && strcmp(fileName, "..") != 0);
          //printf("Test Return Value: %i\n", test);
          if (strcmp(fileName, ".") == 0 || strcmp(fileName, "..") == 0 || test == 1){
            continue;           /* Skip . and .. */
          }
        }

        if (!isCurrent)
            printf("%s/", dirpath);
        printf("%s\n", fileName);
    }

    if (errno != 0)
        errExit("readdir");

    if (closedir(dirp) == -1)
        errMsg("closedir");
}

int main(int argc, char *argv[])
{
  /* Initilize the 'showHidden' boolean to false. This boolean represents if
  the -a option has been passed */
  Boolean showHidden = 0;
  //printf("Number of arguments = %i\n", argc);

  if (argc > 3 && strcmp(argv[1], "--help") == 0){
    usageErr("%s [dir-path...]\n", argv[0]);
  }

  if (argc == 1){         /* No arguments - use current directory */
    listFiles(".", showHidden);
}

  /* If -a is passed as the first argument then we will show hidden files */
  if (strcmp(argv[1], "-a") == 0){
    showHidden = 1;
    //printf("-a loop = %d\n", showHidden);
    if (argc == 2){       /* If the only argument is -a, use current directory */
      listFiles(".", showHidden);
    }
    // if the -a is activated and there's more parameters
    else {
      for(int i = 2; i < argc; i++){
        listFiles(argv[i], showHidden);
    }
  }
}

  else{
    for (argv++; *argv; argv++)
        listFiles(*argv, showHidden);

    /*for(int i = 2; i < argc; i++){
      listFiles(argv[i], showHidden);
    } */
  }

  exit(EXIT_SUCCESS);
}
