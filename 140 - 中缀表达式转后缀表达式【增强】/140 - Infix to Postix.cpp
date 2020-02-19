#include"LinkStack.h"

/**************************************************************************************************************************************
	1. 遇到数字直接输出
	2. 如果栈顶运算符的优先级低于 等候入栈的运算符，进栈
	3. 如果栈顶运算符的优先级不低于 等候入栈的运算符（>=）,弹出栈中元素，直到栈顶元素优先级低于等候入栈元素的优先级，再入栈
	4. 括号的优先级最低，如果遇到右括号一只弹出栈中符号，直到匹配到相应的右括号

	 Operation - 操作 - операция
	 priority - 优先级 - приоритет

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

// Get priority - приоритет
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
