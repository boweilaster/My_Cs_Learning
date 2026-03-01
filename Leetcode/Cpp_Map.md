## unordered_map 核心语法

### 1.引用和初始化
#include <unordered_map>
#include <string>

// 语法：std::unordered_map<Key的数据类型, Value的数据类型> 变量名;

* std::unordered_map<int, int> numMap;       // 常用于：数字映射下标

* std::unordered_map<std::string, int> dict; // 常用于：统计字符串出现次数

### 2.增和改
// 1. 新增元素：如果 Key 不存在，自动创建并赋值
* dict["apple"] = 5; 

// 2. 修改元素：如果 Key 已经存在，直接覆盖旧值
* dict["apple"] = 10; 

// 3. 累加运算（面试统计频率时极常用！）
* ict["banana"]++; // 如果 banana 不存在，默认为0，然后加1变成1

### 3.查
// 姿势一：使用 find() （最专业、最推荐）
// find() 返回一个迭代器，找不到就会返回 .end()
if (dict.find("apple") != dict.end()) {
    // 确定找到了，再用 [] 拿出来它的真实值
    int count = dict["apple"]; 
}

// 姿势二：使用 count() （新手快乐写法）
// 返回这个 Key 出现的次数，哈希表里只能是 1 (有) 或 0 (无)
if (dict.count("apple") > 0) {
    // 找到了！
}

### 4.删除

// 根据 Key 删除整个键值对
dict.erase("apple");

### 5.遍历

// kv 代表 key-value pair（键值对）
for (auto& kv : dict) {
    // kv.first 是 Key，kv.second 是 Value
    std::cout << "键: " << kv.first << " 值: " << kv.second << "\n";
}