#include <iostream>
using namespace std;

struct StuInfo
{
	char* name;
	int age;
};

int main() {

	StuInfo stu;
	StuInfo* t = &stu;
	//StuInfo* t; // ERROR
	t->name = (char*)malloc(sizeof(char) * 100);

	cout << "Name: "; cin >> t->name;
	cout << "Age: "; cin >> t->age;
	cout << endl;

	cout << "Name: " << t->name << endl;
	cout << "Age: " << t->age << endl;

	free(t->name);
}

