#include "iterator.h"
#include <iostream>
#include <string>


int main()
{
    using std::cin;
    using std::cout;
    char choice;
    cout<<"请输入演示的示例选项：\n";
    cout<<"A:find算法，链表迭代器，数组指针\t B:反响迭代器，copy算法\t C:inserts迭代器\t D:内存管理\t退出:Q\n";
    while(std::cin>>choice&& toupper(choice) != 'Q'){
        while (cin.get() != '\n')
            continue;
        switch (toupper(choice))
        {
        case 'A':itera();
            break;
        case 'B':copyit();
            break;
        case 'C':inserts();
            break;
        }
        cout << "请输入选项 (A/B/C/D/Q): ";
    }
    cout << "程序结束\n";
    return 0;
}



