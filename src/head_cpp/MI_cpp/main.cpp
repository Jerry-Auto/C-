// workmi.cpp -- 测试Worker类多重继承体系
#include <iostream>
#include <cstring>      // 用于strchr()
#include "worker.h"     // 包含Worker类层次定义
using namespace std;

const int SIZE = 5;     // 定义员工数组大小

int main()
{
    // 创建Worker指针数组（多态演示）
    Worker* staff[SIZE]; 

    // 临时变量用于用户输入
    int choice;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "请选择员工类型:\n"
             << "1: 服务员  2: 歌手  3: 会唱歌的服务员  0: 退出\n";
        cin >> choice;
        
        // 清除输入缓冲区（防止换行符影响后续输入）
        while (cin.get() != '\n')
            continue;

        // 用户选择退出
        if (choice == 0)
            break;

        // 根据用户选择创建不同派生类对象
        switch (choice)
        {
        case 1:  // 创建Waiter对象
            staff[i] = new Waiter;
            staff[i]->Set();  // 调用虚函数
            break;
        case 2:  // 创建Singer对象
            staff[i] = new Singer;
            staff[i]->Set();
            break;
        case 3:  // 创建SingingWaiter对象
            staff[i] = new SingingWaiter;
            staff[i]->Set();
            break;
        default: // 无效输入
            cout << "无效选择！\n";
            i--;  // 重新循环
            continue;
        }
    }

    // 显示所有员工信息
    cout << "\n===== 员工列表 =====\n";
    for (int i = 0; i < SIZE; i++)
    {
        if (staff[i] == nullptr)  // 可能提前退出
            break;
        
        staff[i]->Show();  // 多态调用
        cout << endl;
    }

    // 释放动态分配的内存
    for (int i = 0; i < SIZE; i++)
    {
        delete staff[i];  // 调用虚析构函数
    }

    return 0;
}