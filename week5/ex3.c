//race condition is met 
//we can see it in buffer variable
//it happens when thread is getting blocked while printing
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define ITERATIONS_NUM 100000
int buffer=0;

void* producer(){
	int i = 0;
	while(i < ITERATIONS_NUM){
		while(buffer == 200000);
		if(i%1000 == 0){
			printf("Producer: i=%d, buffer=%d\n", i, buffer);
		}
		i++;
		buffer++;
	}
}
void* consumer(){
	int i = 0;
	while(i < ITERATIONS_NUM){
		while(buffer == 0);
		if(i%1000 == 0){
			printf("Consumer: i=%d, buffer=%d\n", i, buffer);
		}
		i++;
		buffer--;
	}
}	
int main(){
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, producer, NULL);
	pthread_create(&thread2, NULL, consumer, NULL);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}
