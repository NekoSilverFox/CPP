#include"LinkStack.h"

// ��ʼ��
LinkStack* InIt_LinkStack()
{
	LinkStack* stack = new LinkStack;
	stack->header.next = nullptr;
	stack->size = 0;
	return stack;
}

// ѹջ
void Push_LinkStack(LinkStack* stack, LinkNode* data)
{
	if (stack == nullptr || data == nullptr) return;

	data->next = stack->header.next;
	stack->header.next = data;
	stack->size++;
}

// ����ջ��Ԫ��
LinkNode* Top_LinkStack(LinkStack* stack)
{
	if (stack == nullptr || stack->size == 0) return 0;
	return stack->header.next;
}

// ����Ԫ�ظ���
int Size_LinkStack(LinkStack* stack)
{
	if (stack == nullptr || stack->size == 0) return 0;
	return stack->size;
}

// �ж��Ƿ�Ϊ��
bool IsEmpty_LinkStack(LinkStack* stack)
{
	if (stack == nullptr || stack->size == 0) return true;
	else return false;
}

// ��ջ
void Pop_LinkStack(LinkStack* stack)
{
	if (stack == nullptr || stack->size == 0) return;
	stack->header.next = stack->header.next->next;
	stack->size--;
}

// ���ջ
void Clear_LinkStack(LinkStack* stack)
{
	if (stack == nullptr || stack->size == 0) return;
	stack->header.next = nullptr;
	stack->size = 0;
}


// ����ջ
void Desgroy_LinkStack(LinkStack* stack)
{
	if (stack == nullptr || stack->size == 0) return;
	delete stack;
	stack = nullptr;
}
