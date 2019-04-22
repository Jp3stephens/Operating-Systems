/*Sample C program for Lab assignment 2*/
/* Name - Jack Stephens
   Date - April 15 2019
   Title - Lab 2 part 5
   Description - This program computes 7 processes. Each processes has 2 or 0 children. 
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
		pid_t proc1 = fork(); 
		pid_t proc2 = fork();
		pid_t proc3 = fork(); 
		 
		for(int i = 0; i < 2; i++)
		{  
			 if(fork() == 0) 
			{ 
				printf("[child] pid %d from [parent] pid %d\n", getpid(), getppid()); 
				exit(0); 	
			}
			kill(proc3); 
			wait(NULL); 
			
		   
		}
		  
		kill(proc2); 
	//	pid_t proc3 = fork(); 				
/*		pid_t proc3 = fork();  
		for (int i = 0; i < 2; i++){
			if (proc3 == 0)
			{
			printf("[child] pid %d from [parent] pid %d\n", getpid(), getppid()); 
			exit(0); 
			}
			wait(NULL); 
		}*/
			return 0; 
}

