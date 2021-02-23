
#include <windows.h>
#include <stdio.h>
#include <string.h>

// нить / поток - 线程


// LPVOID 是一个没有类型的指针
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	int param;
	param = *(int*)lpParameter;

	printf("I am ThreadProc=%d Hello!\n", param);

	while (TRUE)
	{
		printf("ThreadProc=%d in while!\n", param);

		Sleep(100); // ms - миллисекунда
	}

}

int main(int argc, char* argv[])
{
	// HANDLE 在程序设计中，句柄（handle）是Windows操作系统用来标识被应用程序所建立或使用的对象的整数。
	// 其本质相当于带有引用计数的智能指针。当一个应用程序要引用其他系统（如数据库、操作系统）所管理的内存块或对象时，可以使用句柄。

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

	//while(TRUE)
	//	{
	//		printf("Main in while!\n");

	//		Sleep(100);
	//	}
	return 0;

}