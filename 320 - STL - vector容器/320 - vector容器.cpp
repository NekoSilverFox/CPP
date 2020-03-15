#include<iostream>
#include<vector>
using namespace std;

void vector_test()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		cout << v.capacity() << " "; // v.capacity()����������
	}
	cout << endl;
}


/*
vector���캯��
vector<T> v; //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
vector(v.begin(), v.end());//��v[begin(), end())�����е�Ԫ�ؿ���������
vector(n, elem);//���캯����n��elem����������
vector(const vector &vec);//�������캯����
*/
void test01()
{
	// vector<T> v; //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
	vector<int> v;

	// 1. vector(v.begin(), v.end());//��v[begin(), end())�����е�Ԫ�ؿ���������
	int array_[] = { 1,2,3,4,5 };
	vector<int> v1(array_, array_ + sizeof(array_) / sizeof(int));
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 2. vector(v.begin(), v.end());//��v[begin(), end())�����е�Ԫ�ؿ���������
	vector<int> v2(v1.begin(), v1.end());
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 3. vector(n, elem);//���캯����n��elem����������
	vector<int> v3(10, 66);
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


/*
3.2.4.2 vector���ø�ֵ����
assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);//��n��elem������ֵ������
vector& operator=(const vector  &vec);//���صȺŲ�����
swap(vec);// ��vec�뱾���Ԫ�ػ�����
*/
void test02()
{
	vector<char> v1;
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };

	// assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
	v1.assign(&arr[1], &arr[4]);
	for (vector<char>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
	vector<char> v2;
	v2.push_back('A');
	v2.push_back('B');
	v2.push_back('C');
	v2.push_back('D');
	v2.push_back('E');

	vector<char> v3(v2.begin() + 1, v2.end());
	for (vector<char>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// assign(n, elem);//��n��elem������ֵ������
	v3.assign(10, '$');
	for (vector<char>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// swap(vec);// ��vec�뱾���Ԫ�ػ�����
	v3.swap(v2);
	cout << "swap() ֮��� v3 ��" << endl;
	for (vector<char>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	cout << "swap() ֮��� v2 ��" << endl;
	for (vector<char>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}


/*
3.2.4.3 vector��С����
size();//����������Ԫ�صĸ���
empty();//�ж������Ƿ�Ϊ��
resize(int num);//����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(int num, elem);//����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á����������̣���ĩβ����������>�ȵ�Ԫ�ر�ɾ����
capacity();//����������
reserve(int len);//����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
*/
void test03()
{
	vector<char>v;
	v.push_back('X');
	v.push_back('Y');
	v.push_back('Z');

	// size(); ����������Ԫ�صĸ���
	cout << "size = " << v.size() << endl;

	// empty();//�ж������Ƿ�Ϊ��
	if (v.empty()) cout << "vector ����Ϊ��" << endl;
	else  cout << "vector ������Ϊ��" << endl;


	cout << endl;
	// resize(int num);//����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ###########Ĭ��ֵΪ���ַ�###########�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
	v.resize(10);
	cout << "size = " << v.size() << endl;
	for (vector<char>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << '\'' << endl << endl;


	// resize(int num, elem);//����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á����������̣���ĩβ����������>�ȵ�Ԫ�ر�ɾ����
	v.resize(20, '#');
	cout << "size = " << v.size() << endl;
	for (vector<char>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << '\'' << endl << endl;


	v.resize(5, '#');
	cout << "size = " << v.size() << endl;
	for (vector<char>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << '\'' << endl << endl;


	// reserve(int len);//����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
	// v.reserve(3);
	v.reserve(10);
	cout << "size = " << v.size() << endl;
	for (vector<char>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\' <- Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�!!!" << endl << endl; // Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�!!!
}



/*
vector���ݴ�ȡ����
at(int idx); //��������idx��ָ�����ݣ����idxԽ�磬�׳�out_of_range�쳣��
operator[];//��������idx��ָ�����ݣ�Խ��ʱ������ֱ�ӱ���
front();//���������е�һ������Ԫ��
back();//�������������һ������Ԫ��

3.2.4.5 vector�����ɾ������
insert(const_iterator pos, int count, ele);//������ָ��λ��pos����count��Ԫ��ele.
push_back(ele); //β������Ԫ��ele
pop_back();//ɾ�����һ��Ԫ��
erase(const_iterator start, const_iterator end);//ɾ����������start��end֮���Ԫ��
erase(const_iterator pos);//ɾ��������ָ���Ԫ��
clear();//ɾ������������Ԫ��

*/
void test04()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << "The first element : " << v.front() << endl;
	cout << "The last element : " << v.back() << endl;

	cout << endl;

	v.insert(v.begin() + 2, 66);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) cout << *it << " "; cout << endl;
	v.insert(v.begin() + 5,4, 77);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) cout << *it << " "; cout << endl;

	v.erase(v.begin() + 4, v.begin() + 9);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) cout << *it << " "; cout << endl;

	v.erase(v.begin());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) cout << *it << " "; cout << endl;

	v.pop_back();
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) cout << *it << " "; cout << endl;

	v.clear();
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) cout << *it << " "; cout << endl;
	if (v.empty()) cout << "null" << endl;
}


// �������
void test05()
{
	vector<char> v;
	for (char ch = 'a'; ch < 'h'; ch++)
	{
		v.push_back(ch);
	}
	// �������
	for (vector<char>::iterator it = v.begin(); it != v.end(); it++) cout << *it << " "; cout << endl;

	//reverse_iterator ��������� ##################################################!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (vector<char>::reverse_iterator r_it = v.rbegin(); r_it != v.rend(); r_it++) cout << *r_it << " "; cout << endl;
}

int main()
{
	vector_test();
	cout << endl << "-----------------------------------------------------------" << endl << endl;
	test01();
	cout << endl << "-----------------------------------------------------------" << endl << endl;
	test02();
	cout << endl << "-----------------------------------------------------------" << endl << endl;
	test03();
	cout << endl << "-----------------------------------------------------------" << endl << endl;
	test04();
	cout << endl << "-----------------------------------------------------------" << endl << endl;
	test05();
}