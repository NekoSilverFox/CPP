#include <iostream>
using namespace std;
int main(void) {

	int a, b, c;

	cout << "a="; cin >> a;
	cout << "b="; cin >> b;
	cout << "c="; cin >> c;

	// 将最小值定义到 min 中
	int min = a < b ? a : b; 
	min = min < c ? min : c;

	//  将最大值定义到 max 中
	int max = a > b ? a : b;
	max = max > c ? max : c;

	// 既然已知最大值（max）和最小值（min），那么可以得到：
	int mid = (a + b + c - min - max);

	cout << min << "<="<< mid << "<="  << max;

	cin.get();
	return 0;
}