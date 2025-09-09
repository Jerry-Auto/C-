#include<iostream>
#include"stringbad.h"
using std::cout;
using std::cin;
using std::endl;

void refcallme(stringbad& );
void cpycallme(stringbad );
void test_constructor();
void test_cin();
const int arsize=10;
const int maxlen=81;
int main(int argc, char const *argv[])
{
    test_constructor();
    return 0;
}

void test_cin()
{
    stringbad name;
    cout<<"输入名字\n";
    cin>>name;
    cout<<name<<endl;
    stringbad saying[arsize];
    char temp[maxlen];
    cout<<stringbad::HowMany()<<endl; 
}
void refcallme(stringbad& strb){
    cout<<"引用传递\n";
    cout<<strb<<endl;
}
void cpycallme(stringbad strb){
    cout<<"值传递\n";
    cout<<strb<<endl;
}

void test_constructor()
{
    cout<<"内部块：\n";
    stringbad headl1("obj1");
    stringbad headl2("obj2");
    stringbad sports("obj3");
    cout<<headl1<<endl;
    cout<<headl2<<endl;
    cout<<sports<<endl;

    refcallme(headl1);
    cout<<headl1<<endl;

    cpycallme(headl2);
    cout<<headl2<<endl;

    cout<<"通过复制构造初始化"<<endl;
    stringbad sailor=sports;
    cout<<"sailor:"<<sailor<<endl;
    cout<<"通过赋值运算符初始化"<<endl;
    stringbad knot;
    knot=sports;
    cout<<"knot:"<<knot<<endl;
}