#pragma once
#include<iostream>
#include<string>

namespace pers
{
    struct Person
    {
        std::string fname;
        std::string lname;
    };
    void getPersion();
    void showPerson(const Person& per);

}

namespace debts
{
    using namespace pers;
    struct Debt
    {
        Person name;
        double amount;
    };
    void showDebt();
    
} 
