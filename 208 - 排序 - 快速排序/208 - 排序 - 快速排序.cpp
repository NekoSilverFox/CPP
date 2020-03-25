#include<iostream>
#include<time.h>
#include<sys/timeb.h>
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


void QuickSort(int arr[], int start_arr, int end_arr)
{
	int i = start_arr;
	int j = end_arr;

	//��׼��
	int temp = arr[start_arr];

	if (i < j)
	{

		while (i < j)
		{

			// from right to left, find which num is smaller than temp
			while (i < j && arr[j] >= temp) j--;
			//���
			if (i < j)
			{
				arr[i] = arr[j];
				i++;
			}

			// from left to right, find which num is bigger than temp
			while (i < j && arr[i] < temp) i++;
			//���
			if (i < j)
			{
				arr[j] = arr[i];
				j--;
			}
		}
		//�ѻ�׼���ŵ�i/ jλ��
		arr[i] = temp;

		//����벿�ֽ��п�������
		QuickSort(arr, start_arr, i - 1);

		//���Ұ벿�ֽ��п�������
		QuickSort(arr, i + 1, end_arr);
	}

}

void printArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// count the time 
long getSystemTime() {
	timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}

int main()
{
	int length = 100000000;
	int max = 100000000;
	int* arr = CreatArray(length, max);

	// printArray(arr, length);
	double t_start = getSystemTime();
	QuickSort(arr, 0, length);
	double t_end = getSystemTime();
	// printArray(arr, length);

	cout << endl << "Use time : " << (t_end - t_start) / 1000;



}