#include <iostream>
#include <cmath>    // 或 math.h, 用于 sqrt()
#include <string>

// 异常类 - 表示数学错误
class bad_hmean
{
private:
    double v1;
    double v2;
public:
    bad_hmean(double a = 0, double b = 0) : v1(a), v2(b) {}
    void mesg();
};

inline void bad_hmean::mesg()
{
    std::cout << "hmean(" << v1 << ", " << v2 << "): "
              << "invalid arguments: a = -b\n";
}

// 另一个异常类 - 表示数学计算错误
class bad_gmean
{
public:
    double v1;
    double v2;
    bad_gmean(double a = 0, double b = 0) : v1(a), v2(b) {}
    const char * mesg();
};

inline const char * bad_gmean::mesg()
{
    return "gmean() arguments should be >= 0\n";
}

// 用于演示构造和析构的类
class demo
{
private:
    std::string word;
public:
    explicit demo(const std::string & str):word(str)
    {
        std::cout << "demo " << word << " created\n";
    }
    ~demo()
    {
        std::cout << "demo " << word << " destroyed\n";
    }
    void show() const
    {
        std::cout << "demo " << word << " lives!\n";
    }
};


// 调和平均数函数
double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a, b);  // 抛出异常
    return 2.0 * a * b / (a + b);
}

// 几何平均数函数
double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);  // 抛出异常
    return std::sqrt(a * b);
}


// 计算两种平均数的函数 - 演示异常传播
double means(double a, double b)
{
    double am, hm, gm;
    demo d2("found in means()");  // 局部 demo 对象
    
    am = (a + b) / 2.0;
    try {
        hm = hmean(a, b);
        gm = gmean(a, b);
    }
    catch (bad_hmean & bg) {
        bg.mesg();
        std::cout << "Caught in means()\n";
        throw;  // 重新抛出，演示栈解退
    }
    d2.show();
    return (am + hm + gm) / 3.0;
}