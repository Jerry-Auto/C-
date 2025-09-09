// dma.cpp -- implementation of DMA classes
#include <cstring>
#include "dma.h"

// BaseDMA Methods
BaseDMA::BaseDMA(const char * l, int r) {
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

BaseDMA::BaseDMA(const BaseDMA & rs) {
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

BaseDMA::~BaseDMA() {
    delete [] label;  // 释放动态内存
}

BaseDMA & BaseDMA::operator=(const BaseDMA & rs) {
    if (this == &rs)
        return *this;
    delete [] label;  // 释放原有内存
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

std::ostream & operator<<(std::ostream & os, const BaseDMA & rs) {
    os << "Label: " << rs.label << ", Rating: " << rs.rating;
    return os;
}

// LacksDMA Methods (无动态内存分配，无需额外处理)
LacksDMA::LacksDMA(const char * c, const char * l, int r) : BaseDMA(l, r) {
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

LacksDMA::LacksDMA(const char * c, const BaseDMA & rs) : BaseDMA(rs) {
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const LacksDMA & ls) {

    os << (const BaseDMA &)ls;  // 调用基类友元函数
    
    os << ", Color: " << ls.color;
    return os;
}

// HasDMA Methods (需要处理动态内存)
HasDMA::HasDMA(const char * s, const char * l, int r) : BaseDMA(l, r) {
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

HasDMA::HasDMA(const char * s, const BaseDMA & rs) : BaseDMA(rs) {
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

HasDMA::HasDMA(const HasDMA & hs) : BaseDMA(hs) {  // 调用基类拷贝构造函数
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

HasDMA::~HasDMA() {
    delete [] style;  // 释放派生类动态内存
}

HasDMA & HasDMA::operator=(const HasDMA & hs) {
    if (this == &hs)
        return *this;
    BaseDMA::operator=(hs);  // 调用基类赋值运算符
    delete [] style;         // 释放原有内存
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

std::ostream & operator<<(std::ostream & os, const HasDMA & hs) {
    os << (const BaseDMA &)hs;  // 调用基类友元函数
    os << ", Style: " << hs.style;
    return os;
}