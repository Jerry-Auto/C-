#include"Algorithm.h"
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>   // 包含数值算法
#include <valarray>
#include <iterator>
#include <string>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;

void algorithms_demo1()
{
    // 1. sort算法示例 - 对区间进行排序
    vector<int> vec{3, 1, 4, 2, 5};
    cout << "sort算法示例:" << endl;
    sort(vec.begin(), vec.end());  // 默认升序排序
    for (int val : vec) cout << val << " ";
    cout << endl;

    // 2. find算法示例 - 查找特定值
    cout << "\nfind算法示例:" << endl;
    auto it = find(vec.begin(), vec.end(), 4);
    if (it != vec.end())
        cout << "找到元素4，位置索引: " << distance(vec.begin(), it) << endl;
    else
        cout << "未找到元素4" << endl;

    // 3. for_each算法示例 - 对每个元素执行操作
    cout << "\nfor_each算法示例:" << endl;
    for_each(vec.begin(), vec.end(), [](int x) {
        cout << x * 2 << " ";  // 将每个元素乘以2输出
    });
    cout << endl;

    // 4. copy算法示例 - 复制序列到目标位置
    cout << "\ncopy算法示例:" << endl;
    vector<int> dest(5);
    copy(vec.begin(), vec.end(), dest.begin());
    cout << "复制后的目标向量: ";
    for (int val : dest) cout << val << " ";
    cout << endl;

    // 5. replace算法示例 - 替换特定值
    cout << "\nreplace算法示例:" << endl;
    vector<int> vec2{1, 2, 3, 2, 1};
    replace(vec2.begin(), vec2.end(), 2, 99);  // 将所有2替换为99
    cout << "替换后的向量: ";
    for (int val : vec2) cout << val << " ";
    cout << endl;

    // 6. accumulate算法示例 - 计算累加和
    cout << "\naccumulate算法示例:" << endl;
    int sum = accumulate(vec.begin(), vec.end(), 0);  // 从0开始累加
    cout << "向量元素总和: " << sum << endl;

    // 7. count算法示例 - 统计特定值出现次数
    cout << "\ncount算法示例:" << endl;
    vector<int> vec3{1, 2, 3, 2, 2, 4};
    int cnt = count(vec3.begin(), vec3.end(), 2);
    cout << "数字2出现次数: " << cnt << endl;

    // 8. unique算法示例 - 去除相邻重复元素
    cout << "\nunique算法示例:" << endl;
    vector<int> vec4{1, 2, 2, 3, 3, 3, 4};
    auto last = unique(vec4.begin(), vec4.end());  // 返回去重后的新末尾
    //vec4 = {1,2,2,3,3,3,4} → unique 后变为 {1,2,3,4,2,3,3}，last 指向 4 后面的第一个元素（即索引3的位置）
    vec4.erase(last, vec4.end());  // 实际删除重复元素，左闭右开
    cout << "去重后的向量: ";
    for (int val : vec4) cout << val << " ";
    cout << endl;

    // 9. reverse算法示例 - 反转序列
    cout << "\nreverse算法示例:" << endl;
    vector<char> letters{'a', 'b', 'c', 'd'};
    reverse(letters.begin(), letters.end());
    cout << "反转后的字符序列: ";
    for (char c : letters) cout << c << " ";
    cout << endl;

    // 10. transform算法示例 - 对元素进行转换
    cout << "\ntransform算法示例:" << endl;
    vector<string> words{"hello", "world", "cpp"};
    vector<int> lengths;
    transform(words.begin(), words.end(), back_inserter(lengths),
              [](const string& s) { return s.length(); });  // 计算每个字符串长度
    // 使用 std::back_inserter(container)。
    // 适用容器：需支持 push_back（vector、deque、list 等）。对 set/map 等需用 std::inserter。
    // 优点：不需要事先调整目标容器大小，代码简洁。
    // 返回一个 std::back_insert_iterator<std::vector<int>> out。这个迭代器在被赋值时(out=value)会调用 lengths.push_back(value)。
    cout << "各单词长度: ";
    for (int len : lengths) cout << len << " ";
    cout << endl;
    /* 
    transform 算法作用（简要）：

    对输入区间的每个元素应用一个一元或二元操作，将结果写入输出区间（逐元素“变换”）。
    常见用途：映射（map）、类型/值转换、就地修改或写到另一个容器。
    复杂度：O(N)。

    常用函数签名（简化）：

    一元版本：
    std::transform(InputIt first, InputIt last, OutputIt d_first, UnaryOp op);
    二元版本：
    std::transform(InputIt1 first1, InputIt1 last1, InputIt2 first2, OutputIt d_first, BinaryOp op); */
    std::vector<int> a{1,2,3,4};
    std::vector<int> c{10,20,30,40}, d;
    d.resize(a.size());
    std::transform(a.begin(), a.end(), c.begin(), d.begin(), [](int x,int y){ return x+y; });
    for (int v : d) std::cout << v << ' '; std::cout << '\n';
}

// 显示容器内容的辅助函数
template<typename T>
void display(const string& msg, const T& container) {
    cout << msg << ": ";
    for (const auto& item : container) {
        cout << item << " ";
    }
    cout << endl;
}

//演示:random_shuffle, set_union, set_intersection, set_difference, transform, replace_if, next_permutation
void algorithms_demo2(){
    // 设置随机数种子
    srand(time(0));
    
    cout << "=== STL算法演示 ===\n" << endl;

    // 1. random_shuffle 演示
    cout << "1. random_shuffle 算法演示:" << endl;
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display("原始序列", nums);
    
    random_shuffle(nums.begin(), nums.end());
    display("随机重排后", nums);
    cout << endl;

    std::random_device rd;
    std::mt19937 g(rd());        // 每次不同；用 mt19937 g(123); 可复现
    std::shuffle(nums.begin(), nums.end(), g); // 推荐
    display("随机重排后", nums);
    cout << endl;
    
    // 2. transform 演示
    cout << "2. transform 算法演示:" << endl;
    vector<int> source{1, 2, 3, 4, 5};
    vector<int> target;
    
    display("源容器", source);
    
    // 将每个元素平方
    transform(source.begin(), source.end(), back_inserter(target),
              [](int x) { return x * x; });
    display("平方变换后", target);
    
    // 字符串转换示例
    vector<string> words{"hello", "world", "cpp", "algorithm"};
    vector<string> upper_words;
    
    transform(words.begin(), words.end(), back_inserter(upper_words),
              [](const string& s) {
                  string result = s;
                  transform(s.begin(), s.end(), result.begin(), ::toupper);
                  return result;
              });
    display("原始单词", words);
    display("转换为大写", upper_words);
    cout << endl;

    // 3. replace_if 演示
    cout << "3. replace_if 算法演示:" << endl;
    vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display("原始序列", numbers);
    
    // 将所有偶数替换为0
    replace_if(numbers.begin(), numbers.end(),
               [](int x) { return x % 2 == 0; }, 0);
    display("偶数替换为0后", numbers);
    cout << endl;

    // 4. 集合操作演示 (set_union, set_intersection, set_difference)
    cout << "4. 集合操作算法演示:" << endl;
    vector<int> set1{1, 2, 3, 4, 5};
    vector<int> set2{3, 4, 5, 6, 7};
    vector<int> result_union;
    vector<int> result_intersection;
    vector<int> result_difference;
    
    display("集合A", set1);
    display("集合B", set2);
    
    // 注意：集合操作要求输入已排序
    sort(set1.begin(), set1.end());
    sort(set2.begin(), set2.end());
    
    // 并集
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
              back_inserter(result_union));
    display("A ∪ B (并集)", result_union);
    
    // 交集
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                     back_inserter(result_intersection));
    display("A ∩ B (交集)", result_intersection);
    
    // 差集 (A - B)
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
                   back_inserter(result_difference));
    display("A - B (差集)", result_difference);
    cout << endl;

    // 5. next_permutation 演示
    /* 
    next_permutation 做什么（简短）：

    将给定序列就地变为“下一个字典序（lexicographic）排列”。
    若存在更大的排列，函数把序列改为下一个排列并返回 true。
    若当前序列已是最大的排列（按比较器），函数把序列重置为最小排列并返回 false。
    原地操作，复杂度 O(n)，要求双向迭代器（BidirectionalIterator）。
    支持自定义比较器：next_permutation(first, last, comp)。
    要注意的点：

    若想枚举所有排列，先把序列按升序排序，然后用 do { ... } while(next_permutation(...)); 这种模式。
    next_permutation 使用元素的 operator<（或自定义 comp）判断字典序。
    */
    cout << "5. next_permutation 算法演示:" << endl;
    vector<int> perm{1, 2, 3};
    int count = 0;
    
    cout << "序列 {1, 2, 3} 的所有排列:" << endl;
    do {
        cout << "排列 " << ++count << ": ";
        for (int x : perm) cout << x << " ";
        cout << endl;
    } while (next_permutation(perm.begin(), perm.end()));
    
    cout << "\n总共 " << count << " 种排列" << endl;
    cout << endl;

    // 6. 综合示例：字符串处理
    cout << "6. 综合示例 - 字符串处理:" << endl;
    string text = "Hello World! This is a test string.";
    cout << "原始文本: " << text << endl;
    
    // 将所有小写字母转换为大写
    transform(text.begin(), text.end(), text.begin(), ::toupper);
    cout << "转换为大写: " << text << endl;
    
    // 将所有空格替换为下划线
    replace_if(text.begin(), text.end(),
               [](char c) { return c == ' '; }, '_');
    cout << "空格替换为下划线: " << text << endl;
    
    // 随机重排前10个字符
    if (text.length() >= 10) {
        random_shuffle(text.begin(), text.begin() + 10);
        cout << "前10个字符随机重排: " << text << endl;
    }
}

void Show(int v)
{
    std::cout << v << ' ';
}

void listrmv(){
    const int LIM = 10;
    int ar[LIM] = {4, 5, 4, 2, 2, 3, 4, 8, 1, 4};
    list<int> la(ar, ar + LIM);
    list<int> lb(la);
    
    cout << "Original list contents:\n\t";
    for_each(la.begin(), la.end(), Show);
    cout << endl;
    
    // 使用remove方法删除所有值为4的元素
    la.remove(4);
    cout << "After using the remove() method:\n\t";
    for_each(la.begin(), la.end(), Show);
    cout << endl;
    
    // 使用remove_if算法删除所有大于4的元素
    list<int>::iterator last;
    last = remove_if(lb.begin(), lb.end(), [](int x) { return x > 4; });
    cout << "After using the remove_if() function:\n\t";
    for_each(lb.begin(), lb.end(), Show);
    cout << endl;
    
    // 实际删除被"移除"的元素
    lb.erase(last, lb.end());
    cout << "After using the erase() method:\n\t";
    for_each(lb.begin(), lb.end(), Show);
    cout << endl;
}

// 辅助函数1: 将单个字符转换为小写
char toLower(char ch) { return tolower(ch); }

// 辅助函数2: 将整个字符串转换为小写
string & ToLower(string & st) {
    transform(st.begin(), st.end(), st.begin(), toLower);
    return st;
}

// 辅助函数3: 显示字符串
void Display(const string & s) {
    cout << s << " ";
}

void usealgo(){
    vector<string> words;
    cout << "请输入单词（输入quit结束）:\n";
    string input;
    
    // 读取单词，直到输入"quit"
    while (cin >> input && input != "quit")
        words.push_back(input);
    
    cout << "您输入的单词如下:\n";
    // 使用for_each和Display函数显示所有单词
    for_each(words.begin(), words.end(), Display);
    cout << endl;
    
    // 将单词放入set中，转换为小写并去重
    set<string> wordset;
    transform(words.begin(), words.end(), 
              insert_iterator<set<string> >(wordset, wordset.begin()),
              ToLower);//插入到wordset.begin()，然后自动排序
    cout << "\n按字母顺序排列的单词（不区分大小写）:\n";
    for_each(wordset.begin(), wordset.end(), Display);
    cout << endl;

    // 使用map统计单词频率 - wordmap演示
    map<string, int> wordmap;
    set<string>::iterator si;
    // 统计每个单词出现的次数
    for (si = wordset.begin(); si != wordset.end(); si++)
        wordmap[*si] = count(words.begin(), words.end(), *si);
    
    // 显示单词频率
    cout << "\n单词频率统计:\n";
    for (si = wordset.begin(); si != wordset.end(); si++)
        cout << *si << ": " << wordmap[*si] << "次" << endl;
}

void valvect(){
    // 使用vector容器 - 通用序列容器
    vector<double> data;
    double temp;
    
    cout << "输入数字（<=0 退出）:\n";
    // 读取用户输入的数字，直到输入<=0的数
    while (cin >> temp && temp > 0)
        data.push_back(temp);  // 将输入的数字添加到vector末尾
    
    // 对vector进行排序
    sort(data.begin(), data.end());
    int size = data.size();
    
    cout << "Vector内容:\n";
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
    
    // 使用valarray（数值数组）- 专门用于数值计算
    valarray<double> numbers(size);
    int i;
    // 将vector中的数据复制到valarray中
    for (i = 0; i < size; i++)
        numbers[i] = data[i];
    
    cout << "Valarray内容:\n";
    for (i = 0; i < size; i++)
        cout << numbers[i] << " ";
    cout << endl;
    
    // valarray的数学运算 - 可以对整个数组进行操作
    numbers = numbers + 10;  // 每个元素加10
    
    cout << "每个元素加10后:\n";
    for (i = 0; i < size; i++)
        cout << numbers[i] << " ";
    cout << endl;
    
    // 更多valarray操作
    numbers = numbers * 2.0;  // 每个元素乘以2
    
    cout << "乘以2后:\n";
    for (i = 0; i < size; i++)
        cout << numbers[i] << " ";
    cout << endl;
    
    // 计算valarray的总和
    cout << "Valarray总和: " << numbers.sum() << endl;
    
    // 计算valarray的大小
    cout << "Valarray大小: " << numbers.size() << endl;
    
    // 找到最大和最小值
    cout << "最大值: " << numbers.max() << endl;
    cout << "最小值: " << numbers.min() << endl;
    
    // 应用数学函数 - 对整个数组应用数学函数
    numbers = sqrt(numbers);  // 对每个元素求平方根
    
    cout << "求平方根后:\n";
    for (i = 0; i < size; i++)
        cout << numbers[i] << " ";
    cout << endl;
    
    // 使用slice（切片） - valarray的特殊功能
    if (size >= 3) {
        // 创建一个切片：从索引1开始，取2个元素，步长为1
        valarray<double> slice_array = numbers[slice(1, 2, 1)];
        cout << "从索引1开始的切片（2个元素）:\n";
        for (i = 0; i < slice_array.size(); i++)
            cout << slice_array[i] << " ";
        cout << endl;
    }

    
    cout << "=== 矩阵运算演示 ===" << endl;

    const int R = 3, C = 3;
    valarray<double> A(R * C), B(R * C);

    // 填充 A = [1..9], B = 单位矩阵
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j) {
            A[i * C + j] = i * C + j + 1;
            B[i * C + j] = (i == j) ? 1.0 : 0.0;
        }

    auto printMat = [&](const valarray<double>& M, int rows, int cols, const string& name) {
        cout << name << " (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << M[i * cols + j] << "\t";
            cout << "\n";
        }
        cout << endl;
    };

    printMat(A, R, C, "A");
    printMat(B, R, C, "B (identity)");

    // 标量与逐元素运算
    valarray<double> A_plus_B = A + B;      // 元素加
    valarray<double> A_times2 = A * 2.0;    // 标量乘
    valarray<double> A_ele_mul = A * A;     // 元素乘（逐元素平方）

    printMat(A_plus_B, R, C, "A + B");
    printMat(A_times2, R, C, "A * 2");
    printMat(A_ele_mul, R, C, "A element-wise * A");

    // 转置（生成新 valarray）
    valarray<double> At(R * C);
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            At[j * R + i] = A[i * C + j]; // 注意行列交换
    printMat(At, C, R, "A^T");

    // 矩阵乘法（经典三重循环）: C = A * B
    valarray<double> Cmat(R * C);
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            double s = 0.0;
            for (int k = 0; k < C; ++k)
                s += A[i * C + k] * B[k * C + j];
            Cmat[i * C + j] = s;
        }
    }
    printMat(Cmat, R, C, "A * B");

    // 使用 slice 提取列（示例：提取第1列）
    valarray<double> col1 = A[slice(1, R, C)]; // start=1, count=R, stride=C
    cout << "A 第1列 (slice): ";
    for (size_t i = 0; i < col1.size(); ++i) cout << col1[i] << " ";
    cout << "\n\n";

    // 行向量与列向量的点积示例（行0 与 列0）
    double dot = 0.0;
    for (int k = 0; k < C; ++k)
        dot += A[0 * C + k] * A[k * C + 0];
    cout << "A 第一行 与 A 第一列 的点积: " << dot << "\n\n";

    cout << "=== 演示结束 ===" << endl;
}

typedef std::valarray<int> vint;  // 简化类型声明
// 显示valarray内容的函数
void show(const vint & v, int cols)
{
    using std::cout;
    using std::endl;
    
    int size = v.size();
    for (int i = 0; i < size; ++i)
    {
        cout.width(4);  // 设置输出宽度为4个字符，使数字对齐
        cout << v[i];   // 输出当前元素
        
        // 判断是否需要换行：每cols个元素换行
        if ((i + 1) % cols == 0)
            cout << endl;
        else
            cout << ' ';  // 元素间用空格分隔
    }
    
    // 如果最后一行不完整，添加换行
    if (size % cols != 0)
        cout << endl;
}


void vslice(){
    const int SIZE = 12;
    // 创建包含12个元素的valarray
    vint valint(SIZE);
    
    // 初始化随机数种子（实际程序中应该使用srand，但这里为简单起见直接赋值）
    // 为了可重现的结果，我们不使用随机数，而是使用固定模式
    for (int i = 0; i < SIZE; ++i)
        valint[i] = i + 1;  // 填充1-12，便于观察切片效果
    
    cout << "原始数组 (按3列显示，模拟3x4矩阵):\n";
    show(valint, 3);  // 按3列显示，模拟3列4行的矩阵
    
    // ========== 切片演示 ==========
    
    // slice构造函数: slice(起始索引, 元素数量, 步长)
    
    // 提取第0列: 从索引0开始，取4个元素，步长为3
    // 对应矩阵中的: [0, 3, 6, 9] 位置
    vint vcol = valint[slice(0, 4, 3)];
    cout << "\n第0列 (索引0,3,6,9):\n";
    show(vcol, 1);  // 按1列显示
    
    // 提取第1列: 从索引1开始，取4个元素，步长为3  
    // 对应矩阵中的: [1, 4, 7, 10] 位置
    vcol = valint[slice(1, 4, 3)];
    cout << "第1列 (索引1,4,7,10):\n";
    show(vcol, 1);
    
    // 提取第2列: 从索引2开始，取4个元素，步长为3
    // 对应矩阵中的: [2, 5, 8, 11] 位置
    vcol = valint[slice(2, 4, 3)];
    cout << "第2列 (索引2,5,8,11):\n";
    show(vcol, 1);
    
    // 提取第2行: 从索引6开始，取3个元素，步长为1
    // 对应矩阵中的: [6, 7, 8] 位置
    cout << "第2行 (索引6,7,8):\n";
    vint vrow = valint[slice(6, 3, 1)];
    show(vrow, 3);
    
    // ========== 切片赋值操作 ==========
    
    cout << "\n=== 切片赋值操作 ===\n";
    
    // 将第1列所有元素设为10
    cout << "将第1列所有元素设为10:\n";
    valint[slice(1, 4, 3)] = 10;
    show(valint, 3);
    
    // 使用另一个valarray为切片赋值
    cout << "将第0列设为新值[100, 101, 102, 103]:\n";
    vint new_values(4);
    for (int i = 0; i < 4; i++)
        new_values[i] = 100 + i;
    valint[slice(0, 4, 3)] = new_values;
    show(valint, 3);
    
    // 使用表达式为切片赋值
    cout << "将第2列设为第0列的两倍:\n";
    valint[slice(2, 4, 3)] = vint(valint[slice(0, 4, 3)]) * 2;
    show(valint, 3);
    
    // ========== 更多切片示例 ==========
    
    cout << "\n=== 更多切片示例 ===\n";
    
    // 重置数组为1-12
    for (int i = 0; i < SIZE; ++i)
        valint[i] = i + 1;
    
    cout << "重置后的数组:\n";
    show(valint, 3);
    
    // 提取对角线: [0, 4, 8] - 3x3矩阵的主对角线
    cout << "主对角线 [0,4,8]:\n";
    vint diagonal = valint[slice(0, 3, 4)];  // 从0开始，取3个，步长4
    show(diagonal, 1);
    
    // 提取副对角线: [2, 4, 6] - 3x3矩阵的副对角线
    cout << "副对角线 [2,4,6]:\n";
    vint anti_diagonal = valint[slice(2, 3, 2)];  // 从2开始，取3个，步长2
    show(anti_diagonal, 1);
}

#include <initializer_list>
// 计算初始化列表中所有元素的和
double sum(initializer_list<double> il)
{
    double tot = 0;
    // 方法1: 使用迭代器遍历
    for (auto p = il.begin(); p != il.end(); p++)
        tot += *p;
    return tot;
}

// 计算初始化列表中所有元素的平均值
double average(const initializer_list<double> & ril)
{
    // 如果列表为空，返回0避免除以0
    if (ril.size() == 0)
        return 0.0;
        
    double tot = 0;
    // 方法2: 使用范围for循环 (C++11)
    for (auto elem : ril)
        tot += elem;
    return tot / ril.size();
}

void ilist(){
    cout << "=== 初始化列表演示 ===\n" << endl;
    
    // 方法1: 直接使用花括号列表作为参数
    cout << "列表1 {2, 3, 4}: 总和 = " << sum({2, 3, 4})
         << ", 平均值 = " << average({2, 3, 4}) << '\n';
    
    // 方法2: 创建initializer_list变量
    initializer_list<double> dl = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << "列表2 {1.1, 2.2, 3.3, 4.4, 5.5}: 总和 = " << sum(dl)
         << ", 平均值 = " << average(dl) << '\n';
    
    // 方法3: 重新赋值给initializer_list变量
    dl = {16.0, 25.0, 36.0, 40.0, 64.0};
    cout << "列表3 {16.0, 25.0, 36.0, 40.0, 64.0}: 总和 = " << sum(dl)
         << ", 平均值 = " << average(dl) << endl;
    
    // 更多示例
    cout << "\n=== 更多示例 ===\n";
    
    // 空列表
    cout << "空列表: 总和 = " << sum({}) 
         << ", 平均值 = " << average({}) << '\n';
    
    // 单个元素列表
    cout << "单元素列表 {42.5}: 总和 = " << sum({42.5})
         << ", 平均值 = " << average({42.5}) << '\n';
    
    // 较大列表
    cout << "较大列表 {1,2,3,4,5,6,7,8,9,10}: 总和 = " 
         << sum({1,2,3,4,5,6,7,8,9,10})
         << ", 平均值 = " << average({1,2,3,4,5,6,7,8,9,10}) << endl;   
}