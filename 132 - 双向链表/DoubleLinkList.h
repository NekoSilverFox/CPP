#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;
#ifndef H_COMPLEX
#define H_COMPLEX

typedef struct DouLinkNode
{
	int date;
	DouLinkNode* pre, * next;
	unsigned int static lenth;
};
unsigned int DouLinkNode::lenth = 0;

// ��ʼ������
DouLinkNode* Init_LinkList();

// �� ֵΪ oldval �������һ���µ����� newval
void InSetByValue_LinkList(DouLinkNode* header);

// ɾ��ֵΪval�Ľڵ�
void RemByValue_LinkList(DouLinkNode* header);

// ����
void ForEach_LinkList(DouLinkNode* header);

// ����
void Destroy_LinkNode(DouLinkNode* header);

// ���
void Clear_LinkList(DouLinkNode* header);

#endif