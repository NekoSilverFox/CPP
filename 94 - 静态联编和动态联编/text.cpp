#include<iostream>
using namespace std;
// 94 - ��̬����Ͷ�̬����

class Animle
{
public:
	 virtual void speak()
	{
		cout << "С��������˵��" << endl;
	}
	 void eat()
	 {
		 cout << "С�������ڳԷ�" << endl;
	 }
};

class Fox : public Animle
{
public:
	 void speak()
	{
		cout << "What's the fox say? Yiff Yiff!!!!!" << endl;
	}
	 void eat()
	 {
		 cout << "Fox are having lanch" << endl;
	 }
};

// ����doSpeak ��speak�����ĵ�ַ��Ͱ󶨺��ˣ���󶨣���̬���࣬����׶ξ�ȷ�����˵�ַ
// ��������fox��speak��������ǰ�󶨺ú����ĵ�ַ�ˣ�������Ҫ������ʱ����ȥȷ��������ַ
// ��̬���࣬д�� doSpeak������Ϊ�麯��,�ڸ����������麯���������˶�̬
// ��������û���ָ�� ָ�� �������
void dospeak(Animle& animle) //Animal & animal = fox
{
	animle.speak();
}

void test01()
{
	Fox f1;
	dospeak(f1);
}

void test02()
{
	//Animle* an = new Animle;
	//an->speak();

	Animle* an = new Fox;
	an->speak();
	// *(int*)* (int*)an ������ַ������ָ�����ָ������ַ
	((void(*)())	(*(int*) * (int*)an)) ();
}

int main()
{
//	test01();
	test02();
	cout << sizeof(Animle) << endl;
	cout << sizeof(Fox) << endl;
}