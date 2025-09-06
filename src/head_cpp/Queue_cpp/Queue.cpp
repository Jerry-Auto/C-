#include "Queue.h"
#include <iostream>

// Node结构体的构造函数
template <typename T>
Queue<T>::Node::Node(const T& data) : data(data), next(nullptr) {}

// 队列构造函数
template <typename T>
Queue<T>::Queue(int qs) : frontPtr(nullptr), rearPtr(nullptr),qsize(qs),items(0){}

// 析构函数
template <typename T>
Queue<T>::~Queue() {
    T temp;
    while (!isEmpty()) {
        dequeue(temp);
    }
}

// 拷贝构造函数
template <typename T>
Queue<T>::Queue(const Queue& other) : frontPtr(nullptr), rearPtr(nullptr), qsize(other.getmaxSize()),items(0) {
    Node* current = other.frontPtr;
    while (current != nullptr) {
        enqueue(current->data);
        current = current->next;
    }
}

// 赋值运算符
template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
    if(qsize!=other.getmaxSize())
        throw std::runtime_error("最大允许元素数量不相等，不能赋值");
    if (this != &other) {
        // 清空当前队列
        T temp;
        while (!isEmpty()) {
            dequeue(temp);
        }
        
        // 复制元素
        Node* current = other.frontPtr;
        while (current != nullptr) {
            enqueue(current->data);
            current = current->next;
        }
    }
    return *this;
}

// 入队操作
template <typename T>
void Queue<T>::enqueue(const T& item) {
    if(isfull())
        throw std::runtime_error("满了，不能添加");
    Node* newNode = new Node(item);
    
    if (isEmpty()) {
        frontPtr = rearPtr = newNode;
    } else {
        rearPtr->next = newNode;
        rearPtr = newNode;
    }
    items++;
}

// 出队操作
template <typename T>
void Queue<T>::dequeue(T&item) {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty. Cannot dequeue.");
    }
    
    item=frontPtr->data;
    Node* temp = frontPtr;
    frontPtr = frontPtr->next;
    if (frontPtr == nullptr) {
        rearPtr = nullptr;
    }
    
    delete temp;
    items--;
}

// 获取队首元素
template <typename T>
T& Queue<T>::front() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty. No front element.");
    }
    return frontPtr->data;
}

// 获取队首元素（const版本）
template <typename T>
const T& Queue<T>::front() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty. No front element.");
    }
    return frontPtr->data;
}

// 检查队列是否为空
template <typename T>
bool Queue<T>::isEmpty() const {
    return frontPtr == nullptr;
}
// 检查队列是否为满
template <typename T>
bool Queue<T>::isfull() const {
    return qsize==items;
}

// 获取队列最大容量
template <typename T>
int Queue<T>::getmaxSize() const {
    return qsize;
}

// 获取队列大小
template <typename T>
int Queue<T>::queuecount() const {
    return items;
}

// 打印队列内容（用于调试）
template <typename T>
void Queue<T>::print() const {
    Node* current = frontPtr;
    std::cout << "Queue: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}