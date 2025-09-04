#include<namesp.h>
void another();
namespace
{
    int a=10;
}
void other();

int main(int argc, char const *argv[])
{
    int b=a;
    other();

    return 0;
}
void other()
{
    using namespace debts;
    showDebt();
}
void another()
{
    using pers::Person;
    Person per={"a","b"};
    showPerson(per);
}
