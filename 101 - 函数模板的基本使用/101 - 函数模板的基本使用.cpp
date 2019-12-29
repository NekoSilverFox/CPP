#include<iostream>
using namespace std;

// 交换 int 类型 a 和 b 的数据
void mySwepInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 交换 char 类型 c 和 d 的数据
void mySwepChar(char& a, char& b)
{
	char temp = a;
	a = b;
	b = temp;
}

// =====================================================
//类型，逻辑又非常相似
//类型参数化  泛型编程 -- 模板技术
template<class T> // 告诉编译器 下面如果出现T不要报错，T是一个通用的类型
void mySwep(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

// =====================================================
template<class D> // 等价于 template<class T>
void mySwep2() {}
void mySwep3(){}  // 不是模板，紧挨着声明的才是？？？？
// =====================================================

int main()
{
	int a = 10;
	int b = 20;
	char c1 = 'c';
	mySwepInt(a, b);

	//1 自动类型推导,必须有参数类型才可以推导
	//mySwap(a, c1); 推导不出来T，所以不能运行
	mySwep(a, b);
	//2 显示指定类型
	mySwep<int>(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	char c = 'c';
	char d = 'd';
	mySwepChar(c, d);
	mySwep(a, b);
	cout << c << endl;
	cout << d << endl;


	//模板必须要指定出T才可以使用
	mySwep2();
	mySwep2<string>();

	mySwep3();
}