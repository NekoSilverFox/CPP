#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

#ifdef __cplusplus
extern "C" {
#endif


	//定义节点数据类型
	struct LinkNode
	{
		int data;
		struct LinkNode* next;
	};

	//初始化链表
	struct LinkNode* Init_LinkList();
	//在值为oldval的位置插入新的数据newval
	void InsertByValue_LinkList(struct LinkNode* header, int oldval, int newval);
	//删除值为val的结点
	void RemoveByValue_LinkList(struct LinkNode* header, int delValue);
	//遍历
	void Foreach_LinkList(struct LinkNode* header);
	//销毁
	void Destroy_LinkList(struct LinkNode* header);
	//清空
	void Clear_LinkList(struct LinkNode* header);


#ifdef __cplusplus
}
#endif
