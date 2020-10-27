#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int file1 = open("ex1.txt", O_RDWR), file2 = open("ex1.memcpy.txt", O_RDWR);
    struct stat buf;
    stat("ex1.txt", &buf);

    char *from = mmap(NULL, buf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, file1, 0);
    char *to = mmap(NULL, buf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, file2, 0);
	
	ftruncate(file2, buf.st_size);
    memcpy(to, from, buf.st_size);
    
    munmap(from, buf.st_size);
    munmap(to, buf.st_size);
	close(file1);
	close(file2);
    return 0;
}
