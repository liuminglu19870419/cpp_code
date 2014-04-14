#include "stdio.h"
#include "sys/stat.h"
#include "fcntl.h"

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)    
int main() {
    int fd;
    char *buf = "1234567890";
    if((fd = creat("test", FILE_MODE)) < 0) {
        printf("open error");
        return -1;
    }
    if (write(fd, buf, 10) != 10) {
        printf("write 1 error");
        return -1;
    }
    int off_t = 100;
    int off_tL = 100L;
    if (lseek(fd, off_t, SEEK_SET) == -1) {
        printf("lseek error");
        return -1;
    }

    if (write(fd, buf, 10) != 10) {
        printf("write 2 error");
        return -1;
    }
    close(fd);
    if((fd = open("test", O_RDWR))< 0) {
        printf("open error");
        return -1;
    }

    char rebuf[20];
    if(read(fd, rebuf, 10)> 0) {
        printf("%s", rebuf);
    }
    close(fd);
    return 0;
}
