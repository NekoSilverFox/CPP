#include <iostream>
using namespace std;
class Person
{
public:
	
	void show()
	{
		cout << "The age is what?" << endl; // û���õ� this ָ��
	}

	void showAge()
	{

		if (this == NULL)
		{
			return;
		}

		cout << m_age;// �õ��� this ָ�� �൱�� this->m_age; �������ʱ�� this == NULL�����Ի�崵�
	}
	int m_age;
};

int main()
{
	// ����һ����ָ��
	Person* p = NULL;

	p->show();

	p->showAge();
}

�ܽ᣺
1. �����Ա����û���õ� this ����ô��ָ�����ֱ�ӷ���
2. �����Ա�����õ� this ָ�룬��Ҫע�⣬���Լ� if �жϣ���� this Ϊ NULL ��  return