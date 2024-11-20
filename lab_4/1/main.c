#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>

int main() {
    int fd1[2], fd2[2];
    // fd1: parent[1] --> child[0]
    // fd2: parent[0] <-- child[1]

    // дескиптор 0 - на чтение, а 1 - на запись
    pipe(fd1);
    pipe(fd2);

    if (fork() == 0) {
        // закрываем операции чтения/записи для родительский файловых дескрипторов
        close(fd1[1]);
        close(fd2[0]);

        char phrase[1024] = {0};
        read(fd1[0], phrase, 1024);
        printf("Parent: %s\n", phrase);

        const char* reply = "msg from child";
        write(fd2[1], reply, strlen(reply));
        close(fd1[0]);
        close(fd2[1]);
        
    } else {
        // закрываем операции чтения/записи для потомков файловых дескрипторов
        close(fd1[0]);
        close(fd2[1]);
        const char* buf = "msg from parent";
        write(fd1[1], buf, strlen(buf));

        char reply[1024] = {0};
        read(fd2[0], reply, 1024);
        printf("Child: %s\n", reply);
        close(fd1[1]);
        close(fd2[0]);
        
    }

    return 0;
}