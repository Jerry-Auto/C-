#include "containers.h"
#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <queue>        //queue 和 priority_queue 都在此头文件中
#include <array>
#include <stack>
#include <forward_list>
#include <algorithm>
#include <iterator>
#include <functional>   // 用于 std::greater


void outint(int n) { std::cout << n << " "; }

void list_demo(){
    using namespace std;
    
    list<int> one(5, 2); // 创建包含5个2的list
    int stuff[5] = {1, 2, 4, 8, 6};
    list<int> two;
    
    two.insert(two.begin(), stuff, stuff + 5); // 在two的开头插入数组元素
    cout << "链表一: ";
    for_each(one.begin(), one.end(), outint);
    cout << endl;
    
    cout << "链表二: ";
    for_each(two.begin(), two.end(), outint);
    cout << endl;
    
    list<int> three(two); // 用two初始化three
    int more[6] = {6, 4, 2, 4, 6, 5};
    three.insert(three.end(), more, more + 6);
    cout << "链表三insert插入more后: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;
    cout << "此时more还在: ";
    for_each(more,more+6,outint);
    cout << endl;
    
    three.remove(2); // 删除所有值为2的元素
    cout << "链表三删除所有2后: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;
    
    three.splice(three.begin(), one); // 将链表one的内容拼接到three的开头
    cout << "拼接链表一后的链表三: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;
    cout << "拼接后的链表一: ";
    for_each(one.begin(), one.end(), outint); // 此时one应为空
    cout << "(空)" << endl;
    
    three.unique(); // 删除连续重复的元素
    cout << "链表三去重后: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;
    
    three.sort(); // 排序
    cout << "链表三排序后: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;
    
    three.unique(); // 再次去重（针对排序后的连续重复项）
    cout << "链表三排序后再去重: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;
    
    two.sort();
    cout << "排序后的链表二: ";
    for_each(two.begin(), two.end(), outint);
    cout << endl;
    
    three.merge(two); // 合并两个已排序链表
    cout << "合并链表二后的链表三: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;
    cout << "合并后的链表二: ";
    for_each(two.begin(), two.end(), outint); // 合并后two应为空
    cout << "(空)" << endl;
}

void vec_deque_fl(){
    using namespace std;
    cout << "=== 序列容器演示程序 ===" << endl;
    
    // 1. vector 容器演示（动态数组）
    cout << "\n*** Vector容器演示 ***" << endl;
    vector<int> vec_coll;
    
    // 尾部添加元素
    for (int i = 1; i <= 6; ++i) {
        vec_coll.push_back(i);
    }
    cout << "Vector元素: ";
    for_each(vec_coll.begin(), vec_coll.end(), outint);
    cout << endl;
    
    // 随机访问和修改
    vec_coll[2] = 99;
    cout << "修改第三个元素后: ";
    for_each(vec_coll.begin(), vec_coll.end(), outint);
    cout << endl;
    
    // 中间插入
    vec_coll.insert(vec_coll.begin() + 2, 55);
    cout << "中间插入后: ";
    for_each(vec_coll.begin(), vec_coll.end(), outint);
    cout << endl;
    
    // 2. deque 容器演示（双端队列）
    cout << "\n*** Deque容器演示 ***" << endl;
    deque<float> deque_coll;
    
    // 前端插入
    for (int i = 1; i <= 3; ++i) {
        deque_coll.push_front(i * 1.1);
    }
    cout << "前端插入后: ";
    for (auto elem : deque_coll) {
        cout << elem << " ";
    }
    cout << endl;
    
    // 后端插入
    for (int i = 4; i <= 6; ++i) {
        deque_coll.push_back(i * 1.1);
    }
    cout << "后端插入后: ";
    for (auto elem : deque_coll) {
        cout << elem << " ";
    }
    cout << endl;
    
    // 3. forward_list 容器演示（单向链表）
    cout << "\n*** Forward_list容器演示 ***" << endl;
    forward_list<int> flist_coll;
    
    // 只能前端插入（单链表特性）
    flist_coll.push_front(3);
    flist_coll.push_front(2);
    flist_coll.push_front(1);
    cout << "前端插入后: ";
    for (auto elem : flist_coll) {
        cout << elem << " ";
    }
    cout << endl;
    
    // 在指定位置后插入
    auto it = flist_coll.begin();
    advance(it, 1); // 移动到第二个位置
    flist_coll.insert_after(it, 99);
    cout << "在第二个位置后插入99: ";
    for (auto elem : flist_coll) {
        cout << elem << " ";
    }
    cout << endl;
    

}

void arr_que_stk_pq(){
    using namespace std;
    // 4. array 容器演示（固定大小数组）
    cout << "\n*** Array容器演示 ***" << endl;
    array<string, 5> array_coll = {"hello", "world"}; // 部分初始化
    
    cout << "Array元素: ";
    for (int i = 0; i < array_coll.size(); ++i) {
        cout << i << ":" << array_coll[i] << " ";
    }
    cout << endl;
    
    // 修改元素
    array_coll[2] = "C++";
    array_coll[3] = "STL";
    cout << "修改后: ";
    for (const auto& elem : array_coll) {
        cout << elem << " ";
    }
    cout << endl;


    cout << "===== stack (栈) - LIFO 演示 =====" << endl;
    stack<int> s;
    
    // 入栈
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "栈顶元素: " << s.top() << endl; // 输出 30
    cout << "栈大小: " << s.size() << endl;
    
    // 出栈（后进先出）
    cout << "出栈顺序: ";
    while (!s.empty()) {
        cout << s.top() << " "; // 依次输出 30, 20, 10
        s.pop();
    }
    cout << endl << endl;

    cout << "===== queue (队列) - FIFO 演示 =====" << endl;
    queue<int> q;
    
    // 入队
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "队头元素: " << q.front() << endl; // 输出 10
    cout << "队尾元素: " << q.back() << endl;  // 输出 30
    
    // 出队（先进先出）
    cout << "出队顺序: ";
    while (!q.empty()) {
        cout << q.front() << " "; // 依次输出 10, 20, 30
        q.pop();
    }
    cout << endl << endl;

    cout << "===== priority_queue (优先队列) 演示 =====" << endl;
    
    // 默认大顶堆（优先级：值越大越高）
    cout << "默认大顶堆 (降序出队): ";
    priority_queue<int> pq_max;
    pq_max.push(30);
    pq_max.push(10);
    pq_max.push(50);
    pq_max.push(20);
    while (!pq_max.empty()) {
        cout << pq_max.top() << " "; // 输出 50, 30, 20, 10
        pq_max.pop();
    }
    cout << endl;

    // 小顶堆（优先级：值越小越高）
    cout << "小顶堆 (升序出队): ";
    priority_queue<int, vector<int>, greater<int>> pq_min;
    pq_min.push(30);
    pq_min.push(10);
    pq_min.push(50);
    pq_min.push(20);
    while (!pq_min.empty()) {
        cout << pq_min.top() << " "; // 输出 10, 20, 30, 50
        pq_min.pop();
    }
    cout << endl;
}