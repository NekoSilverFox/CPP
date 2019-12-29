#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	string s1, s2, s3, s4, s5, s6;
	s1 = "1234K";
	s2 = "4321K";
	s3 = "123K";
	s4 = "432K";
	// 将字符串转为，整形
	int num = stoi(s4);
	cout << num << endl;
	if (s1 < s2)
	{
		cout << "1234K < 4321K" << endl;
	}
	else
	{
		cout << "1234K >= 4321K" << endl;
	}

	if (s1 > s4)
	{
		cout << "1234K > 123K" << endl;
	}
	else
	{
		cout << "ERROR" << endl;
	}
}