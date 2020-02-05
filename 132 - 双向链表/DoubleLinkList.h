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

// 初始化链表
DouLinkNode* Init_LinkList();

// 在 值为 oldval 后面插入一个新的数据 newval
void InSetByValue_LinkList(DouLinkNode* header);

// 删除值为val的节点
void RemByValue_LinkList(DouLinkNode* header);

// 遍历
void ForEach_LinkList(DouLinkNode* header);

// 销毁
void Destroy_LinkNode(DouLinkNode* header);

// 清空
void Clear_LinkList(DouLinkNode* header);

#endif