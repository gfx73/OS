#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	char *buf;
    setvbuf(stdout, buf, _IOLBF, BUFSIZ);
	printf("H");
	sleep(1);
	printf("E");
	sleep(1);
	printf("L");
	sleep(1);
	printf("L");
	sleep(1);
	printf("O\n");
    return 0;
}
