// arraytp.h -- 泛型数组模板类（固定大小）
#ifndef ARRAYTP_H_
#define ARRAYTP_H_

#include <iostream>
#include <cassert>  // 用于边界检查

template <typename T, int n>  // 非类型参数 n 指定数组大小
class ArrayTP {
private:
    T items[n];  // 泛型数组（编译期确定大小）

public:
    // 默认构造函数
    ArrayTP() = default;

    // 显式构造函数（支持初始化列表）
    explicit ArrayTP(const T& val) {
        for (int i = 0; i < n; ++i)
            items[i] = val;
    }

    // 访问元素（带边界检查）
    virtual T& operator[](int i) {
        assert(i >= 0 && i < n);  // 越界检查
        return items[i];
    }
    //只读版本
    virtual const T& operator[](int i) const {
        assert(i >= 0 && i < n);
        return items[i];
    }

    // 获取数组大小
    int size() const { return n; }

    // 迭代器支持（简化版）
    T* begin() { return &items[0]; }
    const T* begin() const { return &items[0]; }
    T* end() { return &items[n]; }
    const T* end() const { return &items[n]; }
};

#endif // ARRAYTP_H_