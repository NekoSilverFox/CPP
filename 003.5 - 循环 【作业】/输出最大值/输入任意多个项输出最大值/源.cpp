#include <iostream>
using namespace std;
int main(void) {

	int x = 1, max = 0;

	while (x != 0)
	{
		cout << "请输入一个整数："; cin >> x;
		max = x > max ? x : max;
	}

	cout << "最大值为：" << max;

	cin.get();
	return 0;
}