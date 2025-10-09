// use_student.cpp -- test the Student classes
#include <iostream>
#include "studentc.h"  
#include "studentp.h"   
using private_inheritance::Student;
//using containment::Student;

const int NUM = 3;
int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    // 1. 创建 Student 对象数组
    Student students[NUM] = {
        Student("Alice", 5),
        Student("Bob", 4),
        Student("Charlie", 3)
    };

    // 2. 输入学生分数
    for (int i = 0; i < NUM; i++) {
        cout << "Enter " << students[i].Name() << "'s scores:\n";
        for (int j = 0; j < students[i].size(); j++) {
            cin >> students[i][j];
        }
    }

    // 3. 输出学生信息
    cout << "\n==== Student Results ====\n";
    for (int i = 0; i < NUM; i++) {
        cout << students[i];
        cout << "Average: " << students[i].Average() << endl << endl;
    }

    return 0;
}