#include<iostream>
#include<string>
using namespace std;
const int N = 8;

void test01()
{
	string arr_str[N];

	arr_str[0] = "abcdefg";
	arr_str[1] = "acbedfg";
	arr_str[2] = "abcdegf";
	arr_str[3] = "sdfsfasf";
	arr_str[4] = "abc";
	arr_str[5] = "abcd";
	arr_str[6] = "sad1";
	arr_str[7] = "1sad";


	string temp;
	int flag = 1;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			flag = 0;
			if (arr_str[j] > arr_str[j + 1])
			{
				// cout << arr_str[i] << endl;
				temp = arr_str[j];
				arr_str[j] = arr_str[j + 1];
				arr_str[j + 1] = temp;
			}
			
		}
		if (flag) { return; }
		flag = 1;
	}

	for (int i = 0; i < N; i++)
	{
		cout << arr_str[i] << endl;
	}

}

int main()
{
	test01();
}