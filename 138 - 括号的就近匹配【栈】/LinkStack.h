#pragma once
#pragma once
#ifndef LINKSTACK_H
#define LINKSTACK_H
#include <iostream>
#include <string>
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

#endif