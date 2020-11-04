#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int randomFile = open("/dev/random", O_RDONLY);
    int myFile = open("ex1.txt", O_WRONLY);
    ftruncate(myFile, 20);
    char randomString[20];
    read(randomFile, randomString, 20);
    write(myFile, randomString, 20);
    close(randomFile);
    close(myFile);
    return 0;
}
