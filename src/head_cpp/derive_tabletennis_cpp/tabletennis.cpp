// tabtenn.cpp -- simple base-class methods
#include "tabletennis.h"
#include <iostream>

// TableTennisPlayer methods
TableTennisPlayer::TableTennisPlayer(const std::string & fn,
                                     const std::string & ln, bool ht)
                                     : firstname(fn), lastname(ln), hasTable(ht) {}//基类列表初始化

void TableTennisPlayer::Name() const {
    std::cout << lastname << ", " << firstname;
}

// RatedPlayer methods
RatedPlayer::RatedPlayer(unsigned int r, const std::string & fn,
                         const std::string & ln, bool ht)
                         : TableTennisPlayer(fn, ln, ht), rating(r) {}//派生类给基类进行列表初始化，附带初始化派生类成员

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp)
                         : TableTennisPlayer(tp), rating(r) {}//派生类给基类进行拷贝构造，附带初始化派生类成员