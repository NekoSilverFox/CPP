# 一. 流

## 1.1 std
- **`std::getline(输入流，string，终止符[可选])   `** 

  从输入流中获取一整行，可以是单个普通字符、**空字符、制表符**和**换行符**

  ```cpp
    std::string str;
    std::getline(std::cin, str);	// 将输入流作为参数传入
    std::getline(std::cin, str, ',');	// 最后一个参数是终止字符，即读取到这个字符后结束
  ```

- **`std::ws`**

  剔除流中的**空字符、制表符**和**换行符**，直到匹配到非空字符

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

> 输入和输出流都能够作为参数传递，除了在 main 函数（主进程中），其他的函数中的输入输出流都应该作为参数传入，而不应该直接使用 `std::cin` 或者 `std::cout` ，因为在引发异常时主线程必须能够将子线程中的流覆盖

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



Q：什么是STL

A：STL - Standard Template Library - 标准模板库



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

## 2.3 容器的基本使用

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

