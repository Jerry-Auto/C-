#include "containers.h"
#include <iostream>
#include <string>


int main()
{
    using std::cin;
    using std::cout;
    char choice;
    cout<<"请输入演示的示例选项：\n";
    cout<<"A:list\t B:vec,deque,fl\t C:array,queue,stack,priority_queue\t D:内存管理\t退出:Q\n";
    while(std::cin>>choice&& toupper(choice) != 'Q'){
        while (cin.get() != '\n')
            continue;
        switch (toupper(choice))
        {
        case 'A':list_demo();
            break;
        case 'B':vec_deque_fl();
            break;
        case 'C':arr_que_stk_pq();
            break;
        }
        cout << "请输入选项 (A/B/C/D/Q): ";
    }
    cout << "程序结束\n";
    return 0;
}



