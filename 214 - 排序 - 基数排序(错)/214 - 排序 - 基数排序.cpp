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

int GetSortTime(int max_num)
{
	int time_sort = 0;
	while (max_num)
	{
		max_num /= 10;
		time_sort++;
	}
	return time_sort;
}

void RadixSort(int arr[], const int length_arr, const int time_sort) // 4
{
	int temp_arr[10];  // 辅助数组
	int num_insert; // 插入的数
	int division_num_10 = 1; // 除以的10
	int i_insert_arrN2_backet = 0;


	// how many backet need
	int** arrN2_backet = new int* [time_sort];
	for (int i = 0; i < time_sort; i++)
	{	
		arrN2_backet[i] = new int[10];
	}

	// make the all the number in the arrN2_backet to 0
	for (int i = 0; i < time_sort; i++)
	{
		for (int j = 0; j < 10; j++) arrN2_backet[i][j] = 0;
	}

	// put the arr[] number in the arrN2_backet
	for (int time = 0; time < time_sort; time++)
	{

		for (int i = 0; i < 10; i++) temp_arr[i] = 0; //将备用数组全部重置为 0 


		// 取到当前的位数上的值		
		for (int i = 0; i < length_arr; i++)
		{
			num_insert = arr[i];
			num_insert = num_insert / division_num_10 % 10;			
			cout << num_insert << " ";
			temp_arr[num_insert]++;
		}

		cout << endl;

		for (int i = 0; i < 10; i++)
		{
			int subscript = 0; // 下标
			if (temp_arr[i] != 0)
			{
				for (int j = 0; j < temp_arr[i]; j++, subscript++)
				{
					//arr_need[subscript] = arr_need[subscript] + i * division_num_10;
					arrN2_backet[i_insert_arrN2_backet][subscript] = i;
				}
			}
		}

		division_num_10 *= 10;
	}
	
	for (int i = 0; i < length_arr; i++) arr[i] = 0;


	division_num_10 = 1;
	
	int i_insert = 0, i = 0, j = 0;
	int subscript = i_insert;
	for (int i_insert = 0; i_insert < length_arr; i_insert++)
	{

			if (arrN2_backet[i][j] != 0)
			{
				// arr[i_insert] = arr[i_insert] + j 
				for (int k = 0; k < arrN2_backet[i][j]; k++, subscript++) arr[i_insert] = arr[i_insert] + j * division_num_10;
			}
			j++;
			subscript = i_insert;
			if (10 == j)
			{
				j = 0;
				i++;
				division_num_10 *= 10;
			}
	}


	/*
	for (int i_insert = 0; i < length_arr; i_insert++)
	{

		for (int i = 0; i < time_sort; i++)
		{
			for (int j = 0; j < 10; j++)
			{

			}
		}

		arr[i] = 
	}
	*/

}


int main()
{
	int arr[] = { 1244, 4576, 3634, 1111, 7656, 7767,3343, 8878, 9869, 1480, 3800,5790, 5769 };

	int length_arr = GetArrayLength(arr);
	int max_num = GetMaxElemArray(arr, length_arr);
	int time_sort = GetSortTime(max_num);
	PrintArray(arr);
	RadixSort(arr, length_arr, time_sort);
	PrintArray(arr);


}