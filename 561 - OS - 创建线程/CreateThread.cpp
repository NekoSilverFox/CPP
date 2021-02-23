
#include <windows.h>
#include <stdio.h>
#include <string.h>

// нить / поток - 线程

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	int param;
	param = *(int*)lpParameter;

	printf("I am ThreadProc=%d Hello!\n", param);

	while (TRUE)
	{
		printf("ThreadProc=%d in while!\n", param);

		Sleep(100);
	}

}

int main(int argc, char* argv[])
{
	HANDLE mHandle[2];
	DWORD mArg[2], mId[2];
	int i;

	printf("I am main! Hello!\n");

	for (i = 0; i < 2; i++)
	{
		mArg[i] = i;
		mHandle[i] = CreateThread(NULL, 0, ThreadProc, mArg + i, 0, mId + i);
	}

	Sleep(1000);

	/*	while(TRUE)
		{
			printf("Main in while!\n");

			Sleep(100);
		}*/
	return 0;

}