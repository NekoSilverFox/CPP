#include <iostream>
#include <cmath>
#define NUM 15
using namespace std;

// 用于计算 n 的几次方的函数 ，x-为幂，n-为指数，index-为指数运算结果
//double index(double  x, int n) {
//	double sqr = x;
//	for (int for_i = 1; for_i < n; for_i++)
//		sqr *= x;
//	return sqr;
//}

// No.4 次作业（#4 Функции）- 第17题，函数 ln( x+1/ x-1 ) (2<x<3)
//double fun19(double x) {
//	double add = 0;
//	for (double i = 1; i <= NUM; i++) {
//		add += 1 / ((i * 2 - 1) * index(x, i * 2 - 1));
//	}
//	return add * 2;
//}


double absError(double x) {
	double fx = log1p(x) - log(x - 1);
	return fx;
}

double numberMax(double x) {
	double sum = 0;
		for (double i = 1; i <= NUM; i++) {
			sum += 1 / ((i * 2 - 1) * pow(x, 2 * i - 1));
		}
		return sum * 2;
}

int main() {
	double num, absError, numberMax; // num - 为间隔
	cout << "请输入间隔 num ：\n"; cin >> num;
	cout << "请输入精度 absError ：\n"; cin >> absError;
	cout << "请输入最大值 numberMax： \n"; cin >> numberMax;

	if (!cin) {
		cerr << "NaN!\n";
		cin.get();
		return 1;
	}
	try {
		cout << calculateSeries(num, absError, numberMax) << "\n";
	}
	catch (int exc) {
		switch (exc) {
		case 1:
			cerr << "Wrong x\n";
			break;
		case 2:
			cerr << "Too many\n";
			break;
		default:
			break;
		}
	}
	cin.get();
	return 0;
}
// 主函数
//int main() {
//	double interval;
//	cout << "请输入所测试间隔大小："; cin >> interval; cout << endl;
//
//	if (!cin) {
//		cerr << "ERROR!!" << endl;
//		return 1;
//	}
//	else {
//		for (double i = interval; interval + 2 < 3; interval += i) {
//			cout << interval + 2 << "	";
//			cout << absError(interval + 2) << "	";
//			cout << numberMax(interval + 2) << endl;
//		}
//		return 0;
//	}
//}