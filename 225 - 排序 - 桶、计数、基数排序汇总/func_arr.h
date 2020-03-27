#pragma once
#ifndef FUNC_ARR
#define FUNC_ARR
#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#include<Windows.h>
#include<sys/timeb.h>
#include<sys/utime.h>
using namespace std;


int* CreatArray(int length, int max_num)
{
	srand((unsigned int)time(NULL));
	int* arr = new int[length];
	for (int i = 0; i < length + 1; i++)
	{
		arr[i] = rand() % max_num;
	}
	return arr;
}

template<typename T>
int GetArrayLength(T& arr)
{
	return sizeof(arr) / sizeof(arr[0]);
}

int PrintArray(int arr[], int length_arr)
{
	// cout << "length : " << length_arr << endl;
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

int GetSortTime(int arr[], int length)
{
	int max_value = GetMaxElemArray(arr, length);
	int time_sort = 0;
	while (max_value)
	{
		max_value /= 10;
		time_sort++;
	}
	return time_sort;
}

// count the time 
long getSystemTime() {
	timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}

int PrintUseTime(int t_start, int t_end)
{
	int use_time = t_end - t_start;
	if (0 == use_time)
	{
		cout.width(14); cout << "Use time : " << "< 0.1 ms" << endl;
	}
	else
	{
		cout.width(14); cout << "Use time : " << t_end - t_start << " ms" << endl;
	}
	return use_time;
}
#endif // !FUNC_ARR