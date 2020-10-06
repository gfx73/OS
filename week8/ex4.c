#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main(){
	void *a[10];
	for(int i = 0; i < 10; i++){
		int who = RUSAGE_SELF;
		struct rusage usage;
		a[i] = malloc(10 * 1024 * 1024);
		memset(a[i], 0, 10 * 1024 * 1024);
		getrusage(who, &usage);
		printf("%ld\n", usage.ru_maxrss);
		sleep(1);
	}
	return 0;
}
