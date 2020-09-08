#include <stdio.h>
#include <sys/types.h>

int main(){
	for(int i = 1; i <=5; i++){
		fork();
		sleep(5);
	}
	return 0;
}
//depending on the time when pstree was executed we can see 2-32 proccess
//you can run ex2.sh to see it
