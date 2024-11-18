#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

void disp(int sig) {
    signal(sig, SIG_DFL);
}

int main() {
    signal(SIGINT, disp);

    while(1)
        sleep(1);

    return 0;
}