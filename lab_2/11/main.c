#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char * argv[]) {
    pid_t pid;

    if (argc < 3) {
        printf("usage: %s filename\n", argv[0]);
        return 1;
    }

    pid = fork();
    if (pid){
        printf("parent process\n");
    }else{
        printf("child process\n");
        execv(argv[1], argv + 1);
    }

    return 0;
}