#include<iostream>
using namespace std;

int main() {

	int i, x = 1, y = 1, z = 1, max = 1, min, num_max = 0;
	
	while (x != 0 && y != 0) {
		cout << "���ӧ�էڧ� ��֧ݧ�� ��ڧ�ݧ� : "; cin >> x;
		cout << "���ӧ�էڧ� ��֧ݧ�� ��ڧ�ݧ� : "; cin >> y;
		num_max = max == x || y ? num_max++ : i=1 ;
		max = x >= y ? x : y;
	}

	cout << "The Program stop running!" << num_max;

	cin.get();
	return 0;
}