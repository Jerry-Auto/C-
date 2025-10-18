#include "func.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool FillReview(Review &rr) {
    cout << "请输入书名（输入quit退出）：";
    getline(cin, rr.title);
    if (rr.title == "quit")
        return false;
    cout << "请输入评分（0-10）：";
    cin >> rr.rating;
    if (!cin) return false;
    
    cout << "请输入价格：";
    cin >> rr.price;
    if (!cin) return false;
    
    // 清理输入缓冲区
    while (cin.get() != '\n') continue;
    return true;
}

void ShowReview(const Review &rr) {
    cout << rr.rating << "\t" << rr.price << "\t" << rr.title << endl;
}


void vect2(){
    vector<Review> books;  // 创建存储书籍信息的向量
    Review temp;
    
    // 循环输入书籍信息
    while (FillReview(temp))
        books.push_back(temp);  // 将元素添加到向量末尾
    
    int num = books.size();
    if (num > 0) {
        cout << "谢谢！您输入了以下内容：\n"
             << "评分\t价格\t书籍名称\n";
        for (int i = 0; i < num; i++)
            ShowReview(books[i]);
        
        cout << "重新显示：\n" << "评分\t价格\t书籍名称\n";
        // 使用迭代器遍历
        vector<Review>::iterator pr;  // 迭代器是一个广义指针
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);  // 对迭代器解除引用以访问元素
        
        // 使用拷贝构造函数创建副本
        vector<Review> oldlist(books);
        
        if (num > 3) {
            // 删除第2到第4个元素（注意区间是左闭右开）
            // erase()方法删除向量中给定区间的元素
            // 第一个迭代器指向区间的起始处，第二个迭代器位于区间终止处的后一个位置
            books.erase(books.begin() + 1, books.begin() + 3);  // 删除索引为1和2的元素
            cout << "删除元素后：\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
            
            // 插入元素
            // insert()方法接受3个迭代器参数：
            // 第一个参数指定新元素插入的位置
            // 第二个和第三个迭代器参数定义了被插入区间
            books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
            cout << "插入元素后：\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
        }
        
        // 交换两个容器的内容
        books.swap(oldlist);
        cout << "交换oldlist与books后：\n";
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
    } else {
        cout << "没有输入任何内容。\n";
    }
}


void vect3(){
    vector<Review> books;
    Review temp;
    
    // 填充向量
    while (FillReview(temp))
        books.push_back(temp);
    
    if (books.empty()) {
        cout << "没有输入任何内容，程序结束。\n";
        return ;
    }
    
    cout << "谢谢！您输入了以下内容：\n";
    cout << "评分\t价格\t书籍名称\n";
    for_each(books.begin(), books.end(), ShowReview);
    
    // 使用默认排序（基于operator<）
    sort(books.begin(), books.end());
    cout << "\n按书名排序后：\n";
    cout << "评分\t价格\t书籍名称\n";
    for_each(books.begin(), books.end(), ShowReview);
    
    // 使用评分排序
    sort(books.begin(), books.end(), worseThan);
    cout << "\n按评分排序后：\n";
    cout << "评分\t价格\t书籍名称\n";
    for_each(books.begin(), books.end(), ShowReview);
    
    // 使用价格排序
    sort(books.begin(), books.end(), cheaperThan);
    cout << "\n按价格排序后：\n";
    cout << "评分\t价格\t书籍名称\n";
    for_each(books.begin(), books.end(), ShowReview);
    
    // 随机打乱
    random_shuffle(books.begin(), books.end());
    cout << "\n随机打乱后：\n";
    cout << "评分\t价格\t书籍名称\n";
    for_each(books.begin(), books.end(), ShowReview);
    
    // 演示基于范围的for循环
    cout << "\n演示基于范围的for循环：\n";
    cout << "\n所有rating+1后：\n";
    cout << "评分\t价格\t书籍名称\n";
    for(auto& x:books){
        InflateReview(x);
        ShowReview(x);
    };

    // 演示随机访问
    cout << "\n演示随机访问：\n";
    cout << "第一个元素：";
    ShowReview(books[0]);
    cout << "最后一个元素：";
    ShowReview(books[books.size() - 1]);
}

// 重载小于运算符，按书名排序
bool operator<(const Review &r1, const Review &r2) {
    if (r1.title < r2.title)
        return true;
    else if (r1.title == r2.title && r1.rating < r2.rating)
        return true;
    else
        return false;
}

// 按评分排序（评分低的排在前面）
bool worseThan(const Review &r1, const Review &r2) {
    if (r1.rating < r2.rating)
        return true;
    else
        return false;
}

// 按价格排序（价格低的排在前面）
bool cheaperThan(const Review &r1, const Review &r2) {
    if (r1.price < r2.price)
        return true;
    else
        return false;
}
