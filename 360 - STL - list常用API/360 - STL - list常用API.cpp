#include<iostream>
#include<list>
using namespace std;

// list����������һ��˫���������һ���һ��ѭ����˫������
// ֤����
void listisDoubleList()
{
	//list<int> myList;
	//for (int i = 0; i < 10; i++) {
	//	myList.push_back(i);
	//}

	//list<int>::_Nodeptr node = myList._Myhead->_Next;

	//for (int i = 0; i < myList._Mysize * 2; i++) {
	//	cout << "Node:" << node->_Myval << endl;
	//	node = node->_Next;
	//	if (node == myList._Myhead) {
	//		node = node->_Next;
	//	}
	//}

}

//3.6.4.1 list���캯��
//list<T> lstT;//list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ��
//list(beg, end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
//list(n, elem);//���캯����n��elem����������
//list(const list& lst);//�������캯����
void test01()
{
	list<char> list1(6, 'a');
	list<char>list2(list1.begin(), list1.end());
	list2.push_back('E');

	for (list<char>::iterator it = list2.begin(); it != list2.end(); it++) cout << *it << " ";
	cout << endl;

	for (list<char>::reverse_iterator it = list2.rbegin(); it != list2.rend(); it++) cout << *it << " ";
	cout << endl << endl;
}

//
//3.6.4.2 list����Ԫ�ز����ɾ������
//push_back(elem);//������β������һ��Ԫ��
//pop_back();//ɾ�����������һ��Ԫ��
//push_front(elem);//��������ͷ����һ��Ԫ��
//pop_front();//��������ͷ�Ƴ���һ��Ԫ��
//insert(pos, elem);//��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�// !!!!!!!!!!!!!!!!!!!!!!@@@@@@@@@@@@@@@@@@
//insert(pos, n, elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
//insert(pos, beg, end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
//clear();//�Ƴ���������������
//erase(beg, end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
//erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
//remove(elem);//ɾ��������������elemֵƥ���Ԫ�ء�
void test02()
{
	list<char> l;
	l.push_back('a');
	l.push_back('b');
	l.push_back('c');
	l.push_front('A');
	l.push_front('B');
	l.push_front('C');

	l.pop_back();
	l.pop_front();

	list<char> l2(5, 'd');
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << endl;

	l2.insert(l2.begin(), 'A');
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << endl;

	l2.insert(l2.end(), 5, 'b');
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << endl;

	l2.insert(l2.end(), l.begin(), l.end());
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << endl;

	l2.erase(l2.begin());
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << endl;

	l2.remove('a');
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << endl;

	l2.clear();
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << endl;

}

//3.6.4.3 list��С����
//size();//����������Ԫ�صĸ���
//empty();//�ж������Ƿ�Ϊ��
//resize(num);//����ָ�������ĳ���Ϊnum��
//�������䳤������Ĭ��ֵ�����λ�á�
//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
//resize(num, elem);//����ָ�������ĳ���Ϊnum��
//�������䳤������elemֵ�����λ�á�
//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
//
//3.6.4.4 list��ֵ����
//assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ�������Ḳ��ԭ�е�����
//assign(n, elem);//��n��elem������ֵ������
//list& operator=(const list& lst);//���صȺŲ�����
//swap(lst);//��lst�뱾���Ԫ�ػ�����
//3.6.4.5 list���ݵĴ�ȡ
//front();//���ص�һ��Ԫ�ء�
//back();//�������һ��Ԫ�ء�
//3.6.4.6 list��ת����
//reverse();//��ת��������lst����1,3,5Ԫ�أ����д˷�����lst�Ͱ���5,3,1Ԫ�ء�
//sort(); //list����
void test03()
{
	list<char> l1;
	l1.push_back('a');
	l1.push_back('b');
	l1.push_back('c');
	l1.push_back('d');
	l1.push_back('e');

	cout << "List size : " << l1.size() << endl;

	if (l1.empty()) cout << "list in null" << endl;
	else cout << "list is not null" << endl;

	l1.resize(10);
	for (list<char>::iterator it = l1.begin(); it != l1.end(); it++) cout << *it << " "; cout << '\'' << endl;
	
	l1.resize(15, '#');
	for (list<char>::iterator it = l1.begin(); it != l1.end(); it++) cout << *it << " "; cout << '\'' << endl;
	cout << endl << endl;
	// --------------------
	//assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ�������Ḳ��ԭ�е�����
	//assign(n, elem);//��n��elem������ֵ������
	//list& operator=(const list& lst);//���صȺŲ�����
	//swap(lst);//��lst�뱾���Ԫ�ػ�����
	//3.6.4.5 list���ݵĴ�ȡ
	//front();//���ص�һ��Ԫ�ء�
	//back();//�������һ��Ԫ�ء�
	//3.6.4.6 list��ת����
	//reverse();//��ת��������lst����1,3,5Ԫ�أ����д˷�����lst�Ͱ���5,3,1Ԫ�ء�
	//sort(); //list����
	list<char>l2(5, 'a');
	l2.assign(l1.begin(), l1.end());
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << '\'' << endl;

	l2.assign(3, 'B');
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << '\'' << endl;

	l2.swap(l1);
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << '\'' << endl;

	cout << "The first element : " << l2.front() << endl;
	cout << "The list element : " << l2.back() << endl;

	l2.reverse();
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << '\'' << endl;

	l2.sort();
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << '\'' << endl;


}

int main()
{
	test01();
	test02();
	test03();
}