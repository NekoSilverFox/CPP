#include <iostream>
#include <cmath>
using namespace std;

int main() {

	// log() Ϊֱ������ ln
	// log10() ������10Ϊ�׵Ķ���
	// log10() ������10Ϊ�׵Ķ���
	// log1p() ������ ln(1 + x)
	cout <<  "ln(100)  ---  log(100)     " << log(100)  << endl;

	// ���� e �ĸ������� e^x
	cout << "e^23  ---  exp(100)		" << exp(23) << endl;
	// ���� e �ĸ������� e^x
	cout << "2^5  ---  exp2(5)		" << exp2(5) << endl;

	// x^n
	cout << "2^5  ---  pow(2, 5)		" << pow(2, 5) << endl;



	cin.get();
	return 0;
}