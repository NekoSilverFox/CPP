#include<iostream>
#include<time.h>
#include<sys/timeb.h>
using namespace std;

int* CreatArray(int length, int num_max)
{
	++length;
	srand((unsigned int)time(NULL));

	int* arr = new int[length];

	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % num_max;
	}
	return arr;
}

void PrintArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// 从小到大
void Merge(int arr[], const int start_arr, const int end_arr, const int mid_arr, int* temp)
{
	int i_start = start_arr;
	int i_end = mid_arr;
	int j_start = mid_arr + 1;
	int j_end = end_arr;

	//表示辅助空间有多少个元素
	int length = 0;

	while (i_start <= i_end &&  j_start <= j_end)
	{
		if (arr[i_start] < arr[j_start])
		{
			temp[length] = arr[i_start];
			i_start++;
			length++;
		}
		else 
		{
			temp[length] = arr[j_start];
			j_start++;
			length++;
		}
	}

	// 如果两个数组不等长， 将后半截合并
	while (i_start <= i_end)
	{
		 temp[length] = arr[ i_start];
		 length++;
		 i_start++;
	}
	while (j_start <= j_end)
	{
		temp[length] = arr[ j_start];
		j_start++;
		length++;
	}

	//辅助空间数据覆盖原空间
	for (int i = 0; i < length; i++)
	{
		arr[start_arr + i] = temp[i]; ///////////////  注意！！！！是 arr[start_arr  + i]  防止前端元素被覆盖！！
	}
}


//归并排序
void MergeSort(int arr[], int start_arr, int end_arr, int* temp)
{
	if (start_arr >= end_arr) return;

	int mid = (start_arr + end_arr) / 2;

	// 分组 - 左半组
	MergeSort(arr, start_arr, mid, temp);

	// 分组 - 右半组
	MergeSort(arr, mid + 1, end_arr, temp);

	// 合并
	Merge(arr, start_arr, end_arr, mid, temp);
}

int main()
{
	int* arr = CreatArray(10, 10);
	int* temp = new int[10];
	PrintArray(arr, 10);
	MergeSort(arr, 0, 10, temp);
	PrintArray(arr, 10);
}