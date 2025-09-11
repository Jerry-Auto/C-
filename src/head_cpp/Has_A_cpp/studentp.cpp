// studentp.cpp -- Student class using private inheritance
#include "studentp.h"

using std::ostream;
using std::endl;
using std::istream;
using std::string;

// 私有方法：输出分数
ostream & Student::arr_out(ostream & os) const {
    int i;
    int lim = size();
    if (lim > 0) {
        for (i = 0; i < lim; i++) {
            os << operator[](i) << " ";
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
    if (size() > 0)
        return sum() / size();
    else
        return 0;
}

// 友元函数：输入运算符
istream & operator>>(istream & is, Student & stu) {
    is >> (string &)stu; // 转换为基类引用
    return is;
}

// 友元函数：获取一行输入
istream & getline(istream & is, Student & stu) {
    getline(is, (string &)stu);
    return is;
}

// 友元函数：输出运算符
ostream & operator<<(ostream & os, const Student & stu) {
    os << "Scores for " << (const string &)stu << ":\n";
    stu.arr_out(os);
    return os;
}