/* Name - Jack Stephens
   Date - April 15 2019
   Title - Lab 2 part 7
   Description - This program computes parent process 100 times and child process 100 times. Then it lists the contents of whatever directory the file is in. 
*/ 

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
/* main function with command-line arguments to pass */ 
int main (int argc, char *argv[]) {
	pid_t pid; 
	int i, n = atoi(argv[1]); 
	printf("\n Before forking. \n"); 
	pid = fork(); 
	if (pid == -1){
		fprintf(stderr, "can't fork, error %d\n", errno); 
	}
	if (pid){
		// Parent Process
		for (i=0;i<100;i++){
			printf("\t \t \t Parent Process %d\n", i); 
			usleep(n); 
			}
	
		wait(NULL); 
	printf("Child Complete"); 
	exit(0); 
}
	
	else if(pid == 0)
	{
	for (i = 0; i < 100; i++){
	printf("Child process %d\n", i); 
	usleep(n); 
	}
	execlp("/bin/ls", "ls", NULL); 
	}
	return 0; 
}



