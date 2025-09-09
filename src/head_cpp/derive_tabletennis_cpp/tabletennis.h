// tabtenn.h -- a table-tennis base class
#ifndef TABTENN_H_
#define TABTENN_H_
#include <string>

// Base Class
class TableTennisPlayer {
private:
    std::string firstname;
    std::string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const std::string & fn = "none",
                      const std::string & ln = "none",
                      bool ht = false);
    void Name() const;
    bool HasTable() const { return hasTable; }
    void ResetTable(bool v) { hasTable = v; }
};

// Derived Class
class RatedPlayer : public TableTennisPlayer 
{
private:
    unsigned int rating; // 新增数据成员：评分
public:
    RatedPlayer(unsigned int r = 0, const std::string & fn = "none",
                const std::string & ln = "none", bool ht = false);
    RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
    unsigned int Rating() const { return rating; } // 新增方法
    void ResetRating(unsigned int r) { rating = r; }
};

#endif