#include <iostream>
#include <utility> // for std::move

class MyString {

public:
    // 默认构造函数
    MyString() : data_(nullptr), size_(0) {
        std::cout << "默认构造字符串\n";
    }  // 初始化成员变量

    // 普通构造函数
    MyString(const char* str) {
        std::cout << "普通构造字符串\n";
        // 假设此处分配内存并复制数据
    }

    // 移动构造函数
    MyString(MyString&& other) noexcept 
        : data_(other.data_), size_(other.size_) {
        other.data_ = nullptr;  // 原对象资源置空
        other.size_ = 0;
        std::cout << "移动构造字符串\n";
    }

    // 移动赋值运算符
    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            delete[] data_;      // 释放当前资源
            data_ = other.data_; // 接管新资源
            size_ = other.size_;
            other.data_ = nullptr;
            other.size_ = 0;
            std::cout << "移动赋值运算\n";
        }
        else{
            std::cout << "自移动赋值\n";
        }
        return *this;
    }

    // 拷贝构造函数
    MyString(const MyString& other) {
        std::cout << "拷贝构造\n";
        // 深拷贝逻辑
    }

private:
    char* data_;
    size_t size_;
};

//在 C++17 及更高版本中，编译器会强制启用 返回值优化
//临时对象被直接构造到目标位置：MyString("World") 会直接在 s2 的内存位置构造，跳过移动构造函数。
//移动构造函数被绕过：编译器认为直接构造更高效，因此不会生成临时对象再移动的操作。
//禁用编译器优化
//g++ -g -std=c++11 -fno-elide-constructors rightvalue.cpp -o rightvalue
 

int main() {
    using namespace std;
    cout<<"-----------普通构造--------\n";
    // 示例1: 普通构造函数
    MyString s1("Hello");       // 输出 普通构造

    cout<<"-----------移动构造--------\n";
    // 示例2: 移动构造函数（通过右值初始化）
    MyString s2 = MyString("World"); // 输出 普通构造+移动构造

    cout<<"-----------拷贝构造--------\n";
    // 示例3: 拷贝构造函数
    MyString s3 = s1;           // 输出 拷贝构造

    cout<<"-----------移动赋值运算-----\n";
    // 示例4: 移动赋值运算符
    MyString s4;                // 输出 默认构造
    s4 = std::move(s2);         // 输出 移动赋值运算

    cout<<"-----------移动构造--------\n";
    // 示例5: 函数返回临时对象（触发移动构造）
    auto createString = []() {
        return MyString("Temp");  //输出 普通构造+移动构造
    };
    MyString s5 = createString(); // 输出 移动构造

    cout<<"-----------传递右值--------\n";
    // 示例6: 传递右值参数（触发移动构造）
    auto processString = [](MyString&& str) {
        MyString s6 = std::move(str); // 输出 移动构造字符串
    };
    processString(MyString("RValue")); // 输出 普通构造字符串

    cout<<"-----------移动赋值--------\n";
    // 示例7: 移动赋值给已存在对象
    MyString s7;               // 输出 默认构造
    s7 = MyString("MoveMe");    // 输出 普通构造字符串+移动赋值运算

    cout<<"-----------自移动赋值--------\n";
    // 示例8: 自移动赋值
    s7 = std::move(s7);         // 输出 自移动赋值（条件判断 this == &other）
    MyString s8=std::move(s7);  // 输出 移动构造
    // 析构顺序：s7 -> s4 -> s3 -> s1 -> s5 -> s6（按作用域结束顺序）
    return 0;

}