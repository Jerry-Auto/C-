#include<iostream>

// 函数声明：演示四种C++类型转换操作符
void cast_static();        // 演示 static_cast
void cast_const();         // 演示 const_cast
void change(const int * pt, int n); // 用于 const_cast 演示的辅助函数
void dynamic_cast_();      // 演示 dynamic_cast
void cast_reinterpret();   // 演示 reinterpret_cast

// 基类定义，包含虚函数以支持多态和dynamic_cast
class base_A {
private: 
    std::string word; // 私有成员变量，存储字符串
public: 
    explicit base_A(char * w) : word(w) {}; // 显式构造函数，防止隐式转换
    virtual void what() { std::cout << word << std::endl; } // 虚函数，输出单词
    virtual ~base_A() {}; // 虚析构函数，确保正确释放派生类对象[7](@ref)
};

// 派生类定义，继承自base_A
class derive_A : public base_A {
private:
    std::string word2; // 派生类私有成员变量
public: 
    derive_A(char * w, char * w2) : base_A(w), word2(w2) {}; // 构造函数，初始化基类和派生类成员
    void what() override { // 重写基类虚函数
        base_A::what();   // 调用基类版本的what()
        std::cout << word2 << std::endl; // 输出派生类特有的字符串
    }
};

// 简单的结构体，包含两个short类型成员
struct dat { 
    short a; 
    short b; 
};

int main() {
    using std::cin;
    using std::cout;
    char choice; // 存储用户输入的选项
    
    // 显示菜单选项
    cout << "请输入演示的示例选项：\n";
    cout << "D:dynamic_cast\t S:static_cast\t C:const_cast\t R:reinterpret_cast\t退出:Q\n";
    
    // 主循环：读取用户选择并调用相应函数
    while (std::cin >> choice && toupper(choice) != 'Q') {
        while (cin.get() != '\n') // 清除输入缓冲区中的剩余字符
            continue;
        
        // 根据用户选择调用不同的演示函数[7](@ref)
        switch (toupper(choice)) {
        case 'D': 
            dynamic_cast_(); // 动态类型转换演示
            break;
        case 'S': 
            cast_static();   // 静态类型转换演示
            break;
        case 'R': 
            cast_reinterpret(); // 重新解释类型转换演示
            break;
        case 'C': 
            cast_const();    // 常量类型转换演示
            break;
        }
        cout << "请输入选项 (D/S/C/R/Q): "; // 提示用户再次输入
    }
    cout << "程序结束\n";
    return 0;
}

// 演示reinterpret_cast：将一种类型重新解释为另一种类型[6,7](@ref)
void cast_reinterpret() {
    long value = 0xA224B118; // 长整型值
    std::cout << std::hex << value << std::endl; // 以十六进制格式输出
    
    // 使用reinterpret_cast将long类型的指针重新解释为dat结构体指针
    dat* pd = reinterpret_cast<dat*>(&value);
    std::cout << std::hex << pd->a << std::endl; // 输出结构体成员a（值的上半部分）
    std::cout << std::hex << pd->b << std::endl; // 输出结构体成员b（值的下半部分）
}

// 演示static_cast：编译时类型转换，用于相关类型间的转换[7](@ref)
void cast_static() {
    derive_A da = derive_A("基类base_A", "派生类derive_A"); // 创建派生类对象
    base_A ba = base_A("我是基类"); // 创建基类对象
    
    std::cout << "类型转化前：" << std::endl;
    ba.what(); // 调用基类对象的what方法
    da.what(); // 调用派生类对象的what方法
    
    std::cout << "类型转化后：" << std::endl;
    // 向上转换：派生类指针转换为基类指针（安全）
    base_A* pba = static_cast<base_A*>(&da);
    // 向下转换：基类指针转换为派生类指针（不安全，可能导致未定义行为）
    derive_A* pda = static_cast<derive_A*>(&ba);
    
    pba->what(); // 调用派生类对象的what方法（通过基类指针，多态）
    pda->what(); // 调用基类对象的what方法（通过派生类指针，不安全）
    
    // 以下代码无效，编译错误：static_cast不能用于不相关的指针类型转换
    // char *pc = static_cast<char *>(&ba);
}

// 演示const_cast：移除或添加const属性[7](@ref)
void cast_const() {
    int pop1 = 38383;       // 非常量变量
    const int pop2 = 2000;  // 常量变量
    
    std::cout << "改变前pop1、pop2: " << pop1 << "," << pop2 << std::endl;
    change(&pop1, -1000);  // 修改非常量变量（安全）
    change(&pop2, -1000);  // 修改常量变量（不安全，未定义行为）
    std::cout << "改变后pop1、pop2: " << pop1 << "," << pop2 << std::endl;
}

// 辅助函数：通过const_cast修改指针指向的值
void change(const int * pt, int n) {
    // 使用const_cast移除const属性，获得可修改的指针
    int *pc = const_cast<int*>(pt);
    *pc += n; // 修改指针指向的值
}

// 演示dynamic_cast：运行时类型检查的安全向下转换[7](@ref)
void dynamic_cast_() {
    derive_A da = derive_A("基类base_A", "派生类derive_A"); // 创建派生类对象
    
    std::cout << "类型转化前：" << std::endl;
    da.what(); // 调用派生类对象的what方法
    
    // 使用dynamic_cast进行向下转换（派生类到基类的引用转换）
    base_A& pa = dynamic_cast<base_A&>(da);
    
    std::cout << "类型转化后：" << std::endl;
    pa.what(); // 调用基类引用指向的对象的what方法（多态）
}