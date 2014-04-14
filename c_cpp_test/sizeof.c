#include "stdio.h"
#include "string.h"
int main() {
    char *p = new char[20];
    char *p1 = "12345";
    char p3[20];
    char p4[] = "12345";
    printf("%d\n", sizeof(p));
    printf("%d\n", sizeof(p1));
    printf("p3 %d\n", sizeof(p3));
    strcpy(p3, "123456789123456789123456789");
    printf("p3 str %d\n", sizeof(p3));
    printf("%d\n", sizeof(p4));
    printf("%d\n", sizeof(&p));
    printf("%d\n", sizeof(&p1));
    printf("%d\n", sizeof(&p3));
    printf("%d\n", sizeof(&p4));
    return 0;
}
