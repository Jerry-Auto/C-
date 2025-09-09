// acctabc.h -- abstract base class for bank accounts
#ifndef ACCTABC_H_
#define ACCTABC_H_
#include <iostream>
#include <string>

// Abstract Base Class (ABC)
class AcctABC {
private:
    std::string fullName;
    long acctNum;
    double balance;
protected:
    struct Formatting {  // 嵌套结构，用于格式化输出
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string & FullName() const { return fullName; }
    long AcctNum() const { return acctNum; }
    Formatting SetFormat() const;          // 设置输出格式
    void Restore(Formatting & f) const;    // 恢复输出格式
public:
    AcctABC(const std::string & s = "Nullbody", long an = -1,
            double bal = 0.0);
    void Deposit(double amt);             // 存款（非虚函数）

    virtual void Withdraw(double amt) = 0; // 纯虚函数（抽象方法）

    double Balance() const { return balance; }

    virtual void ViewAcct() const = 0;     // 纯虚函数（抽象方法）
    
    virtual ~AcctABC() {}                 // 虚析构函数
};

// Brass Account Class (Concrete)
class Brass : public AcctABC {
public:
    Brass(const std::string & s = "Nullbody", long an = -1,
          double bal = 0.0) : AcctABC(s, an, bal) {}
    virtual void Withdraw(double amt);     // 实现纯虚函数
    virtual void ViewAcct() const;         // 实现纯虚函数
    virtual ~Brass() {}
};

// BrassPlus Account Class (Concrete)
class BrassPlus : public AcctABC {
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const std::string & s = "Nullbody", long an = -1,
              double bal = 0.0, double ml = 500, double r = 0.10);
    BrassPlus(const Brass & ba, double ml = 500, double r = 0.1);
    virtual void Withdraw(double amt);     // 实现纯虚函数
    virtual void ViewAcct() const;         // 实现纯虚函数
    void ResetMax(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; }
    void ResetOwes() { owesBank = 0; }
    virtual ~BrassPlus() {}
};

#endif