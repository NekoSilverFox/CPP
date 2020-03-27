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
	int max_ele = arr[0];
	for (int i = 0; i < length_arr; i++)
	{
		if (max_ele < arr[i]) max_ele = arr[i];
	}
	return max_ele;
}

int GetMinElemArray(int arr[], int length_arr)
{
	int min_ele = arr[0];
	for (int i = 0; i < length_arr; i++)
	{
		if (min_ele > arr[i]) min_ele = arr[i];
	}
	return min_ele;
}

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

int main()
{
	int arr[] = { 67,23,89,43,78,12,90,45,34,76,12, };

	int length_arr = GetArrayLength(arr);

	PrintArray(arr);
	CountingSort(arr, length_arr);
	PrintArray(arr);
}