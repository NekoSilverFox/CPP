#include <iostream>
#include <cmath>
#include <cstdlib>
#include <conio.h> 
using namespace std;

// 函数的声明（可以舍弃）
double function_19(double x, double absError, int numberMax);

// 函数的定义
double function_19(double x, double absError, int numberMax) {
	
	// 如果范围有误（确定范围）
	if (x > 3 || x < 2) {
		throw 1;
	}

	double n = 0, elem = 1.0, sum = 0; // elem - 元素

	while (abs(elem) > absError) {  // 这是个什么鬼东西
			n++;
			if (n >= numberMax) {
				throw 2;
			}
			elem = 1 / ((n * 2 - 1) * pow(x, 2 * n - 1));
			sum += elem;
		}
	return sum * 2;
}

int main() {
	double x, absError, interval; // interval  - 为步长（间隔）
	int numberMax;

	cout << "请输入间隔(步长)："; cin >> interval; cout << endl;
	cout << "请输入精度："; cin >> absError; cout << endl;
	cout << "请输入最大运算值："; cin >> numberMax; cout << endl;
	x = interval + 2;

	// 判断输入错误！
	if (!cin) {
		cerr << "ERROR! Вводит числа!";
		return 1;
	}

	for (interval; x < 3; x += interval) {
		cout << x << "    ";
		cout << log((x + 1) / (x - 1)) << "    ";

		try {
			cout << function_19(x, absError, numberMax) << endl;
		}

		// 利用 swish 语句来输出 之前 throw 抛出的错误
		catch (int exc) {
			switch (exc) {
			case 1:
				cerr << "范围错误！" << endl;
				break;
			case 2:
				cerr << "精度不足！" << endl;
				break;
			default:
				break;
			}
		}
	}
	cin.get();
	return 0;
}