#include"Algorithm.h"
#include <iostream>
#include <string>

// 函数符也叫函数对象，是重载了函数调用运算符 () 的类对象。
// 自适应函数符是一种特殊的函数符，它通过typedef公开其参数和返回类型，使得函数适配器能够识别和使用它们。
// 函数适配器是用来修改或组合现有函数符行为的工具。
int main()
{
    using std::cin;
    using std::cout;
    char choice;
    cout<<"请输入演示的示例选项：\n";
    cout<<"A:算法演示1\t B:算法演示2\t C:remove对list使用\t D:一些算法的使用\tE:valarray矩阵运算\t E:初始化列表\t G:切片\t退出:Q\n";
    while(std::cin>>choice&& toupper(choice) != 'Q'){
        while (cin.get() != '\n')
            continue;
        switch (toupper(choice))
        {
        case 'A':algorithms_demo1();
            break;
        case 'B':algorithms_demo2();
            break;
        case 'C':listrmv();
            break;
        case 'D':usealgo();
            break;
        case 'E':valvect();
            break;
        case 'F':ilist();
            break;
        case 'G':vslice();
            break;
        }
        cout << "请输入选项 (A/B/C/D/E/F/G/Q): ";
    }
    cout << "程序结束\n";
    return 0;
}



