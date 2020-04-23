#include <iostream>
#include <conio.h> 
using namespace std;

double calculateSeries(double x, double absError, int numberMax);

// 1/sqrt(1+x)
double calculateSeries(double x, double absError, int numberMax) {
	if (x > 1 || x < -1) {
		throw 1;
	}
	int n = 0;
	double elem = 1.0;
	double sum = elem;
	while (abs(elem) > absError) {
		n++;
		if (n > numberMax) {
			throw 2;
		}
		elem *= (-2.0 * n + 1) / (2.0 * n) * x;
		sum += elem;
	}
	return sum;
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
		for (int i = -1; i < 1; i += num) {
			cout << calculateSeries(num, absError, numberMax) << "\n";
		}
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
	_getch();
	return 0;
}