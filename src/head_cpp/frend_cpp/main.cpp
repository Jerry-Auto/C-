// use_tv.cpp -- 测试Tv和Remote类（友元类演示）
#include <iostream>
#include "tv.h"  // 包含Tv和Remote类定义
void use_tv();
using std::cout;
int main() {
    
    use_tv();


    return 0;
}

void use_tv()
{
    // === 1. 创建电视机对象 ===
    Tv s42;  // 默认关闭状态
    cout << "42英寸电视的初始设置:\n";
    s42.settings();  // 显示初始状态（关闭）
    
    // === 2. 电视机直接操作 ===
    s42.onoff();     // 打开电视
    s42.chanup();    // 频道+1
    cout << "\n调整后的42英寸电视设置:\n";
    s42.settings();
    
    // === 3. 使用遥控器操作 ===
    Remote grey;  // 创建遥控器
    grey.set_chan(s42, 10);  // 直接设置频道（友元特权）
    grey.volup(s42);         // 音量+1
    grey.volup(s42);         // 音量+1
    cout << "\n使用遥控器后的设置:\n";
    s42.settings();
    
    // === 4. 另一台电视机测试 ===
    Tv s58(Tv::On);  // 创建时直接打开
    s58.set_mode();  // 切换模式
    grey.set_chan(s58, 28);  // 设置频道
    cout << "\n58英寸电视设置:\n";
    s58.settings();
}

