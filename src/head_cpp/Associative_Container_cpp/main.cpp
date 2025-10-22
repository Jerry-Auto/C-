#include "AContainer.h"
#include <iostream>
#include <string>


int main()
{
    using std::cin;
    using std::cout;
    char choice;
    cout<<"请输入演示的示例选项：\n";
    cout<<"A:multimap\t B:map\t C:multiset\t D:set\tE:unordered_multimap_demo\t F:unordered_map_demo \t G:unordered_multiset_demo \t H:unorderd_set \t 退出:Q \n";
    while(std::cin>>choice&& toupper(choice) != 'Q'){
        while (cin.get() != '\n')
            continue;
        switch (toupper(choice))
        {
        case 'A':multimapExample();
            break;
        case 'B':mapExample();
            break;
        case 'C':multisetExample();
            break;
        case 'D':setExample();
            break;
        case 'E':unordered_multimap_demo();
            break;
        case 'F':unordered_map_demo();
            break;
        case 'G':unordered_multiset_demo();
            break;
        case 'H':unorderd_set();
            break;
        }
        cout << "请输入选项 (A/B/C/D/E/F/G/H/Q): ";
    }
    cout << "程序结束\n";
    return 0;
}



