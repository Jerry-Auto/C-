// Customer.cpp
#include "Agent.h"
#include <cstdlib> // 用于rand()

// 设置顾客到达时间和随机生成处理时间
void Customer::set(long when) {
    processtime = std::rand() % 3 + 1; // 随机处理时间1-3分钟
    arrive = when;                     // 记录到达时间
}

ostream& operator<<(ostream& os,const Customer& cs)
{
    os<<"进入队列时间：\t"<<cs.when()<<std::endl;
    os<<"交易所需时间：\t"<<cs.ptime()<<std::endl;
    return os;
}
