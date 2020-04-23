#include <iostream>
#define NUM 15
using namespace std;

// 用于计算 n 的几次方的函数 ，x-为幂，n-为指数，index-为指数运算结果
double index(double  x, int n) {  
	double sqr = x;
	for (int for_i = 1; for_i < n; for_i++)
		sqr *= x;
	return sqr;
	}

// No.4 次作业（#4 Функции）- 第17题，函数 ln( x+1/ x-1 ) (2<x<3)
double fun19(double x) {
	double add = 0;
	for (double i = 1; i <= NUM; i++) {
		add += 1 / ((i * 2 - 1) * index(x, i * 2 - 1)); 
	}
	return add * 2;
}

// 主函数
int main() {
	double x;

	cout << "请输入 x 的值："; cin >> x; 

	if (x <= 2 || x >= 3 || !cin) {
		cerr << "ERROR! Нужно вводит x, (2 < x < 3) !" << endl;
		return 1;
	}
	else {
		cout << fun19(x) << endl;
		return 0;
	}
}