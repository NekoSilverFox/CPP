#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	int min_value;
	int max_value;
	srand((unsigned int)time(NULL));

	cout << "bilibili������ѩ��ͺ��ܲ�" << endl
			<< "����ʱ��(Ī˹��ʱ��)��" << __TIMESTAMP__ << endl << endl;

	cout << "��������Сֵ��"; cin >> min_value;
	cout << "���������ֵ��"; cin >> max_value;

	cout << endl
		<< "\033[32m"
		<< "�н�¥�㣺" << min_value + (rand() % (max_value - min_value + 1)) << endl
		<< "\033[0m";
}