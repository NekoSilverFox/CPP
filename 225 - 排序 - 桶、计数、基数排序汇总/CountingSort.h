#pragma once
#include "func_arr.h"

void CountingSort(int arr[], const int length_arr)
{
	int max_value = GetMaxElemArray(arr, length_arr);
	int min_value = GetMinElemArray(arr, length_arr);
	int num_backet = max_value - min_value + 1;
	int* counting_arr = new int[num_backet];

	// 1. make all the num in counting_arr = 0
	for (int i = 0; i < num_backet; i++) counting_arr[i] = 0;

	// 2. count num of subscript
	for (int i = 0; i < length_arr; i++)
	{
		counting_arr[arr[i] - min_value]++;
	}

	// 3. put the subscript in arr[]
	int subscript = 0;
	for (int i = 0; i < num_backet; i++)
	{
		if (counting_arr[i] != 0)
		{
			for (int j = 0; j < counting_arr[i]; j++)
			{
				arr[subscript] = min_value + i;
				subscript++;
			}
		}
	}
}