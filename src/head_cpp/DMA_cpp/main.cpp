// usedma.cpp -- test the DMA classes
#include <iostream>
#include "dma.h"

int main() {
    using std::cout;
    using std::endl;

    // 1. 测试 BaseDMA
    BaseDMA shirt("Portabelly", 8);
    cout << shirt << endl;

    // 2. 测试 LacksDMA（无动态内存）
    LacksDMA balloon("red", "Blimpo", 4);
    cout << balloon << endl;

    // 3. 测试 HasDMA（有动态内存）
    HasDMA map("Mercator", "Buffalo Keys", 5);
    cout << map << endl;

    // 4. 测试派生类赋值（多态行为）
    HasDMA map2 = map;  // 调用拷贝构造函数
    cout << "Copy of map:\n" << map2 << endl;

    // 5. 测试基类指针管理派生类对象
    BaseDMA * p_clients[3];
    p_clients[0] = new BaseDMA("Client1", 10);
    p_clients[1] = new LacksDMA("blue", "Client2", 20);
    p_clients[2] = new HasDMA("Modern", "Client3", 30);

    cout << "\n==== Polymorphic Output ====\n";
    for (int i = 0; i < 3; i++) {
        cout << *p_clients[i] << endl;  // 仅显示基类部分（无多态输出）
        delete p_clients[i];            // 虚析构函数确保正确释放
    }

    return 0;
}