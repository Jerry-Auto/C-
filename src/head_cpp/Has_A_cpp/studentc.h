// studentc.h -- defining a Student class using containment
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>
#include <valarray>
namespace containment{
class Student {
private:
    typedef std::valarray<double> ArrayDb;
    std::string name;       // 包含对象：字符串
    ArrayDb scores;         // 包含对象：valarray
    // 私有方法，用于分数输出
    std::ostream & arr_out(std::ostream & os) const;
public:
    Student() : name("Null Student"), scores() {}
    explicit Student(const std::string & s)
        : name(s), scores() {}
    explicit Student(int n) : name("Nully"), scores(n) {}
    Student(const std::string & s, int n)
        : name(s), scores(n) {}
    Student(const std::string & s, const ArrayDb & a)
        : name(s), scores(a) {}
    Student(const char * str, const double * pd, int n)
        : name(str), scores(pd, n) {}
    ~Student() {}
    
    double Average() const;
    const double size()const{return scores.size();};//返回的是一个临时值
    const std::string & Name() const { return name; }
    double & operator[](int i);
    double operator[](int i) const;

    // 友元函数
    friend std::istream & operator>>(std::istream & is, Student & stu);
    friend std::istream & getline(std::istream & is, Student & stu);
    friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};
}

#endif