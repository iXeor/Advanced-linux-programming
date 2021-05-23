#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    pid_t pid = -1;
    int length = -1;
    pid = fork();
    if (pid > 0)
    {
        wait(NULL);
        int fd = open("1.txt", O_RDWR);
        length = lseek(fd, 0, SEEK_END);
        lseek(fd, 0, SEEK_SET);
        char *buffer = (char *)malloc(sizeof(char) * length);
        read(fd, buffer, length);
        printf("%s", buffer);
        free(buffer);
        close(fd);
    }
    else if (pid == 0)
    {
        int fd = open("1.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
        dup2(fd, 1);
        execlp("ls", "ls", "-l", NULL);
        close(fd);
    }
    return 0;
}
