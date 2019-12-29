#include<iostream>
using namespace std;

// 如何去定义一个指向函数的指针
int myFun(int a, char b)
{
	cout << "===== void myFun(int a, char b) =====" << endl;
	return 0;
}

int main()
{
	// 1. 定义函数类型，通过类型来定义函数指针
	typedef int (Fun_TYPE)(int, char);

	Fun_TYPE* pFun = myFun;
	myFun(4, 'o');
	pFun(3, 'b'); // 系统给默认加 “*”了
	(*pFun)(3, 'v'); // 等效为 myFun(3, 'v');

	// 2. 直接定义函数指针类型
	typedef int(*Fun_p)(int, char);
	Fun_p pFun2 = myFun;
	pFun(12, 'l');

	// 函数指针要指向同类型！


	// 3. 直接定义函数指针变量 ★★
	// 函数指针其实  int(*)(参数列表)
	// 把指针转化为指针类型  int(*)(参数列表)
	int(*pFun3_)(int, char) = (int(*)(int, char))NULL;
	int(*pFun3)(int, char) = NULL;
	pFun3 = myFun;

	// 或者将 3 整合为一句话：
	int(*pFun4)(int, char) = myFun;

	pFun4(1, 'f');
}