#include <stdio.h>
#define SIZE 1024

int main(int argc, char* argv[])
{
    int c;
//    while((c = getc(stdin)) != EOF)
//    {
//        if(putc(c, stdout) == EOF)
//        {
//            printf("stdout error\n");
//        }
//        if(ferror(stdin))
//        {
//            printf("stdin error");
//        }
//    }
//    exit(0);

    char buf[SIZE];
    while((fgets(buf, SIZE, stdin) != NULL)
    {
        if (fputs(buf, stdout) == EOF)
        {
            printf("stdout error\n");
        }
        if(ferror(stdin))
        {
            printf("stdin error");
        }
    }
    return 0;
}
