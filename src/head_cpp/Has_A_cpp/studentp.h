// studentp.h -- defining a Student class using private inheritance
#ifndef STUDENTP_H_
#define STUDENTP_H_

#include <iostream>
#include <string>
#include <valarray>
namespace private_inheritance{
//从两个基类派生出来
class Student : private std::string, private std::valarray<double> {
private:
    typedef std::valarray<double> ArrayDb;
    // 私有方法，用于分数输出
    std::ostream & arr_out(std::ostream & os) const;
public:
    // using BaseClass::member;  // 引入基类的成员（可以是变量、函数、类型等）
    using std::valarray<double>::operator[]; // 暴露基类方法的常用方法，using ...
    using std::valarray<double>::size;//
    
    Student() : std::string("Null Student"), ArrayDb() {}
    explicit Student(const std::string & s)
        : std::string(s), ArrayDb() {}
    explicit Student(int n) : std::string("Nully"), ArrayDb(n) {}
    Student(const std::string & s, int n)
        : std::string(s), ArrayDb(n) {}
    Student(const std::string & s, const ArrayDb & a)
        : std::string(s), ArrayDb(a) {}
    Student(const char * str, const double * pd, int n)
        : std::string(str), ArrayDb(pd, n) {}
    ~Student() {}
    
    double Average() const;
    const std::string & Name() const { return *this; } // 转换为基类引用
    double & operator[](int i) { return ArrayDb::operator[](i); }
    double operator[](int i) const { return ArrayDb::operator[](i); }

    // 友元函数
    friend std::istream & operator>>(std::istream & is, Student & stu);
    friend std::istream & getline(std::istream & is, Student & stu);
    friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};

}


#endif