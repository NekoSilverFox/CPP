// 2.	���һ��ѧ���࣬������������ѧ�ţ����Ը�������ѧ�Ÿ�ֵ��������ʾѧ������   ����ѧ��

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Student {

public:
	
	string stu_name;
	int stu_id;

	void setName(string name) {
		stu_name = name;
	}

	void setID(int id) {
		stu_id = id;
	}

	void printInfo() {
		cout << "������" << stu_name << endl;
		cout << "ID��" << stu_id << endl;
	}
};


int main() {

	Student stu1;

	string name;
	int id;

	cout << setw(30) << setfill('=');

	cout << "������������"; cin >> name;  stu1.setName(name);
	cout << "������ID��"; cin >> id; stu1.setID(id);
	stu1.printInfo();

	return 0;
}