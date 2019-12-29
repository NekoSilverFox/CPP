#include<iostream>
using namespace std;


// ����
class Point {
public:
	void setX(int x) { m_X = x; }
	void setY(int y) { m_Y = y; }

	int getX() { return m_X; }
	int getY() { return m_Y; }

private:
	int m_X;
	int m_Y;

};



// Բ��
class Circle {
public:
	// ���ð뾶
	void setR(int r) { m_R = r; }
	// ��ȡ�뾶
	int getR() { return m_R; }


	//==================================================================

	// ����Բ��
	void setCenter(Point p) {
		m_Center = p;
	}

	// ��ȡԲ��   ����� ����ʵ��һ�������� Point ���� �������  ����Ҳ������Ϊһ�����󣡣������������������������������������������������
	Point getCenter() {
		return m_Center;
	}

	//==================================================================

private:
	int m_R; //�뾶
	Point m_Center; // Բ��
};


// ʵ���� �� ���� ȫ�ֺ���
void test1() {
	// ʵ���� �� ����
	Point p_dian;
	p_dian.setX(10);
	p_dian.setY(10);


	// ʵ���� Բ ����
	Circle c1;
	Point center;
	center.setX(10);
	center.setY(0);
	c1.setCenter(center);
	c1.setR(10);

	isInCircle(c1, p_dian);

}


// ����ȫ�ֺ����жϵ��Բ�Ĺ�ϵ
void isInCircle(Circle& c, Point& p) {

	int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int rDistance = c.getR() * c.getR();

	if (distance == rDistance)
	{
		cout << "On the circle." << endl;
	}
	else if (distance > rDistance) {
		cout << "Out of the circle." << endl;
	}
	else {
		cout << "IN the circle." << endl;
	}

}



int main() {

	test1();

	return 0;
}