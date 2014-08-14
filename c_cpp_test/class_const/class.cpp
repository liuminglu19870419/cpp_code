#include "class.h"
#include <iostream>

int Class::fun() const
{
    return k;
}

int Class::fun1()
{
    return k;
}

Class::Class(int k)
{
    this->k = k;
}
int main( int argc, char *argv[])
{
    Class class1(10);
    class1.k = 10;
    const Class class2 = class1;
    std::cout << class1.k << std::endl;
    std::cout << class2.k << std::endl;
    std::cout << class1.fun() << std::endl;
    std::cout << class2.fun() << std::endl;
    std::cout << class1.fun1() << std::endl;
    std::cout << class2.fun1() << std::endl;
    return 0;
}
