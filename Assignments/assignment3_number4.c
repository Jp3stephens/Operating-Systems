#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Header file for sleep(). man 3 sleep for details
#include <pthread.h>

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp); 
void *threadtwofunction(void *vargp); 

int main() 
{
	 
	pthread_t tid[2]; 
	 	
	pthread_create(&tid[0], NULL, myThreadFun, NULL);	
	sleep(2); 	
	pthread_create(&tid[1], NULL, threadtwofunction, NULL); 	
 	pthread_join(tid[0], NULL); 
	pthread_join(tid[1], NULL);  
	printf("After Thread\n"); 
	exit(0); 
}


void *myThreadFun(void *vargp)
{
	int i = 0; 
	while(1){
		i++;
		if (i % 10000000 == 0){
			printf(".\n");
		}
}
	return NULL; 
	
}

void *threadtwofunction(void *vargp)
{	
char inputs[100];
while(1){
	printf("please enter something"); 
	scanf("%s", inputs); 
	printf("Thank you for your input"); 
	
}
return NULL; 
}

