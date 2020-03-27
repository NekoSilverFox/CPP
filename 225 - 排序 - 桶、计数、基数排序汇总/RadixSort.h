#pragma once
#include "func_arr.h"

void RadixSort(int arr[], const int length_arr, const int time_sort) // 4
{
	// use pair to help insert value
	pair<pair<int, int>*, int> temp_arr[10];  // temp_arr.first --->other pair(arr_pair) £¬ temp_arr.second save subscript
	for (int i = 0; i < 10; i++)
	{
		temp_arr[i].first = new pair<int, int>[length_arr];
		temp_arr[i].second = 0;
	}

	int division_num_10 = 1; //  10^? 

	//  arr_pair.first ---> save arr[i]£¬arr_pair.second ----> save number which use for num insert (0 ~ 9)
	pair<int, int>* arr_pair = new pair<int, int>[length_arr];

	for (int time = 0; time < time_sort; time++)
	{
		// use array which have sort and save in the --> arr_pair[].first£¬Overwrite the original array£¨arr[]£©
		for (int i = 0; i < length_arr; i++)
		{
			arr_pair[i].first = arr[i];
			arr_pair[i].second = 0;
		}

		// Reset spare array all the element to 0
		for (int i = 0; i < 10; i++) temp_arr[i].second = 0;

		// get the value need to use ( 0 ~ 9 )
		// cout.width(14);
		for (int i = 0; i < length_arr; i++)
		{
			arr_pair[i].second = arr_pair[i].first / division_num_10 % 10;
			// cout << arr_pair[i].second << " ";

			temp_arr[arr_pair[i].second].first[temp_arr[arr_pair[i].second].second] = arr_pair[i];
			temp_arr[arr_pair[i].second].second++;
		}
		division_num_10 *= 10;

		// cout << endl;

		int subscript = 0; 
		for (int i = 0; i < 10; i++)
		{
			if (temp_arr[i].second != 0)
			{
				for (int j = 0; j < temp_arr[i].second; j++, subscript++)
				{
					arr[subscript] = temp_arr[i].first[j].first;
				}
			}
		}
	}
}
