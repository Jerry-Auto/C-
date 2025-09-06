#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include "Queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x); // 是否有新顾客到来

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    typedef Customer Item;
    // 初始化随机数生成器
    std::srand(std::time(0));
    
    cout << "案例学习：Bank of Heather Automatic Teller\n";
    cout << "输入队列的最大长度：";
    int qs;
    cin >> qs;
    Queue<Customer> line(qs);
    
    cout << "输入模拟的小时数：";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours; // 模拟周期数
    
    cout << "输入每小时的平均顾客数：";
    double perhour;
    cin >> perhour;
    double min_per_cust = MIN_PER_HR / perhour; // 平均到达间隔
    
    Item temp;              // 新顾客数据
    long turnaways = 0;     // 被拒顾客数
    long customers = 0;     // 加入队列的顾客数
    long served = 0;        // 在模拟期间得到服务的顾客数
    long sum_line = 0;      // 累计队列长度
    int wait_time = 0;      // ATM空闲时间
    long line_wait = 0;     // 排队累计等待时间
    
    // 开始模拟
    for (long cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(min_per_cust)) { // 有新顾客到来
            if (line.isfull())
                turnaways++;
            else {
                customers++;
                temp.set(cycle);
                line.enqueue(temp);
            }
        }
        
        if (wait_time <= 0 && !line.isEmpty()) {
            line.dequeue(temp);//轮到弹出的temp处理
            wait_time = temp.ptime();//需要的处理时间
            line_wait += cycle - temp.when();//当前时间减去开始排队的时间
            served++;
        }
        
        if (wait_time > 0)
            wait_time--;
        
        sum_line += line.queuecount();
    }
    
    // 输出结果
    if (customers > 0) {
        cout << "接受的顾客数: " << customers << endl;
        cout << "服务的顾客数: " << served << endl;
        cout << "被拒的顾客数: " << turnaways << endl;
        cout << "平均队列长度: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << "平均等待时间: " 
             << (double) line_wait / served << " 分钟\n";
    } else
        cout << "没有顾客！\n";
    
    cout << "完成！\n";
    return 0;
}

// x = 顾客平均到达间隔时间（分钟）
// 如果1分钟内有顾客到达，则返回true
bool newcustomer(double x) {
    return (std::rand() * x / RAND_MAX < 1);
}