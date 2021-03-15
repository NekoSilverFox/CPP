#include <iostream>
using namespace std;

struct Students
{
	char* name;
	int age;
};

// 申请内存
void memGet(int n)
{
}


// 录入数据
void infoIn(int n)
{

}



int main()
{
	/*int n;
	cout << "How many students you want to take in: "; cin >> n;*/

	// 申请内存
	Students* t = (Students*)malloc(sizeof(Students));
	t->name = (char*)malloc(sizeof(char) * 200);


	// 录入数据
	cout << "Name: "; cin >> t->name;
	cout << "Age: "; cin >> t->age;

	cout.width(50) | cout.fill('=');

	cout << endl;

	cout << "Name: " << t->name << endl;
	cout << "Age: " << t->age << endl;

	// 释放堆空间内存
	free(t->name);
	free(t);


}