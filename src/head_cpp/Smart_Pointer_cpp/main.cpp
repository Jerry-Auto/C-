#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "func.h"
using namespace std;
void ptr(int* a);
int main() {
    using std::cin;
    using std::cout;
    int a=10;
    ptr(&a);
    char choice;
    cout<<"请输入演示的示例选项：\n";
    cout<<"S:多种智能指针\t H:猜单词游戏\t F:文件读取\t R:内存管理\t退出:Q\n";
    while(std::cin>>choice&& toupper(choice) != 'Q'){
        while (cin.get() != '\n')
            continue;
        switch (toupper(choice))
        {
        case 'S':smartptrs();
            break;

        }
        cout << "请输入选项 (C/H/F/R/Q): ";
    }
    cout << "程序结束\n";

    return 0;
}


void ptr(int* a){
    std::cout<<*a;
}

