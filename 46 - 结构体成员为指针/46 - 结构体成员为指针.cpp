#include <iostream>
using namespace std;
const int N = 100;

struct Students
{
	char* name;
	int score[2];
};



int main()
{
	Students stu[3];
	
	// ����ռ估��ֵ
	for (int i = 0; i < 3; i++)
	{
		cout << "Students No. " << i + 1 << endl;

		stu[i].name = (char*)malloc(sizeof(char) * N);
		cout << "Name: "; cin >> stu[i].name;

		cout << "Score 1 : "; cin >> stu[i].score[0];
		cout << "Score 2 : "; cin >> stu[i].score[1];
		cout << endl;
	}

	cout.width(40) << cout.fill('+');
	cout << endl;


	// ��Ϣ���
	for (int i = 0; i < 3; i++)
	{
		cout << "Student NO. " << i + 1 << endl;
		cout << "Name: " << stu[i].name << endl;
		cout << "Score 1: " << stu[i].score[0] << endl;
		cout << "Score 2: " << stu[i].score[1] << endl << endl;
	}

	// �ͷŶѿռ�
	for (int i = 0; i < 3; i++)
	{
		free(stu[i].name);
	}
}