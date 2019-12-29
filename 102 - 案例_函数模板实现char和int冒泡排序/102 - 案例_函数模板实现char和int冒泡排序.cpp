#include<iostream>
using namespace std;

// Ä£°å ´òÓ¡Êý×é
template<class T>
void printArr(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

// Ä£°å Ã°ÅÝÅÅÐò
template<typename T>
void bubbleAree(T arr[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				T tmp;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int arrInt[] = { 1,5,8,2,9,3,9,5,0 };
	int lenInt = sizeof(arrInt) / sizeof(int);

	char arrChar[] = "fdobsadflo";
	int lenChar = strlen(arrChar); // !!!!!!

	printArr(arrInt, lenInt);
	printArr(arrChar, lenChar);

	// Ä£°å Ã°ÅÝÅÅÐò
	bubbleAree(arrInt, lenInt);
	bubbleAree(arrChar, lenChar);

	printArr(arrInt, lenInt);
	printArr(arrChar, lenChar);
}