#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;
#ifndef H_COMPLEX
#define H_COMPLEX

//class Date
//{
//public:
//	int val;
//};


class LinkNode
{
public:
	//LinkNode();

public:
	int date;
	LinkNode* next;
};

// 初始化链表
LinkNode* Init_LinkList();

// 在 值为 oldval 后面插入一个新的数据 newval
void InSetByValue_LinkList(LinkNode* herder, int old_val, int new_val);

// 删除值为val的节点
void RemByValue_LinkList(LinkNode* header, int del_val);

// 遍历
void ForEach_LinkList(LinkNode* header);

// 销毁
void Destroy_LinkNode(LinkNode* header);

// 清空
void Clear_LinkList(LinkNode* header);

#endif