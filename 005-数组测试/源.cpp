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
		cout << "�� " << i + 1 << " λѧ���ĳɼ�Ϊ: " << shuzu[i] << endl;
		cout << "������ڴ��ַΪ��" << &shuzu[i] << endl << endl;
	}
	cout << "ƽ���ɼ�Ϊ��" << zongchengji / STU;

	cin.get();
	return 0;
}