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

