#include <stdio.h>
#include <pthread.h>

void* printThreadNumber(void* threadNumber){
	printf("Thread number is %d\n", *(int*)threadNumber);
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		pthread_t thread;
		pthread_create(&thread, NULL, printThreadNumber, &i);
		printf("Thread %d created\n", i);
		pthread_join(thread, NULL);
		printf("Thread %d exits\n", i);
	}
	return 0;
}
