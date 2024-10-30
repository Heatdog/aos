#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

const int buf_size = 1024;

int get_permission_flag(const char *permission_codes) {
    int r = strstr(permission_codes, "r") > 0;
    int w = strstr(permission_codes, "w") > 0;

    if (r && w) return O_RDWR;
    else if (r) return O_RDONLY;
    else if (w) return O_WRONLY;
    else return -1;
}

int main(int argc, char **argv){
    if (argc != 3) {
        fprintf(stderr, "requeired 2 arguments\n");
        return 1;
    }
    const char *filename = argv[1];
    int permission_flag = get_permission_flag(argv[2]);

    int fd = open(filename, O_CREAT | permission_flag, 0444);
    printf("opened file descriptor: %d\n", fd);
    perror("open() ");
    const char * msg = "mephi\nmephi\nmephi";
    int writed_len = write(fd, msg, strlen(msg));
    printf("writed number of bytes: %d\n", writed_len);
    perror("write() ");
    close(fd);
    perror("close() ");

    fd = open(filename, O_RDONLY);
    printf("opened file descriptor: %d\n", fd);
    perror("open() ");
    char buf[buf_size];
    int r = read(fd, buf, buf_size);
    if (r < 0) printf("unable to read\n");
    else printf("message:\n%s\n", buf);
    perror("read() ");
    close(fd);
    perror("close() ");

    fd = open(filename, O_RDWR);
    printf("opened file descriptor: %d\n", fd);
    perror("open() ");
    if (fd >= 0) close(fd);
    return 0;
}