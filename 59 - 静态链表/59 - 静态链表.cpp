#include<iostream>
using namespace std;

struct LinkNode
{
	// ������
	int date;

	// ָ����
	LinkNode* next;
};

void test01()
{
	LinkNode ln01, ln02, ln03, ln04, ln05;

	LinkNode* link_head = &ln01; // �׽ڵ� link_head
	
	// ��ʼ���ṹ�����
	ln01 = { 1, NULL };
	ln02 = { 2, NULL };
	ln03 = { 3, NULL };
	ln04 = { 4, NULL };
	ln05 = { 5, NULL };

	ln01.next = &ln02; // ln01 �� next ָ�� ln02
	ln02.next = &ln03;
	ln03.next = &ln04;
	ln04.next = &ln05;
	ln05.next = NULL; // β�ڵ�

	while (link_head != NULL)
	{
		cout << link_head->date << endl;
		cout << link_head << endl; // ��ӡ��ַ
		link_head = link_head->next; // �ڵ�����ƶ�һλ
	}
}

int main()
{
	test01();
}