#include"LinkQueue.h"

void test01()
{
	LinkQueue<char> char_queue;

	if (char_queue.empty()) cout << "queue is null" << endl;
	else cout << "queue is not null" << endl << endl;

	cout << ">> Insert element  >> Now queue size is -- " << char_queue.size() << endl;
	char_queue.push('A'); cout << ">> Insert element  >> Now queue size is -- " << char_queue.size() << " >> last element is -- " << char_queue.back() << endl;
	char_queue.push('B'); cout << ">> Insert element  >> Now queue size is -- " << char_queue.size() << " >> last element is -- " << char_queue.back() << endl;
	char_queue.push('C'); cout << ">> Insert element  >> Now queue size is -- " << char_queue.size() << " >> last element is -- " << char_queue.back() << endl;
	char_queue.push('D'); cout << ">> Insert element  >> Now queue size is -- " << char_queue.size() << " >> last element is -- " << char_queue.back() << endl;
	char_queue.push('E'); cout << ">> Insert element  >> Now queue size is -- " << char_queue.size() << " >> last element is -- " << char_queue.back() << endl << endl;

	cout << "The first element is " << char_queue.front() << endl;
	cout << "The last element is " << char_queue.back() << endl << endl;

	// char_queue.clear();

	if (char_queue.empty()) cout << "queue is not null" << endl << endl;
	else cout << "queue is null" << endl << endl;

	while (char_queue.empty())
	{
		cout << ">> Pop -- " << char_queue.front() << " >> now the first element is -- ";
		char_queue.pop();
		if(char_queue.empty()) cout << char_queue.front() << endl;
	}

	if (char_queue.empty()) cout << "queue is not null" << endl << endl;
	else cout << "queue is null" << endl << endl;


}

int main()
{
	try
	{
		test01();
	}
	catch (MyErrorInfo& err)
	{
		cout << err.what() << endl;
	}
	
}

