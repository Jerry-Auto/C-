// acctabc.cpp -- abstract base class implementation
#include <iostream>
#include "acctABC.h"

using std::cout;
using std::endl;
using std::string;
using std::ios_base;

// AcctABC Methods
AcctABC::AcctABC(const string & s, long an, double bal) {
    fullName = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt) {
    if (amt < 0)
        cout << "Negative deposit not allowed; deposit is cancelled.\n";
    else
        balance += amt;
}

// 设置输出格式（保留两位小数）
AcctABC::Formatting AcctABC::SetFormat() const {
    Formatting f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

// 恢复输出格式
void AcctABC::Restore(Formatting & f) const {
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}

// Brass Methods
void Brass::Withdraw(double amt) {
    if (amt < 0)
        cout << "Withdrawal amount must be positive; withdrawal canceled.\n";
    else if (amt <= Balance())
        AcctABC::Deposit(-amt);  // 通过存款实现取款（简化逻辑）
    else
        cout << "Withdrawal amount exceeds your balance.\n";
}

void Brass::ViewAcct() const {
    Formatting f = SetFormat();
    cout << "Brass Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    Restore(f);
}

// BrassPlus Methods
BrassPlus::BrassPlus(const string & s, long an, double bal,
                     double ml, double r) : AcctABC(s, an, bal) {
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r)
                    : AcctABC(ba) {  // 使用基类拷贝构造函数
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

void BrassPlus::Withdraw(double amt) {
    Formatting f = SetFormat();
    double bal = Balance();

    if (amt <= bal) {
        AcctABC::Deposit(-amt);
    } else if (amt <= bal + maxLoan - owesBank) {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Deposit(-amt);
    } else {
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    }
    Restore(f);
}

void BrassPlus::ViewAcct() const {
    Formatting f = SetFormat();
    cout << "BrassPlus Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout << "Loan Rate: " << 100 * rate << "%\n";
    Restore(f);
}