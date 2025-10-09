// rtti1.cpp -- 使用 RTTI 的 dynamic_cast 运算符
#include <iostream>
#include <cstdlib>  // 用于 rand() 和 srand()
#include <ctime>    // 用于 time()

using std::cout;

// 基类 Grand
class Grand
{
private:
    int hold; // 持有的数据
public:
    Grand(int h = 0) : hold(h) {} // 构造函数
    virtual void Speak() const { cout << "我是一个 Grand 类！\n"; } // 虚函数
    virtual int Value() const { return hold; } // 另一个虚函数，返回值
};

// 派生类 Superb，继承自 Grand
class Superb : public Grand
{
public:
    Superb(int h = 0) : Grand(h) {} // 构造函数，调用基类构造函数
    // ​虚函数特性在继承链中保持​​：在 C++ 中，一旦一个成员函数在基类中被声明为 virtual（虚函数），
    // 那么在所有直接或间接从该基类派生的类中，​​所有与这个基类虚函数具有相同函数签名（函数名、参数列表、常量性）的重写函数，
    // 自动成为虚函数​​，无论你是否显式地写上 virtual关键字
    void Speak() const { cout << "我是一个 superb 类！！\n"; } // 重写基类虚函数
    virtual void Say() const // 派生类新增的虚函数
        { cout << "我持有 superb 值 " << Value() << "!\n"; }
};

// 派生类 Magnificent，继承自 Superb (间接继承自 Grand)
class Magnificent : public Superb
{
private:
    char ch; // 派生类新增的数据成员
public:
    Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {} // 构造函数，调用直接基类构造函数
    void Speak() const { cout << "我是一个 magnificent 类！！！\n"; } // 重写 Speak
    void Say() const { cout << "我持有字符 '" << ch << // 重写 Say
               "' 和整数 " << Value() << "!\n"; }
};

