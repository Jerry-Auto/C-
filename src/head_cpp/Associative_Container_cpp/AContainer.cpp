#include "AContainer.h"
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include<algorithm>
using namespace std;

void setExample() {
    const int N = 6;
    string s1[N] = {"buffoon", "thinkers", "for", "heavy", "can", "for"};
    string s2[N] = {"metal", "any", "food", "elegant", "deliver","for"};
    
    set<string> A(s1, s1 + N);
    set<string> B(s2, s2 + N);
    
    ostream_iterator<string, char> out(cout, " ");
    
    cout << "集合 A: ";
    copy(A.begin(), A.end(), out);
    cout << endl;
    
    cout << "集合 B: ";
    copy(B.begin(), B.end(), out);
    cout << endl;
    
    cout << "A 和 B 的并集:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;
    
    cout << "A 和 B 的交集:\n";
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;
    
    cout << "A 和 B 的差集 (A - B):\n";
    set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;
    
    set<string> C;
    cout << "集合 C:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(),
              insert_iterator<set<string> >(C, C.begin()));
    copy(C.begin(), C.end(), out);
    cout << endl;
    
    string s3("grungy");
    C.insert(s3);
    cout << "插入元素后的集合 C:\n";
    copy(C.begin(), C.end(), out);
    cout << endl;
    
    cout << "显示特定范围内的元素:\n";
    copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
    cout << endl;
}



void multisetExample() {
    std::multiset<int> numbers;
    
    // 插入重复元素
    numbers.insert(10);
    numbers.insert(20);
    numbers.insert(10);
    numbers.insert(30);
    numbers.insert(10);
    
    // 遍历多重集合
    std::cout << "Multiset elements: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // 统计元素出现次数
    std::cout << "Number 10 appears " << numbers.count(10) << " times" << std::endl;
    
    // 查找所有等于10的元素
    auto range = numbers.equal_range(10);
    std::cout << "All 10s: ";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


void mapExample() {
    std::map<std::string, int> studentScores;
    
    // 插入键值对
    studentScores["Alice"] = 95;
    studentScores["Bob"] = 87;
    studentScores["Charlie"] = 92;
    studentScores.insert({"David", 78});
    
    // 遍历映射
    std::cout << "Student scores:" << std::endl;
    for (const auto& pair : studentScores) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
    // 查找和访问元素
    auto it = studentScores.find("Alice");
    if (it != studentScores.end()) {
        std::cout << "Alice's score: " << it->second << std::endl;
    }
    
    // 使用下标操作符（如果键不存在会创建）
    std::cout << "Bob's score: " << studentScores["Bob"] << std::endl;
    
    // 检查键是否存在
    if (studentScores.count("Eve") == 0) {
        std::cout << "Eve not found in the map" << std::endl;
    }
}



typedef int KeyType;
typedef std::pair<const KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;
void multimapExample() {   
    MapCode codes;
    
    // 插入地区码和城市名的键值对
    codes.insert(Pair(415, "旧金山"));
    codes.insert(Pair(510, "奥克兰"));
    codes.insert(Pair(718, "布鲁克林"));
    codes.insert(Pair(718, "斯塔滕岛"));
    codes.insert(Pair(415, "圣拉斐尔"));
    codes.insert(Pair(510, "伯克利"));
    
    cout << "区号为415的城市数量: "
         << codes.count(415) << endl;
    cout << "区号为718的城市数量: "
         << codes.count(718) << endl;
    cout << "区号为510的城市数量: "
         << codes.count(510) << endl;
    
    cout << "区号   城市\n";
    MapCode::iterator it;
    for (it = codes.begin(); it != codes.end(); ++it)
        cout << "   " << (*it).first << "     "
             << (*it).second << endl;
    
    // 查找特定区号的所有城市
    pair<MapCode::iterator, MapCode::iterator> range 
        = codes.equal_range(718);
    
    cout << "区号为718的城市:\n";
    for (it = range.first; it != range.second; ++it)
        cout << (*it).second << endl;
}

void unorderd_set(){
    unordered_set<string> words;
    
    // 插入元素
    words.insert("apple");
    words.insert("banana");
    words.insert("cherry");
    words.insert("apple");  // 重复元素不会被插入
    
    cout << "无序集合元素: ";
    for (const auto& word : words) {
        cout << word << " ";
    }
    cout << endl;
    
    cout << "桶数量: " << words.bucket_count() << endl;
    cout << "负载因子: " << words.load_factor() << endl;
    
    // 查找元素
    auto it = words.find("banana");
    if (it != words.end()) {
        cout << "找到: " << *it << endl;
    }
}

void unordered_multiset_demo(){
    unordered_multiset<int> numbers;
    
    // 插入重复元素
    numbers.insert(10);
    numbers.insert(20);
    numbers.insert(10);
    numbers.insert(30);
    numbers.insert(10);
    
    cout << "无序多重集合元素: ";
    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "数字10出现的次数: " << numbers.count(10) << endl;
    
    // 显示哈希特性
    cout << "哈希统计:" << endl;
    for (int i = 0; i < numbers.bucket_count(); ++i) {
        cout << "桶 " << i << " 有 " << numbers.bucket_size(i) << " 个元素" << endl;
    }
}

void unordered_map_demo(){
    unordered_map<int, string> areaCodes;
    
    // 插入区号和城市
    areaCodes[415] = "旧金山";
    areaCodes[510] = "奥克兰"; 
    areaCodes[718] = "布鲁克林";
    areaCodes[212] = "曼哈顿";
    areaCodes[312] = "芝加哥";
    
    cout << "无序映射内容:" << endl;
    for (const auto& pair : areaCodes) {
        cout << "区号 " << pair.first << ": " << pair.second << endl;
    }
    
    // 查找操作
    int code = 415;
    auto found = areaCodes.find(code);
    if (found != areaCodes.end()) {
        cout << "区号 " << code << " 对应的城市是: " << found->second << endl;
    }
    
    // 显示哈希表信息
    cout << "\n哈希表统计信息:" << endl;
    cout << "元素数量: " << areaCodes.size() << endl;
    cout << "桶数量: " << areaCodes.bucket_count() << endl;
    cout << "负载因子: " << areaCodes.load_factor() << endl;
    cout << "最大负载因子: " << areaCodes.max_load_factor() << endl;
}

typedef std::unordered_multimap<int, std::string> AreaMap;
void unordered_multimap_demo(){
    AreaMap areaCodes;
    
    // 插入重复键的值
    areaCodes.insert({415, "旧金山"});
    areaCodes.insert({510, "奥克兰"});
    areaCodes.insert({718, "布鲁克林"});
    areaCodes.insert({718, "斯塔滕岛"});
    areaCodes.insert({415, "圣拉斐尔"});
    areaCodes.insert({510, "伯克利"});
    
    cout << "无序多重映射中的所有城市:" << endl;
    for (const auto& pair : areaCodes) {
        cout << "区号 " << pair.first << ": " << pair.second << endl;
    }
    
    // 统计特定区号的城市数量
    cout << "\n统计信息:" << endl;
    cout << "区号415的城市数量: " << areaCodes.count(415) << endl;
    cout << "区号718的城市数量: " << areaCodes.count(718) << endl;
    cout << "区号510的城市数量: " << areaCodes.count(510) << endl;
    
    // 查找特定区号的所有城市
    cout << "\n区号718的所有城市:" << endl;
    auto range = areaCodes.equal_range(718);
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->second << endl;
    }
}