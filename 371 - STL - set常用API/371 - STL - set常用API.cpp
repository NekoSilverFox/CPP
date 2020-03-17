#include<iostream>
#include<set> // set �� multiset ֻ��Ҫ����ͬһ��ͷ�ļ���
using namespace std;

// set�ı�����һ�� ��������������

/*
3.7.2.1 set���캯��
set<T> st;//setĬ�Ϲ��캯����
mulitset<T> mst; //multisetĬ�Ϲ��캯��:
set(const set &st);//�������캯��
3.7.2.2 set��ֵ����
set& operator=(const set &st);//���صȺŲ�����
swap(st);//����������������
3.7.2.3 set��С����
size();//����������Ԫ�ص���Ŀ
empty();//�ж������Ƿ�Ϊ��

3.7.2.4 set�����ɾ������
insert(elem);//�������в���Ԫ�ء�
clear();//�������Ԫ��
erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
erase(beg, end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
erase(elem);//ɾ��������ֵΪelem��Ԫ�ء�

3.7.2.5 set���Ҳ���
find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
count(key);//���Ҽ�key��Ԫ�ظ���
lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������

*/
void test01()
{
	set<char> set1;

	if (set1.empty()) cout << "set1 is null" << endl;
	else cout << "set1 is not null" << endl;

	// set dont have PUSH!  need use "inset"
	set1.insert('E'); //    pair<iterator, bool> insert(value_type&& _Val) 
	set1.insert('e');// inset() ���벢����һ����������bool�����������ж��壡��
	set1.insert('A');
	set1.insert('C');
	set1.insert('T');

	cout << "Size - set_1 : " << set1.size() << endl;
	if (set1.empty()) cout << "set1 is null" << endl;
	else cout << "set1 is not null" << endl;

	cout << endl;

	for (set<char>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl << "--------------------------------------------------------------" << endl << endl;


	/*
	clear();//�������Ԫ��
	erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
	erase(beg, end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
	erase(elem);//ɾ��������ֵΪelem��Ԫ�ء�
	*/
	set1.erase(set1.begin());
	for (set<char>::iterator it = set1.begin(); it != set1.end(); it++) cout << *it << " "; cout << endl;

	set1.erase('T');
	for (set<char>::reverse_iterator it = set1.rbegin(); it != set1.rend(); it++) cout << *it << " "; cout << endl;

	set1.insert('D');
	set1.insert('S');
	set1.insert('G');
	for (set<char>::iterator it = set1.begin(); it != set1.end(); it++) cout << *it << " "; cout << endl;
	cout << endl << "--------------------------------------------------------------" << endl << endl;
	/*
	find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�ص�#@@@#������#@@@#���������ڣ�����set.end();
	count(key);//���Ҽ�key��Ԫ�ظ��� 0 OR 1
	*/
	set<char>::iterator find_it = set1.find('S');
	if (find_it == set1.end()) cout << "Didn't find key S ! " << endl;
	else cout << "Find key : " << *find_it << endl; // ע�� �� find_it�ǵ�������ע��ȡ�ǣ���

	cout << "D �ĸ���Ϊ��" << set1.count('D') << endl;
	cout << "U �ĸ���Ϊ��" << set1.count('U') << endl;
	cout << endl << "--------------------------------------------------------------" << endl << endl;

}


// �鿴�����ظ���Ԫ���Ƿ�ɹ�����
void insert_same_key()
{
	set<char> set1;
	//    pair<iterator, bool> insert(value_type&& _Val) 
	// inset() ���벢����һ�����飬���а���������������bool�������������ж��壡��
	// 	ע�⣬ ������һ�������ţ���pair< xxx  >
	pair<set<char>::iterator, bool> pair_set =  set1.insert('E'); 
	if (pair_set.second) cout << "Seccful insert !" << endl;
	else cout << "Faile insert !" << endl;

	pair<set<char>::iterator, bool> pair_set2 = set1.insert('E');
	if (pair_set2.second) cout << "Seccful insert !" << endl;
	else cout << "Faile insert !" << endl;

	cout << endl << "--------------------------------------------------------------" << endl << endl;

}


/*
lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
*/
void test03()
{
	set<int> s;
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(8);
	s.insert(9);
	s.insert(0);
	s.insert(12);
	s.insert(7);
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) cout << *it << " "; cout << endl;

	/*
	lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
	upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
	equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������Ҳ����lower_bound��upper_bound����������
	*/
	set<int>::iterator lower_it = s.lower_bound(5); cout << *lower_it << endl;
	set<int>::iterator upper_it = s.upper_bound(5); cout << *upper_it << endl;

	set<int>::iterator lower_it2 = s.lower_bound(6); cout << *lower_it2 << endl;
	set<int>::iterator upper_it2 = s.upper_bound(6); cout << *upper_it2 << endl;

	pair<set<int>::iterator, set<int>::iterator> equal_it = s.equal_range(7);
	cout << *equal_it.first << "  " << *equal_it.second << endl;

}
int main()
{
	//test01();
	//insert_same_key();
	test03();
}