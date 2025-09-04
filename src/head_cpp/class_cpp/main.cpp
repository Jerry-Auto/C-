#include<class_cpp.h>
#include<iostream>

void test()
{
        class_cpp c1={1,"abc",2.2};
        //先定义临时对象，调用自定义构造
        //再调用拷贝构造，没有显式定义拷贝构造时，将对所有变量进行复制
        class_cpp c2=class_cpp(2);
        
        c1.show();
        c2.show();
        c2=class_cpp(3);
        c2.show();

        const class_cpp c3 =class_cpp(4);
        c3.show();   
}
int main(int argc, char const *argv[])
{
    {
        class_cpp cs[3]={
            class_cpp(),
            class_cpp(2),
            class_cpp(3)
        };
        for(int i=0;i<3;i++)
        {
            cs[i].show();
        }
    }
    return 0;
}
