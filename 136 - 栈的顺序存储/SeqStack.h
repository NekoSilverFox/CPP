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

//����ȥģ��ջ��˳��洢
struct SeqStack
{
	void* data[MAX_SIZE];
	int size;
};

// ��ʼ��ջ
SeqStack* Init_Stack();

// ��ջ��ѹջ
void Push_Stack(SeqStack* stack, void* data);

// ����ջ��Ԫ��
void* Top_Stack(SeqStack* stack);

// ��ջ
void Pop_Stack(SeqStack* stack);

// �ж�ջ�Ƿ�Ϊ��
bool IsEmpty_Stack(SeqStack* stack);

// ����ջ��Ԫ�ظ���
int Size_Stack(SeqStack* stack);

// ���ջ
void Clear_Stack(SeqStack* stack);

// ����ջ
void Disdroy_Stack(SeqStack* stack);

#endif
