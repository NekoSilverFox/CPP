#include <iostream>
using namespace std;
int main(void) {

	int a, b, c;

	cout << "a="; cin >> a;
	cout << "b="; cin >> b;
	cout << "c="; cin >> c;

	// ����Сֵ���嵽 min ��
	int min = a < b ? a : b; 
	min = min < c ? min : c;

	//  �����ֵ���嵽 max ��
	int max = a > b ? a : b;
	max = max > c ? max : c;

	// ��Ȼ��֪���ֵ��max������Сֵ��min������ô���Եõ���
	int mid = (a + b + c - min - max);

	cout << min << "<="<< mid << "<="  << max;

	cin.get();
	return 0;
}