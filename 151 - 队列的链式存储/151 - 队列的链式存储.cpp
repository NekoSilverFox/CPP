#include "SeqQueue.h"

typedef struct PERSON {
	char name[64];
	int age;
}Person;

int main() {

	//创建队列
	SeqQueue* queue = Init_SeqQueue();

	//创建数据
	Person p1 = { "aaa", 10 };
	Person p2 = { "bbb", 20 };
	Person p3 = { "ccc", 30 };
	Person p4 = { "ddd", 40 };
	Person p5 = { "eee", 50 };

	//数据入队列
	Push_SeqQueue(queue, &p1);
	Push_SeqQueue(queue, &p2);
	Push_SeqQueue(queue, &p3);
	Push_SeqQueue(queue, &p4);
	Push_SeqQueue(queue, &p5);

	//输出队尾元素
	Person* backPerson = (Person*)Back_SeqQueue(queue);
	printf("Name:%s Age:%d\n", backPerson->name, backPerson->age);

	//输出
	while (Size_SeqQueue(queue) > 0) {
		//取出队头元素
		Person* p = (Person*)Front_SeqQueue(queue);
		printf("Name:%s Age:%d\n", p->name, p->age);
		//从队头弹出元素
		Pop_SeqQueue(queue);
	}


	//销毁队列
	Desgroy_SeqQueue(queue);

}