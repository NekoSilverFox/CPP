#include<iostream>
using namespace std;

int main()
{
	int time_print;
	string print_string;

	cout << "打印次数："; cin >> time_print;
		cout << "内容："; cin >> print_string;
		for (int i = 0; i < time_print; ++i)
		{
		cout << print_string << " ";	
	}
		cin.get();
}