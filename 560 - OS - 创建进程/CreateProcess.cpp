#include <windows.h>
#include <stdio.h>
#include <string.h>

// процесс - 进程


// LPCWSTR是一个指向unicode编码字符串的32位指针，所指向字符串是wchar型，而不是char型。
LPCWSTR lpCommandLine[3] = { L"C:\\WINDOWS\\SYSTEM32\\NOTEPAD.EXE temp.txt",
L"C:\\WINDOWS\\sYSTEM32\\CALC.EXE",L"C:\\WINNT\\SYSTEM32\\CHARMAP.EXE" };
// charmap.exe是微软Micorsoft Windows工具，用于帮助你定位非标准字符集

// STARTUPINFO用于指定新进程的主窗口特性的一个结构
STARTUPINFO startInfo;

// PROCESS_INFORMATION 创建进程时相关的数据结构之一，该结构返回有关新进程及其主线程的信息
PROCESS_INFORMATION processInfo;

int main(int argc, char* argv[])
{
	// ZeroMemory只是将指定的内存块清零
	ZeroMemory(&startInfo, sizeof(STARTUPINFO));
	startInfo.cb = sizeof(startInfo);

	WCHAR proc_name[256];
	for (int i = 0; i < 3; i++)
	{
		wcscpy_s(proc_name, wcslen(lpCommandLine[i]) + 1, lpCommandLine[i]);
		printf("!!!%ls %d\n", lpCommandLine[i], wcslen(lpCommandLine[i]));

		if (!CreateProcess(NULL, proc_name, NULL, NULL, FALSE,
			HIGH_PRIORITY_CLASS | CREATE_NEW_CONSOLE, NULL, NULL,
			&startInfo, &processInfo))
		{
			fprintf(stderr, "CreateProcess failed on error %d\n", GetLastError());
			ExitProcess(1);
		}
	}



	printf("ProcessHandle=%d\n", (int)processInfo.hProcess);
	printf("ThreadHandle=%d\n", (int)processInfo.hThread);

	CloseHandle(processInfo.hProcess);
	CloseHandle(processInfo.hThread);
	return 0;
}