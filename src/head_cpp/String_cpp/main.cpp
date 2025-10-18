#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "func.h"
using namespace std;

int main() {
    using std::cin;
    using std::cout;
    char choice;
    cout<<"请输入演示的示例选项：\n";
    cout<<"C:string构造函数\t H:猜单词游戏\t F:文件读取\t R:内存管理\t退出:Q\n";
    while(std::cin>>choice&& toupper(choice) != 'Q'){
        while (cin.get() != '\n')
            continue;
        switch (toupper(choice))
        {
        case 'C':string_constructor();
            break;
        case 'H':hangman();
            break;
        case 'F':strfile();
            break;
        case 'R':capacity_ma();
            break;
        }
        cout << "请输入选项 (C/H/F/R/Q): ";
    }
    cout << "程序结束\n";

    return 0;
}


