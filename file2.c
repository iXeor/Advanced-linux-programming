//文件参数演示
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
    int fd = -1;
    fd = open("4.txt", O_RDWR | O_CREAT, S_IWUSR | S_IROTH);
    if (fd < 0)
    {
        perror("文件不存在");
        printf("errno=%d\n", errno);
    }
    close(fd);
    return 0;
}