#include"LinkQueue.h"

class Person
{
public:
	string name_;
	int age_;
};

Person* CreatPerson(string name, int age)
{
	Person* per = new Person;
	per->name_ = name;
	per->age_ = age;
	return per;
}

void test()
{
	LinkQueue* queue = Init_LinkQueue();

	Push_LinkQueue(queue, (LinkNode*)CreatPerson("aaa", 12));
	Push_LinkQueue(queue, (LinkNode*)CreatPerson("bbb", 13));
	Push_LinkQueue(queue, (LinkNode*)CreatPerson("ccc", 14));
	Push_LinkQueue(queue, (LinkNode*)CreatPerson("ddd", 15));
	Push_LinkQueue(queue, (LinkNode*)CreatPerson("eee", 16));
	Push_LinkQueue(queue, (LinkNode*)CreatPerson("fff", 17));

	cout << Size_LinkQueue(queue);

 	Person* temp = (Person*)Frount_LinkQueue(queue);
	cout << "First : " << temp->name_ << "   " << temp->age_ << endl << endl;

	temp = (Person*)Back_LinkQueue(queue);
	cout << "Last : " << temp->name_ << "   " << temp->age_ << endl << endl;

	while (IsEmpty_LinkQueue(queue))
	{
		Pop_LinkQueue(queue);
		temp = (Person*)Frount_LinkQueue(queue);
		cout << temp->name_ << "   " << temp->age_ << endl;
	}
}
int main()
{
	test();
}