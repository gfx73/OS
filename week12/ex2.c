#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define BUF_SIZE 512

int main(int argc, char **argv) {
	FILE *myFile = fopen(argv[1], "a");
	int input = STDIN_FILENO;
	
    char c[BUF_SIZE];
    int n = read(input, c, BUF_SIZE);
    fwrite(c, 1, n, myFile);
    
    while(n != 0){
    	n = read(input, c, BUF_SIZE);
    	fwrite(c, 1, n, myFile);
    }
    
    close(input);
    fclose(myFile);
    return 0;
}
