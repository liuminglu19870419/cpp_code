//
//  File.c
//  UNIX
//
//  Created by 刘明录 on 14-5-16.
//  Copyright (c) 2014年 刘明录. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

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

#define BUFFERSIZE 4096

int main(int argc, char * argv[])
{
    long n;
    char buffer[BUFFERSIZE];
//    set_fl(STDOUT_FILENO, O_SYNC);
    while ((n = read(STDIN_FILENO, buffer, BUFFERSIZE)) > 0) {
        if (write(STDOUT_FILENO, buffer, BUFFERSIZE) != n) {
            exit(0);
        }
    }
    return 0;
}