// functor.cpp -- 使用函数对象
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include"functor.h"

// 输出整数的函数
void outint(int n) {std::cout << n << " ";}

void functors()
{
    using std::list;
    using std::cout;
    using std::endl;
	
    TooBig<int> f100(100); // 限制值为100
    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    list<int> yadayada(vals, vals + 10); // 范围构造函数
    list<int> etcetera(vals, vals + 10);
 
    // C++11 可以使用以下方式代替
    // list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    // list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	
    cout << "原始列表:\n";
    std::for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    std::for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;
	
    yadayada.remove_if(f100);               // 使用命名的函数对象
    etcetera.remove_if(TooBig<int>(200));   // 构造一个函数对象
	
    cout << "修剪后的列表:\n";
    std::for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    std::for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;

}

void funadap(){

    const int LIM = 6;
    using namespace std;
    
    double arr1[LIM] = {28, 29, 30, 35, 38, 59};
    double arr2[LIM] = {63, 65, 69, 75, 80, 99};
    
    vector<double> gr8(arr1, arr1 + LIM);
    vector<double> m8(arr2, arr2 + LIM);
    
    cout.setf(ios_base::fixed);  // 固定浮点数格式
    cout.precision(1);           // 设置精度为1位小数
    
    cout << "gr8数组:\t";
    for_each(gr8.begin(), gr8.end(), Show);
    cout << endl;
    
    cout << "m8数组:\t";
    for_each(m8.begin(), m8.end(), Show);
    cout << endl;
    
    // 使用plus函数对象计算两个向量的和
    vector<double> sum(LIM);
    transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), plus<double>());
    cout << "和数组:\t";
    for_each(sum.begin(), sum.end(), Show);
    cout << endl;
    
    // 使用bind1st适配器将multiplies的第一个参数绑定为2.5
    vector<double> prod(LIM);
    transform(gr8.begin(), gr8.end(), prod.begin(), 
              bind1st(multiplies<double>(), 2.5));
    cout << "乘积数组:\t";
    for_each(prod.begin(), prod.end(), Show);
    cout << endl;

}

void Show(double v)
{
    std::cout.width(6);
    std::cout << v << ' ';
}

void func_pnt(){
    // 定义函数指针：返回值类型 (*指针名)(参数类型列表)
    int (*funcPtr)(int, int);
    
    // 将函数地址赋给指针
    funcPtr = &add;  // & 可选，函数名本身就是地址
    // 或者：funcPtr = add;
    
    // 通过函数指针调用函数
    int result = funcPtr(3, 4);  // 像普通函数一样调用
    // 或者：int result = (*funcPtr)(3, 4);
    
    std::cout << "3 + 4 = " << result << std::endl;  // 输出 7  
}

#include <memory>

void function_adaptor(){

    // 使用智能指针管理员工对象
    std::vector<std::shared_ptr<Employee>> employees = {
        std::make_shared<Employee>("张三", 75000.0, 3, true),
        std::make_shared<Employee>("李四", 95000.0, 7, true),
        std::make_shared<Employee>("王五", 60000.0, 2, false),
        std::make_shared<Employee>("赵六", 120000.0, 10, true),
        std::make_shared<Employee>("钱七", 55000.0, 1, true)
    };
    
    // std::mem_fn - 成员函数适配器
    // 成员函数转普通函数：让成员函数可以像普通函数一样调用
    // 自动处理调用方式：支持对象、指针、智能指针
    // const正确性：保持原成员函数的const属性
    // STL友好：完美配合STL算法

    auto display=std::mem_fn(&Employee::displayInfo);
    std::cout << "=== 所有员工信息 ===" << std::endl;
    //第一个参数是对象实例本身或者对象的指针
    //用法为display(employees[i])或display(&employees[i])
    std::for_each(employees.begin(), employees.end(),display);
    
    // =========================================================================
    // 1. 组合使用 mem_fn 和 not_fn - 找出非在职员工
    // =========================================================================
    // std::not_fn - 逻辑取反适配器 (C++17)
    // 逻辑取反：对谓词的返回值取反
    // 统一接口：替代传统的 not1 和 not2
    // 类型安全：编译时类型检查
    // 通用性强：支持任何返回bool的可调用对象,
    // 成员函数要先用mem_fn，再用not_fn,第一个参数是对象实例本身或者对象的指针

    std::cout << "\n=== 1. 使用 mem_fn + not_fn 找出离职员工 ===" << std::endl;
    
    // 方法A: 使用函数适配器
    auto isActive = std::mem_fn(&Employee::isActive);
    auto isInactive = std::not_fn(isActive);
    
    std::cout << "离职员工: ";
    std::for_each(employees.begin(), employees.end(),
                 [&](const auto& emp) {
                     if (isInactive(*emp)) {
                         std::cout << emp->getName() << " ";
                     }
                 });
    std::cout << std::endl;
    

    // 方法B: 使用lambda表达式对比
    std::cout << "离职员工(lambda): ";
    std::for_each(employees.begin(), employees.end(),
                 [](const auto& emp) {
                     if (!emp->isActive()) {
                         std::cout << emp->getName() << " ";
                     }
                 });
    std::cout << std::endl;
    
    // =========================================================================
    // 2. 使用 bind 创建复杂的条件判断
    // =========================================================================
    // std::bind - 通用参数绑定器
    // 参数绑定：固定函数的部分参数
    // 参数重排序：通过 _1, _2, _3... 改变参数顺序
    // 通用性强：支持普通函数、成员函数、函数对象
    // 灵活组合：可以嵌套使用
    std::cout << "\n=== 2. 使用 bind 创建复杂条件 ===" << std::endl;
    
    // 方法A: 使用bind组合多个条件
    auto isSeniorHighPaid = std::bind(std::logical_and<bool>(),
                                     std::bind(std::mem_fn(&Employee::isSenior), _1),
                                     std::bind(std::mem_fn(&Employee::isHighPaid), _1));
    
    std::cout << "资深高薪员工(bind): ";
    int count1 = std::count_if(employees.begin(), employees.end(),
                              [&](const auto& emp) { return isSeniorHighPaid(*emp); });
    std::cout << count1 << " 人" << std::endl;
    
    // 方法B: 使用lambda表达式对比
    std::cout << "资深高薪员工(lambda): ";
    int count2 = std::count_if(employees.begin(), employees.end(),
                              [](const auto& emp) {
                                  return emp->isSenior() && emp->isHighPaid();
                              });
    std::cout << count2 << " 人" << std::endl;
    
    // =========================================================================
    // 3. bind 与智能指针和成员函数结合
    // =========================================================================
    // bind(&T::func,_1,_2,_3)，对成员函数操作
    // _1是对象，可以是引用std::ref(Tobj)或者指针&Tobj或普通对象Tobj(拷贝副本)或智能指针
    // _2,_3是函数输入参数
    std::cout << "\n=== 3. bind + 智能指针 + 成员函数 ===" << std::endl;
    
    // 方法A: 使用bind给所有员工加薪10%
    std::cout << "使用bind加薪10%:" << std::endl;
    auto giveRaise10 = std::bind(&Employee::giveRaise, _1, 10.0);
    std::for_each(employees.begin(), employees.end(), giveRaise10);
    
    // 方法B: 使用lambda表达式对比
    std::cout << "\n使用lambda再次加薪5%:" << std::endl;
    std::for_each(employees.begin(), employees.end(),
                 [](const auto& emp) { emp->giveRaise(5.0); });
    
    // =========================================================================
    // 4. 更复杂的组合：条件性操作
    // =========================================================================
    std::cout << "\n=== 4. 复杂组合：给特定员工额外加薪 ===" << std::endl;
    
    // 条件：在职且工资低于平均水平
    auto needsExtraRaise = [](const std::shared_ptr<Employee>& emp) {
        return emp->isActive() && emp->getSalary() < 80000.0;
    };
    
    // 方法A: 使用bind和条件判断
    auto giveConditionalRaise = [&](const std::shared_ptr<Employee>& emp) {
        if (needsExtraRaise(emp)) {
            auto giveBonusRaise = std::bind(&Employee::giveRaise, emp, 15.0);
            giveBonusRaise();
        }
    };
    
    std::cout << "使用bind条件加薪:" << std::endl;
    std::for_each(employees.begin(), employees.end(), giveConditionalRaise);
    
    // 方法B: 纯lambda对比
    std::cout << "\n使用lambda条件加薪:" << std::endl;
    std::for_each(employees.begin(), employees.end(),
                 [&](const auto& emp) {
                     if (needsExtraRaise(emp)) {
                         emp->giveRaise(15.0);
                     }
                 });
    
    // =========================================================================
    // 5. 性能和使用场景分析
    // =========================================================================
    std::cout << "\n=== 5. 性能和使用场景总结 ===" << std::endl;
    
    // 统计各类员工数量 - 展示不同方法的可读性
    
    // 方法A: 函数适配器组合（适合简单条件）
    auto isJunior = std::not_fn(std::mem_fn(&Employee::isSenior));
    auto activeJunior = std::bind(std::logical_and<bool>(),
                                 isActive, isJunior);
    
    int juniorCount = std::count_if(employees.begin(), employees.end(),
                                   [&](const auto& emp) { return activeJunior(*emp); });
    
    // 方法B: lambda表达式（适合复杂条件）
    int juniorCountLambda = std::count_if(employees.begin(), employees.end(),
                                         [](const auto& emp) {
                                             return emp->isActive() && !emp->isSenior();
                                         });
    
    std::cout << "初级员工数量 - 适配器: " << juniorCount 
              << ", lambda: " << juniorCountLambda << std::endl;
    
    // =========================================================================
    // 6. 创建可重用的谓词工厂
    // =========================================================================
    std::cout << "\n=== 6. 创建可重用的谓词工厂 ===" << std::endl;
    
    // 使用bind创建可配置的谓词
    auto createSalaryRangeFilter = [](double minSalary, double maxSalary) {
        return [minSalary, maxSalary](const std::shared_ptr<Employee>& emp) {
            double salary = emp->getSalary();
            return salary >= minSalary && salary <= maxSalary;
        };
    };
    
    auto createSeniorityFilter = [](int minYears, bool activeOnly = true) {
        return [minYears, activeOnly](const std::shared_ptr<Employee>& emp) {
            bool yearCondition = emp->getYears() >= minYears;
            bool activeCondition = !activeOnly || emp->isActive();
            return yearCondition && activeCondition;
        };
    };
    
    // 使用工厂创建的谓词
    auto midSalaryFilter = createSalaryRangeFilter(70000.0, 100000.0);
    auto experiencedFilter = createSeniorityFilter(3, true);
    
    std::cout << "中等薪资员工: ";
    std::for_each(employees.begin(), employees.end(),
                 [&](const auto& emp) {
                     if (midSalaryFilter(emp)) {
                         std::cout << emp->getName() << " ";
                     }
                 });
    std::cout << std::endl;
    
    std::cout << "有经验的在职员工: ";
    std::for_each(employees.begin(), employees.end(),
                 [&](const auto& emp) {
                     if (experiencedFilter(emp)) {
                         std::cout << emp->getName() << " ";
                     }
                 });
    std::cout << std::endl;
    
    // 最终状态展示
    std::cout << "\n=== 最终员工状态 ===" << std::endl;
    std::for_each(employees.begin(), employees.end(),
                  std::mem_fn(&Employee::displayInfo));
}


void lambda_express(){
    // lambda表达式
    // 基本语法：  [捕获列表](参数列表) -> 返回类型 { 函数体 }
    // 捕获列表就像给Lambda发放的"访问通行证"，决定它可以访问哪些外部变量以及如何访问

    int external_value = 10;
    std::string external_name = "test";

    // 空捕获 - 不捕获任何外部变量
    auto lambda1 = [](const auto & input) { std::cout << "无捕获," <<"输入值:"<<input<< std::endl; };

    // 值捕获 - 创建外部变量的副本
    auto lambda2 = [external_value]() { 
        std::cout << "值: " << external_value << std::endl; 
    };

    // 引用捕获 - 使用外部变量的引用
    auto lambda3 = [&external_name]() { 
        std::cout << "引用: " << external_name << std::endl; 
    };

    // 隐式值捕获 - 捕获所有使用的外部变量（值方式）
    auto lambda4 = [=]() { 
        std::cout << "隐式值: " << external_value << std::endl; 
    };

    // 隐式引用捕获 - 捕获所有使用的外部变量（引用方式）
    auto lambda5 = [&]() { 
        std::cout << "隐式引用: " << external_name << std::endl; 
    };

    // 混合捕获
    auto lambda6 = [external_value, &external_name]() {
        std::cout << "混合: " << external_value << ", " << external_name << std::endl;
    };

    lambda1(10);
    lambda2();
    lambda3();
    lambda4();
    lambda5();
    lambda6();
}