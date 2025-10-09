#include "rtti1.h"

// 函数声明：随机生成三种类型对象之一并返回其基类指针
Grand * GetOne();
void ref_dynamic();
void dynamic_cast_();
void typeid_();
int main()
{
    std::srand(std::time(0)); // 用当前时间初始化随机数种子
    
    using std::cin;
    using std::cout;
    char choice;
    cout<<"请输入演示的示例选项：\n";
    cout<<"D:dynamic_cast\t R:dynamic_cast接受引用类型\t T:typeid\t退出:Q\n";
    while(std::cin>>choice&& toupper(choice) != 'Q'){
        while (cin.get() != '\n')
            continue;
        switch (toupper(choice))
        {
        case 'D':dynamic_cast_();
            break;
        case 'P':ref_dynamic();
            break;
        case 'T':typeid_();
            break;
        }
        cout << "请输入选项 (S/P/A/T/Q): ";
    }
    cout << "程序结束\n";
    
    
    // std::cin.get(); // 原书可能用于暂停屏幕
    return 0;
}
void typeid_(){
    Grand * pg; // 基类指针

    for (int i = 0; i < 5; i++) // 循环5次
    {
        pg = GetOne(); // 获取一个随机类型的对象（基类指针指向派生类对象）
        cout << "现在处理类型为 " << typeid(*pg).name() << " 的对象。\n"; // 使用 typeid 获取对象的实际类型名称
        pg->Speak();   // 通过基类指针调用虚函数 Speak (多态)

        // 使用 typeid 和 type_info 的比较功能来识别具体类型
        if (typeid(*pg) == typeid(Grand))
        {
            cout << "这是纯 Grand 对象，没有特定派生类行为。\n";
        }
        else if (typeid(*pg) == typeid(Superb))
        {
            // 对于 Superb 或 Magnificent 对象，我们可以安全地转换为 Superb* 以调用 Say
            Superb * ps = dynamic_cast<Superb*>(pg);
            if (ps) // 转换成功检查（对于这个分支，理论上总是成功，因为类型是 Superb）
                ps->Say();
        }
        else if (typeid(*pg) == typeid(Magnificent))
        {
            // 对于 Magnificent 对象，同样转换为 Superb* 调用 Say（Magnificent 重写了 Say）
            Superb * ps = dynamic_cast<Superb*>(pg);
            if (ps) // 转换成功检查
                ps->Say();
            // 或者也可以直接转换为 Magnificent* 来调用其特有的方法（如果有的话）
            // Magnificent * pm = dynamic_cast<Magnificent*>(pg);
            // if (pm) pm->SpecificMethod(); // 假设有 SpecificMethod
        }
        else
        {
            cout << "未知类型！\n"; // 理论上不会执行到这里
        }
        cout << "----------------\n";
        delete pg; // 释放动态分配的对象
    }
}

void dynamic_cast_(){
    Grand * pg; // 基类指针
    Superb * ps; // 派生类指针

    for (int i = 0; i < 5; i++) // 循环5次
    {
        pg = GetOne(); // 获取一个随机类型的对象（基类指针指向派生类对象）
        pg->Speak();   // 通过基类指针调用虚函数 Speak (多态)

        // 尝试用 dynamic_cast 将基类指针 Grand* 安全地向下转换为派生类指针 Superb*
        // 如果 pg 实际指向 Superb 或 Magnificent 对象（即 is-a Superb），转换成功，ps 不为 nullptr
        // 如果 pg 实际指向 Grand 对象，转换失败，ps 为 nullptr
        if (ps = dynamic_cast<Superb*>(pg)) 
            ps->Say(); // 仅当转换成功（ps 非空）时，调用 Superb 及派生类的 Say 方法

        delete pg; // 释放动态分配的对象 (实际中需根据类型正确析构，这里基类有虚函数，建议虚析构函数)
    }
}

void ref_dynamic()
{
    Grand * pg; // 基类指针
    for (int i = 0; i < 5; i++) // 循环5次
    {
        pg = GetOne(); // 获取一个随机类型的对象（基类指针指向派生类对象）
        pg->Speak();   // 通过基类指针调用虚函数 Speak (多态)

        try{
            Superb& rs=dynamic_cast<Superb &>(*pg);
            rs.Say(); // 仅当转换成功（ps 非空）时，调用 Superb 及派生类的 Say 方法
        }
        catch(std::bad_cast& bc)
        {
            cout<<"当前类是grand基类\n";
        }
        delete pg; // 释放动态分配的对象 (实际中需根据类型正确析构，这里基类有虚函数，建议虚析构函数)
    }
}


// 函数定义：随机生成三种类型对象之一
Grand * GetOne()
{
    Grand * p = nullptr; // 初始化基类指针
    switch (std::rand() % 3) // 随机数对3取模，得到0, 1, 2
    {
        case 0: // 生成 Grand 对象
            p = new Grand(std::rand() % 100); // 随机初始化 hold 值
            break;
        case 1: // 生成 Superb 对象
            p = new Superb(std::rand() % 100); // 随机初始化 hold 值 (通过Grand构造函数)
            break;
        case 2: // 生成 Magnificent 对象
            p = new Magnificent(std::rand() % 100, // 随机初始化 hold 值 (通过Superb, Grand)
                                'A' + std::rand() % 26); // 随机初始化 ch (字母)
            break;
    }
    return p; // 返回指向新对象的基类指针
}