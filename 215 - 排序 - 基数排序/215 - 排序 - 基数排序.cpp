#include<iostream>
using namespace std;

template<typename T>
int GetArrayLength(T& arr)
{
	return sizeof(arr) / sizeof(arr[0]);
}

template<typename T>
int PrintArray(T& arr)
{
	int length_arr = GetArrayLength(arr);
	cout << "length : " << length_arr << endl;
	for (int i = 0; i < length_arr; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return length_arr;
}

int GetMaxElemArray(int arr[], int length_arr)
{
	int max_value = arr[0];
	for (int i = 0; i < length_arr; i++)
	{
		if (max_value < arr[i]) max_value = arr[i];
	}
	return max_value;
}

int GetSortTime(int max_value)
{
	int time_sort = 0;
	while (max_value)
	{
		max_value /= 10;
		time_sort++;
	}
	return time_sort;
}

void RadixSort(int arr[], const int length_arr, const int time_sort) // 4
{
	pair<pair<int, int>*, int> temp_arr[10];  // 使用对组，辅助插入 - 辅助数组 first 存放另一堆 对组， second存放下标
	for (int i = 0; i < 10; i++)
	{
		temp_arr[i].first = new pair<int, int>[length_arr];
		temp_arr[i].second = 0;
	}

	int division_num_10 = 1; // 除以的10

	//  arr_pair.first 储存了当前数组的值，arr_pair.second 存储了个/十/百/千/万 上的值
	// arr_pair[i].first = arr[i] ,     arr_pair[i].second = 0 <---will use for num insert
	pair<int, int>* arr_pair = new pair<int, int>[length_arr]; 

	for (int time = 0; time < time_sort; time++)
	{
		// 将arr_pair[].first 中排序好的数组，覆盖掉原来的arr[]
		for (int i = 0; i < length_arr; i++)
		{
			arr_pair[i].first = arr[i];
			arr_pair[i].second = 0;
		}

		//将备用数组 (大小为10) 全部重置为 0 
		for (int i = 0; i < 10; i++) temp_arr[i].second = 0; 

		// 取到当前的位数上的值	
		for (int i = 0; i < length_arr; i++)
		{
			arr_pair[i].second = arr_pair[i].first / division_num_10 % 10;
			cout << arr_pair[i].second << " ";

			temp_arr[arr_pair[i].second].first[temp_arr[arr_pair[i].second].second++] = arr_pair[i];
			// temp_arr[arr_pair[i].second].second++;
		}
		division_num_10 *= 10;

		cout << endl;

		int subscript = 0; // 下标
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


int main()
{
	int arr[] = { 1244, 4576, 3634, 1111, 7656, 7767,343, 8878, 9869, 1480, 3800,5790, 5769, 941, 41 };

	int length_arr = GetArrayLength(arr);
	int max_value = GetMaxElemArray(arr, length_arr);
	int time_sort = GetSortTime(max_value);
	PrintArray(arr);
	RadixSort(arr, length_arr, time_sort);
	PrintArray(arr);


}