//
//  duptest.c
//  UNIX
//
//  Created by 刘明录 on 14-5-16.
//  Copyright (c) 2014年 刘明录. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    int fd = dup(STDOUT_FILENO);
    int fd2 = dup(STDIN_FILENO);
//    int fd3 = dup2(STDOUT_FILENO, 4);
    char* buffer = "test\n";
    char buf[1024];
    printf("%d\n", fd);
    printf("%d\n", fd2);
//    printf("%d\n", fd3);
    write(fd, buffer, strlen(buffer));
    read(fd2, buf, 1024);
    write(fd, buf, strlen(buf));
    return 0;
}
