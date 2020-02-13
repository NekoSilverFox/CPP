#include"SeqStack.h"
Person::Person(string name, int age) : m_name(name), m_age(age) {}

// ��ʼ��ջ
SeqStack* Init_Stack()
{
	SeqStack* stack = new SeqStack;
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		stack->data[i]= nullptr;
	}
	stack->size = 0;
	return stack;
}

// ��ջ��ѹջ
void Push_Stack(SeqStack* stack, void* data)
{
	if (stack == nullptr || data == nullptr || stack->size == MAX_SIZE) return;
	stack->data[stack->size] = data; // !!!!
	++stack->size;
}

// ����ջ��Ԫ��
void* Top_Stack(SeqStack* stack)
{
	if (stack == nullptr || stack->size == 0) return 0;
	return stack->data[stack->size - 1];
}

// ��ջ
void Pop_Stack(SeqStack* stack)
{
	if (stack == nullptr || stack->size == 0) return;
	// cout << "Pop : " << stack[stack->size - 1].data << endl;
//	delete stack->data[stack->size - 1]; !!!!!!!!
	stack->data[stack->size - 1] = nullptr;
	stack->size--;
}

// �ж�ջ�Ƿ�Ϊ��
bool IsEmpty_Stack(SeqStack* stack)
{
	if (stack == nullptr || stack->size == 0) return false;
	else return true;
}

// ����ջ��Ԫ�ظ���
int Size_Stack(SeqStack* stack)
{
	if (stack == nullptr || stack->size == 0) return 0;
	return stack->size;
}

// ���ջ
void Clear_Stack(SeqStack* stack)
{
	if (stack == nullptr || stack->size == 0) return;
	for (int i = 0; i < stack->size; ++i)
	{
		delete stack->data[i];
		stack->data[i] = nullptr;
		stack->size--;
	}
}

// ����ջ
void Disdroy_Stack(SeqStack* stack)
{
	if (stack == nullptr) return;
	delete stack;
	stack = nullptr;
}

int main()
{
	SeqStack* stack = Init_Stack();
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	Push_Stack(stack, &p1);
	Push_Stack(stack, &p2);
	Push_Stack(stack, &p3);
	Push_Stack(stack, &p4);
	Push_Stack(stack, &p5);

	cout << Size_Stack(stack) << endl;

	while (Size_Stack(stack) > 0)
	{
		Person* temp = (Person*)Top_Stack(stack);
		cout << "Name : " << temp->m_name << "  Age : " << temp->m_age << endl;
		Pop_Stack(stack);
	}

	Clear_Stack(stack);

	if (IsEmpty_Stack(stack))
	{
		cout << "Stack have data" << endl;
	}
	else
	{
		cout << "Stack  no data" << endl;
	}

}
