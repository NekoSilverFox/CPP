#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;
#ifndef H_COMPLEX
#define H_COMPLEX

// ����ڵ���������
struct LinkNode
{
	// ������
	int data;

	// ָ����
	LinkNode* next;
};

// ��ʼ������
LinkNode* Init_LinkList();

// �� ֵΪ oldval �������һ���µ����� newval
void InSetByValue_LinkList(LinkNode* herder, int old_val, int new_val);

// ɾ��ֵΪval�Ľڵ�
void RemByValue_LinkList(LinkNode* header, int del_val);

// ����
void ForEach_LinkList(LinkNode* header);

// ����
void Destroy_LinkNode(LinkNode* header);

// ���
void Clear_LinkList(LinkNode* header);

#endif // DEBUG




