#include <iostream>
using namespace std;
int main() {
	int x = 1, max = 1, max2;
	while (x != 0) {
		cout << "���ӧ�էڧ� ��֧ݧ�� ��ڧ�ݧ� : "; cin >> x;
		
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
				cout << "�������ӦΪ����" << endl;
				cin.get();
				return 1;
			}
	}


	cout << "�����еڶ���Ԫ��Ϊ��" << max2 << endl;

	cin.get();
	return 0;
}