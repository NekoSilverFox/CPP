#include<iostream>
#include<time.h>
#include<sys/timeb.h>
using namespace std;

const int MAX = 100000;

// 冒泡排序 - 冒泡排序通过内层循环找到最小值的###下标###，内层循环结束后才会交换数据
void SelectSort(int arr[], int length)
{
	int min;
	int temp;
	for (int i = 0; i < length; i++)
	{
		min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (arr[j] < arr[min]) min = j;
		}

		if (min != i)
		{
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}

	}
	cout << endl << "================================================================" << endl << endl;
}


// function for print the array
void printArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
		cout << arr[i] << " ";
	cout << endl << "================================================================" << endl << endl;
}

// count the time 
long getSystemTime() {
	timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}

int main()
{
	int arr[MAX];

	// 获取随机数种子
	srand((unsigned int)time(NULL));

	// Init
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	cout << __TIME__ << endl;
	//  printArray(arr, MAX);
	double t_start = getSystemTime();
	SelectSort(arr, MAX);
	double t_end = getSystemTime();
	//  printArray(arr, MAX);

	cout << endl << "Use time : " << (t_end - t_start) / 1000;

}