#include <iostream>
using namespace std;

struct Students
{
	char* name;
	int age;
};

// �����ڴ�
void memGet(int n)
{
}


// ¼������
void infoIn(int n)
{

}



int main()
{
	/*int n;
	cout << "How many students you want to take in: "; cin >> n;*/

	// �����ڴ�
	Students* t = (Students*)malloc(sizeof(Students));
	t->name = (char*)malloc(sizeof(char) * 200);


	// ¼������
	cout << "Name: "; cin >> t->name;
	cout << "Age: "; cin >> t->age;

	cout.width(50) | cout.fill('=');

	cout << endl;

	cout << "Name: " << t->name << endl;
	cout << "Age: " << t->age << endl;

	// �ͷŶѿռ��ڴ�
	free(t->name);
	free(t);


}