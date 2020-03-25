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

void BucketSort(int arr[], int length_arr)
{
	int max_ele = GetMaxElemArray(arr, length_arr);
	int* temp_arr = new int[max_ele];

	for (int i = 0; i < max_ele; i++)
	{
		temp_arr[i] = 0;
	}

	for (int i = 0; i < length_arr; i++)
	{
		temp_arr[arr[i]] = temp_arr[arr[i]] + 1;
	}

	int subscript = 0;
	for (int i = 0; i < max_ele; i++)
	{
		if (temp_arr[i] != 0)
		{
			for (int  j = 0; j < temp_arr[i];  j++, subscript++)
			{
				arr[subscript] = i;
			}
		}
	}
}

int main()
{
	int arr[] = { 9,6,7,4,3,1,3,3,8,9 };

	int length_arr = GetArrayLength(arr);

	PrintArray(arr);
	BucketSort(arr, length_arr);
	PrintArray(arr);
}