#include<iostream>
int& test();
int main(int argc, char const *argv[])
{
    int &a=test();
    std::cout<<a<<std::endl;
    return 0;
}


int& test()
{
    int *a=new int();
    *a=10;
    return *a;
}