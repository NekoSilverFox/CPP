#include<iostream>
using namespace std;

class Cube {

public:
	// ���ó�
	void setL(int set_L) { L = set_L; }; // ��Ҫ��  L  �� set_L���ˣ�����
	// ��ȡ��
	int getL() { return L; };

	// ���ÿ�
	void setW(int set_W) { W = set_W; };
	// ��ȡ��
	int getW() { return W; };

	// ���ø�
	void setH(int set_H) { H = set_H; };
	// ��ȡ��
	int getH() { return H; };


	//�����������
	void cudeV() {
		cout << "V = " << H * L * W << endl;
	}


	//�����������
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
