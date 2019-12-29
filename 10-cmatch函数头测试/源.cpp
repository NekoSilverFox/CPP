#include <iostream>
#include <cmath>
using namespace std;

int main() {

	// log() 为直接运算 ln
	// log10() 计算以10为底的对数
	// log10() 计算以10为底的对数
	// log1p() 计算以 ln(1 + x)
	cout <<  "ln(100)  ---  log(100)     " << log(100)  << endl;

	// 返回 e 的给定次幂 e^x
	cout << "e^23  ---  exp(100)		" << exp(23) << endl;
	// 返回 e 的给定次幂 e^x
	cout << "2^5  ---  exp2(5)		" << exp2(5) << endl;

	// x^n
	cout << "2^5  ---  pow(2, 5)		" << pow(2, 5) << endl;



	cin.get();
	return 0;
}