#include <iostream>
#include <conio.h>
using namespace std;
int main(void){

	int num;                 // num - �ܧ�ݧڧ�֧��ӧ� �ӧ���� 
	cout << "���ܧ�ݧ�ܧ� �ӧ���� �ӧ� ����ڧ��?\n";
	cin >> num; 

	if (num > 0) {         // ����اߧ� �٧ߧѧ�� �ҧ�ݧ��� �ڧݧ� �ާ֧ߧ��� �ߧ�ݧ�
		
		if (num == 1) {
			cout << "�� ���ѧ� 1 �ӧ���ߧ�." << endl;
			return 0;
		}

		if (1 < num < 5) {
			cout << "�� ���ѧ� " << num << " �ӧ���ߧ�." << endl;
			return 0;
		}

		if (num >= 5) {
			cout << "�� ���ѧ� " << num << " �ӧ����." << endl;
			return 0;
		}
	}

	else {
		cout << "����اߧ� �ҧ�ݧ��� ��֧� �ߧ�ݧ�!";
		return 1;
	}

		cin.get();
		return 0;
}