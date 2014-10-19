#include <iostream>
#include <memory>
#include <string>

class Simple {
public:
Simple(int param = 0) 
{
    number = param;
    std::cout << "Simple: " << number << std::endl; 
}

~Simple() {
    std::cout << "~Simple: " << number << std::endl;
}

void PrintSomething() {
    std::cout << "PrintSomething: " << info_extend.c_str() << std::endl;
}

std::string info_extend;
int number;
};

void testAutoPtr()
{
    std::auto_ptr<Simple> my(new Simple(1));
    if( my.get())
    {
       my->PrintSomething(); 
       my.get()->info_extend = "Addition";
       my->PrintSomething(); 
    }
}
int main(int argc, char * argv[])
{
    std::shared_ptr<int> p1(new int(1));
    std::shared_ptr<int> p2(p1);
    std::cout << *p2 << std::endl;
    testAutoPtr();
    return 0;
}
