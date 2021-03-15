#include <iostream>
using namespace std;


// 设计立方体类(Cube)，求出立方体的面积( 2*a*b + 2*a*c + 2*b*c )和体积( a * b * c)，分别用全局函数和成员函数判断两个立方体是否相等。
class Cube {

public:

	// 改 长度
	void setLong(int Long) {
		m_Long = Long;
	}
	// 读 长度
	int getLong() {
		return m_Long;
	}


	// 改 宽
	void setWight(int Wight) {
		m_Wight = Wight;
	}
	// 读 宽
	int getWight() {
		return m_Wight;
	}

	// 改 高
	void setHigh(int High) {
		m_High = High;
	}
	// 读 高
	int getHigh() {
		return m_High;
	}


	// 打印操作：===================================================

	// 打印表面积
	void printS() {
		cout << "立方体的表面积为：" << 2 * (m_Long * m_Wight + m_Long * m_High + m_High * m_Wight) << endl;
	}
	//打印体积
	void printV() {
		cout << "立方体的体积为：" << m_Long * m_Wight * m_High << endl;
	}


private:

	int m_Long, m_Wight, m_High;
};

int main() {

	Cube t1;
	int x;

	cout << "长："; cin >> x; t1.setLong(x);
	cout << "宽："; cin >> x; t1.setWight(x);
	cout << "高："; cin >> x; t1.setHigh(x);

	// 调用成员函数，（打印面积和体积的）
	t1.printS();
	t1.printV();

	return 0;
}