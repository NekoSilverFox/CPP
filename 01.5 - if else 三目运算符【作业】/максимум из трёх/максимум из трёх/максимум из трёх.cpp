#include <iostream>
#include <climits>
using namespace std;
int main(void) {

	int a, b, c;
	cout << "a="; cin >> a;
	cout << "b="; cin >> b;
	cout << "c="; cin >> c;

	/*
	if (a > b){
		if ((a > c) && (b > c)){
		cout << "���ѧܧ�ڧާ�� �ڧ� ���ק� - " << a;
}
		else {
		cout << "���ѧܧ�ڧާ�� �ڧ� ���ק� - " << c;
}
	}

	// b > a
	else {
		if ((b > c) && (c < a)){
			cout << "���ѧܧ�ڧާ�� �ڧ� ���ק� - " << b;
}
		else {
				cout << "���ѧܧ�ڧާ�� �ڧ� ���ק� - " << c;
			}
		}
		*/

	int max = a > b ? a : b;
	max = max > c ? max : c;

	cout << "���ѧܧ�ڧާ�� �ڧ� ���ק� - " << max << endl;

	cin.get();
	return 0;
}
