#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

HANDLE hNextThreadEvent;

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{

	BOOL bExit=FALSE;
	char str[50];
	int num;
	DWORD dw;

	num = *((int *)lpParameter);
	
	printf("Thread %d begins\n", num);

	while(!bExit)
	{
		dw=WaitForSingleObject(hNextThreadEvent,INFINITE);
		switch (dw)
		{
		case WAIT_OBJECT_0: printf("Thread %d catch Event\n", num); break;
		case WAIT_FAILED: printf("Wait failed\n"); break;
		}
		
		printf("Thread %d in while\n", num);

		gets_s(str,50); 
		printf("User input %s\n",str);

		while((strcmp(str,"next"))&&(strcmp(str,"exit")))
		{
			gets_s(str,50); 
			printf("User input %s\n",str);
		}

		if(!strcmp(str,"exit")) bExit=TRUE;

		printf("Thread %d release control\n", num);

		SetEvent(hNextThreadEvent);

	}

	printf("Thread %d finished\n", num);

	return 0;
}


int main(int argc, char* argv[])
{	
	HANDLE hThreads[2];
	int thargs[2];

	printf("I am main! Hello!\n");
	
	hNextThreadEvent=CreateEvent(NULL,FALSE,FALSE,NULL);

	for (int i = 0; i < 2; i++)
	{
		thargs[i] = i;
		hThreads[i] = CreateThread(NULL, 0, ThreadProc, thargs + i, 0, NULL);

	}
	Sleep(100);

	SetEvent(hNextThreadEvent);
	
	WaitForMultipleObjects(2,hThreads,TRUE,INFINITE);

	CloseHandle(hNextThreadEvent);
	CloseHandle(hThreads[0]);
	CloseHandle(hThreads[1]);

	return 0;
	
}