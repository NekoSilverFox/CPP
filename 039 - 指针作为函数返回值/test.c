#include <iostream.h>


char* test01()
{
	char arr[] = "Hello world"; // 字符数组，创建在栈区

	return arr;


	// 字符串常量，程序运行时会在 常量区 ，但只能读取，不能修改
	char* arr = "Hello world"; // C++ 中不可以
}

int main()
{

}