#include <iostream>
using namespace std;
int main(void) {

	int x = 1, max = 0;

	while (x != 0)
	{
		cout << "������һ��������"; cin >> x;
		max = x > max ? x : max;
	}

	cout << "���ֵΪ��" << max;

	cin.get();
	return 0;
}