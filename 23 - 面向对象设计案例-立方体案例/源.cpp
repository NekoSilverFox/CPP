#include<iostream>
using namespace std;

class Cube {

public:
	// 设置长
	void setL(int set_L) { L = set_L; }; // 不要把  L  和 set_L打反了！！！
	// 获取长
	int getL() { return L; };

	// 设置宽
	void setW(int set_W) { W = set_W; };
	// 获取宽
	int getW() { return W; };

	// 设置高
	void setH(int set_H) { H = set_H; };
	// 获取高
	int getH() { return H; };


	//求立方体体积
	void cudeV() {
		cout << "V = " << H * L * W << endl;
	}


	//求立方体面积
	void cudeS() {
		cout << "S = " << 2 * (L * W + L * H + H * W) << endl;
	}
private:
	int L;
	int W;
	int H;
};

int main() {
	Cube t2;
	int x;
	cout << "L = "; cin >> x; t2.setL(x);
	cout << "W = "; cin >> x; t2.setW(x);
	cout << "H = "; cin >> x; t2.setH(x);

	t2.cudeS();
	t2.cudeV();

}
