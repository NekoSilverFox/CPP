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
// ��ʼ��
LinkStack* InIt_LinkStack();

// ѹջ
void Push_LinkStack(LinkStack* stack, LinkNode* data);

// ����ջ��Ԫ��
LinkNode* Top_LinkStack(LinkStack* stack);

// ����Ԫ�ظ���
int Size_LinkStack(LinkStack* stack);

// �ж��Ƿ�Ϊ��
bool IsEmpty_LinkStack(LinkStack* stack);

// ��ջ
void Pop_LinkStack(LinkStack* stack);

// ���ջ
void Clear_LinkStack(LinkStack* stack);

// ����ջ
void Desgroy_LinkStack(LinkStack* stack);

#endif