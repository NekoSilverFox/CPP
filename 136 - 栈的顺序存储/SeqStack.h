#pragma once
#ifndef SEQSTACK_H
#define SEQSTACK_H
#include<iostream>
#include<string>
using namespace  std;
#define MAX_SIZE 1024

class  Person
{
public:
Person(string name, int age);
public:
	string m_name;
	int m_age;
};

//数组去模拟栈的顺序存储
struct SeqStack
{
	void* data[MAX_SIZE];
	int size;
};

// 初始化栈
SeqStack* Init_Stack();

// 入栈、压栈
void Push_Stack(SeqStack* stack, void* data);

// 返回栈顶元素
void* Top_Stack(SeqStack* stack);

// 出栈
void Pop_Stack(SeqStack* stack);

// 判断栈是否为空
bool IsEmpty_Stack(SeqStack* stack);

// 返回栈中元素个数
int Size_Stack(SeqStack* stack);

// 清空栈
void Clear_Stack(SeqStack* stack);

// 销毁栈
void Disdroy_Stack(SeqStack* stack);

#endif
