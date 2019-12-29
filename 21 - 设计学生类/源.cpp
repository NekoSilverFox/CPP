// 2.	设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓   名和学号

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
		cout << "姓名：" << stu_name << endl;
		cout << "ID：" << stu_id << endl;
	}
};


int main() {

	Student stu1;

	string name;
	int id;

	cout << setw(30) << setfill('=');

	cout << "请输入姓名："; cin >> name;  stu1.setName(name);
	cout << "请输入ID："; cin >> id; stu1.setID(id);
	stu1.printInfo();

	return 0;
}