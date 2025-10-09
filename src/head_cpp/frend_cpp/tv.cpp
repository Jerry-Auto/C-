// tv.cpp -- Tv类方法实现
#include <iostream>
#include "tv.h"

// === Tv类方法 ===

// 音量增加（返回是否成功）
bool Tv::volup() {
    if (volume < MaxVal) {
        volume++;
        return true;
    }
    return false;
}

// 音量降低（返回是否成功）
bool Tv::voldown() {
    if (volume > MinVal) {
        volume--;
        return true;
    }
    return false;
}

// 频道增加（循环）
void Tv::chanup() {
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}

// 频道降低（循环）
void Tv::chandown() {
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

// 显示当前设置
void Tv::settings() const {
    using std::cout;
    using std::endl;

    cout << "TV is " << (state == Off ? "Off" : "On") << endl;
    if (state == On) {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = " << (mode == Antenna ? "antenna" : "cable") << endl;
        cout << "Input = " << (input == TV ? "TV" : "DVD") << endl;
    }
}