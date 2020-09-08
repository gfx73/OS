#include <stdio.h>
#include <sys/types.h>
int main() {
	if(fork() == 0){
		int pid = getpid();
		printf("Hello from child [PID - %d]\n", pid);
	}
	else{
		int pid = getpid();
		printf("Hello from parent [PID - %d]\n", pid);
	}
	
	return 0;
}
//PID increases every time program executed


