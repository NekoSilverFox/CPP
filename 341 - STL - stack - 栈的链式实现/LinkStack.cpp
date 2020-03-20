#include"LinkStack.h"

void test01()
{
	LinkStack<char> char_stack;

	if (char_stack.empty()) cout << "stack is null" << endl;
	else cout << "stack is not null" << endl << endl;

	cout << ">> Insert element  >> Now stack size is -- " << char_stack.size() << endl;
	char_stack.push('A'); cout << ">> Insert element  >> Now stack size is -- " << char_stack.size() << " >> The top element is -- " << char_stack.top() << endl;
	char_stack.push('B'); cout << ">> Insert element  >> Now stack size is -- " << char_stack.size() << " >> The top element is -- " << char_stack.top() << endl;
	char_stack.push('C'); cout << ">> Insert element  >> Now stack size is -- " << char_stack.size() << " >> The top element is -- " << char_stack.top() << endl;
	char_stack.push('D'); cout << ">> Insert element  >> Now stack size is -- " << char_stack.size() << " >> The top element is -- " << char_stack.top() << endl;
	char_stack.push('E'); cout << ">> Insert element  >> Now stack size is -- " << char_stack.size() << " >> The top element is -- " << char_stack.top() << endl << endl;

	// char_stack.clear();

	if (char_stack.empty()) cout << "stack is not null" << endl << endl;
	else cout << "stack is null" << endl << endl;

	while (char_stack.empty())
	{
		cout << ">> Pop -- " << char_stack.top();
		char_stack.pop();
		cout << " >> now the top element is -- " << char_stack.top() << endl;
	}

	if (char_stack.empty()) cout << "stack is not null" << endl << endl;
	else cout << "stack is null" << endl << endl;
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

