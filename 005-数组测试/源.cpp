#include <iostream>
#define STU 5
using namespace std;
int main(void) {

	int shuzu[STU], zongchengji = 0;

	for (int i = 0; i < STU; i++) {
		cin >> shuzu[i];
		zongchengji += shuzu[i];
	}

	for (int i = 0; i < STU; i++) {
		cout << "第 " << i + 1 << " 位学生的成绩为: " << shuzu[i] << endl;
		cout << "此项的内存地址为：" << &shuzu[i] << endl << endl;
	}
	cout << "平均成绩为：" << zongchengji / STU;

	cin.get();
	return 0;
}