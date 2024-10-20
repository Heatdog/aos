#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage: %s filename\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    long file_size = lseek(fd, -1, SEEK_END);
    if (file_size > 0) {
        do {
            char letter = '\0';
            read(fd, &letter, 1);
            printf("%c", letter);
        } while (lseek(fd, -2, SEEK_CUR) >= 0);
    }
    printf("\n");
    close(fd);
    return 0;
}
