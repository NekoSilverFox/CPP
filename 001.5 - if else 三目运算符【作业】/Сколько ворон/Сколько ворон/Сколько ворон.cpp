#include <iostream>
#include <conio.h>
using namespace std;
int main(void){

	int num;                 // num - §Ü§à§Ý§Ú§é§Ö§ã§ä§Ó§à §Ó§à§â§à§ß 
	cout << "§³§Ü§à§Ý§î§Ü§à §Ó§à§â§à§ß §Ó§í §ç§à§ä§Ú§ä§Ö?\n";
	cin >> num; 

	if (num > 0) {         // §¯§å§Ø§ß§à §Ù§ß§Ñ§ä§î §Ò§à§Ý§î§ê§Ö §Ú§Ý§Ú §Þ§Ö§ß§î§ê§Ö §ß§å§Ý§ñ
		
		if (num == 1) {
			cout << "§£ §ã§ä§Ñ§Ö 1 §Ó§à§â§à§ß§Ñ." << endl;
			return 0;
		}

		if (1 < num < 5) {
			cout << "§£ §ã§ä§Ñ§Ö " << num << " §Ó§à§â§à§ß§í." << endl;
			return 0;
		}

		if (num >= 5) {
			cout << "§£ §ã§ä§Ñ§Ö " << num << " §Ó§à§â§à§ß." << endl;
			return 0;
		}
	}

	else {
		cout << "§¯§å§Ø§ß§à §Ò§à§Ý§î§ê§Ö §é§Ö§Þ §ß§à§Ý§î!";
		return 1;
	}

		cin.get();
		return 0;
}