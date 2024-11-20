#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/stat.h>


int main(int argc, char *argv[]) {
    const char* filename = argv[1];

    if (fork() == 0) {
        // child
        int fd = open(filename, O_RDONLY);
        //int fd = open(filename, O_RDONLY | O_NDELAY);
        int r;
        char buf[1];
        while((r = read(fd, buf, 1) > 0)) printf("%s", buf);
        close(fd);
    } else {
        // parent
        int fd = open(filename, O_WRONLY | O_CREAT, 0666);
        //int fd = open(filename, O_WRONLY | O_CREAT | O_NDELAY, 0666);
        char buf[] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for (int i = 0; i < 100; i++) write(fd, &buf[i % 10], 1);
        close(fd);
    }
}