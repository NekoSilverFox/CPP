#include <iostream>
using namespace std;


// �����������(Cube)���������������( 2*a*b + 2*a*c + 2*b*c )�����( a * b * c)���ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ���ȡ�
class Cube {

public:

	// �� ����
	void setLong(int Long) {
		m_Long = Long;
	}
	// �� ����
	int getLong() {
		return m_Long;
	}


	// �� ��
	void setWight(int Wight) {
		m_Wight = Wight;
	}
	// �� ��
	int getWight() {
		return m_Wight;
	}

	// �� ��
	void setHigh(int High) {
		m_High = High;
	}
	// �� ��
	int getHigh() {
		return m_High;
	}


	// ��ӡ������===================================================

	// ��ӡ�����
	void printS() {
		cout << "������ı����Ϊ��" << 2 * (m_Long * m_Wight + m_Long * m_High + m_High * m_Wight) << endl;
	}
	//��ӡ���
	void printV() {
		cout << "����������Ϊ��" << m_Long * m_Wight * m_High << endl;
	}


private:

	int m_Long, m_Wight, m_High;
};

int main() {

	Cube t1;
	int x;

	cout << "����"; cin >> x; t1.setLong(x);
	cout << "��"; cin >> x; t1.setWight(x);
	cout << "�ߣ�"; cin >> x; t1.setHigh(x);

	// ���ó�Ա����������ӡ���������ģ�
	t1.printS();
	t1.printV();

	return 0;
}