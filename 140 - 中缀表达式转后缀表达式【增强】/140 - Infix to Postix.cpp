#include"LinkStack.h"

/**************************************************************************************************************************************
	1. ��������ֱ�����
	2. ���ջ������������ȼ����� �Ⱥ���ջ�����������ջ
	3. ���ջ������������ȼ������� �Ⱥ���ջ���������>=��,����ջ��Ԫ�أ�ֱ��ջ��Ԫ�����ȼ����ڵȺ���ջԪ�ص����ȼ�������ջ
	4. ���ŵ����ȼ���ͣ��������������һֻ����ջ�з��ţ�ֱ��ƥ�䵽��Ӧ��������

	 Operation - ���� - ���֧�ѧ�ڧ�
	 priority - ���ȼ� - ���ڧ��ڧ�֧�

**************************************************************************************************************************************/

//Create MyChar
MyChar* CreateMyChar(char* ch) {
	MyChar* mychar = new MyChar;
	mychar->ch = ch;
	return mychar;
}

// Is number or not
bool isNumber(const char ch)
{
	return (ch >= '0' && ch <= '9');
}

// Is the '(' 
bool isLeft(const char ch)
{
	return ch == '(';
}

// Is the ')'
bool isRight(const char ch)
{
	return ch == ')';
}

// Is operator
bool isOperator(const char  ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Get priority - ���ڧ��ڧ�֧�
int getPriority(const char ch)
{
	if (ch == '(') return -1;
	if (ch == '+' || ch == '-') return 1;
	if (ch == '*' || ch == '/') return 2;
	if (ch == '^') return 3;
	return 0;
}


// Operation of Number
void operNumber(string& postix_formula, char ch)
{
	postix_formula += ch;
}

// Operation of Operator
void operOperator(string& postix_formula, LinkStack* stack, char* ch)
{
	MyChar* mychar = (MyChar*)Top_LinkStack(stack);
	if (mychar == nullptr) {
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(ch));
		return;
	}

	if (getPriority(*(mychar->ch)) < getPriority(*ch)) Push_LinkStack(stack, (LinkNode*)CreateMyChar(ch)); // if stack is null or Top_stack > ch; make ch in the stack

	//if(getPriority(*(mychar->ch)) >= getPriority(*ch))
	else
	{
		while (Size_LinkStack(stack) > 0)
		{
			MyChar* mychar2 = (MyChar*)Top_LinkStack(stack);

			//������ȼ��� ��ǰ������ջ
			if (getPriority(*(mychar2->ch)) < getPriority(*ch))
			{
				Push_LinkStack(stack, (LinkNode*)CreateMyChar(ch));
				return;
			}
			postix_formula += *(mychar2->ch);
			Pop_LinkStack(stack);
			delete mychar2;
		}

		//	while (IsEmpty_LinkStack(stack) || getPriority(*(mychar->ch)) < getPriority(*ch)) // if priority Top_stack  > priority ch, pop_stack until it's null or priority ch > Top_stack
		//	{
		//		postix_formula += *(mychar->ch);
		//		// cout << *(mychar->ch);
		//		Pop_LinkStack(stack);
		//		mychar = (MyChar*)Top_LinkStack(stack); //===+++++
		//	}
		//	Push_LinkStack(stack, (LinkNode*)CreateMyChar(ch));
		//}
	}
}

// Operation of '('
void operLeftBracket(LinkStack* stack, char* ch)
{
	Push_LinkStack(stack, (LinkNode*)CreateMyChar(ch));
}

// Operation of ')'
void operRightBracket(string& postix_formula, LinkStack* stack, char ch)
{
	while ((char)Top_LinkStack(stack) != '(')
	{
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		if (isLeft(*(mychar->ch)))
		{
			Pop_LinkStack(stack);
			delete mychar;
			break;
		}
		postix_formula += *(mychar->ch);
		Pop_LinkStack(stack);
		delete mychar;
	}
}

// Infix expression TO Postix expression
string infixToPostix(LinkStack* stack, string infix_formula)
{
	string postix_formula;
	// cout << infix_formula << endl << endl;

	for (int i = 0; i < infix_formula.size(); i++)
	{
		if (isNumber(infix_formula.at(i))) operNumber(postix_formula, infix_formula.at(i));
		if (isOperator(infix_formula.at(i))) operOperator(postix_formula, stack, &(infix_formula.at(i)));
		if (isLeft(infix_formula.at(i))) operLeftBracket(stack, &(infix_formula.at(i)));
		if (isRight(infix_formula.at(i))) operRightBracket(postix_formula, stack, infix_formula.at(i));
	}

	// Pop stack until it's NULL
	while (IsEmpty_LinkStack(stack) == false)
	{
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		postix_formula += *(mychar->ch);
		Pop_LinkStack(stack);
		delete mychar;
	}
	return postix_formula;
}
