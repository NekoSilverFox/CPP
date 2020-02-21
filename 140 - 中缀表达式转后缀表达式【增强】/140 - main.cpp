#include"LinkStack.h"

int main()
{
	LinkStack* stack = InIt_LinkStack();
	string infix_formula("8+5*2*4-(6-2)*3*2^3"); // 8+5*2*4-(6-2)*3
	cout << "Infix  formula : " << infix_formula << endl << endl;

	string postix_formula;
	postix_formula = infixToPostix(stack, infix_formula);
	cout << "Postix formula : " << postix_formula << endl << endl;
	Desgroy_LinkStack(stack);

	LinkStack* stack2 = InIt_LinkStack();
	double answer = Calculate(stack2, postix_formula);
	Desgroy_LinkStack(stack2);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << endl << "Answer ===>>> " << answer << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}