#include <iostream>
#include<string>
#include<fstream>
using namespace std;

string str;
int CHECK_SIGN;

//----------------------------------------------Вариант 4---------------------------------------------

//Понятие вещественное число определено следующим образом :
//<вещественное> :: = <мантисса> <порядок> | <знак> <мантисса> <порядок>
//<мантисса> :: = <целое без знака> . <целое без знака> | <целое без знака>
//<порядок> :: = E <знак> <целое без знака>
//<целое без знака> :: = <цифра> | <цифра> <целое без знака>
//<цифра> :: = 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
//< знак > :: = +| -

//----------------------------------------------Названия---------------------------------------------
bool fun_sign();				// знак - sign
bool fun_letter_Ee();		// буква - letter
bool fun_number();			// цифра - number
// bool fun_unsigned();		// целое без знака - unsigned
bool fun_exponent();		// порядок - exponent
bool fun_mantissa();		// мантисса - mantissa
bool fun_realNum();		// вещественное - real number
//------------------------------------------------------------------------------------------------------


bool fun_realNum(){
	if (CHECK_SIGN == 2) {
		if (str[0] != '+' && str[0] != '-') {
			return false;
		}
	}
	else {
		return true;
	}
}


bool fun_mantissa() {
	int num_dian = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '.') {
			num_dian++;
		}
	}
	
	if (num_dian == 1) {

		int place_sign_dian = str.find('.');

		int place_letter_Ee = str.find('E');
		if (place_letter_Ee == -1) {
			place_letter_Ee = str.find('e');
		}

		if (place_sign_dian > place_letter_Ee) {
			return false;
		}
		else {
			return fun_realNum(); //=====================================
		}
	}

	else if (num_dian == 0)
	{
		return fun_realNum(); // ==================================
	}

	else
	{
		return false;
	}

}


bool fun_exponent() {
	for (int i = 0; i < str.size(); i++) {
		if ((str[i] == 'E' || str[i] == 'e') && (str[i + 1] == '+' || str[i + 1] == '-')) {
			return fun_mantissa();
		}
	}
	return false;
}


bool fun_letter_Ee() {
	int check_Ee = 0, check_letter = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] > 57 && str[i] < 127) {		// 如果不为 E e ，或者为 : ; < > ? ^ & * ( ) " ' 则挂掉
			check_letter++;
		}
		if (str[i] == 'E' || str[i] == 'e') {
			check_Ee++;
		}
	}

	if (check_Ee == check_letter && check_Ee == 1 ) {
		return fun_exponent();
	}
	else {
		return false;
	}
}


bool fun_number() {
	int check_num = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] > 47 && str[i] < 58) {
			check_num++;
		}
	}

	if (check_num != 0) {
		return fun_letter_Ee();
	}
	else {
		return false;
	}
}


bool fun_sign() {
	CHECK_SIGN = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			CHECK_SIGN++;
		}
	}
	if (CHECK_SIGN < 3 && CHECK_SIGN > 0) {
		return fun_number();
	}
	else {
		return false;
	}
}


int main() {
	ifstream ifs;
	ifs.open("./Input.txt", ios::in);
	if (!ifs.is_open()) {
		cerr << "Can't open the file!" << endl;
	}

	while (!ifs.eof())
	{
		ifs >> str;
		cout.width(20) | cout.setf(ios::left);
		cout << str;
		if (fun_sign()) {
			cout << "Ture" << endl;
		}
		else {
			cout << "False" << endl;
		}
	}
	return 0;
}