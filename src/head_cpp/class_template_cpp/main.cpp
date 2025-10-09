// stacktem.cpp -- 测试Stack模板类
#include <iostream>
#include <string>
#include <cctype>  // 用于toupper()
#include "stacktp.h"  // 包含栈模板定义
#include "arraytp.h"
#include "pair.h"
#include <cstdlib>    // 用于rand()和srand()
#include <ctime>      // 用于time()
using namespace std;
const int num=10;
void stacktem();
void stkoptr1();
void twod();
void my_pair();
int main()
{
    char choice;
    cout<<"请输入演示的示例选项：\n";
    cout<<"S:入栈出栈\t P:指针数组与栈\t A:二维数组\t T:pair \t退出:Q\n";
    while(cin>>choice&& toupper(choice) != 'Q'){
        while (cin.get() != '\n')
            continue;
        switch (toupper(choice))
        {
        case 'S':stacktem();
            break;
        case 'P':stkoptr1();
            break;
        case 'A':twod();
            break;
        case 'T':my_pair();
            break;
        }
        cout << "请输入选项 (S/P/A/T/Q): ";
    }
    cout << "程序结束\n";

    return 0;
}

void stacktem()
{
    Stack<string> st;  // 创建字符串栈（容量默认为10）
    char ch;
    string po;

    cout << "请输入选项:\n"
         << "A: 压栈   P: 弹栈   Q: 退出\n";

    while (cin >> ch && toupper(ch) != 'Q')
    {
        // 清除输入缓冲区中的换行符
        while (cin.get() != '\n')
            continue;

        switch (toupper(ch))
        {
        case 'A':
            cout << "请输入要压栈的字符串: ";
            getline(cin, po);
            if (st.isfull())
                cout << "栈已满！\n";
            else
                st.push(po);
            break;

        case 'P':
            if (st.isempty())
                cout << "栈已空！\n";
            else {
                st.pop(po);
                cout << "弹出字符串: " << po << endl;
            }
            break;
        }
        cout << "请输入选项 (A/P/Q): ";
    }

    cout << "程序结束\n";
}

void stkoptr1(){
    // 初始化随机数种子
    std::srand(std::time(0));
    // 用户自定义栈大小
    std::cout << "输入栈长度: ";
    int stacksize;
    std::cin >> stacksize;
    Stack<const char*> st(stacksize);  // 创建存储 const char* 的栈
    // 初始化任务池（指针数组）
    const char* in[num] = {
        "1: 编译代码", "2: 测试模块", "3: 修复Bug", 
        "4: 优化算法", "5: 编写文档", "6: 会议讨论",
        "7: 部署服务", "8: 备份数据", "9: 用户调研", "10: 代码审查"
    };
    const char* out[num];  // 存储已完成的任务
    int processed = 0;      // 已处理任务计数
    int nextin = 0;        // 下一个待压栈的任务索引
    // 模拟任务调度（随机压栈/弹栈）
    while (processed < num) {
        if (st.isempty()) {
            st.push(in[nextin++]);  // 栈空时强制压入新任务
        } 
        else if (st.isfull()) {
            st.pop(out[processed++]); // 栈满时强制弹出任务
        } 
        else {
            // 随机决定压栈或弹栈（50%概率）
            if (std::rand() % 2 && nextin < num) {
                st.push(in[nextin++]);  // 压入新任务
            } else {
                st.pop(out[processed++]); // 弹出已完成任务
            }
        }
    }
    // 输出处理结果
    std::cout << "\n===== 任务处理顺序 =====\n";
    for (int i = 0; i < num; i++) {
        std::cout << out[i] << std::endl;
    }
    std::cout << "任务调度结束！\n";
}

void twod(){
    ////1.
    //const int col=5,row=10;
    ////2.
    enum{col=5,row=10};
    ////3.引用不行
    // int a=10,b=5;
    // int& row=a;
    // int& col=b;

    ArrayTP<int,row> sums;
    ArrayTP<double,row> aves;
    ArrayTP<ArrayTP<int,col>,row> twodee;

    int i,j;
    for(i=0;i<row;i++){
        sums[i]=0;
        for(j=0;j<col;j++)
        {
            twodee[i][j]=(i+1)*(j+1);
            sums[i]+=twodee[i][j];
        }
        aves[i]=(double)sums[i]/col;
    }

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            cout.width(2);
            cout<<twodee[i][j]<<' ';
        }
        cout<<":sum= ";
        cout.width(3);
        cout<<sums[i]<<", average="<<aves[i]<<endl;
    }

    cout<<"再见\n";
}
void my_pair(){

    // 定义常量NUM为4
    const int NUM = 4;

    // 创建Pair<string, int>数组存储餐厅评分
    Pair<string, int> ratings[NUM] = {
        Pair<string, int>("The Purple Duck", 4),      
        Pair<string, int>("Jaquie's Frisco Al Fresco", 4),
        Pair<string, int>("Cafe Souffle", 5),
        Pair<string, int>("Bertie's Eats", 3)
    };

    // 计算数组元素个数（joints = NUM = 4）
    int joints = sizeof(ratings) / sizeof(Pair<string, int>);

    // 打印表头
    cout << "Rating:\t Eatery\n";

    // 遍历输出所有餐厅评分
    for (int i = 0; i < joints; i++) {
        cout << ratings[i].second() << ":\t" 
             << ratings[i].first() << endl;
    }

    // 修改最后一个元素的值
    cout << "修改最后一个元素的值:\n";
    ratings[3].second() = 6;          // 修改评分为6
    ratings[3].first() = "B F E";     // 修改店名为"B F E"

    // 输出修改后的元素
    cout << ratings[3].second() << ":\t" 
         << ratings[3].first() << "\n";
}

