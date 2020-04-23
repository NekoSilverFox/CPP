#include <iostream>
using namespace std;
int main() {
	int x = 1, max = 1, max2;
	while (x != 0) {
		cout << "Вводит целое число : "; cin >> x;
		
		if (cin) {

			if (x > max) {
				max2 = max;
			}
			max = x;

			if (x <= max) {
				;
			}
		}
			else {
				cout << "输入的数应为整数" << endl;
				cin.get();
				return 1;
			}
	}


	cout << "数组中第二大元素为：" << max2 << endl;

	cin.get();
	return 0;
}