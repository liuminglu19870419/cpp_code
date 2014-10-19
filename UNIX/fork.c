#include <stdio.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
    int var;
    int global = 0;
    pid_t pid;
    char buf[] = "write to stdout\n";
    var = 99;
    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1 ) != sizeof(buf) - 1)
    {
        exit(0);
    }

    pid = fork();
    if(pid == 0)
    {
        var++;
        global ++;
    } else {
        sleep(2);
    }
    printf("pid:%d var:%d global:%d\n", getpid(), global, var);
    return -1;
}
