#include <functional>


template<class T>  // 函数对象类(函数符)定义了operator()()
class TooBig
{
private:
    T cutoff;  // 阈值
public:
    TooBig(const T & t) : cutoff(t) {}
    bool operator()(const T & v) { return v > cutoff; }
};

void functors();
void Show(double v);
void funadap();


// 自定义自适应函数符
class IsEven : public std::unary_function<int, bool> {
public:
    bool operator()(int x) const {
        return x % 2 == 0;
    }
};


// 一个普通函数
int add(int a, int b) {
    return a + b;
}

void func_pnt();



using namespace std::placeholders;

// 员工类
class Employee {
public:
    Employee(const std::string& name, double salary, int years, bool active = true)
        : name_(name), salary_(salary), years_(years), active_(active) {}
    
    // 成员函数
    double getSalary() const { return salary_; }
    std::string getName() const { return name_; }
    int getYears() const { return years_; }
    bool isActive() const { return active_; }
    bool isSenior() const { return years_ >= 5; }
    bool isHighPaid() const { return salary_ > 80000; }
    
    void giveRaise(double percentage) {
        salary_ *= (1.0 + percentage / 100.0);
        std::cout << name_ << " 获得 " << percentage << "% 加薪，新工资: $" << salary_ << std::endl;
    }
    
    void displayInfo() const {
        std::cout << name_ << " - 工资: $" << salary_ 
                  << ", 工龄: " << years_ << "年"
                  << ", 状态: " << (active_ ? "在职" : "离职") << std::endl;
    }

private:
    std::string name_;
    double salary_;
    int years_;
    bool active_;
};

void function_adaptor();
void lambda_express();