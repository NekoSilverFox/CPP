#include <iostream>
#include <conio.h> 
#include <cmath>
#include <cstdlib>
#define NUM 15
using namespace std;

double fx(double x) {
	double fx = log1p(x) - log(x - 1);
	return fx;
}

double fun19(double x, double absError, int numberMax) {
	if (x > 3 || x < 2) {
		throw 1;
	}
	int n = 0;
	double elem = 1;
	// double sum = elem;

	while (abs(elem) > absError) {
		n++;

		if (n > numberMax) {
			throw 2;
		}

		elem += 1 / ((n * 2 - 1) * pow(x, 2 * n - 1));
		// sum += elem;
	}

	return elem * 2;
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
		cout << fun19(num + 2, absError, numberMax) << "\n";
		
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
