//
//  main.c
//  UNIX
//
//  Created by 刘明录 on 14-5-16.
//  Copyright (c) 2014年 刘明录. All rights reserved.
//

#include <stdio.h>
#include "string.h"
#include "fcntl.h"
#include "unistd.h"

int main(int argc, const char * argv[])
{
    
    // insert code here...
    int fd = open("/Users/liuminglu/git/cpp_code/UNIX/UNIX/main.c", O_RDONLY);//open the file with read only
    printf("file id: %d\n", fd);
    char buffer[1024];
    long length = read(fd,buffer, 1024);// read from the file
    //    printf("file size: %ld\n %s", length, buffer);
    close(fd);//close file
    
//    fd = open("/Users/liuminglu/git/cpp_code/UNIX/UNIX/test.c", O_WRONLY | O_APPEND | O_SYNC | O_CREAT);
//    if (fd == -1) {
    fd = open("/Users/liuminglu/git/cpp_code/UNIX/UNIX/test.c", O_RDWR | O_SYNC | O_APPEND);// open the file with read/write
    //    }
    printf("file id: %d \n", fd);
    pwrite(fd, buffer, strlen(buffer), 0); //write the buffer to the file
    lseek(fd, 0, SEEK_SET);// reset the file pointer
    while ((length = read(fd, buffer, 1024)) > 0) {
        printf("%s", buffer);
    }
//    write(STDOUT_FILENO, buffer, strlen(buffer));

//    long n = 0;
//    while ((n = read(STDIN_FILENO, buffer, 4096))>0) {
//        write(STDOUT_FILENO, buffer, n);
//    }
    sync();
    fsync(fd);
    close(fd);
    fcntl(fd, F_DUPFD);
    
    
    
    return 0;
}

