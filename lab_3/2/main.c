#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

void disp(int sig) {
    signal(sig, SIG_DFL);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = disp;
    sigaction(SIGINT, &sa, NULL);
    while(1) sleep(1);
    return 0;
}