#include<stdio.h>

int main()
{
	// 字符串常量是一个常量的数组，可以读取字符或者字符串，但不能修改！！！
	char* arr = "Hello world"; // 这是一个字符串的常量
	printf("%s\n", arr);

	char* p = arr;
	*p = 'A'; // 在这里会宕掉，因为不能修改常量区的内容！
	p[0] = 'A';

	*p = "Hello world"; // 换汤不换药，并没有改变 p 指向的地址！
	*p = 'B'; // 同样会宕掉
	p[0] = 'B';
}