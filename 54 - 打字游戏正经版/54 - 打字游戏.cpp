#include<iostream>
#include<ctime>
#include<conio.h>

using namespace std;

// ��ʾ
void tips()
{
	cout << "---------------------------------------������Ϸ---------------------------------------" << endl;
	cout << "===============================�밴�����������ESC�˳�================================" << endl;
	cout << "============ ��������Ӣ��״̬�����룬�������Ĳ���ȷ ���� �� - ����� ============" << endl;
	// _getch() ֻʶ������ĵ����ַ����������ӡ����Ļ�ϣ�
	char ch = _getch();
	// cin >> ch; <----- Neend't !!!

	if (ch != 27)
	{
		cout << endl;
	}
	else
	{
		exit(0);
	}
}

void rand_letter(char* letter)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 50; i++)
	{
		letter[i] = rand() % 26 + 'a';
		cout << letter[i];
	}
	cout << endl;
}

void check_letter(char* letter, double* num_right)
{
	int start_time, end_time;
	for (int i = 0; i < 50; i++)
	{
		if (i == 0)
		{
			start_time = time(NULL);
		}

		char ch = _getch();

		if (ch == letter[i])
		{
			cout << ch;
			(*num_right)++;
		}
		else
		{
			cout << "-";
		}
	}
	end_time = time(NULL);
	cout << endl << "��ʱ��" << end_time - start_time << "s" << endl;

}

int main()
{
	char letter[51];

	// ��ѭ��
	while (true)
	{
		double num_right = 0;

		// ��ʾ
		tips();

		// �������������ͨ��ָ�����뵽������
		rand_letter(letter);

		// �ж�������Ƿ���ȷ��
		check_letter(letter, &num_right);

		cout << "��ȷ�ʣ�" << (num_right / 50.00) * 100 << "%" << endl;

		cout << "==========================��������ؿ�һ��=========================" << endl;
		_getch();

		system("cls"); // �������� �� Ҫ����ͷ�ļ� conio.h
	}



}