#include <Windows.h>
#include <stdio.h>

int main()
{
	int value_time;
	 char name_user[100];

	 printf("��ը�������� ��"); scanf_s("%s", &name_user, 40);
	 printf("��ը������", &value_time); scanf_s("%d", &value_time);

	// string name_user;
	//cout << "��ը�������� ��"; cin >> name_user;
	//cout << "��ը������"; cin >> value_time;

	// �ҵ��Ի�����
	HWND H = FindWindow (0, name_user);
	for (int i = 0; i < value_time; i++)
	{
		SendMessage(H, WM_PASTE, 0, 0); // ճ������
		SendMessage(H, WM_KEYDOWN, VK_RETURN, 0); // �س�����
	}
}