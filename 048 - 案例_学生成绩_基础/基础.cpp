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

	// Ϊ �ṹ�塢 �������ɼ� ��ȡ�ѿռ��ڴ�
	Students* t = (Students*)malloc(sizeof(Students) * 3);
	/*t->name = (char*)malloc(sizeof(char) * 200 * 3);
	t->scrose = (float*)malloc(sizeof(float) * 2);*/


	// ͨ�� for ѭ�� ���� ��Ϣ��Ҫע�� t��i����ʹ�� - Ϊ��Ӧ�ѿռ�¼����Ϣ
	for (int i = 0; i <3; i++)
	{

		t[i].name = (char*)malloc(sizeof(char) * 200);
		t[i].scrose = (float*)malloc(sizeof(float) * 2);

		cout << "Now you are taking Students NO. " << i + 1 << endl;
		cout << "Name: "; cin >> t[i].name;
		cout << "Age: "; cin >> t[i].age;

		for (int j = 0; j < 2; j++)
		{
			cout << "Sebject " << j + 1 << " :"; cin >> t[i].scrose[j];
		}
	}

	cout << "======================================" << endl;

	// ��ӡ���
	for (int i = 0; i < 3; i++)
	{
		cout << "Name: " << t[i].name << endl;
		cout << "Age: " << t[i].age << endl;

		for (int j = 0; j < 2; j++)
		{
			cout << "Sebject " << j + 1 << " : " << t[i].scrose[j] << endl;
		}
		cout << endl;

	}


	// �ͷ� �ѿռ� ��ע���ͷŵ�˳�򣡣�
	free(t->scrose);
	free(t->name);
	free(t);

	cin.get();
}