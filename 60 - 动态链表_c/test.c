#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"��ͷ.h"

void test()
{
	//��ʼ������ 100 200 666 300 400 500 600
	struct LinkNode* header = Init_LinkList();
	//��ӡ����
	Foreach_LinkList(header);
	//��������
	InsertByValue_LinkList(header, 200, 666);
	//��ӡ����
	printf("\n-------------------\n");
	Foreach_LinkList(header);

	//�������
	Clear_LinkList(header);
	//��ӡ����

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

	//��������
	Destroy_LinkList(header);
	//��ӡ����
	Foreach_LinkList(header);

}

int main() {

	test();

	system("pause");
	return EXIT_SUCCESS;
}