#include<iostream>
using namespace std;

struct Students
{
	char* name;
	int age;
	float* scrose;
};

int main()
{
	int n_stu, n_seb;
	// 获知 学生 和 科目 的个数
	cout << "How many students you want : "; cin >> n_stu;
	cout << "How many sebject you want : "; cin >> n_seb;

	// 为 结构体、 姓名、成绩 获取堆空间内存
	Students* t = (Students*)malloc(sizeof(Students) * n_stu);
	//t->name = (char*)malloc(sizeof(char) * 200 * n_stu);						// <-----------Error!
	//t->scrose = (float*)malloc(sizeof(float) * n_seb * n_stu);


	// 通过 for 循环 输入 信息、要注意 t【i】的使用 - 为对应堆空间录入信息
	for (int i = 0; i < n_stu; i++)
	{

		t[i].name = (char*)malloc(sizeof(char) * 200);
		t[i].scrose = (float*)malloc(sizeof(float) * n_seb);

		cout << "Now you are taking Students NO. " << i + 1 << endl;
		cout << "Name: "; cin >> t[i].name;
		cout << "Age: "; cin >> t[i].age;

		for (int j = 0; j < n_seb; j++)
		{
			cout << "Sebject " << j + 1 << " :"; cin >> t[i].scrose[j];
		}
	}

	cout << "======================================" << endl;

	// 打印输出
	for (int i = 0; i < n_stu; i++)
	{
		cout << "Name: " << t[i].name << endl;
		cout << "Age: " << t[i].age << endl;

		for (int j = 0; j < n_seb; j++)
		{
			cout << "Sebject " << j + 1 << " : " << t[i].scrose[j] << endl;
		}
		cout << endl;

	}


	// 释放 堆空间 ，注意释放的顺序！！
	free(t->scrose);
	free(t->name);
	free(t);

	cin.get();
}