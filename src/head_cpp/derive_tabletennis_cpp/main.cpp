#include"tabletennis.h"
#include<iostream>

int main(int argc, char const *argv[])
{
    using std::cout;
    using std::endl;

    // 1. 创建基类对象
    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);

    // 2. 调用基类方法
    player1.Name();
    if (player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";

    player2.Name();
    if (player2.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";

    // 3. 创建派生类对象（使用基类构造函数）
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);

    // 4. 调用派生类方法
    rplayer1.Name();
    if (rplayer1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    cout << "Rating: " << rplayer1.Rating() << endl;

    // 5. 使用基类对象初始化派生类对象
    RatedPlayer rplayer2(1212, player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;

    return 0;
}
