#pragma once
#include<iostream>
class class_cpp
{
private:
    int a;
    const char *b;
    double c;
public:
    class_cpp():a(0),b("p_b"),c(0.0){
        std::cout<<a<<"默认构造\n";
    }
    class_cpp(int p_a,const char *p_b="class",double p_c=0.0):a(p_a),b(p_b),c(p_c){
        std::cout<<a<<"自定义构造\n";
    }
    class_cpp(const class_cpp& other) :a(other.a),b(other.b),c(other.c){ 
        std::cout << "拷贝构造: " << a << std::endl; 
    }

    class_cpp& operator=(const class_cpp& other) { 
        std::cout << "赋值操作: " << a<< std::endl; 
        return *this;
    }
    void show() const;

    ~class_cpp()
    {
        std::cout<<a<<"默认析构函数\n";
    }
};


