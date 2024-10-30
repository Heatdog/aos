#include <stdio.h>
#include <unistd.h>

int main() {
    int child_pid = fork();
    if (child_pid) printf("parent\n");
    else printf("child\n");
    return 0;
}