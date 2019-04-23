/*
# Name: <Jack Stephens>
# Date: <April 22, 2019>
# Title: Lab3 step 4
# Description: This program computes the shell command "cat /etc/passwd | grep root "
*/


#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void runpipe(); 


int main(int arc, char **argv)
{
	int pid, status; 
	int fd[2]; 
	
	pipe(fd); 
	
	switch (pid = fork()) {
	
	case 0: /*child */
		runpipe(fd); 
		exit(0); 
	
	default: /*parent*/
		while ((pid = wait(&status)) != -1)
			fprintf(stderr, "process %d exits with %d\n", pid, WEXITSTATUS(status)); 
		break;
	
	case -1:
		perror("fork"); 
		exit(1); 
	}
	exit(0); 
	
}

char *cmd1[] = { "cat", "/etc/passwd", 0}; 
char *cmd2[] = { "grep", "root", 0}; 

void runpipe(int pfd[]){
	int pid; 
	switch (pid = fork()) {
	
	case 0: /*child*/
		dup2(pfd[0], 0); 
		close(pfd[1]); 
		execvp(cmd2[0], cmd2); 
		perror(cmd2[0]); 

	default: /*parent*/
		dup2(pfd[1], 1); 
		close(pfd[0]); 
		execvp(cmd1[0], cmd1); 
		perror(cmd1[0]); 
	
	case -1: 
		perror("fork"); 
		exit(1); 
	}
}



