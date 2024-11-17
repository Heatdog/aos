#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char * argv[], char * envp[]) {
    printf("process %s\n", argv[0]);
    printf("parameters\n");
    for (char** it = argv; *it; it++) {
        printf("%s\n", *it);
    }
    printf("env\n");
    for (char** it = envp; *it; it++) {
        printf("%s\n", *it);
    }
    return 0;
}