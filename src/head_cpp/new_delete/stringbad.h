#pragma once
#include <iostream>
class stringbad
{
private:
    char * str;
    int len;
    static int num_strings;
    static const int CIN_LIM=80;
public:
    stringbad();
    stringbad(const char * s);
    stringbad(const stringbad& sb);
    ~stringbad();

    static int HowMany();

    stringbad& operator=(const stringbad& st);
    stringbad& operator=(const char* st);
    char & operator[](int i);
    const char & operator[](int i) const;

    friend  std::ostream& operator<<(std::ostream& os,const stringbad&st);
    friend  std::istream& operator>>(std::istream& is,stringbad&st);
};




