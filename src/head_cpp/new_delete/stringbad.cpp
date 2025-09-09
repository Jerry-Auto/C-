#include<cstring>
#include"stringbad.h"
using std::cout;
int stringbad::num_strings=0;

stringbad::~stringbad()
{
    cout<<str<<"  \t对象被销毁\n";
    --num_strings;
    delete[] str;
    cout<<num_strings<<"  \t个对象剩余"<<std::endl;
    cout<<"------------------\n";
}

stringbad::stringbad(const char * s){
    len=std::strlen(s);
    str =new char[len+1];
    std::strcpy(str,s);
    ++num_strings;
    cout<<"普通构造\n";
    cout<<num_strings<<"个对象被创建\n";
    cout<<str<<"  \t对象创建\n";
    cout<<"------------------\n";
}

stringbad::stringbad(){
    len=4;
    str =new char[len];
    std::strcpy(str,"c++");
    ++num_strings;
    cout<<"默认构造\n";
    cout<<num_strings<<"个对象被创建\n";
    cout<<str<<"  \t对象创建\n";
    cout<<"------------------\n";
}

stringbad::stringbad(const stringbad& sb)
{
    len=sb.len;
    str=new char[len+1];
    std::strcpy(str,sb.str);
    num_strings++;
    cout<<"复制构造\n";
    cout<<num_strings<<"个对象被创建\n";
    cout<<str<<"  \t对象创建\n";
    cout<<"------------------\n";
}
stringbad& stringbad::operator=(const stringbad& st)
{
    if(this==&st)
        return *this;
    delete[] str;
    len=st.len;
    str=new char[len+1];
    std::strcpy(str,st.str);
    cout<<"stringbad类赋值运算\n";
    cout<<"------------------\n";
    return *this;
}

stringbad& stringbad::operator=(const char* st)
{
    delete[] str;
    len=std::strlen(st);
    str=new char[len+1];
    std::strcpy(str,st);
    cout<<"char*类赋值运算\n";
    cout<<"------------------\n";
    return *this;
}


std::ostream& operator<<(std::ostream& os,const stringbad& st)
{
    os<<st.str;
    return os;
}
std::istream& operator>>(std::istream& is,stringbad&st)
{
    char temp[stringbad::CIN_LIM];
    is.get(temp,stringbad::CIN_LIM);
    if(is)
        st=temp;
    while(is &&is.get()!='\n')
    continue;
    return is;
}
char & stringbad::operator[](int i)
{
    return str[i];
}
const char & stringbad::operator[](int i) const
{
    return str[i];
}
int stringbad::HowMany()
{
    return num_strings;
}
