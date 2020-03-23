#include<iostream>
using namespace std;

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

int main()
{
	int arr[] = { 4,2,8,0,5,7,1,3,9 };
	printArray(arr, sizeof(arr) / sizeof(int));
	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	printArray(arr, sizeof(arr) / sizeof(int));

}