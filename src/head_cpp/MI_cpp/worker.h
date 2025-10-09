// worker.h -- 使用多重继承的工作类
#ifndef WORKER_H_
#define WORKER_H_

#include <string>

// Worker类 - 抽象基类，包含纯虚函数的类称为抽象类，无法实例化（只能作为基类使用）
class Worker   
{
private:
    std::string fullname;  // 员工全名
    long id;               // 员工ID
protected:
    virtual void Data() const;  // 显示数据（保护成员函数）
    virtual void Get();         // 获取数据（保护成员函数）
public:
    Worker() : fullname("no one"), id(0L) {}  // 默认构造函数
    Worker(const std::string & s, long n)     // 带参构造函数
            : fullname(s), id(n) {}
    virtual ~Worker() = 0; // 纯虚析构函数，使Worker成为抽象类
    virtual void Set() = 0;     // 纯虚函数，基类中不用实现，设置信息
    virtual void Show() const = 0; // 纯虚函数，显示信息
};

// Waiter类 - 服务员，虚继承自Worker
// 加上virtual关键字即当前类将基类看作虚基类
class Waiter : virtual public Worker  
{
private:
    int panache;  // 服务员风度评级
protected://覆盖基类的函数
    void Data() const override;  // 显示Waiter特有数据
    void Get() override;         // 获取Waiter特有数据
public:
    Waiter() : Worker(), panache(0) {}  // 默认构造函数
    Waiter(const std::string & s, long n, int p = 0)  // 带参构造函数
            : Worker(s, n), panache(p) {}
    explicit Waiter(const Worker & wk, int p = 0)  // 从Worker转换构造函数
            : Worker(wk), panache(p) {}
    void Set() override;      // 实现Worker的纯虚函数
    void Show() const override; // 实现Worker的纯虚函数
};

// Singer类 - 歌手，虚继承自Worker
class Singer : virtual public Worker  
{
protected:
    // 声音类型匿名枚举
    enum {other, alto, contralto, soprano, bass, baritone, tendor};
    enum {Vtypes = 7};  // 声音类型数量
    void Data() const override;  // 显示Singer特有数据
    void Get() override;         // 获取Singer特有数据
private:
    static const char *pv[Vtypes];  // 声音类型的字符串表示
    int voice;          // 当前声音类型
public:
    Singer() : Worker(), voice(other) {}  // 默认构造函数
    Singer(const std::string & s, long n, int v = other)  // 带参构造函数
            : Worker(s, n), voice(v) {}
    explicit Singer(const Worker & wk, int v = other)  // 从Worker转换构造函数
            : Worker(wk), voice(v) {}
    void Set() override;      // 实现Worker的纯虚函数
    void Show() const override; // 实现Worker的纯虚函数
};

// SingingWaiter类 - 会唱歌的服务员，多重继承自Singer和Waiter
class SingingWaiter : public Singer, public Waiter  
{
protected:
    void Data() const override;  // 显示SingingWaiter特有数据
    void Get() override;         // 获取SingingWaiter特有数据
public:
    SingingWaiter() {}  // 默认构造函数
    // 带参构造函数
    SingingWaiter(const std::string & s, long n, int p = 0, int v = other)
            : Worker(s,n), Waiter(s, n, p), Singer(s, n, v) {}
    // 从Worker转换构造函数
    explicit SingingWaiter(const Worker & wk, int p = 0, int v = other)
            : Worker(wk), Waiter(wk, p), Singer(wk, v) {}
    // 从Waiter转换构造函数
    explicit SingingWaiter(const Waiter & wt, int v = other)
            : Worker(wt), Waiter(wt), Singer(wt, v) {}
    // 从Singer转换构造函数
    explicit SingingWaiter(const Singer & wt, int p = 0)
            : Worker(wt), Waiter(wt, p), Singer(wt) {}
    void Set() override;      // 实现Worker的纯虚函数
    void Show() const override; // 实现Worker的纯虚函数
};

#endif // WORKER_H_