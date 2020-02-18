#include"LinkStack.h"
//�ж��Ƿ�������
int IsNumber(char c) {
	return c >= '0' && c <= '9';
}

//�ж��ǲ���������
int IsLeft(char c) {
	return c == '(';
}

//�ж��ǲ���������
int IsRight(char c) {
	return c == ')';
}

//�ж��ǲ����������
int IsOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

//��������������ȼ�
int GetPriority(char c) {
	if (c == '*' || c == '/') {
		return 2;
	}
	if (c == '+' || c == '-') {
		return 1;
	}
	return 0;
}

struct MyChar {
	LinkNode node;
	char* p;
};

//���ֲ���
void NumberOperate(char* p) {
	cout << *p;
}

//����MyChar
MyChar* CreateMyChar(char* p) {
	MyChar* mychar = new MyChar;
	mychar->p = p;
	return mychar;
}

//�����ŵĲ���
void LeftOperate(LinkStack* stack, char* p) {
	Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
}

//�����Ų���
void RightOperate(LinkStack* stack) {

	//���ж�ջ����û��Ԫ��
	while (Size_LinkStack(stack) > 0) {
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		//���ƥ�䵽������
		if (IsLeft(*(mychar->p))) {
			Pop_LinkStack(stack);
			delete mychar;
			break;
		}
		//���
		cout << *(mychar->p);
		//����
		Pop_LinkStack(stack);
		//�ͷ��ڴ�
		delete mychar;
	}
}

//������ŵĲ���
void OperatorOperate(LinkStack* stack, char* p) {

	//��ȡ��ջ������
	MyChar* mychar = (MyChar*)Top_LinkStack(stack);
	if (mychar == NULL) {
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
		return;
	}

	//���ջ�����ȼ����ڵ�ǰ�ַ������ȼ� ֱ����ջ
	if (GetPriority(*(mychar->p)) < GetPriority(*p)) {
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
		//return;
	}

	//���ջ���������ȼ�����
	else {

		while (Size_LinkStack(stack) > 0) {

			MyChar* mychar2 = (MyChar*)Top_LinkStack(stack);

			//������ȼ��� ��ǰ������ջ
			if (GetPriority(*(mychar2->p)) < GetPriority(*p)) {
				Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
				return;
			}

			//���
			cout << *(mychar2->p);
			//����
			Pop_LinkStack(stack);
			//�ͷ�
			delete mychar2;
		}
	}

}


int main() {

	char* str = (char*)("8+(3-1)*(5+7)");  // 8+(3-1)*5
	char* p = str;
	cout << str << endl << endl;
	//����ջ
	LinkStack* stack = InIt_LinkStack();

	while (*p != '\0') {
		 
		//���������
		if (IsNumber(*p)) {
			NumberOperate(p);
		}

		//��������� ֱ�ӽ�ջ
		if (IsLeft(*p)) {
			LeftOperate(stack, p);
		}

		//�����������
		if (IsRight(*p)) {
			RightOperate(stack);
		}

		//������������
		if (IsOperator(*p)) {
			OperatorOperate(stack, p);
		}
		p++;
	}

	while (Size_LinkStack(stack) > 0) {
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		cout << *(mychar->p);
		Pop_LinkStack(stack);
		delete mychar;
	}
	cout << endl;
}