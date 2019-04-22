/* Name - Jack Stephens
   Date - April 15 2019
   Title - Lab 2 part 6
   Description - This program computes parent process 100 times and child process 100 times using threads. 
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

 
	void *thread1create(void *ptr){
	int i = 0; 
	char *message; 
	message = (char *) ptr; 
	for (i = 0; i < 100; i++){
	
	printf("\t \t \t Parent Process %d \n",i);   
}
}
	void *thread2create(void *ptr){
	int j = 0; 
	char *message; 
	message = (char *) ptr; 
	for (j = 0; j < 100; j++){
	printf("Child process %d\n",j);
}
} 



	int main(int argc, char *argv[]){
	pthread_t thread1, thread2; 
	char *message1 = "Thread 1"; 
	char *message2 = "Thread 2"; 
	int iret1, iret2; 

	// Create independent theads each of which will execute function
	iret1 = pthread_create( &thread1, NULL, thread1create, (void*) message1); 
	iret2 = pthread_create( &thread2, NULL, thread2create, (void*) message2); 

	// Wait until threads are complete before main continues. Unless we wait we run the risk 
	// of executing an exit which will terminate the process and all threads before the threads
	// have completed. 
	pthread_join( thread1, NULL); 
	pthread_join( thread2, NULL); 

	printf("Thread1 returns: %d\n", iret1); 
	printf("Thread2 returns: %d\n", iret2); 
	exit(0); 
}

