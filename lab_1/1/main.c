#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

// sys_errlist - DEPRYCATED

int main(int argc, char **argv){
    errno = 0;

    const char *filename = argv[1];
	int fd = open(filename, O_RDWR);

    printf("errno: %d\n", errno);
    perror("open() ");

    /*
	for(int i=0; i<sys_nerr; i++)
        printf("sys_errlist[%d] = \"%s\"\n", i, sys_errlist[i]);
    */

	if (fd >= 0) {
        close(fd);
    }
    return 0;
}