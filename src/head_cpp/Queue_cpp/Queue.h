#pragma once

#include <stdexcept>
#include "Agent.h"

template <typename T>
class Queue {
private:
    enum {Q_size=10};
    struct Node {
        T data;
        Node* next;
        Node(const T& data);
    };
    
    Node* frontPtr;  // 指向队列前端的指针
    Node* rearPtr;   // 指向队列后端的指针
    const int qsize;     // 队列最大元素数量
    int items;

public:
    // 构造函数和析构函数
    Queue(int qs=Q_size);
    ~Queue();
    
    // 拷贝构造函数和赋值运算符
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);
    
    // 队列操作
    bool isEmpty() const;
    bool isfull() const;
    int queuecount()const;

    void enqueue(const T& item);
    void dequeue(T&item);

    T& front();
    const T& front() const;
    int getmaxSize() const;
    
    // 调试用
    void print() const;
};
//模板类最好在头文件里写实现，分文件编写限制多
template class Queue<int>;    // 显式实例化
template class Queue<double>; // 常用类型
template class Queue<Customer>;


