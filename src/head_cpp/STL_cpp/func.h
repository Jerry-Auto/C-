#pragma once
#include <string>
struct Review {
    std::string title;  // 书名
    int rating;    // 评分
    double price;  // 价格字段
};
// 函数声明
bool FillReview(Review &rr);
void ShowReview(const Review &rr);
bool operator<(const Review &r1, const Review &r2);
bool worseThan(const Review &r1, const Review &r2);
bool cheaperThan(const Review &r1, const Review &r2);
inline void InflateReview(Review &R){++R.rating;};
//函数定义必须使用內联，当你在头文件中定义函数（非内联）时，每个包含该头文件的源文件都会获得该函数的完整定义。
void vect2();
void vect3();