#include<iostream>
#include<algorithm>
#include<vector>
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

int GetMinElemArray(int arr[], int length_arr)
{
	int min_value = arr[0];
	for (int i = 0; i < length_arr; i++)
	{
		if (min_value > arr[i]) min_value = arr[i];
	}
	return min_value;
}

void BucketSort(int arr[], const int length_arr)
{
	int max_value = GetMaxElemArray(arr, length_arr);
	int min_value = GetMinElemArray(arr, length_arr);
	int gap = (max_value - min_value) / length_arr + 1;
	int num_backet = (max_value - min_value) / gap + 1;

	pair<vector<int>, int>* backet_arr = new pair<vector<int>, int>[num_backet]; // first - ���飬 second - first��Ԫ������

	// 1. �����е�Ԫ��ȫ�����뵽Ͱ��
	int put_in_which_backet;
	for (int i = 0; i < length_arr; i++)
	{
		put_in_which_backet = (arr[i] - min_value) / gap;
		backet_arr[put_in_which_backet].first.push_back(arr[i]);
		backet_arr[put_in_which_backet].second++;
	}

	// 2. ��ÿ��Ͱ��������
	for (int i = 0; i < num_backet; i++)
	{
		if (backet_arr[i].second != 0)
		{
			sort(backet_arr[i].first.begin(), backet_arr[i].first.end());
		}
	}

	// 3. ��������Ͱ�е�Ԫ�ظ���ԭ����
	int subscript = 0; // �±�
	for (int i = 0; i < num_backet; i++)
	{
		for (vector<int>::iterator it = backet_arr[i].first.begin(); it != backet_arr[i].first.end(); it++)
		{
			arr[subscript] = *it;
			subscript++;
		}
	}
}

int main()
{
	int arr[] = { 9,6,7,4,3,1,3,3,8,9,67,23,89,43,78, 142,12,90,45,34,76,12,78,43 };

	int length_arr = GetArrayLength(arr);

	PrintArray(arr);
	BucketSort(arr, length_arr);
	PrintArray(arr);
}