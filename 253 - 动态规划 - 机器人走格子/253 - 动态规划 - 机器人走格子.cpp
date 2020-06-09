/*
** 已知有一个 NxM 的矩阵，机器人在矩阵的左上角，求机器人走到 右下角或者(i, j)所跨过的格子数量
*/

#include <iostream>
using namespace std;

int uniquePaths(int m, int n)
{
	int** arr = new int*[m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((0 == i) || (0 == j))
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}

		cout << endl;
	}

	return arr[m - 1][n - 1];
}


int main()
{
	uniquePaths(5, 10);
}