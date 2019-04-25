#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char ** argv) 
{
	int child = fork(); 
	int x = 5; 

	if (child == 0) 
		x += 5; 
	else {
		child = fork(); 
		x += 10; 
		if (child)
			x += 5; 

	}
	printf("value of x: %d\n", x); 
}

