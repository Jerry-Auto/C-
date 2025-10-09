// studentc.cpp -- Student class using containment
#include "studentc.h"

using std::ostream;
using std::endl;
using std::istream;
using std::string;
namespace containment{
// 私有方法：输出分数
ostream & Student::arr_out(ostream & os) const {
    int i;
    int lim = scores.size();
    if (lim > 0) {
        for (i = 0; i < lim; i++) {
            os << scores[i] << " ";
            if (i % 5 == 4)
                os << endl;
        }
        if (i % 5 != 0)
            os << endl;
    } else {
        os << " empty array ";
    }
    return os;
}

// 计算平均分
double Student::Average() const {
    if (scores.size() > 0)
        return scores.sum() / scores.size();
    else
        return 0;
}

// 重载下标运算符（可修改版本）
double & Student::operator[](int i) {
    return scores[i]; // 使用 valarray 的下标运算符
}

// 重载下标运算符（const 版本）
//可以使用const double& Student::operator[](int i) const
//double a=stu[1],a仍然是值拷贝
//const double &ref=stu[1],ref只读
double Student::operator[](int i) const {
    return scores[i];
}

// 友元函数：输入运算符
istream & operator>>(istream & is, Student & stu) {
    is >> stu.name;
    return is;
}

// 友元函数：获取一行输入
istream & getline(istream & is, Student & stu) {
    getline(is, stu.name);
    return is;
}

// 友元函数：输出运算符
ostream & operator<<(ostream & os, const Student & stu) {
    os << "Scores for " << stu.name << ":\n";
    stu.arr_out(os);
    return os;
}
}