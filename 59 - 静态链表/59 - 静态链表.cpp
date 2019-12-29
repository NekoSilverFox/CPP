#include<iostream>
using namespace std;

struct LinkNode
{
	// 数据域
	int date;

	// 指针域
	LinkNode* next;
};

void test01()
{
	LinkNode ln01, ln02, ln03, ln04, ln05;

	LinkNode* link_head = &ln01; // 首节点 link_head
	
	// 初始化结构体变量
	ln01 = { 1, NULL };
	ln02 = { 2, NULL };
	ln03 = { 3, NULL };
	ln04 = { 4, NULL };
	ln05 = { 5, NULL };

	ln01.next = &ln02; // ln01 的 next 指向 ln02
	ln02.next = &ln03;
	ln03.next = &ln04;
	ln04.next = &ln05;
	ln05.next = NULL; // 尾节点

	while (link_head != NULL)
	{
		cout << link_head->date << endl;
		cout << link_head << endl; // 打印地址
		link_head = link_head->next; // 节点向后移动一位
	}
}

int main()
{
	test01();
}