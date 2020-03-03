#include"LinkStack.h"

struct MyNumber {
	LinkNode node;
	double num_;
};
MyNumber* CreateMyNumber(double num) {
	MyNumber* mynum = new MyNumber;
	mynum->num_ = num;
	return mynum;
}

void funcCalculate(LinkStack* stack, const char oper)
{
	if (IsEmpty_LinkStack(stack)) return;

	MyNumber* myNum = (MyNumber*)Top_LinkStack(stack);
	double rightNum = myNum->num_;
	Pop_LinkStack(stack);

	myNum = (MyNumber*)Top_LinkStack(stack);
	if (myNum == nullptr)
	{
		throw "Error Stack";
	}
	double leftNum = myNum->num_;
	Pop_LinkStack(stack);
	delete myNum;

	double answer;

	if (oper == '+') { answer = leftNum + rightNum; }
	else if (oper == '-') { answer = leftNum - rightNum; }
	else if (oper == '*') { answer = leftNum * rightNum; }
	else if (oper == '/') { answer = leftNum / rightNum; }
	else if (oper == '^')
	{
		answer = leftNum;
		for (int i = 0; i < rightNum - 1; i++)
		{
			answer *= leftNum;
		}
	}
	else return;

	MyNumber* numPush = new MyNumber;
	numPush->num_ = answer;

	Push_LinkStack(stack, (LinkNode*)numPush);
	// myNum = (MyNumber*)Top_LinkStack(stack);
	cout << "Top Stack --> " << numPush->num_ << endl;
}

//// +
//void pulsCalculate(LinkStack* stack)
//{
//	MyNumber* myNum = (MyNumber*)Top_LinkStack(stack);
//	int rightNum = (int)(myNum->num_);
//	Pop_LinkStack(stack);
//	myNum = (MyNumber*)Top_LinkStack(stack);
//	int leftNum = (int)(myNum->num_);
//	myNum->num_ = (char*)(rightNum + leftNum);
//	Push_LinkStack(stack, (LinkNode*)myNum);
//}
//
//// -
//void minusCalculate(LinkStack* stack)
//{
//	MyNumber* myNum = (MyNumber*)Top_LinkStack(stack);
//	int rightNum = (int)(myNum->num_);
//	Pop_LinkStack(stack);
//	myNum = (MyNumber*)Top_LinkStack(stack);
//	int leftNum = (int)(myNum->num_);
//	myNum->num_ = (char*)(rightNum - leftNum);
//	Push_LinkStack(stack, (LinkNode*)myNum);
//}
//
//// *
//void multiplyCalculate(LinkStack* stack);
//
//// / 
//void divisionCalculate(LinkStack* stack);
//
//// ^
//void sqrCalculate(LinkStack* stack);

double Calculate(LinkStack* stack, string postix_formula)
{
	for (int i = 0; i < postix_formula.size(); i++)
	{
		//MyChar* mychar = new MyNumber;
		//mychar->num_ = (postix_formula.at(i));
		if (isNumber(postix_formula.at(i))) 
		{ 
			MyNumber* num = new MyNumber;
			num->num_ = postix_formula.at(i) - '0'; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			Push_LinkStack(stack, (LinkNode*)CreateMyNumber(num->num_)); 
		}
		if (isOperator(postix_formula.at(i))) { funcCalculate(stack, postix_formula.at(i)); }
		// delete mychar;
	}

	MyNumber* mynum = (MyNumber*)Top_LinkStack(stack);
	if (mynum == nullptr)
	{
		throw 1;
	}
	double ansewer = mynum->num_;
	// cout << ansewer;
	delete mynum;
	return ansewer;
}