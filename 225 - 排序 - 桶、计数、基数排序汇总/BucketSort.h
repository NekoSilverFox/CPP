#pragma once
#include "func_arr.h"


void BucketSort(int arr[], const int length_arr)
{
	int max_value = GetMaxElemArray(arr, length_arr);
	int min_value = GetMinElemArray(arr, length_arr);
	int gap = (max_value - min_value) / length_arr + 1;
	int num_backet = (max_value - min_value) / gap + 1;

	pair<vector<int>, int>* backet_arr = new pair<vector<int>, int>[num_backet]; // first - 数组， second - first中元素数量

	// 1. put all the number into the backet
	int put_in_which_backet;
	for (int i = 0; i < length_arr; i++)
	{
		put_in_which_backet = (arr[i] - min_value) / gap;
		backet_arr[put_in_which_backet].first.push_back(arr[i]);
		backet_arr[put_in_which_backet].second++;
	}

	// 2. sort for every backet
	for (int i = 0; i < num_backet; i++)
	{
		if (backet_arr[i].second != 0)
		{
			sort(backet_arr[i].first.begin(), backet_arr[i].first.end());
		}
	}

	// 3. put the number which have sort (in backet), overwrite the original array
	int subscript = 0; // 下标
	for (int i = 0; i < num_backet; i++)
	{
		for (vector<int>::iterator it = backet_arr[i].first.begin(); it != backet_arr[i].first.end(); it++)
		{
			arr[subscript] = *it;
			subscript++;
		}
	}
}