/*simple example of a pipe. Not for lab, just to help me understand how pipes work*/
#include <stdlib.h>
#include <stdio.h> /*for printf*/
#include <string.h> /*for strlen*/
#include <unistd.h> 

int main(int argc, char **argv)
{
	int n;
	int fd[2]; 
	char buf[1025]; 
	char *data = "hello... this is simple data"; 
	
	pipe(fd); 
	write(fd[1], data, strlen(data)); 
	if ((n = read(fd[0], buf, 1024)) >= 0) {
		buf[n] = 0; 
		printf("read %d bytes from the pipe: \"%s\"\n", n, buf); 
	}
	else
		perror("read"); 
	exit(0); 
}



