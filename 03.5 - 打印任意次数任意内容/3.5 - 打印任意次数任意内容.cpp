#include<iostream>
using namespace std;

int main()
{
	int time_print;
	string print_string;

	cout << "��ӡ������"; cin >> time_print;
		cout << "���ݣ�"; cin >> print_string;
		for (int i = 0; i < time_print; ++i)
		{
		cout << print_string << " ";	
	}
		cin.get();
}