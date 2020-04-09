// 204 - 排序 - 插入排序
#include<iostream>
#include<time.h>
#include<sys/timeb.h>
using namespace std;

const int MAX = 100000;


//把n插入前面已经排序好的数组
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
		Insert_Sort(A, n - 1); //递归表示前面已经排序好
		Insert(A, n);
	}
	else   //递归的出口是n=0
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

	// 获取随机数种子
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