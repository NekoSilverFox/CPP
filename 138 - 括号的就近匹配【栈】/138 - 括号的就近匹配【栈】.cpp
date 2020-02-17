#include"LinkStack.h"

// 初始化
LinkStack* InIt_LinkStack()
{
	LinkStack* stack = new LinkStack;
	stack->header.next = nullptr;
	stack->size = 0;
	return stack;
}

// 压栈
void Push_LinkStack(LinkStack* stack, LinkNode* data)
{
	if (stack == nullptr || data == nullptr) return;

	data->next = stack->header.next;
	stack->header.next = data;
	stack->size++;
}

// 弹出栈顶元素
LinkNode* Top_LinkStack(LinkStack* stack)
{
	if (stack == nullptr || stack->size == 0) return 0;
	return stack->header.next;
}

// 返回元素个数
int Size_LinkStack(LinkStack* stack)
{
	if (stack == nullptr || stack->size == 0) return 0;
	return stack->size;
}

// 判断是否为空
bool IsEmpty_LinkStack(LinkStack* stack)
{
	if (stack == nullptr || stack->size == 0) return true;
	else return false;
}

// 出栈
void Pop_LinkStack(LinkStack* stack)
{
	if (stack == nullptr || stack->size == 0) return;
	stack->header.next = stack->header.next->next;
	stack->size--;
}

// 清空栈
void Clear_LinkStack(LinkStack* stack)
{
	if (stack == nullptr || stack->size == 0) return;
	stack->header.next = nullptr;
	stack->size = 0;
}


// 销毁栈
void Desgroy_LinkStack(LinkStack* stack)
{
	if (stack == nullptr || stack->size == 0) return;
	delete stack;
	stack = nullptr;
}
class Person
{
public:
	Person(string name, int age) : name_(name), age_(age) {}
public:
	LinkNode node;
	string name_;
	int age_;
};

//int main()
//{
//	LinkStack* stack = InIt_LinkStack();
//
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	Person p3("ccc", 30);
//	Person p4("ddd", 40);
//	Person p5("eee", 50);
//
//	Push_LinkStack(stack, (LinkNode*)& p1);
//	Push_LinkStack(stack, (LinkNode*)& p2);
//	Push_LinkStack(stack, (LinkNode*)& p3);
//	Push_LinkStack(stack, (LinkNode*)& p4);
//	Push_LinkStack(stack, (LinkNode*)& p5);
//
//	cout << Size_LinkStack(stack) << endl;
//
//	while (Size_LinkStack(stack) > 0)
//	{
//		Person* temp = (Person*)Top_LinkStack(stack);
//		cout << "Name : " << temp->name_ << "  Age : " << temp->age_ << endl;
//		Pop_LinkStack(stack);
//	}
//
//	Clear_LinkStack(stack);
//}


struct MyChar {
	LinkNode node;
	char* pAddres;
	int index;
};

int IsLeft(char c) {
	return c == '(';
}

int IsRight(char c) {
	return c == ')';
}

MyChar* CreateMyChar(char* p, int index) {
	MyChar* mychar = new MyChar;
	mychar->pAddres = p;
	mychar->index = index;

	return mychar;
}

void ShowError(char* str, int pos) {
	cout << str << endl;
	for (int i = 0; i < pos; i++) {
		cout << " ";
	}
	cout << "A";
}

int main() {


	char* str = (char*)("1+2+6(dsf)df)sflp(sdfs)");

	//创建栈容器
	LinkStack* stack = InIt_LinkStack();

	char* p = str;
	int index = 0;
	while (*p != '\0') {

		//如果左括号 直接进栈
		if (IsLeft(*p)) {
			Push_LinkStack(stack, (LinkNode*)CreateMyChar(p, index));
		}

		//如果是右括号 从栈顶弹出元素 判断是不是左括号
		if (IsRight(*p)) {
			if (Size_LinkStack(stack) > 0) {
				MyChar* mychar = (MyChar*)Top_LinkStack(stack);
				if (IsLeft(*(mychar->pAddres))) {
					Pop_LinkStack(stack);
					delete mychar;
				}
			}
			else {
				cout << "右括号没有匹配的左括号:" << endl;
				ShowError(str, index);
				break;
			}
		}

		p++;
		index++;
	}


	while (Size_LinkStack(stack) > 0) {
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		cout << "左括号没有匹配的右括号:" << endl;
		ShowError(str, mychar->index);
		Pop_LinkStack(stack);
		delete mychar;
	}

	cout << endl;
	return 0;
}