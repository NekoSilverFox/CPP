#include <iostream>
#include<fstream>
#include <string>
using namespace std;

void c_style() {
	ifstream ifs;
	ifs.open("./Input.txt", ios::in);

	if (!ifs.is_open()) {
		cout << "ERROR! Can't open the file!" << endl;
	}

	int i = -1, num;
	char letter;

	ofstream ofs;
	ofs.open("./Output.txt", ios::out | ios::trunc);

	while (!ifs.eof()) {

		if (i == -1) {
			ifs >> num;
			i++;
			continue;
		}

		ifs >> letter;

		if (i < num && letter != '\0') {
			if (letter != 'a' && letter != 'A' && letter != 'e' && letter != 'E' && letter != 'i' && letter != 'I' && letter != 'o' && letter != 'O' && letter != 'u' && 'U') {
				cout << letter;
				ofs << letter;
			}
			letter = '\0';
			i++;
		}
	}
	ifs.close();
}


void string_style() {
	ifstream ifs;
	ifs.open("./Input.txt", ios::in);

	if (!ifs.is_open()) {
		cout << "ERROR! Can't open the file!" << endl;
	}

	string str;
	int i = -1,i2 = 0, num;
	ofstream ofs;
	ofs.open("./Output.txt", ios::out | ios::trunc);

	while (!ifs.eof()) {

		if (i == -1) {
			ifs >> num;
			i++;
			continue;
		}

		ifs >> str;

		for (int i = 0; i < str.size() && i < num; i++) {
			if (str[i] != 'a' && str[i] != 'A' && str[i] != 'e' && str[i] != 'E' && str[i] != 'i' && str[i] != 'I' && str[i] != 'o' && str[i] != 'O' && str[i] != 'u' && 'U') {
				cout << str[i];
				ofs << str[i];
			}
		}
	}
	ifs.close();
}

int main() {

	int choose;
	cout << "# Использующую только строки в стиле С ------> 1" << endl << endl;
	cout << "# Использующую строки типа string ------ > 2" << endl;
	cout << "Ввдтет тип(1 или 2):"; cin >> choose;
	switch (choose)
	{
	case 1:
		c_style();
		break;
	case 2:
		string_style();
		break;
	default:
		cout << "Недопустимый рарамер! Вводитет 1 или 2" << endl;
		break;
	}

	cin.get();
	return 0;
}

