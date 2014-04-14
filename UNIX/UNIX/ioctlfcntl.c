//
//  ioctlfcntl.c
//  UNIX
//
//  Created by 刘明录 on 14-5-16.
//  Copyright (c) 2014年 刘明录. All rights reserved.
//

#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void set_fl(int fd, int flags)
{
    int val;
    if((val = fcntl(fd, F_GETFL, 0)) < 0)
    {
        exit(0);
    }
    val |= flags;
    if (fcntl(fd, F_SETFL, val) < 0)
        exit(0);
}
int main(int argc, const char * argv[])
{
    struct winsize size;
    if (isatty(STDOUT_FILENO) == 0)
        exit(0);
    if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0)
    {
        perror("ioctl tiocgwinsz error");
        exit(0);
    }
    printf("%d rows, %d columnsn\n", size.ws_row, size.ws_col);
    
    printf("%d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("%s, ", argv[i]);
    }
    printf("\n");
    int val = fcntl(atoi(argv[1]), F_GETFL, 0);
    switch (val & O_ACCMODE) {
        case O_RDONLY:
            printf("read only\n");
            break;
        case O_WRONLY:
            printf("write only\n");
            break;
        case O_RDWR:
            printf("read write\n");
            break;
        default:
            break;
    }
    if (val & O_APPEND)
        printf("append\n");
    if (val & O_NONBLOCK)
        printf("noblock\n");
    if (val & O_SYNC)
        printf("sync\n");
    return 0;
}