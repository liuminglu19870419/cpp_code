//
//  File.c
//  UNIX
//
//  Created by 刘明录 on 14-5-16.
//  Copyright (c) 2014年 刘明录. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void my1(void);
static void my2(void);
int main(int argc, char * argv[])
{
    atexit(my1);
    atexit(my1);
    atexit(my2);
    exit(0);
}

static void my1(void)
{
    printf("my1 called\n");
}

static void my2(void)
{
    printf("my2 called\n");
}
