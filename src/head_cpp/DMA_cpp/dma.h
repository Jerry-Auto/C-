// dma.h -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

// Base Class: BaseDMA (使用动态内存分配)
class BaseDMA {
private:
    char * label;  // 动态分配的字符串
    int rating;
public:
    BaseDMA(const char * l = "null", int r = 0);
    BaseDMA(const BaseDMA & rs);            // 拷贝构造函数

    virtual ~BaseDMA();                     // 虚析构函数
    
    BaseDMA & operator=(const BaseDMA & rs); // 赋值运算符
    friend std::ostream & operator<<(std::ostream & os, const BaseDMA & rs);
};

// Derived Class 1: LacksDMA (无动态内存分配)
class LacksDMA : public BaseDMA {
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];  // 固定大小数组（无动态分配）
public:
    LacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
    LacksDMA(const char * c, const BaseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const LacksDMA & rs);
};

// Derived Class 2: HasDMA (使用动态内存分配)
class HasDMA : public BaseDMA {
private:
    char * style;  // 动态分配的字符串
public:
    HasDMA(const char * s = "none", const char * l = "null", int r = 0);
    HasDMA(const char * s, const BaseDMA & rs);
    HasDMA(const HasDMA & hs);            // 拷贝构造函数
    ~HasDMA();                            // 析构函数
    HasDMA & operator=(const HasDMA & rs); // 赋值运算符
    friend std::ostream & operator<<(std::ostream & os, const HasDMA & rs);
};

#endif