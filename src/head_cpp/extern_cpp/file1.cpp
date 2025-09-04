#include<iostream>

extern const int a=10;
int b=20;
void show();
int main(int argc, char const *argv[])
{
    using namespace std;
    std::cout<<"file1:"<<std::endl;
    cout<<a<<std::endl;
    show();
    return 0;
}
