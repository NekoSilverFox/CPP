#include<iostream>
#include<ctime>
#include<conio.h>

using namespace std;

// 提示
void tips()
{
	cout << "---------------------------------------打字游戏---------------------------------------" << endl;
	cout << "===============================请按任意键继续，ESC退出================================" << endl;
	cout << "============ 规则：请在英文状态下输入，如果输入的不正确 会以 “ - ”标记 ============" << endl;
	// _getch() 只识别输入的单个字符，并不会打印到屏幕上！
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
	cout << endl << "用时：" << end_time - start_time << "s" << endl;

}

int main()
{
	char letter[51];

	// 死循环
	while (true)
	{
		double num_right = 0;

		// 提示
		tips();

		// 生成随机数，并通过指针输入到数组中
		rand_letter(letter);

		// 判断输入的是否正确，
		check_letter(letter, &num_right);

		cout << "正确率：" << (num_right / 50.00) * 100 << "%" << endl;

		cout << "==========================按任意键重开一局=========================" << endl;
		_getch();

		system("cls"); // 清屏操作 ， 要调用头文件 conio.h
	}



}