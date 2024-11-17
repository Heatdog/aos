#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char * argv[], char * envp[]) {
    int fr = fork();

    if (argc < 2) {
        printf("usage: %s filename\n", argv[0]);
        return 1;
    }

    if (fr) {
        printf("parent process\n");
        printf("parameters\n");
        for (char** it = argv; *it; it++) {
            printf("%s\n", *it);
        }
        printf("env\n");
        for (char** it = envp; *it; it++) {
            printf("%s\n", *it);
        }
    } else {
        printf("child process\n");
        int er = execv(argv[1], argv + 1);
    }

    return 0;
}