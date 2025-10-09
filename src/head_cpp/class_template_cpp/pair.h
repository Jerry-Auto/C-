#pragma once

template <typename T1, typename T2>
class Pair {
private:
    T1 a;  // 第一个数据成员
    T2 b;  // 第二个数据成员
public:
    // 默认构造函数
    Pair() = default;
    // 带参构造函数
    Pair(const T1& aval, const T2& bval) : a(aval), b(bval) {}
    // 访问第一个元素（非const版本）
    T1& first() { return a; }
    // 访问第二个元素（非const版本）
    T2& second() { return b; }
    // 访问第一个元素（const版本）
    const T1& first() const { return a; }
    // 访问第二个元素（const版本）
    const T2& second() const { return b; }
    // 交换两个Pair的内容（可选扩展）
    void swap(Pair& other) {
        std::swap(a, other.a);
        std::swap(b, other.b);
    }
    // C++11起支持的移动构造函数（可选）
    Pair(T1&& aval, T2&& bval) : a(std::move(aval)), b(std::move(bval)) {}
};
