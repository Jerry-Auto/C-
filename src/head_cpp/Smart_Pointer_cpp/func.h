#pragma once
#include <iostream>
#include <memory>
#include <vector>

void smartptrs();


class Report {
private:
    std::string str;
public:
    Report(const std::string s) : str(s) {
        std::cout << "对象创建: " << str << std::endl;
    }
    ~Report() {
        std::cout << "对象销毁: " << str << std::endl;
    }
    void comment() const {
        std::cout << "这是：" << str << std::endl;
    }
};
