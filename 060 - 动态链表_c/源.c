#include"��ͷ.h"


//��ʼ������
struct LinkNode* Init_LinkList()
{

	//����ͷ���
	struct LinkNode* header = malloc(sizeof(struct LinkNode));
	header->data = -1;
	header->next = NULL;

	//β��ָ��
	struct LinkNode* pRear = header;

	int val = -1;
	while (true)
	{

		printf("������������:\n");
		scanf("%d", &val);
		if (val == -1)
		{
			break;
		}

		//�ȴ����½ڵ�
		struct LinkNode* newnode = malloc(sizeof(struct LinkNode));
		newnode->data = val;
		newnode->next = NULL;

		//�½ڵ���뵽������
		pRear->next = newnode;

		//����β��ָ��ָ��
		pRear = newnode;


	}

	return header;
}

void InsertByValue_LinkList(struct LinkNode* header, int oldval, int newval)
{
	if (NULL == header)
	{
		return;
	}


	//��������ָ�����
	struct LinkNode* pPrev = header;
	struct LinkNode* pCurrent = pPrev->next;

	while (pCurrent != NULL)
	{

		if (pCurrent->data == oldval)
		{
			break;
		}

		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}

#if 0
	//���pCurrentΪNULL  ˵�������в�����ֵΪoldval�Ľ��
	if (pCurrent == NULL)
	{
		return;
	}
#endif


	//�ȴ����½��
	struct LinkNode* newnode = malloc(sizeof(struct LinkNode));
	newnode->data = newval;
	newnode->next = NULL;

	//�½ڵ���뵽������
	newnode->next = pCurrent;
	pPrev->next = newnode;



}
//ɾ��ֵΪval�Ľ��
void RemoveByValue_LinkList(struct LinkNode* header, int delValue)
{

	if (NULL == header)
	{
		return;
	}

	//��������ָ�����
	struct LinkNode* pPrev = header;
	struct LinkNode* pCurrent = pPrev->next;

	while (pCurrent != NULL)
	{

		if (pCurrent->data == delValue)
		{
			break;
		}

		//�ƶ���������ָ��
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}

	if (NULL == pCurrent)
	{
		return;
	}

	//���½�����ɾ���ڵ��ǰ���ͺ�̽���ϵ
	pPrev->next = pCurrent->next;
	//�ͷ�ɾ���ڵ��ڴ�
	free(pCurrent);
	pCurrent = NULL;

}
//����
void Foreach_LinkList(struct LinkNode* header)
{
	if (NULL == header)
	{
		return;
	}

	//����ָ�����
	struct LinkNode* pCurrent = header->next;

	while (pCurrent != NULL)
	{
		printf("%d ", pCurrent->data);
		pCurrent = pCurrent->next;
	}

}
//����
void Destroy_LinkList(struct LinkNode* header)
{
	if (NULL == header)
	{
		return;
	}

	//����ָ�����
	struct LinkNode* pCurrent = header;

	while (pCurrent != NULL)
	{
		//�ȱ����µ�ǰ������һ���ڵ��ַ
		struct LinkNode* pNext = pCurrent->next;

		//�ͷŵ�ǰ����ڴ�
		printf("%d�ڵ㱻����!\n", pCurrent->data);
		free(pCurrent);

		//ָ������ƶ�
		pCurrent = pNext;

	}

}
//���
void Clear_LinkList(struct LinkNode* header)
{
	if (NULL == header)
	{
		return;
	}


	//����ָ�����
	struct LinkNode* pCurrent = header->next;

	while (pCurrent != NULL)
	{

		//�ȱ����µ�ǰ������һ���ڵ��ַ
		struct LinkNode* pNext = pCurrent->next;

		//�ͷŵ�ǰ����ڴ�
		free(pCurrent);

		//pCurrentָ����һ���ڵ�
		pCurrent = pNext;

	}

	header->next = NULL;

}