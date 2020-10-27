#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int myFile = open("ex1.txt", O_RDWR);
    struct stat buf;
    stat("ex1.txt", &buf);
    char *addr = mmap(NULL, buf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, myFile, 0);
	off_t size = strlen("This is a nice day") * sizeof(char);
	ftruncate(myFile, size);
    strncpy(addr, "This is a nice day", size);
    munmap(addr, size);
	close(myFile);
    return 0;
}

