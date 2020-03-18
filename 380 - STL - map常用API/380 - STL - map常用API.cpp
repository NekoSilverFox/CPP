#include<iostream>
#include<map>
using namespace std;

/*
3.8.2.1 map���캯��
map<T1, T2> mapTT;//mapĬ�Ϲ��캯��:
map(const map &mp);//�������캯��


3.8.2.2 map��ֵ����
map& operator=(const map &mp);//���صȺŲ�����
swap(mp);//����������������

3.8.2.3 map��С����
size();//����������Ԫ�ص���Ŀ
empty();//�ж������Ƿ�Ϊ��

3.8.2.4 map��������Ԫ�ز���
map.insert(...); //����������Ԫ�أ�����pair<iterator,bool>
map<int, string> mapStu;
// ��һ�� ͨ��pair�ķ�ʽ�������
mapStu.insert(pair<int, string>(3, "С��"));
// �ڶ��� ͨ��pair�ķ�ʽ�������
mapStu.inset(make_pair(-1, "У��"));
// ������ ͨ��value_type�ķ�ʽ�������
mapStu.insert(map<int, string>::value_type(1, "С��"));
// ������ ͨ������ķ�ʽ����ֵ
mapStu[3] = "С��";
mapStu[5] = "С��";

*/
void test01()
{
	map<int, char>s;
	// ������ͨ��������еģ�����������������������������������������
	// ��һ�� ͨ��pair�ķ�ʽ�������
	s.insert(pair<int, char>(3, 'C'));

	// �ڶ��� ͨ��pair�ķ�ʽ�������
	s.insert(make_pair(2, 'B'));

	// ������ ͨ��value_type�ķ�ʽ�������
	s.insert(map<int, char>::value_type(5, 'F'));

	// ������ ͨ������ķ�ʽ����ֵ
	s[10] = 'H';

	for (map<int, char>::iterator it = s.begin(); it != s.end(); it++)
		cout << "Key = " << it->first << "  Value = " << it->second << endl;

}


// ==================================================================

class Person
{
public:
	Person(string name, int age) : name_(name), age_(age) {}

public:
	int age_;
	string name_;
};

class MyCompareMap
{
public:
	bool operator()(const Person& p1, const Person& p2) const
	{
		if (p1.name_ > p2.name_) return true;
		else return false;
	}
};

// �������
void test02()
{
	Person p1("Judy", 13);
	Person p2("Nick", 14);
	Person p3("Funick", 23);
	Person p4("Yiff", 17);
	Person p5("Neko", 13);
	Person p6("Alisa", 7);
	Person p7("YiffYiff", 13);

	map<Person, int, MyCompareMap>s;
	// ��һ�� ͨ��pair�ķ�ʽ�������
	s.insert(pair<Person, int>(p2, 2));

	// �ڶ��� ͨ��pair�ķ�ʽ�������
	s.insert(make_pair(p7, 7));

	// ������ ͨ��value_type�ķ�ʽ�������
	s.insert(map<Person, int>::value_type(p5, 5));

	// ������ ͨ������ķ�ʽ����ֵ
	s[p4] = 4;

	// �ڶ��� ͨ��pair�ķ�ʽ������� is best
	s.insert(make_pair(p3, 3));
	s.insert(make_pair(p1, 1));
	s.insert(make_pair(p4, 4));
	s.insert(make_pair(p6, 6));

	for (map<Person, int, MyCompareMap>::iterator it = s.begin(); it != s.end(); it++)
		cout << "Name : " << it->first.name_ << "  Age : " << it->first.age_ << " Value : " << it->second << endl;


}


//3.8.2.6 map���Ҳ���
//find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ�������/�������ڣ�����map.end();
//count(keyElem);//����������keyΪkeyElem�Ķ����������map��˵��Ҫô��0��Ҫô��1����multimap��˵��ֵ���ܴ���1��
//lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
//upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
//equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
void test03()
{
	map<string, int>m;
	m.insert(make_pair("LLL",6 ));
	m.insert(make_pair("QQQ",8 ));
	m.insert(make_pair("AAA", 1));
	m.insert(make_pair("SSS", 16));
	m.insert(make_pair("CCC", 3));

	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
		cout << "Key = " << it->first << "      Value = " << it->second << endl;

	map<string, int>::iterator map_it1 = m.find("AAA");
	if (map_it1 != m.end())
	{
		cout << "Have this Key :" << endl
			<< "Number is  = " << m.count(map_it1->first) << endl
			<< "Value = " << map_it1->first << "     Value = " << map_it1->second << endl;
	}
	else cout << "Dont have this key" << endl;

	pair<map<string, int>::iterator, map<string, int>::iterator> map_pair_it = m.equal_range("CCC");
	cout << "First element is >>> Key = " << map_pair_it.first->first << "     Value = " << map_pair_it.first->second << endl
		<< "Secound is >>> Key = " << map_pair_it.second->first << "      Value = " << map_pair_it.second->second << endl;
 
}

int main()
{
	test01();
	test02();
	test03();
}