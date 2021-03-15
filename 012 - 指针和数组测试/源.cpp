#include <iostream>
using namespace std;
int main() {

	char s[] = "Now I'm testing for Arrey and Point!";
	char* t = s;

	cout << "s ------> " << s << endl; // Now I'm testing for Arrey and Point!";
	cout << "*s  ----->" << *s << endl; // N
	cout << "t ------> " << t << endl; // Now I'm testing for Arrey and Point
	cout << "*t  ----->" << *t << endl; // N
	cout << "sizfof(s) ------> " << sizeof(s) << endl; // 37
	cout << "sizeof(t) ------> " << sizeof(t) << endl;// 37
	cout << "sizeof(* t) ------> " << sizeof(*t) << endl; // 4


	cin.get();
	return 0;
}