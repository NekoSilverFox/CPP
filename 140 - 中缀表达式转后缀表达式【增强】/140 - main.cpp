#include"LinkStack.h"

int main()
{
	LinkStack* stack = InIt_LinkStack();
	string infix_formula("8+5*2*4-(6-2)*3"); // 8+5*2*4-(6-2)*3
	cout << "Infix  formula : " << infix_formula << endl << endl;
	string postix_formula;
	postix_formula = infixToPostix(stack, infix_formula);
	cout << "Postix formula : " << postix_formula << endl;


}