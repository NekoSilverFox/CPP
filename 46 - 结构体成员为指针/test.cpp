#include <iostream>
using namespace std;
const int N = 100;
int NOSTUDENTS;

struct Students
{
	char* name;
	int score[2];
};

// 申请空间及赋值
void memAndCin(int NOSTUDENTS)
{
	//	Students stu[NOSTUDENTS];

	for (int i = 0; i < NOSTUDENTS; i++)
	{
		cout << "Students No. " << i + 1 << endl;

		stu[i].name = (char*)malloc(sizeof(char) * N);
		cout << "Name: "; cin >> stu[i].name;

		cout << "Score 1 : "; cin >> stu[i].score[0];
		cout << "Score 2 : "; cin >> stu[i].score[1];
		cout << endl;
	}
}


// 信息输出
void infoOut(int NOSTUDENTS)
{
	for (int i = 0; i < NOSTUDENTS; i++)
	{
		cout << "Student NO. " << i + 1 << endl;
		cout << "Name: " << stu[i].name << endl;
		cout << "Score 1: " << stu[i].score[0] << endl;
		cout << "Score 2: " << stu[i].score[1] << endl << endl;
	}
}

void deleteMem(int NOSTUDENTS)
{
	// 释放堆空间
	for (int i = 0; i < NOSTUDENTS; i++)
	{
		free(stu[i].name);
	}
}

int main()
{


	cout << "How many students do you want take in :"; cin >> NOSTUDENTS;

	Students* stu[NOSTUDENTS] = malloc;

	memAndCin(NOSTUDENTS);

	cout.width(40) << cout.fill('+');
	cout << endl;

	infoOut(NOSTUDENTS);
	deleteMem(NOSTUDENTS);


}