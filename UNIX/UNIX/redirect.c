#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, const char * argv[])
{
    int fd = open("test", O_RDWR | O_CREAT);
    dup2(fd, STDOUT_FILENO);
    printf("testtest");
    close(fd);
}
