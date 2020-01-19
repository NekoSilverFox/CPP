#include<iostream>
#include<vector>
using namespace std;

class MyClass {
public:
	int v;
	/*���캯��*/
	MyClass() :v(0) {}
	MyClass(const int& a) :v(a) {}
	MyClass(const MyClass& t1) :v(t1.v) {}

	/*��������С�ں� < */
	  //�Ƚ���������Ĵ�С 
	bool operator<(const MyClass& t1) const {
		return (v < t1.v);
	}
	//�Ƚ϶����int�Ĵ�С 
	bool operator<(const int& t1) const {
		return (v < t1);
	}
	//��Ԫ�������Ƚ�int�Ͷ���Ĵ�С 
	friend inline bool operator<(const int& a, const MyClass& t1) {
		return (a < t1.v);
	}

	/*�������ظ�ֵ�� = */
	  //����丳ֵ 
	MyClass& operator=(const MyClass& t1) {
		v = t1.v;
		return *this;
	}
	//int��ֵ������ 
	MyClass& operator=(const int& t1) {
		v = t1;
		return *this;
	}

	/*�������ؼӺ� + */
	  //������� int 
	MyClass operator+(const int& a) {
		MyClass t1;
		t1.v = v + a;
		return t1;
	}
	//����Ӷ��� 
	MyClass operator+(MyClass& t1) {
		MyClass t2;
		t2.v = v + t1.v;
		return t2;
	}

	/*�������ؼӵȺ� += */
	  //������϶��� 
	MyClass& operator+=(const MyClass& t1) {
		v += t1.v;
		return *this;
	}
	//�������int
	MyClass& operator+=(const int& a) {
		v += a;
		return *this;
	}

	/*��������˫�Ⱥ� == */
	  //����==���� 
	bool operator==(const MyClass& t1)const {
		return (v == t1.v);
	}
	//����==int
	bool operator==(const int& t1)const {
		return (v == t1);
	}

	/*�������� ����>> ���<< */
	  /*��Ԫ�������������*/
	friend inline ostream& operator << (ostream& os, MyClass& t1) {
		cout << "class t(" << t1.v << ")" << endl;
		return os;
	}
	/*��Ԫ�������������*/
	friend inline istream& operator >> (istream& is, MyClass& t1) {
		cin >> t1.v;
		return is;
	}
};

int main() {
	MyClass t0, t1(3);
	MyClass t2(t1);
	cout << t0 << t1 << t2;
	cin >> t1;
	t2 = t1;
	t2 += t1;
	t1 += 10;
	cout << t2;
	if (t1 < t2) cout << "t1 < t2";
	else if (t1 == t2) cout << "t1 = t2";
	else /* t1 > t2*/ cout << "t1 > t2";
	cout << endl;
	system("pause");
	return 0;
}