#include<iostream>
using namespace std;
//int main(void) {
//
//	char buf[10]; // ע�⣡�������ǡ������� ()
//
//	cin.getline(buf, 5);
//
//	/*cin >> buf;*/
//	cout << buf;
//
//	cin.get();
//	return 0;
//}


void num0_20() {

	while (true)
	{
		int num;
		cout << "������һ��1-10 �����֣�"; cin >> num;

		if (num >= 1 && num <= 10) {
			cout << "�������������Ϊ��" << num;
			break;
		}
		
			cout << "��־λ��" << cin.fail() << endl; // cin.fail() - ��ȡ��־λ
			cout << "������������������������룡" << endl;
			cin.sync();				 // ��ջ�����
			cin.clear();		   	// ���ñ�־λ
	}

}

// �ж�������Ƿ�Ϊ0-10 ������
int main(void) {

	num0_20();

	cin.get();
	return 0;
}