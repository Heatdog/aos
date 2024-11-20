#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>

int main() {
    int fd[2];
    // fd1: parent[1] --> child[0]
    // fd: parent[0] <-- child[1]

    pipe(fd);
    //pipe2(fd, O_NONBLOCK);

    if (fork() == 0) {
        close(fd[0]);
        int n;

        while(1) {
            char buf[80] = {0};
            n = read(STDIN_FILENO, buf, 80);
            write(fd[1], buf, n);
        }
        close(fd[1]);
    } else {
        close(fd[1]);
        int r;

        do {
            char buf[80] = {0};
            r = read(fd[0], buf, 80);
            printf("%s", buf);
        } while(r);
        close(fd[0]);
    }

    return 0;
}