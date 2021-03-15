#include <iostream>
using namespace std;

int fun01(int a, int b)
{
	cout << "fun01" << endl;
	return a + b;
}

int fun02(int a, int b)
{
	cout << "fun02" << endl;
	return a - b;
}

int fun03(int a, int b)
{
	cout << "fun03" << endl;
	return a * b;
}

//  函数作为另一函数的参数 ★★
int doLogic(int(*fun)(int, int))
{
	int a = 6, b = 9;
	double ret = fun(a, b);
	return ret;
}

// 函数指针数组 ★★
void fun_arr_p()
{
	int(*fun_arr[3])(int, int);
	fun_arr[0] = fun01; // 注意，提供的是接口不需要 （）！
	fun_arr[1] = fun02;
	fun_arr[2] = fun03;

	for (int i = 0; i < 3; i++)
	{
		fun_arr[i]; // 是地址，未调用函数并不打印东西（不加括号）★★
		fun_arr[i](i, i * 6);// <---- 注意，这里要打括号才能调用函数！！！★★
		cout << fun_arr[i] << endl; // 打印的是地址，函数未调用 ★★
		cout << fun_arr[i](i, i * 6) << endl; // 打括号才能调用函数!!! ★★
	}
}

int main()
{	
	//  函数作为另一函数的参数 传递
	cout << doLogic(fun01) << endl;

	// 函数指针数组
	fun_arr_p();
}