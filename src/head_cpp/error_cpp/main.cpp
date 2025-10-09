#include<iostream>
#include <cmath>    // 或 math.h, 用于 sqrt()
#include <string>
#include"exe_mean.h"
#include "sales.h"
#include<exception>
using namespace std;

void error5();
void sales();
void uncaught_error();
void cin_error() throw();

void my_quit(){
    cout<<"自定义的退出函数";
    exit(5);
}
int main()
{
    //error5();
    //sales();
    uncaught_error();
    return 0;
}
void uncaught_error(){
    set_terminate(my_quit);
    try{
        cin_error();
    }
    catch(std::logic_error &LE)
    {
        cout<<LE.what();
    }
}
void cin_error() throw()
{
    double A[10]={};
    int i=0;
    cin>>i;
    A[i]=5;
}

void error5()
{
    double x, y, z;
    {
        demo d1("found in main()");  // main 中的 demo 对象
        
        cout << "Enter two numbers: ";
        while (cin >> x >> y)
        {
            try {
                z = means(x, y);
                cout << "The mean of means of " << x << " and " << y
                    << " is " << z << endl;
            }
            catch (bad_hmean & bg) {
                bg.mesg();
                cout << "Try again.\n";
                continue;
            }
            catch (bad_gmean & hg) {
                cout << hg.mesg();
                cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;
                cout << "Sorry, you don't get to play any more.\n";
                break;
            }
        }
        
        d1.show();
    }
    cout << "Bye!\n";
}


void sales(){
    // 测试数据：两个季度的销售额
    double vals1[12] = {
        1220, 1100, 1122, 2212, 1232, 2334,
        2884, 2393, 3302, 2922, 3002, 3544
    };

    double vals2[12] = {
        12, 11, 22, 21, 32, 34,
        28, 29, 33, 29, 32, 35
    };

    // 创建两个Sales对象
    Sales sales1(2011, vals1, 12);
    LabeledSales sales2("Blogstar", 2012, vals2, 12);

    cout << "第一个try块:\n";
    try
    {
        int i;
        cout << "年份 = " << sales1.Year() << endl;
        
        // 显示sales1的所有月份数据（正常范围）
        for (i = 0; i < 12; ++i)
        {
            cout << sales1[i] << ' ';
            if (i % 6 == 5)  // 每6个月换行
                cout << endl;
        }
        
        // 显示sales2的所有月份数据（正常范围）
        cout << "年份 = " << sales2.Year() << endl;
        cout << "标签 = " << sales2.Label() << endl;
        
        for (i = 0; i <= 12; ++i)  // 注意：这里故意访问了13个元素！
        {
            cout << sales2[i] << ' ';
            if (i % 6 == 5)
                cout << endl;
        }
        
        cout << "try块1结束\n";  // 这行不会执行，因为上面会抛出异常
    }
    catch (LabeledSales::nbad_index & bad)
    {
        // 捕获LabeledSales的异常
        cout << bad.what();
        cout << "公司: " << bad.label_val() << endl;
        cout << "错误的索引: " << bad.bi_val() << endl;
    }
    catch (Sales::bad_index & bad)
    {
        // 捕获Sales的异常
        cout << bad.what();
        cout << "错误的索引: " << bad.bi_val() << endl;
    }

    cout << "\n下一个try块:\n";
    try
    {
        // 测试sales2的越界访问
        sales2[2] = 37.5;    // 正常，索引2在范围内
        sales1[20] = 23345;  // 异常！索引20超出范围
        cout << "try块2结束\n";  // 这行不会执行
    }
    catch (LabeledSales::nbad_index & bad)
    {
        // 捕获LabeledSales的异常
        cout << bad.what();
        cout << "公司: " << bad.label_val() << endl;
        cout << "错误的索引: " << bad.bi_val() << endl;
    }
    catch (Sales::bad_index & bad)
    {
        // 捕获Sales的异常
        cout << bad.what();
        cout << "错误的索引: " << bad.bi_val() << endl;
    }
}
