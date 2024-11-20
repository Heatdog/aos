#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/stat.h>


int main(int argc, char *argv[]) {
    mkfifo( argv[1], 0777);
    //int fd = open(argv[1], O_WRONLY | O_NDELAY);
    int fd = open(argv[1], O_WRONLY);
    write(fd, "hi", 2);
    close(fd);
}