#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

#define doit(name) pr_limits(#name, name)

int main(int argc, char * argv[])
{
#ifdef RLIMIT_AS
    doit(RLIMIT_AS);
#endif
    doit(RLIMIT_CPU);
    doit(RLIMIT_CORE);
    doit(RLIMIT_DATA);
    doit(RLIMIT_FSIZE);
    doit(RLIMIT_STACK);
    return 0;
}


void pr_limits(char *name, int resource)
{
    struct rlimit limit;
    getrlimit(resource, &limit);
    printf("%s ", name);
    if(limit.rlim_cur == RLIM_INFINITY)
    {
        printf("inf ");
    }
    else
    {
        printf("%d ", limit.rlim_cur);
    }
    if(limit.rlim_max == RLIM_INFINITY)
    {
        printf("inf\n");
    }
    else
    {
        printf("%d\n", limit.rlim_max);
    }
}
