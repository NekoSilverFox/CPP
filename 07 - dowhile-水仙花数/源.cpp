#include <iostream>
using namespace std;
int main() {

	int index = 100 , a, b, c; // a-��λ b-ʮλ c-��λ
	
	do
	{
		a = index / 100;
		b = index / 10 % 10;
		c = index % 10;

		if (a*a*a + b*b*b + c*c*c == index) {
			cout << "ˮ�ɻ���Ϊ��" << index << endl;
			}

		index++;
	} while (index < 1000);

	cin.get();
	return 0;
}