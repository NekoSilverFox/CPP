#pragma once
#ifndef LINKSTACK_H
#define LINKSTACK_H
#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;

struct LinkNode
{
	LinkNode* next;
};

struct LinkStack
{
	LinkNode header;
	int size;
};
// 初始化
LinkStack* InIt_LinkStack();

// 压栈
void Push_LinkStack(LinkStack* stack, LinkNode* data);

// 弹出栈顶元素
LinkNode* Top_LinkStack(LinkStack* stack);

// 返回元素个数
int Size_LinkStack(LinkStack* stack);

// 判断是否为空
bool IsEmpty_LinkStack(LinkStack* stack);

// 出栈
void Pop_LinkStack(LinkStack* stack);

// 清空栈
void Clear_LinkStack(LinkStack* stack);

// 销毁栈
void Desgroy_LinkStack(LinkStack* stack);

/**************************************************************************************************************************************/
// Is number or not
bool isNumber(const char ch);

// Is the '('
bool isLeft(const char ch);

// Is the ')'
bool isRight(const char ch);

// Is operator
bool isOperator(const char  ch);

// Get priority - приоритет
int getPriority(const char ch);

// Operation of Number
void operNumber(string& postix_formula, char ch);

// Operation of Operator
void operOperator(string& postix_formula, LinkStack* stack, char* ch);

// Operation of '('
void operLeftBracket(LinkStack* stack, char* ch);

// Operation of ')'
void operRightBracket(string& postix_formula, LinkStack* stack, char ch);

// Infix expression TO Postix expression
string infixToPostix(LinkStack* stack, string infix_formula);

double Calculate(LinkStack* stack, string postix_formula);
/**************************************************************************************************************************************/

#endif
