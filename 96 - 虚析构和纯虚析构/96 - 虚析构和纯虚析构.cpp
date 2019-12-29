#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Animal
{
public:
	virtual void speak()
	{
		cout << "��������˵��" << endl;
	}

	//��ͨ���� �ǲ����������������ģ����Կ��ܻᵼ���ͷŲ��ɾ�
	//����������������������
	//virtual ~Animal()
	//{
	//	cout << "�����������������" << endl;
	//}


	//�������� д������ 
	//�������� ����Ҫ���� ����Ҫʵ�� ��������������ʵ�� ��������
	virtual ~Animal() = 0;
	//��������г����� ����������������ô�����Ҳ�������
	//������ ����ʵ��������
};
Animal::~Animal()
{
	cout << "������������" << endl;
}


class Fox : public Animal
{
public:
	virtual void speak()
	{
		cout << "Yiff yiff!!!" << endl;
	}

	Fox(const char* name)
	{
		this->m_Name = new char[strlen(name) + 1];
		strcpy(this->m_Name, name);
	}

	virtual ~Fox()
	{
		cout << "С����������" << endl;
		if (this->m_Name == NULL)
		{
			delete[] this->m_Name;
			this->m_Name = NULL;
		}
	}

	char* m_Name;
};

int main()
{
	Animal* an = new Fox("FOX");
	an->speak();
	delete an;

	// ������ִ�����������Ҳ������࣬����ʵ��������
	//Animal* an2 = new Animal;
	//Animal an3;
}