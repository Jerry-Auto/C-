// brass.cpp -- bank account class methods
#include <iostream>
#include "bra_account.h"

using std::cout;
using std::endl;
using std::string;

// Brass Methods
Brass::Brass(const string & s, long an, double bal) {
    fullName = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt) {
    if (amt < 0)
        cout << "Negative deposit not allowed; deposit is cancelled.\n";
    else
        balance += amt;
}

void Brass::Withdraw(double amt) {
    if (amt < 0)
        cout << "Withdrawal amount must be positive; withdrawal canceled.\n";
    else if (amt <= balance)
        balance -= amt;
    else
        cout << "Withdrawal amount of $" << amt
             << " exceeds your balance.\n"
             << "Withdrawal canceled.\n";
}

double Brass::Balance() const {
    return balance;
}

void Brass::ViewAcct() const {
    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;
}

// BrassPlus Methods
BrassPlus::BrassPlus(const string & s, long an, double bal,
                     double ml, double r) : Brass(s, an, bal) {
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : Brass(ba) {
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

void BrassPlus::ViewAcct() const {

    Brass::ViewAcct();  // 调用基类方法显示基本信息

    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout << "Loan Rate: " << 100 * rate << "%\n";
}

void BrassPlus::Withdraw(double amt) {
    double bal = Balance();  // 获取当前余额
    if (amt <= bal)

        Brass::Withdraw(amt);  // 如果余额足够，直接取款

    else if (amt <= bal + maxLoan - owesBank) {
        double advance = amt - bal;  // 计算透支金额
        owesBank += advance * (1.0 + rate);  // 计算透支利息
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);          // 存入透支金额

        Brass::Withdraw(amt);      // 然后取款

    } else {
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    }
}