#include <stdio.h>
#include <pwd.h>
#include <shadow.h>
#include <string.h>
#define _XOPEN_SOURCE
#include <stdlib.h>
#include <unistd.h>
#include <crypt.h>

int main(int argc, char * argv[])
{
    struct passwd* pwd;
    char* name = "mlliu";
    setpwent();
    while ((pwd = getpwent()) != NULL)
    {
        if(strcmp(name, pwd->pw_name) == 0)
        {
            printf("%s\n", pwd->pw_passwd);
            break;
        }
    }
    struct spwd *spwd = getspnam("mlliu");
    printf("%s\n", spwd->sp_pwdp);
    if(strcmp(spwd->sp_pwdp, (char*)crypt("lml19870419", spwd->sp_pwdp)) == 0)
    {
        printf("%s\n", spwd->sp_pwdp);
    }
    endpwent();
    return 0;
}
