#pragma once

#include <iostream>

// 1. 用于数组的查找函数声明
typedef double* iterator;
iterator find_ar(iterator begin, iterator end, const double& val);

// 2. 链表节点结构体
struct Node {
    double item;
    Node* p_next;
};

// 3. 为链表设计的迭代器类声明
class Iterator {
private:
    Node* pt;

public:
    Iterator();
    Iterator(Node* pn);
    double operator*();
    Iterator& operator++();
    Iterator operator++(int);
    bool operator!=(const Iterator& other) const;
    bool operator==(const Iterator& other) const;
};

// 4. 链表查找函数声明
Iterator find_ll(Iterator head, Iterator end, const double& val);

void copyit();
void itera();
void inserts();