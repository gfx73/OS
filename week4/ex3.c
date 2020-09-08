#include <stdio.h>
#include <stdlib.h>

int main(){
	char command[100];
	printf(">>>");
	while(scanf("%s", command) != 0){
		system(command);
		printf(">>>");
	}
	return 0;
}
