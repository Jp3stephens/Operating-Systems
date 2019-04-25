/**************************
*	Threads
*   Winter 2019
**************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *go(void *);
#define NTHREADS 10
pthread_t threads[NTHREADS];
int i;
int main() {
    for (i = 0; i < NTHREADS; i++)  
        pthread_create(&threads[i], NULL, go, NULL);
    for (i = 0; i < NTHREADS; i++) {
	printf("waiting...\n"); 
        pthread_join(threads[i],NULL);
	printf("Thread %d returned \n", i);
    }
    printf("Main thread done.\n");
}
void *go(void *arg) {
    printf("Hello from thread %d with thread ID %d \n", i, (int)pthread_self());
    return (NULL);
}

