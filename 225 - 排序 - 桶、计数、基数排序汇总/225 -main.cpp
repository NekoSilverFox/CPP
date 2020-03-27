#include "func_arr.h"
#include "BucketSort.h"
#include "CountingSort.h"
#include "RadixSort.h"
#include "QuickSort.h"

void SmallArrayTest()
{
	int length = 20, max = 1000;
	double t_start, t_end;
	int* arr;
	cout << endl << "\033[32m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- Quick Sort -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[0m" << endl;
	arr = CreatArray(length, max);
	cout.width(14); cout << "Array : ";  PrintArray(arr, length);
	t_start = getSystemTime();
	QuickSort(arr, 0, length);
	t_end = getSystemTime();
	cout.width(14); cout << "After sort : "; PrintArray(arr, length);
	PrintUseTime(t_start, t_end);
	Sleep(1000);

	cout << endl <<  "\033[32m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- Counting Sort -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[0m" << endl;
	arr = CreatArray(length, max);
	cout.width(14); cout << "Array : ";  PrintArray(arr, length);
	 t_start = getSystemTime();
	CountingSort(arr, length);
	 t_end = getSystemTime();
	cout.width(14); cout << "After sort : "; PrintArray(arr, length);
	PrintUseTime(t_start, t_end);
	Sleep(1000);


	cout << endl << "\033[32m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- Radix Sort -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[0m" << endl;
	arr = CreatArray(length, max);
	int time_sort = GetSortTime(arr, length);
	cout.width(14); cout << "Array : ";  PrintArray(arr, length);
	t_start = getSystemTime();
	RadixSort(arr, length, time_sort);
	t_end = getSystemTime();
	cout.width(14); cout << "After sort : "; PrintArray(arr, length);
	PrintUseTime(t_start, t_end);
	Sleep(1000);


	cout << endl << "\033[32m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- Bucket Sort -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[0m" << endl;
	arr = CreatArray(length, max);
	cout.width(14); cout << "Array : ";  PrintArray(arr, length);
	t_start = getSystemTime();
	BucketSort(arr, length);
	t_end = getSystemTime();
	cout.width(14); cout << "After sort : "; PrintArray(arr, length);
	PrintUseTime(t_start, t_end);
	Sleep(1000);
}


void BigArrayTest()
{
	int length = 100000, max = 100000;
	double t_start, t_end;
	int* arr;
	cout << endl << "\033[33m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- Quick Sort -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[0m" << endl;
	arr = CreatArray(length, max);
	t_start = getSystemTime();
	QuickSort(arr, 0, length);
	t_end = getSystemTime();
	PrintUseTime(t_start, t_end);
	// Sleep(1000);

	cout << endl << "\033[33m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- Counting Sort -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[0m" << endl;
	arr = CreatArray(length, max);
	t_start = getSystemTime();
	CountingSort(arr, length);
	t_end = getSystemTime();
	PrintUseTime(t_start, t_end);
	// Sleep(1000);


	cout << endl << "\033[33m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- Radix Sort -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[0m" << endl;
	arr = CreatArray(length, max);
	int time_sort = GetSortTime(arr, length);
	t_start = getSystemTime();
	RadixSort(arr, length, time_sort);
	t_end = getSystemTime();
	PrintUseTime(t_start, t_end);
	// Sleep(1000);


	cout << endl << "\033[33m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- Bucket Sort -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[0m" << endl;
	arr = CreatArray(length, max);
	t_start = getSystemTime();
	BucketSort(arr, length);
	t_end = getSystemTime();
	PrintUseTime(t_start, t_end);
	// Sleep(1000);
}

int main()
{
	SmallArrayTest();
	cout << endl
		<< endl << "\033[31mXXXXXXXXXXXXXXXXXXXXX-- Every method sort for 100 000 numbers ! --XXXXXXXXXXXXXXXXXXXXX\033[0m" << endl;
	BigArrayTest();
}

