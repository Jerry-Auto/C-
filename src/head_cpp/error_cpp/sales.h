#ifndef SALES_H_
#define SALES_H_

#include <stdexcept>
#include <string>

// 销售数据异常基类，继承自标准逻辑异常
class Sales
{
public:
    // 枚举类型，定义错误代码
    enum {MONTHS = 12};   // 一年的月份数

    // 构造函数：年份、月份数组
    explicit Sales(int yy = 0);
    Sales(int yy, const double * gr, int n);
    virtual ~Sales() { }  // 虚析构函数，为继承体系做准备

    // 获取年份
    int Year() const { return year; }

    // 虚函数：获取销售数据
    virtual double operator[](int i) const;
    virtual double & operator[](int i);

    // 异常类：销售数据错误
    class bad_index : public std::logic_error
    {
    private:
        int bi;  // 错误的索引值
    public:
        // 显式构造函数：索引值、错误信息
        explicit bad_index(int ix, const std::string & s = "Index error in Sales object\n");
        
        // 获取错误的索引值
        int bi_val() const { return bi; }
        
        // 虚析构函数，throw()异常规范，表示该析构函数不会抛出任何异常，可用noexcept代替
        virtual ~bad_index() throw() { }
    };

private:
    double gross[MONTHS];  // 每月销售额数组
    int year;              // 年份
};

// 带标签的销售数据类，继承自Sales类
class LabeledSales : public Sales
{
public:
    // 嵌套类：带标签的销售数据异常
    class nbad_index : public Sales::bad_index
    {
    private:
        std::string lbl;  // 标签名称
    public:
        // 构造函数：标签名、索引值、错误信息
        nbad_index(const std::string & lb, int ix,
                   const std::string & s = "Index error in LabeledSales object\n");
        
        // 获取标签名
        const std::string & label_val() const { return lbl; }
        
        // 虚析构函数
        virtual ~nbad_index() throw() { }
    };

    // 构造函数：标签、年份
    explicit LabeledSales(const std::string & lb = "none", int yy = 0);
    
    // 构造函数：标签、年份、销售数据数组、数据个数
    LabeledSales(const std::string & lb, int yy, const double * gr, int n);
    
    // 虚析构函数
    virtual ~LabeledSales() { }

    // 获取标签名
    const std::string & Label() const { return label; }

    // 重写基类的下标操作符函数
    virtual double operator[](int i) const;
    virtual double & operator[](int i);

private:
    std::string label;  // 销售数据标签
};

#endif