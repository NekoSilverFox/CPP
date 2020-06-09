/*
** 求最值型 动态规划：
** 动态规划的组成部分：
**		1. 确定状态
**				最后一步（最优策略中使用的最后一枚硬币 ak）
**				化成子问题（最少的硬币拼出更小的面值 27-ak）
**		2. 转移方程
**				f[x] = min{[x-2]+1, [x-5]+1, [x-7]+1}
**		3. 初始条件和边界情况
**				f[0] = 0, 如果不能拼出Y，f[Y]=正无穷
**		4. 计算顺序
**				f[0], f[1], f[2], ..... f[n]
**	消除冗余，加速计算
*/
#include <iostream>
#include <algorithm> // min and max method
#include <climits> // 内置类型的最大值宏定义
using namespace std;


int* makeCoinTypeArray()
{
	int num_type;

	cout << "How many type of coin you want: "; cin >> num_type;

	int* arr = new int[num_type];

	for (int i = 0; i < num_type; i++)
	{
		cout << "The Type NO." << i + 1 << " :"; cin >> arr[i];
	}

	return arr;
}

void coinChange(int arr_coin_type[], int arr_length, const int& max_money_val)
{
	int* arr_method = new int[max_money_val + 1]; // + 1 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	arr_method[0] = 0;

	for (int i = 1; i < max_money_val; i++)
	{
		arr_method[i] = INT_MAX;

		for (int j = 0; j < arr_length; j++)
		{
			if ((i - arr_coin_type[j] >= 0) && (arr_method[i - arr_coin_type[j]] != INT_MAX))
			{
				arr_method[i] = std::min(arr_method[i - arr_coin_type[j]] + 1, arr_method[i]);
			}
		}
	}


	for (int i = 0; i < max_money_val; i++)
	{
		if (arr_method[i] == INT_MAX)
		{
			arr_method[i] = -1;
		}

		cout << "arr_method[" << i << "] = " << arr_method[i] << endl;
	}
}

int main()
{
	int arr[3] = { 2, 5 ,11 };

	coinChange(arr, 3, 5000);
}