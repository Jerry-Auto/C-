#include "func.h"
#include <iostream>
#include <string>
int main()
{
    using std::cin;
    using std::cout;
    char choice;
    cout<<"请输入演示的示例选项：\n";
    cout<<"V:vector基本功能\t F:用于STL的函数\t F:文件读取\t R:内存管理\t退出:Q\n";
    while(std::cin>>choice&& toupper(choice) != 'Q'){
        while (cin.get() != '\n')
            continue;
        switch (toupper(choice))
        {
        case 'V':vect2();
            break;
        case 'F':vect3();
            break;
        }
        cout << "请输入选项 (C/H/F/R/Q): ";
    }
    cout << "程序结束\n";
    return 0;
}
