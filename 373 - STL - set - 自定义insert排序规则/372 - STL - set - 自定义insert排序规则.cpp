#include<iostream>
#include<set>
using namespace std;

// 372 - STL - set - �Զ���insert�������

//ָ��set������� �Ӵ�С
//�º���
template<class T>
class myCompare
{
public:
	//���� ()
	bool operator()(T data1, T data2) const // ע���const����
	{
		return data1 > data2;
	}
};

//set��������
void setSort()
{
	set<int, myCompare<int>> s;
	s.insert(1);
	s.insert(5);
	s.insert(3);
	s.insert(9);
	s.insert(8);
	s.insert(0);

	//                        ��               ��          ע�⣬��ʱ�����е�����ҲҪ���£�����
	for (set<int, myCompare<int>>::iterator it = s.begin(); it != s.end(); it++) cout << *it << " "; cout << endl;
}

int main()
{
	setSort();
}
