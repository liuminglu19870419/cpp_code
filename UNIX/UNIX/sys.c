#include <sys/utsname.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
    struct utsname buf;
    uname(&buf);
    printf("%s\n", buf.sysname);
    printf("%s\n", buf.nodename);
    printf("%s\n", buf.release);
    printf("%s\n", buf.version);
    printf("%s\n", buf.machine);
    return 0;
}
