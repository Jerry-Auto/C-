#include <iostream>

extern const int a;

extern int b;
void show()
{
    std::cout<<"file2:"<<std::endl;
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;

}