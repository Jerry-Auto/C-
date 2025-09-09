// brass.h -- bank account classes
#ifndef BRASS_H_
#define BRASS_H_
#include <string>

// Base Class: Brass Account（普通账户）
class Brass {
private:
    std::string fullName;  // 客户姓名
    long acctNum;          // 账号
    double balance;        // 余额
public:
    Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
    void Deposit(double amt);           // 存款
    virtual void Withdraw(double amt);  // 取款（虚函数，允许派生类重写）
    double Balance() const;             // 查询余额
    virtual void ViewAcct() const;      // 查看账户信息（虚函数）
    virtual ~Brass() {}                 // 虚析构函数
};

// Derived Class: BrassPlus Account（透支账户）
class BrassPlus : public Brass {
private:
    double maxLoan;   // 最大透支额度
    double rate;      // 透支利率
    double owesBank;  // 当前透支金额
public:
    BrassPlus(const std::string & s = "Nullbody", long an = -1,
              double bal = 0.0, double ml = 500, double r = 0.11125);
    BrassPlus(const Brass & ba, double ml = 500, double r = 0.11125);
    virtual void Withdraw(double amt);  // 重写基类的取款方法
    virtual void ViewAcct() const;      // 重写基类的查看账户信息方法
    
    void ResetMax(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; }
    void ResetOwes() { owesBank = 0; }
};

#endif