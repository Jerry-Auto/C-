// use_acctabc.cpp -- test the AcctABC abstract base class
#include <iostream>
#include "acctABC.h"
const int CLIENTS = 4;

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    // 1. 创建抽象基类指针数组（多态）
    AcctABC * p_clients[CLIENTS];
    string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++) {
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> tempnum;
        cout << "Enter opening balance: $";
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or 2 for BrassPlus Account: ";
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout << "Enter either 1 or 2: ";
        
        if (kind == '1') {
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        } else {
            double tmax, trate;
            cout << "Enter the overdraft limit: $";
            cin >> tmax;
            cout << "Enter the interest rate as a decimal fraction: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        }
        while (cin.get() != '\n') continue;  // 清除输入缓冲区
    }

    // 2. 演示多态行为
    cout << "\n==== Account Details ====\n";
    for (int i = 0; i < CLIENTS; i++) {
        p_clients[i]->ViewAcct();  // 根据对象类型调用不同方法
        cout << endl;
    }

    // 3. 清理内存（虚析构函数确保正确释放）
    for (int i = 0; i < CLIENTS; i++) {
        delete p_clients[i];
    }

    return 0;
}