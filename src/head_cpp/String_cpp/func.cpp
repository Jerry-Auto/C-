#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cctype>
#include "func.h"
using namespace std;

void string_constructor(){
    // 构造方法示例
    string one("Lottery Winner!");  // 构造函数1：直接初始化
    cout << one << endl;
    
    string two(20, '$');           // 构造函数2：重复字符初始化
    cout << two << endl;
    
    string three(one);              // 构造函数3：复制构造函数
    cout << three << endl;
    
    // 运算符重载示例
    one += " Oops!";                // 重载+=操作符
    cout << one << endl;
    
    two = "Sorry! That was ";      // 字符串赋值
    three[0] = 'P';                // 修改字符
    
    string four;                   // 默认构造函数
    four = two + three;            // 重载+和=操作符
    cout << four << endl;
    
    // 字符数组构造字符串
    char alls[] = "All's well that ends well";
    string five(alls, 20);         // 从字符数组构造，截取前20个字符
    cout << five << "!\n";
    
    string six(alls + 6, alls + 10); // 从字符数组指定范围构造
    cout << six << ", ";
    
    string seven(&five[6], &five[10]); // 从另一个字符串的特定位置构造
    cout << seven << "...\n";
    
    string eight(four, 7, 16);     // 从另一个字符串的指定位置和长度构造
    cout << eight << " in motion!" << endl;
}


void strfile(){
    ifstream fin;  
    fin.open("../../src/head_cpp/String_cpp/tobuy.txt");  
    if (fin.is_open() == false) {  
        cerr << "Can't open file. Bye.\n";  
        exit(EXIT_FAILURE);  
    }  
    string item;  
    int count = 0;  
    getline(fin, item, ':');  
    while (fin) {  
        ++count;  
        cout << count << ": " << item << endl;  
        getline(fin, item, ':');  
    }  
    cout << "Done\n";  
    fin.close();  
}

void hangman(){
    vector<string> words;
    ifstream fin("../../src/head_cpp/String_cpp/wordlist.txt");
    if (!fin.is_open()) {
        cerr << "文件打开失败！" << endl;
    }
    else{
    string temp;
    while (fin >> temp) {
        words.push_back(temp);
    }
    fin.close();
 
    srand(time(0));
    char play;
    cout << "欢迎玩猜单词游戏！<y/n> ";
    cin >> play;
    play = tolower(play);
 
    while (play == 'y') {
        string target = words[rand() % words.size()];
        string attempt(target.length(), '-');
        string badchars;
        int guesses = 6;
 
        cout << "目标单词有 " << target.length() 
             << " 个字母，请猜一个字母（有 " << guesses << " 次错误机会）：" << endl;
        cout << "当前进度：" << attempt << endl;
 
        while (guesses > 0 && attempt != target) {
            char letter;
            cout << "请输入字母：";
            cin >> letter;
            if (!isalpha(letter)) {
                cout << "请输入有效字母！" << endl;
                continue;
            }
 
            if (badchars.find(letter) != string::npos || 
                attempt.find(letter) != string::npos) {
                cout << "已猜过该字母，请重新输入！" << endl;
                continue;
            }
 
            int loc = target.find(letter);
            if (loc == string::npos) {
                badchars += letter;
                guesses--;
                cout << "错误！剩余机会：" << guesses << endl;
            } else {
                // 找到所有匹配字母
                while (loc != string::npos) {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }
 
            cout << "当前进度：" << attempt << endl;
            if (attempt != target) {
                cout << "错误字母：" << badchars << endl;
                cout << "剩余错误机会：" << guesses << endl;
            }
        }
 
        if (guesses > 0) {
            cout << "恭喜！你猜对了：" << target << endl;
        } else {
            cout << "游戏结束！正确答案是：" << target << endl;
        }
 
        cout << "是否再玩一次？<y/n> ";
        cin >> play;
        play = tolower(play);
    }
 
    cout << "游戏结束，再见！" << endl;
    }
}

void capacity_ma()
{
    string str = "Initial string";
    // 显示当前容量和长度
    cout << "字符串初始容量: " << str.capacity() << endl;
    cout << "初始大小: " << str.size() << endl;
    // 预留至少100个字符的内存
    str.reserve(100);
    cout << "扩大容量后：" << str.capacity() << endl;
    // 添加数据直到容量扩展
    for (int i = 0; i < 50; i++) {
        str += "a";  // 添加字符
    }
    cout << "在添加了50个字母后: " << str.capacity() << endl;
    // 收缩内存（C++11起支持shrink_to_fit）
    string(str).swap(str);  // 创建临时对象以释放多余内存
    cout << "使用交换函数后，容量缩减为：" << str.capacity() << endl;
}