#include <iostream>
using namespace std;
int main(){
	int index = 100, a, b, c; // a��    bʮ    c��
	
	for (index; index <= 999; index++) {

		// ע�� a��b��c���Ķ���Ҫ����for ѭ���У� ��Ȼ a��b��c�����޷������¶��壡������
		a = index / 100;
		b = index / 10 % 10;
		c = index % 10;

		if (a*a + b*b + c*c == index)
		{
			cout << "ˮ�ɻ���Ϊ��" << index << endl;
		}

	}

	cin.get();
	return 0;

	}