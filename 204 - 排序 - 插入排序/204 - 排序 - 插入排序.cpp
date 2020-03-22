// 204 - ���� - ��������
#include<iostream>
#include<time.h>
#include<sys/timeb.h>
using namespace std;

const int MAX = 100000;

void SelectSort(int arr[], int length)
{
	int j;
	for (int i = 1; i < length; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			int temp = arr[i];
			for (j = i - 1; j >= 0 && temp < arr[j]; j--)
			{
				arr[j + 1] = arr[j]; //��������һ���գ�����վ��� arr[j + 1] !!!!
			}
			arr[j + 1] = temp;
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

	// ��ȡ���������
	srand((unsigned int)time(NULL));

	// Init
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	cout << __TIME__ << endl;
	//printArray(arr, MAX);
	double t_start = getSystemTime();
	SelectSort(arr, MAX);
	double t_end = getSystemTime();
	//printArray(arr, MAX);

	cout << endl << "Use time : " << (t_end - t_start) / 1000;

}