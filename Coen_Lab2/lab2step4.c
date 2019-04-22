/*Sample C program for Lab assignment 2*/
/* Name - Jack Stephens
   Date - April 15 2019
   Title - Lab2 part 1-4
   Description - This program computes parent process 100 times and child process 100 times. 
 */

#include <stdio.h> 
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
/*main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
	pid_t pid; 
	int i, n = atoi(argv[1]); // n microseconds to input from keyboard to delay
	printf("\n Before forking. \n"); 
	pid = fork(); 
	if (pid == -1) {
		fprintf(stderr, "can't fork, error %d\n", errno); 
	}
	if (pid){
		//parent process
		for (i=0; i<100; i++){
		printf("\t \t \t Parent process %d\n", i); 
		usleep(n);  
		}
	}
	else {
		// child process
		for (i = 0; i < 100; i++) {
		printf("Child process %d\n", i); 
		usleep(n); 
		}
	}
	return 0; 
	}

