// 204 - ���� - ��������
#include<iostream>
#include<time.h>
#include<sys/timeb.h>
using namespace std;

const int MAX = 100000;


//��n����ǰ���Ѿ�����õ�����
void Insert(int* a, int n)
{
	int i = n - 1;
	int key = a[n];
	while ((i >= 0) && key < a[i])
	{
		a[i + 1] = a[i];
		i--;
	}
	a[i + 1] = key;

}


void Insert_Sort(int* A, int n)
{
	if (n > 0)
	{
		Insert_Sort(A, n - 1); //�ݹ��ʾǰ���Ѿ������
		Insert(A, n);
	}
	else   //�ݹ�ĳ�����n=0
		return;
}



void main()
{
	int A[4] = { 21, 2, 34, 1 };
	Insert_Sort(A, 3);
	for (int i = 0; i < 4; i++)
	{
		cout << A[i] << endl;
	}
	
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
	InsertSort(arr, MAX);
	double t_end = getSystemTime();
	//printArray(arr, MAX);

	cout << endl << "Use time : " << (t_end - t_start) / 1000;

}