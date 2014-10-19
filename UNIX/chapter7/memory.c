#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    printf("PWD: %s\n", getenv("PWD"));
    printf("LINES: %s\n", getenv("LINES"));
    printf("PATH: %s\n", getenv("PATH"));
    rintf("SHELL: %s\n", getenv("SHELL"));
    return 0;
}
