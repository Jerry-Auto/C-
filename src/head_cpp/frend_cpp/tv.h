// tv.h -- 电视机和遥控器类定义（演示友元类）
#ifndef TV_H_
#define TV_H_

class Tv {
public:
    // 状态枚举
    enum { Off, On };
    enum { MinVal, MaxVal = 20 };
    enum { Antenna, Cable };
    enum { TV, DVD };

    Tv(int s = Off, int mc = 125) : state(s), volume(5), 
        maxchannel(mc), channel(1), mode(Cable), input(TV) {}

    void onoff() { state = (state == On) ? Off : On; }
    bool ison() const { return state == On; }
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
    void set_input() { input = (input == TV) ? DVD : TV; }
    void settings() const;  // 显示当前设置

    // 声明Remote为友元类
    friend class Remote;

private:
    int state;       // 开关状态
    int volume;      // 音量
    int maxchannel;  // 最大频道
    int channel;     // 当前频道
    int mode;        // 广播模式（有线/天线）
    int input;       // 输入源（TV/DVD）
};

// --- 遥控器类（Tv的友元）---
class Remote {
public:
    Remote(int m = Tv::TV) : mode(m) {}

    // 通过友元关系直接操作Tv私有成员
    bool volup(Tv & t) { return t.volup(); }
    bool voldown(Tv & t) { return t.voldown(); }
    void onoff(Tv & t) { t.onoff(); }
    void chanup(Tv & t) { t.chanup(); }
    void chandown(Tv & t) { t.chandown(); }
    void set_chan(Tv & t, int c) { t.channel = c; }  // 直接访问私有成员
    void set_mode(Tv & t) { t.set_mode(); }
    void set_input(Tv & t) { t.set_input(); }

private:
    int mode;  // 控制模式（TV/DVD）
};

#endif // TV_H_