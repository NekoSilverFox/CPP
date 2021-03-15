#include <iostream>
#include<string>
#include<fstream>
using namespace std;

string str;
int ANSWER, CHECK_NUM = 0;

//----------------------------------------------§£§Ñ§â§Ú§Ñ§ß§ä 4---------------------------------------------
//
//§±§à§ß§ñ§ä§Ú§Ö §Ó§Ö§ë§Ö§ã§ä§Ó§Ö§ß§ß§à§Ö §é§Ú§ã§Ý§à §à§á§â§Ö§Õ§Ö§Ý§Ö§ß§à §ã§Ý§Ö§Õ§å§ð§ë§Ú§Þ §à§Ò§â§Ñ§Ù§à§Þ :
//<§Ó§Ö§ë§Ö§ã§ä§Ó§Ö§ß§ß§à§Ö> :: = <§Þ§Ñ§ß§ä§Ú§ã§ã§Ñ> <§á§à§â§ñ§Õ§à§Ü> | <§Ù§ß§Ñ§Ü> <§Þ§Ñ§ß§ä§Ú§ã§ã§Ñ> <§á§à§â§ñ§Õ§à§Ü>
//<§Þ§Ñ§ß§ä§Ú§ã§ã§Ñ> :: = <§è§Ö§Ý§à§Ö §Ò§Ö§Ù §Ù§ß§Ñ§Ü§Ñ> . <§è§Ö§Ý§à§Ö §Ò§Ö§Ù §Ù§ß§Ñ§Ü§Ñ> | <§è§Ö§Ý§à§Ö §Ò§Ö§Ù §Ù§ß§Ñ§Ü§Ñ>
//<§á§à§â§ñ§Õ§à§Ü> :: = E <§Ù§ß§Ñ§Ü> <§è§Ö§Ý§à§Ö §Ò§Ö§Ù §Ù§ß§Ñ§Ü§Ñ>
//<§è§Ö§Ý§à§Ö §Ò§Ö§Ù §Ù§ß§Ñ§Ü§Ñ> :: = <§è§Ú§æ§â§Ñ> | <§è§Ú§æ§â§Ñ> <§è§Ö§Ý§à§Ö §Ò§Ö§Ù §Ù§ß§Ñ§Ü§Ñ>
//<§è§Ú§æ§â§Ñ> :: = 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
//< §Ù§ß§Ñ§Ü > :: = +| -
//----------------------------------------------§¯§Ñ§Ù§Ó§Ñ§ß§Ú§ñ---------------------------------------------
// §Ó§Ö§ë§Ö§ã§ä§Ó§Ö§ß§ß§à§Ö - real number
// §Þ§Ñ§ß§ä§Ú§ã§ã§Ñ - mantissa
// §á§à§â§ñ§Õ§à§Ü - exponent
// §è§Ö§Ý§à§Ö §Ò§Ö§Ù §Ù§ß§Ñ§Ü§Ñ - unsigned
// §è§Ú§æ§â§Ñ - number
// §Ù§ß§Ñ§Ü - sign
//------------------------------------------------------------------------------------------------------


// §Ó§Ö§ë§Ö§ã§ä§Ó§Ö§ß§ß§à§Ö - real number
int fun_realNum() {
	int check_realNum = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '.') {
			if ((str[i - 1] > 47 && str[i - 1] < 58) && (str[i + 1] > 47 && str[i + 1] < 58) ) {
				check_realNum++;
			}
		}
	}

	if (check_realNum != 0) {
		return 6;
	}
	else {
		return 4;
	}
}


// §Þ§Ñ§ß§ä§Ú§ã§ã§Ñ - mantissa
int fun_mantissa() {
	int check_mantissa = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '.') {
			if ((str[i - 1] > 47 && str[i - 1] < 58) && (str[i + 1] > 47 && str[i + 1] < 58)) {
				check_mantissa++;
			}
		}
		if ((str[i] > 47 && str[i] < 58) && (str[i + 1] != '.' && str[i + 1] != '+' && str[i + 1] != '-')){
			check_mantissa++;			
		}
	}

	if (check_mantissa != 0) {
		return fun_realNum();
	}
	else {
		return 4;
	}
}


// §á§à§â§ñ§Õ§à§Ü - exponent
int fun_exponent() {
	int check_exponent = 0;

	for (int i = 0; i < str.size(); i++) {
		if ((str[i] == 'E' || str[i] == 'e') && (str[i + 1] == '+' || str[i + 1] == '-') && (str[i + 2] > 47 && str[i + 2] < 58) && (str[i + 3] != '+' && str[i + 3] != '-')) {
			check_exponent++;
		}
	}

	if (check_exponent == 1) {
		return fun_mantissa();
	}
	else {
		return 4;
	}
}


//§è§Ö§Ý§à§Ö §Ò§Ö§Ù §Ù§ß§Ñ§Ü§Ñ - fun_unsigned
int fun_unsigned() {
	int check_unsign = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] > 47 && str[i] < 58) {
			if (str[i + 1] == '+' || str[i + 1] == '-') {
				check_unsign++;
			}
		}
	}
	if (check_unsign == CHECK_NUM) {
		return 4;
	}
	else {
		return fun_exponent();
	}
}


// §è§Ú§æ§â§Ñ - number
int fun_number() {
	CHECK_NUM = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] > 47 && str[i] < 58) {
			CHECK_NUM++;
		}
	}

	if (CHECK_NUM != 0) {
		return fun_unsigned();
	}
	else {
		return 4;
	}
}


//§Ù§ß§Ñ§Ü ::= + || -
int fun_sign() {
	int check_sign = 0, check_letter = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			check_sign++;
		}

		else {
			if ((str[i] > 64 && str[i] < 69) || (str[i] > 69 && str[i] < 101) || (str[i] > 101 && str[i] < 123)) {
				check_letter++;
			}
		}
	}

	if (check_sign != 0 && check_letter == 0) {
		return fun_number();
	}
	else {
		return 4;
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

		ANSWER = fun_sign();
		
		switch (ANSWER)
		{
			case 6:{
				cout << "True" << endl;
				break;
			}
			case 4:{
				cout << "False" << endl;
				break;
			}
		}
	}
	cin.get();
	return 0;
}