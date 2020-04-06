#include <Windows.h>
#include <stdio.h>

int main()
{
	int value_time;
	 char name_user[100];

	 printf("轰炸对象姓名 ："); scanf_s("%s", &name_user, 40);
	 printf("轰炸次数：", &value_time); scanf_s("%d", &value_time);

	// string name_user;
	//cout << "轰炸对象姓名 ："; cin >> name_user;
	//cout << "轰炸次数："; cin >> value_time;

	// 找到对话窗口
	HWND H = FindWindow (0, name_user);
	for (int i = 0; i < value_time; i++)
	{
		SendMessage(H, WM_PASTE, 0, 0); // 粘贴内容
		SendMessage(H, WM_KEYDOWN, VK_RETURN, 0); // 回车发送
	}
}