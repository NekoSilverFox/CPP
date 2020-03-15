#include"LinkQueue.h"

void test01()
{
	LinkQueue<char> char_queue;

	if (char_queue.empty_LQ()) cout << "queue is null" << endl;
	else cout << "queue is not null" << endl << endl;

	cout << ">> Insert element  >> Now queue size is -- " << char_queue.size_LQ() << endl;
	char_queue.push_LQ('A'); cout << ">> Insert element  >> Now queue size is -- " << char_queue.size_LQ() << " >> last element is -- " << char_queue.back_LQ() << endl;
	char_queue.push_LQ('B'); cout << ">> Insert element  >> Now queue size is -- " << char_queue.size_LQ() << " >> last element is -- " << char_queue.back_LQ() << endl;
	char_queue.push_LQ('C'); cout << ">> Insert element  >> Now queue size is -- " << char_queue.size_LQ() << " >> last element is -- " << char_queue.back_LQ() << endl;
	char_queue.push_LQ('D'); cout << ">> Insert element  >> Now queue size is -- " << char_queue.size_LQ() << " >> last element is -- " << char_queue.back_LQ() << endl;
	char_queue.push_LQ('E'); cout << ">> Insert element  >> Now queue size is -- " << char_queue.size_LQ() << " >> last element is -- " << char_queue.back_LQ() << endl << endl;

	cout << "The first element is " << char_queue.front_LQ() << endl;
	cout << "The last element is " << char_queue.back_LQ() << endl << endl;

	// char_queue.clear_LQ();

	if (char_queue.empty_LQ()) cout << "queue is not null" << endl << endl;
	else cout << "queue is null" << endl << endl;

	while (char_queue.empty_LQ())
	{
		cout << ">> Pop -- " << char_queue.front_LQ() << " >> now the first element is -- ";
		char_queue.pop_LQ();
		if(char_queue.empty_LQ()) cout << char_queue.front_LQ() << endl;
	}

	if (char_queue.empty_LQ()) cout << "queue is not null" << endl << endl;
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

