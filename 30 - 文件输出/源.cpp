#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void write() {

	// ������
	ofstream ofs;
	ofs.open("./text.txt", ios::out | ios::trunc);

	// �ж��Ƿ�򿪳ɹ�
	if (!ofs.is_open()) {
		cerr << "Can't open the file!" << endl; 
	}

	// �������
	ofs << "Name: Nick Wilde" << endl;
	ofs << "Which furry: fox" << endl;
	ofs << "Age: 12" << endl;

	int x = 1;
	while (x != 0)
	{
		cin >> x; ofs << x << endl;
	}

	ofs.close();
}

void read() {
	// ������
	ifstream ifs;
	ifs.open("./text.txt", ios::in);

	// �Ƿ�򿪳ɹ�
	if (!ifs.is_open()) {
		cerr << "��ʧ�ܣ�" << endl;
	}

	// ʹ���˵ڶ��ַ�����ȡ�ļ�
	char buf[1024];
	while (!ifs.eof()) // eor() - �Ƿ����β
	{
		ifs.getline /* <--- getline���ж�ȡ*/ (buf/* ���� */,sizeof(buf)/* ���㳤��*/);
		cout << buf << endl;
	}
}

// ������
int main(void) {

	read();
	// cin.get();
	return 0;
}