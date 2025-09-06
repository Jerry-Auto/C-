#pragma once
#include <iostream>
using std::ostream;
class Customer {
private:
    long arrive;     // 进入队列时间
    int processtime; // 交易所需时间
public:
    Customer() : arrive(0), processtime(0) {}
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
    friend ostream& operator<<(ostream& os,const Customer&);
};
