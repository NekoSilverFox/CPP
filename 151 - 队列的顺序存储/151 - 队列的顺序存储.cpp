#include "SeqQueue.hpp"
#include <iostream>
using namespace std;

class Person 
{
public:
	char name[64];
	int age;
};

void testQueue()
{

	Person p1 = { "aaa", 10 };
	Person p2 = { "bbb", 20 };
	Person p3 = { "ccc", 30 };
	Person p4 = { "ddd", 40 };
	Person p5 = { "eee", 50 };

	SeqQueue<Person> queue(3);
	queue.push(p1);
	queue.push(p2);
	queue.push(p3);
	queue.push(p4);
	queue.push(p5);


	// first element in queue
	Person firstPerson = queue.front();
	cout << "The first element : " << endl
		<< "Name : " << firstPerson.name << "  Age : " << firstPerson.age << endl << endl;

	// last element in queue
	Person backPerson = queue.back();
	cout << "The last element : " << endl
		<< "Name : " << backPerson.name << "  Age : " << backPerson.age << endl << endl;

	if (!queue.empty()) cout << "null" << endl << endl;
	else cout << "not null" << endl << endl;

	queue.resize(1000);


	while (queue.size() > 0) {

		Person p = queue.front();
		cout << "Size queue : " << queue.size();
		cout << "      Name : " << p.name << "  Age : " << p.age << endl;

		queue.pop();
	}
}

int main()
{
	try
	{
		testQueue();
	}
	catch (exception& err)
	{
		cerr << err.what() << endl;
	}
}