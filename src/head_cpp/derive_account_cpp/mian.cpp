// use_brass.cpp -- test the Brass and BrassPlus classes
#include <iostream>
#include "bra_account.h"
using std::cout;
using std::endl;

void func();
void virture();
int main() {

    virture();

    return 0;
}
void func()
{
    // 1. 创建基类对象（普通账户）
    Brass Piggy("Porcelot Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);

    // 2. 调用基类方法
    Piggy.ViewAcct();
    cout << endl;

    // 3. 调用派生类方法
    Hoggy.ViewAcct();
    cout << endl;

    // 4. 测试取款（多态行为）
    cout << "Withdrawing $1000 from Piggy's account:\n";
    Piggy.Withdraw(1000.00);
    cout << "Piggy's balance: $" << Piggy.Balance() << endl;

    cout << "\nWithdrawing $4000 from Hoggy's account:\n";
    Hoggy.Withdraw(4000.00);  // 触发透支逻辑
    cout << "Hoggy's balance: $" << Hoggy.Balance() << endl;
}
void virture()
{
        // 1. 创建基类和派生类对象
    Brass normalAccount("Alice", 123456, 1000.00);
    BrassPlus premiumAccount("Bob", 654321, 2000.00, 1000, 0.1);

    // 2. 演示 Deposit() 方法（基类和派生类行为相同）
    cout << "==== Deposit Test ====\n";
    normalAccount.Deposit(500);
    premiumAccount.Deposit(500);
    cout << "Alice's balance: $" << normalAccount.Balance() << endl;
    cout << "Bob's balance: $" << premiumAccount.Balance() << endl;

    // 3. 演示 Withdraw() 方法（多态行为）
    cout << "\n==== Withdrawal Test ====\n";
    cout << "[Alice (Brass)] Trying to withdraw $1200:\n";
    normalAccount.Withdraw(1200);  // 基类方法：直接拒绝超额取款

    cout << "\n[Bob (BrassPlus)] Trying to withdraw $2500:\n";
    premiumAccount.Withdraw(2500); // 派生类方法：允许透支
    cout << "Bob's balance after withdrawal: $" << premiumAccount.Balance() << endl;

    // 4. 演示 ViewAcct() 方法（多态行为）
    cout << "\n==== View Account Test ====\n";
    Brass * accounts[2];
    accounts[0] = &normalAccount;
    accounts[1] = &premiumAccount;

    for (int i = 0; i < 2; i++) {
        cout << "\nAccount " << i + 1 << ":\n";
        accounts[i]->ViewAcct();  // 根据对象类型调用不同方法
    }
}
