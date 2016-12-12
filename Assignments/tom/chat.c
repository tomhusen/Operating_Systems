/* chat.c

   This is the final project for CS350.  It is a chat
   program that uses FIFOS and has a server and client
   functionality.
*/

// *******************************************
// Last edited by: Thomas Husen - December 2016
// *******************************************

#include <stdlib.h>

int main(int argc, char *argv[]) {
	 /* 2 Arguments - run in Server Mode, pass FIFO name */
	 //printf("argc= %d", argc);
	if (argc == 2) {
		system("./server");
	}
	if (argc == 3) { /* 3 Arguments - run in Client Mode, pass own FIFO then server FIFO */
		system("./client");
	}
}