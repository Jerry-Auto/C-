#include "iterator.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include<string>
#include <list>
// 数组查找函数实现
iterator find_ar(iterator begin, iterator end, const double& val) {
    iterator ar;
    for (ar = begin; ar != end; ar++) {
        if (*ar == val) {
            return ar;
        }
    }
    return end;
}

// Iterator类成员函数实现
Iterator::Iterator() : pt(nullptr) {}
Iterator::Iterator(Node* pn) : pt(pn) {}

double Iterator::operator*() {
    return pt->item;
}

Iterator& Iterator::operator++() {
    if (pt != nullptr) {
        pt = pt->p_next;
    }
    return *this;
}

Iterator Iterator::operator++(int) {
    Iterator tmp = *this;
    if (pt != nullptr) {
        pt = pt->p_next;
    }
    return tmp;
}

bool Iterator::operator!=(const Iterator& other) const {
    return pt != other.pt;
}

bool Iterator::operator==(const Iterator& other) const {
    return pt == other.pt;
}

// 链表查找函数实现
Iterator find_ll(Iterator head, Iterator end, const double& val) {
    Iterator start;
    for (start = head; start != end; ++start) {
        if (*start == val) {
            return start;
        }
    }
    return end;
}


void copyit(){
    using namespace std;
    
    int casts[10] = {6, 7, 2, 9, 4, 11, 8, 7, 10, 5};
    vector<int> dice(10);
    
    // 1. 使用copy算法将数组内容复制到vector中
    copy(casts, casts + 10, dice.begin());
    
    cout << "使用copy算法将数组内容复制到vector中\n";
    
    // 2. 创建ostream_iterator用于输出（输出迭代器模型）
    ostream_iterator<int, char> out_iter(cout, " ");
    
    // 3. 使用copy算法和ostream_iterator显示vector内容
    cout << "使用copy算法和ostream_iterator显示vector内容: ";
    copy(dice.begin(), dice.end(), out_iter);
    cout << endl;
    
    // 4. 隐式使用反向迭代器（反向复制到输出）
    cout << "隐式使用反向迭代器（反向复制到输出）:\n";
    copy(dice.rbegin(), dice.rend(), out_iter);
    cout << endl;
    
    // 5. 显式使用反向迭代器
    cout << "显式使用反向迭代器:\n";
    vector<int>::reverse_iterator ri;  // 反向迭代器
    for (ri = dice.rbegin(); ri != dice.rend(); ++ri) {
        cout << *ri << ' ';
    }
    cout << endl;

    cout << "演示输入流迭代器，捕获输入放到容器里，请输入数字,输入符号(,)结束输入：\n";
    copy(istream_iterator<int,char>(cin),
        istream_iterator<int,char>(),dice.begin());
    cout << "覆盖后：\n";
    for(auto x:dice){
        cout<<x<<" "<<endl;
    };
}

void itera(){
// 演示数组查找
    std::cout << "=== 数组查找演示 ===" << std::endl;
    double arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target_arr = 3.3;
    
    iterator result_arr = find_ar(arr, arr + 5, target_arr);
    if (result_arr != arr + 5) {
        std::cout << "在数组中找到元素 " << target_arr << "，位置索引约为: " << (result_arr - arr) << std::endl;
    } else {
        std::cout << "在数组中未找到元素 " << target_arr << std::endl;
    }

    // 演示链表查找
    std::cout << "\n=== 链表查找演示 ===" << std::endl;
    // 创建链表: 1.1 -> 2.2 -> 3.3 -> 4.4 -> 5.5
    Node node5 = {5.5, nullptr};
    Node node4 = {4.4, &node5};
    Node node3 = {3.3, &node4};
    Node node2 = {2.2, &node3};
    Node node1 = {1.1, &node2};

    double target_ll = 4.4;
    Iterator head(&node1);
    Iterator end(nullptr);

    Iterator result_ll = find_ll(head, end, target_ll);
    if (result_ll != end) {
        std::cout << "在链表中找到元素 " << target_ll << std::endl;
    } else {
        std::cout << "在链表中未找到元素 " << target_ll << std::endl;
    }

    // 尝试查找不存在的元素
    double target_not_found = 6.6;
    Iterator result_nf = find_ll(head, end, target_not_found);
    if (result_nf == end) {
        std::cout << "在链表中正确返回未找到元素 " << target_not_found << std::endl;
    }

}

void output(const std::string& s) { std::cout << s << "  "; }

void inserts(){
    using namespace std;
    string s1[4] = { "fine", "fish", "fashion", "fate" };
    string s2[2] = { "busy", "bats" };
    string s3[2] = { "silly", "singers" };
    vector<string> words(4);

    // 1. 常规拷贝（覆盖方式）
    cout << "常规拷贝（覆盖方式）：\n";
    copy(s1, s1 + 4, words.begin());
    for_each(words.begin(), words.end(), output);
    cout << endl;

    // 2. 使用 back_insert_iterator 在尾部插入
    cout << "使用 back_insert_iterator 在尾部插入:\n";
    copy(s2, s2 + 2, back_insert_iterator<vector<string>>(words));
    for_each(words.begin(), words.end(), output);
    cout << endl;

    // 3. 使用 insert_iterator 在指定位置插入
    cout << "使用 insert_iterator 在指定位置插入：\n";
    copy(s3, s3 + 2, insert_iterator<vector<string>>(words, words.begin()));
    for_each(words.begin(), words.end(), output);
    cout << endl;


}