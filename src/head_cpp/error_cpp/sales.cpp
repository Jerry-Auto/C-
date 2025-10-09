#include "sales.h"
using std::string;

// Sales 类的成员函数实现

/**
 * @brief Sales类的默认构造函数
 * @param yy 年份，默认为0
 * @note 初始化年份并将所有月份的销售额设为0
 */
Sales::Sales(int yy)
{
    year = yy;
    for (int i = 0; i < MONTHS; ++i)
        gross[i] = 0;
}

/**
 * @brief Sales类的带参数构造函数
 * @param yy 年份
 * @param gr 销售额数组指针
 * @param n 数组元素个数
 * @note 从传入数组复制数据，如果n小于MONTHS，剩余月份设为0
 *       如果n大于MONTHS，只复制前MONTHS个月的数据
 */
Sales::Sales(int yy, const double * gr, int n)
{
    year = yy;
    int lim = (n < MONTHS) ? n : MONTHS;
    int i;
    
    // 复制传入的销售额数据
    for (i = 0; i < lim; ++i)
        gross[i] = gr[i];
    
    // 如果数据不足12个月，剩余月份补0
    for ( ; i < MONTHS; ++i)
        gross[i] = 0;
}

/**
 * @brief 重载下标操作符（const版本）
 * @param i 月份索引（0-11）
 * @return 对应月份的销售额
 * @throw bad_index 当索引超出范围时抛出异常
 * @note 提供对销售额数据的只读访问
 */
double Sales::operator[](int i) const
{
    if (i < 0 || i >= MONTHS)
        throw bad_index(i);  // 索引越界，抛出异常
    return gross[i];
}

/**
 * @brief 重载下标操作符（非const版本）
 * @param i 月份索引（0-11）
 * @return 对应月份销售额的引用
 * @throw bad_index 当索引超出范围时抛出异常
 * @note 提供对销售额数据的读写访问
 */
double & Sales::operator[](int i)
{
    if (i < 0 || i >= MONTHS)
        throw bad_index(i);  // 索引越界，抛出异常
    return gross[i];
}

// Sales::bad_index 异常类的成员函数实现

/**
 * @brief bad_index异常类的构造函数
 * @param ix 错误的索引值
 * @param s 错误描述信息
 * @note 调用基类logic_error的构造函数，并保存错误的索引值
 */
Sales::bad_index::bad_index(int ix, const string & s) 
    : std::logic_error(s), bi(ix)
{
    // 初始化列表完成了所有工作
}

// LabeledSales 类的成员函数实现

/**
 * @brief LabeledSales类的默认构造函数
 * @param lb 标签名称
 * @param yy 年份
 * @note 调用基类构造函数并设置标签
 */
LabeledSales::LabeledSales(const string & lb, int yy)
    : Sales(yy)  // 调用基类构造函数
{
    label = lb;
}

/**
 * @brief LabeledSales类的带参数构造函数
 * @param lb 标签名称
 * @param yy 年份
 * @param gr 销售额数组指针
 * @param n 数组元素个数
 * @note 调用基类构造函数并设置标签
 */
LabeledSales::LabeledSales(const string & lb, int yy, const double * gr, int n)
    : Sales(yy, gr, n)  // 调用基类构造函数
{
    label = lb;
}

/**
 * @brief 重载下标操作符（const版本）
 * @param i 月份索引（0-11）
 * @return 对应月份的销售额
 * @throw nbad_index 当索引超出范围时抛出派生类异常
 * @note 重写基类函数，抛出更具体的异常类型
 */
double LabeledSales::operator[](int i) const
{
    if (i < 0 || i >= MONTHS)
        throw nbad_index(Label(), i);  // 抛出带标签的异常
    return Sales::operator[](i);       // 调用基类版本
}

/**
 * @brief 重载下标操作符（非const版本）
 * @param i 月份索引（0-11）
 * @return 对应月份销售额的引用
 * @throw nbad_index 当索引超出范围时抛出派生类异常
 * @note 重写基类函数，抛出更具体的异常类型
 */
double & LabeledSales::operator[](int i)
{
    if (i < 0 || i >= MONTHS)
        throw nbad_index(Label(), i);  // 抛出带标签的异常
    return Sales::operator[](i);       // 调用基类版本
}

// LabeledSales::nbad_index 异常类的成员函数实现

/**
 * @brief nbad_index异常类的构造函数
 * @param lb 标签名称
 * @param ix 错误的索引值
 * @param s 错误描述信息
 * @note 调用基类bad_index的构造函数，并保存标签名称
 */
LabeledSales::nbad_index::nbad_index(const string & lb, int ix,
                                     const string & s) 
    : Sales::bad_index(ix, s)  // 调用基类构造函数
{
    lbl = lb;
}