#include<iostream>
#include<deque>
using namespace std;
void foeach_deque(const deque<int>& d);

/*
deque���캯��
deque<T> deqT;//Ĭ�Ϲ�����ʽ
deque(beg, end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
deque(n, elem);//���캯����n��elem����������
deque(const deque &deq);//�������캯����
*/
void test01()
{
	// deque<T> deqT;//Ĭ�Ϲ�����ʽ
	deque<int> d1;
	for (int i = 0; i < 5; i++) d1.push_back(i);
	for (deque<int>::iterator it = d1.begin(); it != d1.end(); it++) cout << *it << " "; cout << endl;

	// deque(beg, end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
	deque<int>d2(d1.begin() +1 , d1.end());
	for (deque<int>::iterator it = d2.begin(); it != d2.end(); it++) cout << *it << " "; cout << endl;
	
	// deque(n, elem);//���캯����n��elem����������
	// d2(6, 77); - ERROR
	deque<char> d3(10, 'A');
	for (deque<char>::iterator it = d3.begin(); it != d3.end(); it++) cout << *it << " "; cout << endl;
}

/*
3.3.3.2 deque��ֵ����
assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);//��n��elem������ֵ������
deque& operator=(const deque &deq); //���صȺŲ�����
swap(deq);// ��deq�뱾���Ԫ�ػ���
*/
// ###################################���ԭ����ֵ���ǵ���������
void test02()
{
	deque<char> d1(5, 'A');
	deque<char> d2(10, 'B');
	for (deque<char>::iterator it = d2.begin(); it != d2.end(); it++) cout << *it << " "; cout << endl;

	// assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
	d2.assign(d1.begin() + 1, d1.end()); // ���d2��ԭ����10��B�����ǵ�
	for (deque<char>::iterator it = d2.begin(); it != d2.end(); it++) cout << *it << " "; cout << endl;

	// assign(n, elem);//��n��elem������ֵ������
	d2.assign(5, 'E');
	for (deque<char>::iterator it = d2.begin(); it != d2.end(); it++) cout << *it << " "; cout << endl;

	// swap(deq);// ��deq�뱾���Ԫ�ػ���
	d2.swap(d1);
	cout << "�������d1 ��";
	for (deque<char>::iterator it = d1.begin(); it != d1.end(); it++) cout << *it << " "; cout << endl;
	cout << "�������d2 ��";
	for (deque<char>::iterator it = d2.begin(); it != d2.end(); it++) cout << *it << " "; cout << endl;
}

/*
3.3.3.3 deque��С����
deque.size();//����������Ԫ�صĸ���
deque.empty();//�ж������Ƿ�Ϊ��
deque.resize(num);//����ָ�������ĳ���Ϊnum,�������䳤������Ĭ��ֵ 0 �����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
deque.resize(num, elem); //����ָ�������ĳ���Ϊnum,�������䳤������elemֵ�����λ��,���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
*/
void test03()
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_back(40);
	d1.push_front(100); // push_front - ͷ�壡
	d1.push_front(200);
	for (deque<int>::iterator it = d1.begin(); it != d1.end(); it++) cout << *it << " "; cout << endl;

	cout << "Deque size : " << d1.size() << endl;
	if (d1.empty()) cout << "null" << endl;
	else cout << "not null" << endl;

	d1.resize(20);
	foeach_deque(d1);
	
	d1.resize(3, 1);
	foeach_deque(d1);

}

// ע��ͨ��const���б���������Ҫ����������##########
// 1. ���������iterator
// 2. ���������reverse_iterator
// 3.ͨ��const��ֵ������const_iterator
void foeach_deque(const deque<int>& d)
{
	for (deque<int>::const_iterator c_it = d.begin(); c_it != d.end(); c_it++) cout << *c_it << " "; cout << '\'' << endl;
}


/*
deque˫�˲����ɾ������
push_back(elem);//������β�����һ������
push_front(elem);//������ͷ������һ������
pop_back();//ɾ���������һ������
pop_front();//ɾ��������һ������

3.3.3.5 deque���ݴ�ȡ
at(idx);//��������idx��ָ�����ݣ����idxԽ�磬�׳�out_of_range��
operator[];//��������idx��ָ�����ݣ����idxԽ�磬���׳��쳣��ֱ�ӳ���
front();//���ص�һ�����ݡ�
back();//�������һ������
3.3.3.6 deque�������
insert(pos,elem);//��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ�á�
insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
3.3.3.7 dequeɾ������
clear();//�Ƴ���������������
erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�

*/
int main()
{
	test01();
	cout << endl << "-----------------------------------------------------------------" << endl << endl;
	test02();
	cout << endl << "-----------------------------------------------------------------" << endl << endl;
	test03();
	cout << endl << "-----------------------------------------------------------------" << endl << endl;
	cout << endl << "-----------------------------------------------------------------" << endl << endl;
}