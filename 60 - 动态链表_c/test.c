#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"标头.h"

void test()
{
	//初始化链表 100 200 666 300 400 500 600
	struct LinkNode* header = Init_LinkList();
	//打印链表
	Foreach_LinkList(header);
	//插入数据
	InsertByValue_LinkList(header, 200, 666);
	//打印链表
	printf("\n-------------------\n");
	Foreach_LinkList(header);

	//清空链表
	Clear_LinkList(header);
	//打印链表

	InsertByValue_LinkList(header, 1000, 111);
	InsertByValue_LinkList(header, 1000, 211);
	InsertByValue_LinkList(header, 1000, 311);
	InsertByValue_LinkList(header, 1000, 411);

	printf("\n-------------------\n");
	Foreach_LinkList(header);


	RemoveByValue_LinkList(header, 311);
	printf("\n-------------------\n");
	Foreach_LinkList(header);

	RemoveByValue_LinkList(header, 211);
	printf("\n-------------------\n");
	Foreach_LinkList(header);

	//销毁链表
	Destroy_LinkList(header);
	//打印链表
	Foreach_LinkList(header);

}

int main() {

	test();

	system("pause");
	return EXIT_SUCCESS;
}