// stacktp.h -- 栈模板类（泛型实现）
#ifndef STACKTP_H_
#define STACKTP_H_

template <typename T>  // 模板声明，T为类型参数
class Stack
{
private:
    enum { MAX = 10 };    // 栈的默认容量（枚举常量）
    int stacksize;
    T *items;         // 存储栈元素的数组（泛型类型）
    int top;              // 栈顶指针

public:
    explicit Stack(int ss=MAX);  // 默认构造函数
    Stack(const Stack& st);
    ~Stack();
    bool isempty() const; // 判断栈是否为空
    bool isfull() const;  // 判断栈是否已满
    bool push(const T& item); // 压栈（传引用避免拷贝）
    bool pop(T& item);       // 弹栈（引用方式返回元素）
    Stack& operator=(const Stack& st);
};

// 模板类的成员函数实现（必须与声明在同一个文件）
template <typename T>
Stack<T>::Stack(int ss) : top(0),stacksize(ss) {
    items=new T [stacksize];
}  // 初始化栈顶指针

template <typename T>
Stack<T>::Stack(const Stack&st): stacksize(st.stacksize),top(st.top){
    items=new T[stacksize];
    for(int i=0;i<top;i++)
    {
        items[i]=st.items[i];
    }
}

template <typename T>
Stack<T>::~Stack(){
    delete[] items;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& st){
    if(this==&st){
        return *this;
    }
    delete[] items;
    stacksize=st.stacksize;
    top=st.top;
    items=new T[stacksize];
    for(int i=0;i<top;i++){
        items[i]=st.items[i];
    }
    return *this;
}

template <typename T>
bool Stack<T>::isempty() const {
    return top == 0;
}

template <typename T>
bool Stack<T>::isfull() const {
    return top == MAX;
}

template <typename T>
bool Stack<T>::push(const T& item) {
    if (top < MAX) {
        items[top++] = item;  // 先赋值再递增栈顶
        return true;
    }
    return false;
}

template <typename T>
bool Stack<T>::pop(T& item) {
    if (top > 0) {
        item = items[--top];  // 先递减栈顶再赋值
        return true;
    }
    return false;
}

#endif // STACKTP_H_