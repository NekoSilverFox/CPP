# C++ 体系结构和内核分析

[toc]

# 一. 流

## 1.1 std
- **`std::getline(输入流，string，终止符[可选])   `** 

  从输入流中获取一整行，可以是单个普通字符、**空字符、制表符**和**换行符**

  ```cpp
    std::string str;
    std::getline(std::cin, str);	// 将输入流作为参数传入
    std::getline(std::cin, str, ',');	// 最后一个参数是终止字符，即读取到这个字符后结束
  ```

- **`std::skipws`** 和 **`std::noskipws`**

  定义于头文件 `<ios>`

  启用或禁用有格式输入函数所做的跳过前导空白符**（默认启用）**。在输出上无效果。
  
  1) 如同用调用 `str.setf([std::ios_base::skipws] ` **启用**流 `str` 中的 `skipws` 标志
  
  2) 如同用调用 `str.unsetf([std::ios_base::skipws]` **禁用**流 `str` 中的 `skipws` 标志**(会对整个流生效知道使用 `std::skipws` 取消)**
  
  ```cpp
  #include <iostream>
  #include <sstream>
  int main()
  {
      char c1, c2, c3;
      std::istringstream("a b c") >> c1 >> c2 >> c3;
      std::cout << "Default  behavior: c1 = " << c1 << " c2 = " << c2 << " c3 = " << c3 << '\n';
    std::istringstream("a b c") >> std::noskipws >> c1 >> c2 >> c3;
      std::cout << "noskipws behavior: c1 = " << c1 << " c2 = " << c2 << " c3 = " << c3 << '\n';
  }
  =================================================================
  输出：
  Default  behavior: c1 = a c2 = b c3 = c
  noskipws behavior: c1 = a c2 =   c3 = b
  ```
  
  
  
- **`std::ws`**

  剔除流中的**空字符、制表符**和**换行符**，直到匹配到非空字符，可使用 **`std::noskipws`** 将此禁用

  ```cpp
  int main()
  {
      std::string str;
      std::cin >> std::ws >> str;	// 剔除str前面的所有空字符，当然在这里不用也行
      
      // 读取一串数字中的一个字母（使用空格分隔）
      // 比如：>>>    16468   f     23541
      int num1 = 0;
      int num2 = 0;
      char c_sign = '\0';
      std::cin >> std::ws >> num1 >> std::ws >>  c_sign >> std::ws >> num2;
  }
  ```

  

## 1.2 iostream

### 1.2.1 常用函数

**所有流中未处理或读取的字符都会在缓冲区等待**

头文件：`#include <iostream>`

> **输入和输出流都能够作为参数传递，除了在 main 函数（主进程中），其他的函数中的输入输出流都应该作为参数传入，而不应该直接使用 `std::cin` 或者 `std::cout` ，因为在引发异常时主线程必须能够将子线程中的流覆盖**

比如：

```cpp
#include <iostream>

// 在函数中 istr 和 ostr 可以像 std::cin 和 std::cout 一样自由使用
void foo(int num, istream& istr, ostream& ostr)
{
    ostr << "Please input one number: ";
    istr >> num;
    
    if (!istr.good() || !ostr.good())
    {
        // 抛出异常
	}
}

int main(int args, char * argv[])
{
    int num;
    
    // 将 std::cin 和 std::cout 从 main 函数中作为参数传入
    foo(num, std::cin, std::cout);
}
```

- **`std::cin <<`** 

  输入时自动跳过前置**空字符**及**空行**
  
- **`std::cin.get()`**	

  从输入流中获取一个字符，这个字符可以是普通字符、**空字符、制表符**和**换行符**
  
- **`std::cin.peek()`**    

  查看输入流中的下一个字符，但是不读取，这个字符可以是普通字符、**空字符、制表符**和**换行符**
  
  ```cpp
  // 从输入流中读取一个字符，如果是字母 A 则读取读取并输出，如果不是则返回
  void foo(istream& istr, ostream& ostr)
  {
      char c_sign = '\0';
      if (istr.peek() == 'A')
      {
          ostr << istr.get();
      }
  }
  ```

- **`std::cin.ignore`**
  - `std::cin.ignore()`

    从输入流中忽略一个字符

  - `std::cin.ignore(num, 终止字符)`

    跳过输入流中n个字符，或在遇到指定的终止字符时提前结束（此时跳过包括终止字符在内的若干字符）

  - `std::cin.ignore(numeric_limits<std::streamsize>::max(), ‘\n’)`

    清除当前行

  - `std::cin.ignore(numeric_limits<std::streamsize>::max())` 

    清除 cin 里所有内容

  - `ignore(std::numeric_limits<std::streamsize>::max(), ',')`

    忽略逗号前面的所有内容

---

### 1.2.1 流状态标志

> std::ios_base::iostate
>
> https://zh.cppreference.com/w/cpp/io/ios_base/iostate

​    

- **`goodbit`**无错误

- **`badbit`**不可恢复的流错误

- **`failbit`**输入/输出操作失败（格式化或提取错误）

- **`eofbit`**关联的输出序列已抵达文件尾

相关函数：

- **`std::cin.fail()`**

  输入/输出操作失败（格式化或提取错误）。比如 `int` 类型的却读取了一个 `char`

- **`std::cin.good()`** 

  输入流无错误

- **`std::cin.setstate(std::istream::failbit)`**

  将输入流设置为 `failbit`，也可以是上面其他的 **`goodbit`**，**`badbit`**，**`eofbit`**

---

## 1.3 string stream

### 1.3.1 常用方法

例如：

将 std::cin 输入流中的内容导入到一个 stringstream 中，再处理这个 stringstream 而不是处理 std::cin 流

```cpp
int main()
{
  std::string str_line;
  std::getline(std::cin, str_line);
  std::stringstream str_stream(str_line);

  int num;
  str_stream >> num;	// 会像 std::cin 一样自动互忽略流中的空字符
}
```

---

# 二. C++标准库

> 重要的网站：
>
> www.cplusplus.com
>
> www.en.cppreference.com/w/
>
> www.gcc.gnu.org

## 2.1 前置知识

Q: 什么是`泛型编程`？

A: 所谓泛型编程，就是使用`template（模板）`为主要工具来编程，STL就是泛型编程最成功的作品

---

Q：什么是STL

A：STL - Standard Template Library - 标准模板库

---

标准库以头文件的形式呈现，而不是编译好的，所以直接看到源代码

- C++的标准库的头文件不带拓展名`.h`，例如 `#include <vector>`
- 新的C文件也不带`.h`了，例如 `#include <cstdio>`
- 新的头文件里的组件都被封装在了 `namespace std`
  - `using namespace std`
  - `using std::cout`
-  旧的头文件中的组件**没有**封装在 `namespace std`



STL六大部件（Components）：

- 容器（Containers）
- 分配器（Allocators） - 为容器分配内存
- 算法（Algorithms）
- 迭代器（Iterators） - 类似于一个泛化指针
- 适配器（Adapters）
- 仿函数（Functors）

![image-20201205185708070](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201205185708070.png)

实例程序：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	int arr[6] = { 21, 210, 100, 40, 56, 6 };
    //    ↓container      ↓allocator
    std::vector<int, allocator<int> > vec(arr, arr + 6);
    
    //           ↓algorithm     ↓iterator↓        ↓function adapter(negator)
    std::cout << count_if(vec.begin(), vec.end(), not1(bind2nd(less<int>(), 40)));
    //                                            function object↑
    // 整个 not1(bind2nd(less<int>(), 40)) 是一个 谓词（predicate）
    return 0;
}
```

## 2.2 算法复杂度

1. O(1) or O(N)：常数时间（constant time）
2. O(N)：线性时间（linear time）
3. O(log2N)：二次线性时间（sub-liner time）
4. O(N^2)：平方时间（quadratic time）
5. O(N^3)：立方时间（cubic time）
6. O(2^N)：指数时间（exponential time）
7. O(Nlog2N)：介于线性及二次方的中间行为模式

# 三. 容器

## 3.1 容器的基本使用

- **前闭后开 [ )**

  `.begin()` 指向容器中的第一个元素

  `.end()` 指向容器所有元素的下一个元素（不是容器的一部分）

  ```cpp
  Container<T> c;
  ...
  Container<T>::iterator it = c.begin();
  for ( ; it < c.end(), ++it)
  {
      ...
  }
  ```

- C++ 11 新的迭代方法

  **range-based `for` statement**

  ```cpp
  for ( 声明 : 容器 )
  {
      ...
  }
  ```

  ```cpp
  for ( int i : { 21, 210, 100, 40, 56, 6 })
  {
      std::cout << i << endl;
  }
  ```

  ```cpp
  std::vector<double> vec;
  ...
  for (auto elem : vec) // 在这里 auto 自动适配为 std::vector<double>::iterator
  {
  	std::cout << elem << std::endl; 
  }
  
  for (auto& elem : vec)
  {
      elem *= 3;
  }
  ```

- C++11 `auto` 关键字

  `auto` 为C++中的自动类型推导

  例如**以往**的代码这么写：

  ```cpp
  list<string> c;
  ...
  list<string>::iterator it;
  it = ::find(c.begin(), c.end(), target);
  ```

  **如今可以更改为**

  ```cpp
  list<string> c;
  ...
  // 自动适配为 list<string>::iterator it
  auto it = ::find(c.begin(), c.end(), target);
  ```

  

- 容器不一定是连续的空间

## 3.2 容器的基本分类

![ ](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201206151434712.png)

- `map`和`set`的底层都是使用红黑树实现
  - `map`中单个节点包含 `key`和`value`，之后使用`key`找`value`
  - `set` 的`key`和`value`是不分的，是一个东西
- 容器中带有**`multi`** 的代表元素可以重复**（multi - 代表多）**，比如：`multiset`和`multimap`中的元素（`key`）可以重复
- 容器中带有**`unordered`** 的代表底部使用了**哈希表**
- **所有的容器中，所有模板都有第二个参数 （vector<参数一，参数二>），第二个参数是一个`分配器`**。如果不填写第二个参数，则使用默认的分配器

---

### 3.2.1 array

![image-20201215185545057](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201215185545057.png)

头文件：`<array>`

初始化：`array<类型, 数组大小> arr;`

方法：

- `arr.size()` 返回数组的大小
- `arr.front() ` 第一个元素的内容
- `arr.back()` 最后一个元素的内容
- `arr.data()` 第一个元素的**地址**

---

### 3.2.2 vector

![image-20201215190852597](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201215190852597.png)

描述：**一端**开口的容器，会自动为容器提前分配空间（大约是1.5倍）。**容器的大小/容量始终大于或等于容器中元素的个数**。注意，这个容器“成长”的过程是缓慢的，因为要在另一个区域重新开辟一块内存，然后将当前内存中的**所有**元素一一拷贝过去

头文件：`<vector>`

初始化：`std::vector<类型> vec;`

方法：

- `vec.push_back()` 将元素从尾部放入
- `vec.size()` 容器中真正的元素个数
- `vec.capacity()` 容器的大小
- `vec.front()` 返回容器中的第一个元素
- `vec.back()` 返回容器中最后一个元素
- `vec.data()` 容器的起始地址

---

### 3.2.3 list

![image-20201218091054364](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201218091054364.png)

描述：双向链表

头文件：`<list>`

初始化：`list<类型> l;`

方法：

- `l.size()` 返回双向链表的大小
- `l.max_size()` 返回双向链表的最大大小
- `l.push_frount` 头插
- `l.push_back` 尾插
- `l.pop_frount` 移除首元素
- `l.pop_back` 移除末元素
- `l.front() ` 返回双向链表中第一个元素的内容
- `l.back()` 返回双向链表中最后一个元素的内容
- **`l.sort()` list 自己提供的排序算法**

---

### 3.2.4 forward_list

![image-20201218210703251](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201218210703251.png)

描述：单向链表

头文件：`<forward_list>`

初始化：`list<类型> f_l;`

方法：

- **无此方法：** *`f_l.size()`* 
- `f_l.max_size()` 返回单向链表的最大大小
- `l.push_frount` 头插
- `f_l.pop_frount` 移除首元素
- **无此方法：** *`l.push_back`*
- `f_l.front() ` 返回双向链表中第一个元素的内容
- **无此方法：** *`f_l.back()`* 
- **`f_l.sort()` forward_list 自己提供的排序算法**

---

### 3.2.5 slist

`slist` 是GUN标准下的（非标准库）一个单向链表，功能完全和标准库中的forward_list完全一样

---

### 3.2.6 deque

描述：duque是一个**双向开口，可进可出**的容器。duque在内存中并不是连续的，连续只是一个假象。duque是有许多内存段中组合而成，**一个内存段称为一个 `buffer`** 。术语上称为：**分段连续**

![image-20201218211839131](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201218211839131.png)

头文件：`<deque>`

初始化：`std::deque<类型> deq;`

方法：

- `deq.size()` 目前deque容器的大小
- `deq.max_size()` deque容器的最大大小
- `deq.resize(N)` 初始化N个元素到deque中
- `deq.at(N)` 返回第N个元素
- `deq.frount()` 返回首元素
- `deq.back()` 返回末元素
- `deq.pop_frount()` 移除首元素
- `deq.pop_back()` 移除末元素
- deque 没有提供自己的 sort

---

### 3.2.7 stack

![image-20201218221718925](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201218221718925.png)

描述：stack是栈 - **先进后出**。因为容器的特性，所以不提供 `iterator` 的操作

头文件：`<stack>`

初始化：`std::stack<类型> s;`

方法：

- `s.size()` 返回栈的大小
- `s.top()` 返回栈顶元素
- `s.push()` 将元素推入栈中
- `s.pop()` 将一个元素弹出栈

---

### 3.2.8 queue

![image-20201218222040350](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201218222040350.png)

描述：queue 是**队列**，**先进先出**。因为容器的特性，所以不提供 `iterator` 的操作

头文件：`<queue>`

初始化：`std::queue<类型> q;`

方法：

- `q.size()` 返回队列的大小
- `q.push()` 将元素推入栈中
- `q.front()` 返回队手元素
- `q.back()` 返回队尾元素
- `q.pop()` 将一个元素弹出栈

---

### 3.2.9 multiset

![image-20201219173103348](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201219173103348.png)

描述：小型的关联数据库，以**红黑树（高度平衡树）**形成的底层结构。**允许出现重复元素**

头文件：`<multiset>`

初始化：`multiset<类型> mul_set;`

方法：

- `mul_set.insert()` 插入一个元素
- `mul_set.size()` multiset 的大小
- `mul_set.max_size()` multiset 能容纳的最多元素
- `mul_set.find()` 查找一个元素，并返回一个迭代器

---

> set 和 map 的区别：
>
> set 容器的一个节点只能存储一个 **value**，
>
> map 可以的一个节点可以存储**一个 key 和一个 value，并通过 key 来查找 value**

---

### 3.2.10 multimap

![image-20201219182902723](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201219182902723.png)

描述：底层是一个红黑树,**第一个参数是key，第二个参数是value**。multimap 不能使用 [] 做 insertion

头文件：`<multimap>`

**初始化：`multimap<key的类型，value的类型> mul_map;`**

方法：

- `mul_map.insert()` 插入一个元素
- **`mul_map.insert(std::pair<key的类型，value的类型>(key值，value值))` 插入一个元素**
- `mul_map.size()` multimap 的大小
- `mul_map.max_size()` multimap 能容纳的最多元素
- `mul_map.find()` 查找一个元素，并返回一个迭代器

---

### 3.2.11 unordered_multiset

![image-20201219182923279](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201219182923279.png)

描述：是一个关联式容器，**底层是一个哈希表**

头文件：`<unordered_multiset>`

初始化：`unordered_multiset<类型> unor_mul_set;`

方法：

- `unor_mul_set.insert()` 插入一个元素
- `unor_mul_set.size()` multiset 的大小
- `unor_mul_set.max_size()` multiset 能容纳的最多元素
- `unor_mul_set.bucker_count()` 因为底层是哈希表，所以此方法取得的是**当前哈希表中篮子的数量**，并且**篮子的数量一定比元素数量多**
- `unor_mul_set.max_bucker_count()` 因为底层是哈希表，所以此方法取得的是**哈希表中篮子的最大数量**
- `unor_mul_set.load_factor()` 载重因子
- `unor_mul_set.max_load_factor()` 最大载重因子（一定是1）
- `unor_mul_set.find()` 查找一个元素，并返回一个迭代器

---

### 3.2.12 unordered_multimap

![image-20201219182934958](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201219182934958.png)

描述：是一个关联式容器，底层是一个哈希表。multimap 不能使用 [] 做 insertion

头文件：`<unordered_multimap>`

**初始化：`unordered_multimap<key的类型，value的类型> unord_mul_map;`**

方法：

- `unord_mul_map.insert()` 插入一个元素
- **`unord_mul_map.insert(std::pair<key的类型，value的类型>(key值，value值))` 插入一个元素**
- `unord_mul_map.size()` multiset 的大小
- `unord_mul_map.max_size()` multiset 能容纳的最多元素
- `unord_mul_map.find()` 查找一个元素，并返回一个迭代器

---

### 3.2.13 set

![image-20201219185139673](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201219185139673.png)

描述：小型的关联数据库，以**红黑树（高度平衡树）**形成的底层结构。**不允许出现重复元素**

头文件：`<set>`

初始化：`set<类型> set;`

方法：

- `set.insert()` 插入一个元素
- `set.size()` set 的大小
- `set.max_size()` set 能容纳的最多元素
- `set.find()` 查找一个元素，并返回一个迭代器

---

### 3.2.14 map

![image-20201219185147583](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201219185147583.png)

描述：底层是一个红黑树，**key 不能重复，value 可以重复**

头文件：`<map>`

**初始化：`map<key的类型，value的类型> map;`**

方法：

- `map.insert()` 插入一个元素
- **`map.insert(std::pair<key的类型，value的类型>(key值，value值))` 插入一个元素**
- **`map[key] = value` 在 key 处插入一个 value ** 重点！！！！！
- `map.size()` map 的大小
- `map.max_size()` map 能容纳的最多元素
- `mul_map.find()` 查找一个元素，并返回一个迭代器

---

### 3.2.16 unordered_set

![image-20201219181928071](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201219181928071.png)

描述：**底层是哈希表支撑的 set 容器**

头文件：`<unordered_set>`

初始化：`unordered_set<类型> unord_set;`

方法：

- `unord_set.insert()` 插入一个元素
- `unord_set.size()` set 的大小
- `unord_set.max_size()` set 能容纳的最多元素
- `unor_set.bucker_count()` 因为底层是哈希表，所以此方法取得的是**当前哈希表中篮子的数量**，并且**篮子的数量一定比元素数量多**
- `unor_set.max_bucker_count()` 因为底层是哈希表，所以此方法取得的是**哈希表中篮子的最大数量**
- `unor_set.load_factor()` 载重因子
- `unor_set.max_load_factor()` 最大载重因子（一定是1）
- `set.find()` 查找一个元素，并返回一个迭代器

---

### 3.2.15 unordered_map

![image-20201219182440457](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201219182440457.png)

描述：**底层是哈希表支撑的 map 容器**

头文件：`<unordered_map>`

**初始化：`unordered_map<key的类型，value的类型> unord_map;`**

方法：

- `unord_map.insert()` 插入一个元素
- **`unord_map.insert(std::pair<key的类型，value的类型>(key值，value值))` 插入一个元素**
- **`unord_map[key] = value` 在 key 处插入一个 value ** 重点！！！！！
- `unord_map.size()` map 的大小
- `unord_map.max_size()` map 能容纳的最多元素
- `unord_map.find()` 查找一个元素，并返回一个迭代器

---

# 四. 分配器 - allocator

## 4.1 基本说明

分配器支持了容器对内存的使用

![image-20201219185923398](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201219185923398.png)

![image-20201220204737370](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201220204737370.png)

## 4.2 基本使用

头文件 `<memory>` 里包含了 allocator

但是如果使用 std::allocator 以外的 allocator，需要自行 `#include <ext\...>`

注意：其他的分配器是在 **`__gnu_cxx::`** 下的

比如：

```cpp
#include <ext\array_allocator.h>
#include <ext\mt_allocator.h>
#include <ext\debug_allocator.h>
#include <ext\pool_allocator.h>		// 内存池
#include <ext\bitmap_allocator.h>
#include <ext\malloc_allocator.h>
#include <ext\new_allocator.h>

void test_list_with_special_allocator()
{
	list<std::string, allocator<std::string> > c1;
    list<std::string, __gnu_cxx::malloc_allocator<std::string> > c2;
    list<std::string, __gnu_cxx::new_allocator<std::string> > c3;
    list<std::string, __gnu_cxx::__pool_allocator<std::string> > c4;
    list<std::string, __gnu_cxx::__mt_allocator<std::string> > c5;
    list<std::string, __gnu_cxx::bitmap_allocator<std::string> > c6;
}
```

![image-20201220204913799](C:\Users\mi\AppData\Roaming\Typora\typora-user-images\image-20201220204913799.png)

**使用分配器分配并归还内存**

```cpp
int* p;		// 注意：p 是一个 int 类型的**指针**

allocator<int> alloc1;
p = alloc1.allocator(1);	// 1 代表申请一份内存
alloc1.deallocator(p, 1);	// 1 代表归还一份内存, p 代表归还的对象是谁。
							// 可以通过 new 和 delete 来理解

__gnu_cxx::malloc_allocator<int> alloc2;
p = alloc2.allocator(1);
alloc2.deallocate(p, 1);

__gnu_cxx::new_allocator<int> alloc3;
p = alloc3.allocator(1);
alloc3.allocator(p, 1);

__gnu_cxx::__pool_allocator<int> alloc4;
p = alloc4.allocator(1);
alloc4.allocator(p, 1);

__gnu_cxx::__mt_allocator<int> alloc5;
p = alloc5.allocator(1);
alloc5.allocator(p, 1);

__gnu_cxx::bitmap_allocator<int> alloc6;
p = alloc6.allocator(1);
alloc6.allocator(p, 1);
```



# 标准库算法

头文件：`<algorithm>`

功能：

复杂度：

定义：

描述：

返回值：

## 查找

### find

头文件：`<algorithm>`

功能：查找元素，循序查找法

复杂度：

定义：find(起始迭代器, 结束迭代器, 谓词)

描述：对容器内的元素进行**线性**查找

返回值：指向该元素的**迭代器**

### bsearch

头文件：`<algorithm>`

功能：二分查找（C标准库）

复杂度：

定义：bseach(谓词，容器起始地址，容器大小，单位元素大小);

描述：对容器内的元素进行**二分**查找，但是注意，**只能对有序容器进行查找**，所以说使用前要对容器进行排序

返回值：指向该元素的**迭代器**

## 排序

### sort

头文件：`<algorithm>`

功能：对容器进行排序

复杂度：*O(N·log(N))*

定义：sort(起始迭代器, 结束迭代器)

描述：默认进行升序排序

返回值：

# 其他函数

## 程序终止

1. [`std::_Exit` ](http://en.cppreference.com/w/cpp/utility/program/_Exit)导致正常程序终止，仅此而已。
2. [`std::quick_exit` ](http://en.cppreference.com/w/cpp/utility/program/quick_exit)导致正常程序终止并调用[ `std::at_quick_exit` ](http://en.cppreference.com/w/cpp/utility/program/at_quick_exit)处理程序，不执行其他任何清除操作。
3. [`std::exit` ](http://en.cppreference.com/w/cpp/utility/program/exit)导致正常程序终止，然后调用[ `std::atexit` ](http://en.cppreference.com/w/cpp/utility/program/atexit)处理程序。执行其他类型的清除，例如调用静态对象析构函数。
4. [`std::abort` ](http://en.cppreference.com/w/cpp/utility/program/abort)导致程序异常终止，不执行任何清理。如果程序以非常非常意外的方式终止，则应调用此方法。它只会通知操作系统有关异常终止的任何信息。在这种情况下，某些系统会执行核心转储。
5. [`std::terminate` ](http://en.cppreference.com/w/cpp/error/terminate)调用[ `std::terminate_handler` ](http://en.cppreference.com/w/cpp/error/terminate_handler)，默认情况下调用[ `std::abort` ](http://en.cppreference.com/w/cpp/utility/program/abort)。

### std::abort

定义于头文件 `<cstdlib> ` - void abort();

导致不正常程序终止，除非传递给 [std::signal](https://zh.cppreference.com/w/cpp/utility/program/signal) 的信号处理函数正在捕捉 [SIGABRT](https://zh.cppreference.com/w/cpp/utility/program/SIG_types) ，且该处理函数不返回。

不调用拥有自动、线程局域 (C++11 起)和静态[存储期](https://zh.cppreference.com/w/cpp/language/storage_duration)的对象的析构函数。亦不调用以 [std::atexit()](https://zh.cppreference.com/w/cpp/utility/program/atexit) 和 [std::at_quick_exit](https://zh.cppreference.com/w/cpp/utility/program/at_quick_exit) (C++11 起) 注册的函数。是否关闭打开的资源，例如文件是实现定义的。返回给宿主环境指示不成功执行的实现定义状态。