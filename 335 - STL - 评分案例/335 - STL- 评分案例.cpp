#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

class Student
{
public:
	Student(string name) : name_(name), score(0) {}
public:
	deque<int> d;
	string name_;
	double score;
};

void mark_fun()
{
	Student s1("A");
	Student s2("B");
	Student s3("C");
	Student s4("D");
	Student s5("E");

	vector<Student> v;
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);
	v.push_back(s5);

	for (vector<Student>::iterator it = v.begin(); it != v.end(); it++)
	{

		sort((*it).d.begin(), (*it).d.end());
		(*it).d.pop_back();
		(*it).d.pop_front();

		for (int i = 0; i < (*it).d.size(); i++)
		{
			(*it).score += (*it).d.at(i);
		}
		(*it).score = (*it).score / (*it).d.size();
		cout << "Student - " << (*it).name_ << "  |  Mark = " << (*it).score;
	}
}

int main()
{
	mark_fun();
}