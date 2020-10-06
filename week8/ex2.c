#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
	void *a[10];
	for(int i = 0; i < 10; i++){
		a[i] = malloc(10 * 1024 * 1024);
		memset(a[i], 0, 10 * 1024 * 1024);
		sleep(1);
	}
	return 0;
}
//free memory decreases
//but there is still enoung memory, so si and so = 0
//program is not cpu intensive
