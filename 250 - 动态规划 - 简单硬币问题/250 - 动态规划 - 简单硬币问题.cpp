#include <iostream>
#include <algorithm>
using namespace std;

/*
** ��1,5,11��������Ǯ�����������ٵ�Ǯ�ճ�15Ԫ
*/

int main()
{
	int cost;
	int n;
	int arr[305] = { 0 };

	cin >> n;

	for (int i = 1; i < n + 1; i++)
	{
		cost = 99999999;
		if (i - 1 >= 0) cost = std::min(cost, arr[i - 1] + 1);
		if (i - 5 >= 0) cost = std::min(cost, arr[i - 5] + 1);
		if (i - 11 >= 0) cost = std::min(cost, arr[i - 11] + 1);

		arr[i] = cost;

		cout << "arr[" << i << "] = " << cost << endl;
	}
}