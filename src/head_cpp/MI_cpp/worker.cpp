// worker.cpp -- 工作类方法实现
#include "worker.h"
#include <iostream>
using namespace std;

// Worker类方法实现
Worker::~Worker() {} // 必须实现纯虚析构函数，即使它是纯虚的

// 显示Worker基础数据
void Worker::Data() const
{
    cout << "姓名: " << fullname << endl;
    cout << "员工ID: " << id << endl;
}

// 获取Worker基础数据
void Worker::Get()
{
    getline(cin, fullname);
    cout << "输入员工ID: ";
    cin >> id;
    while (cin.get() != '\n')  // 清除输入缓冲区
        continue;
}

// Waiter类方法实现
void Waiter::Set()
{
    cout << "输入服务员姓名: ";
    Worker::Get();  // 获取Worker基础数据
    Get();          // 获取Waiter特有数据
}

void Waiter::Show() const
{
    cout << "类别: 服务员\n";
    Worker::Data();  // 显示Worker基础数据
    Data();          // 显示Waiter特有数据
}

// 显示Waiter特有数据
void Waiter::Data() const
{
    cout << "风度评级: " << panache << endl;
}

// 获取Waiter特有数据
void Waiter::Get()
{
    cout << "输入服务员风度评级: ";
    cin >> panache;
    while (cin.get() != '\n')  // 清除输入缓冲区
        continue;
}

// Singer类方法实现

// 声音类型字符串表示，定义必须用int a[],指定长度
const char * Singer::pv[] = {"其他", "女低音", "女中音",
            "女高音", "男低音", "男中音", "男高音"};

void Singer::Set()
{
    cout << "输入歌手姓名: ";
    Worker::Get();  // 获取Worker基础数据
    Get();          // 获取Singer特有数据
}

void Singer::Show() const
{
    cout << "类别: 歌手\n";
    Worker::Data();  // 显示Worker基础数据
    Data();          // 显示Singer特有数据
}

// 显示Singer特有数据
void Singer::Data() const
{
    cout << "音域: " << pv[voice] << endl;
}

// 获取Singer特有数据
void Singer::Get()
{
    cout << "输入歌手音域编号:\n";
    int i;
    // 显示音域选项菜单
    for (i = 0; i < Vtypes; i++)
    {
        cout << i << ": " << pv[i] << "   ";
        if ( i % 4 == 3)  // 每行显示4个选项
            cout << endl;
    }
    if (i % 4 != 0)  // 最后一行未满时换行
        cout << '\n';
    cin >> voice;    // 获取用户输入
    while (cin.get() != '\n')  // 清除输入缓冲区
        continue;
}

// SingingWaiter类方法实现
void SingingWaiter::Data() const
{
    Singer::Data();  // 显示Singer特有数据
    Waiter::Data();  // 显示Waiter特有数据
}

void SingingWaiter::Get()
{
    Waiter::Get();  // 获取Waiter特有数据
    Singer::Get();  // 获取Singer特有数据
}

void SingingWaiter::Set()
{
    cout << "输入会唱歌的服务员姓名: ";
    Worker::Get();  // 获取Worker基础数据
    Get();          // 获取SingingWaiter特有数据
}

void SingingWaiter::Show() const
{
    cout << "类别: 会唱歌的服务员\n";
    Worker::Data();  // 显示Worker基础数据
    Data();          // 显示SingingWaiter特有数据
}