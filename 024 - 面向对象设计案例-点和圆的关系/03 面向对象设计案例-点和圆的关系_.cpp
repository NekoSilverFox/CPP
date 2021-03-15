#include<iostream>
using namespace std;


// 点类
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



// 圆类
class Circle {
public:
	// 设置半径
	void setR(int r) { m_R = r; }
	// 获取半径
	int getR() { return m_R; }


	//==================================================================

	// 设置圆心
	void setCenter(Point p) {
		m_Center = p;
	}

	// 获取圆心   ★★★★ 这其实是一个创建的 Point 对象 ，★★★★  函数也可以作为一个对象！！！★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
	Point getCenter() {
		return m_Center;
	}

	//==================================================================

private:
	int m_R; //半径
	Point m_Center; // 圆心
};


// 实例化 及 调用 全局函数
void test1() {
	// 实例化 点 最象
	Point p_dian;
	p_dian.setX(10);
	p_dian.setY(10);


	// 实例化 圆 对象
	Circle c1;
	Point center;
	center.setX(10);
	center.setY(0);
	c1.setCenter(center);
	c1.setR(10);

	isInCircle(c1, p_dian);

}


// 利用全局函数判断点和圆的关系
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