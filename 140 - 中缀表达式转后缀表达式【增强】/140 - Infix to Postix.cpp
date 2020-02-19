#include"LinkStack.h"

/**************************************************************************************************************************************
	1. ��������ֱ�����
	2. ���ջ������������ȼ����� �Ⱥ���ջ�����������ջ
	3. ���ջ������������ȼ������� �Ⱥ���ջ���������>=��,����ջ��Ԫ�أ�ֱ��ջ��Ԫ�����ȼ����ڵȺ���ջԪ�ص����ȼ�������ջ
	4. ���ŵ����ȼ���ͣ��������������һֻ����ջ�з��ţ�ֱ��ƥ�䵽��Ӧ��������

	 Operation - ���� - ���֧�ѧ�ڧ�
	 priority - ���ȼ� - ���ڧ��ڧ�֧�

**************************************************************************************************************************************/

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
}


// Operation of Number

// Operation of Operator

// Operation of '('

// Operation of ')'

// Infix expression TO Postix expression
string infixToPostix(LinkStack* stack, string infix_formula)
{
	string postix_formula;

	return postix_formula;
}
