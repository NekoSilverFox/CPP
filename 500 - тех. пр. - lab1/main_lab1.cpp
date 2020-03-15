#include"circle.hpp"
#include"rectangle.hpp"

void command_lab1(Shape& shape)
{
	cout << "Before move : " << endl;
	shape.printInfo();
	cout << endl << ">> Move the shape to (12, 7)" << endl;
	shape.move({12, 7});
	cout << endl << "After move :" << endl;
	shape.printInfo();
	
	cout << endl << "-----------------------------------------" << endl << endl;
	
	cout << "Before move : " << endl;
	shape.printInfo();
	cout << endl << ">> Move the shape ¡¾up  ¡ü  4 ¡¿&¡¾ left  ¡û  9¡¿" << endl;
	shape.move(4, -9);
	cout << endl << "After move :" << endl;
	shape.printInfo();

	cout << endl << "===================================================================" << endl << endl;
}

int main()
{
	Rectangle rectangle_1(5, 9, 13, 21);
	Circle circle_1(3, 7, 6);
	try
	{
		cout << "-------------------------- Rectangle --------------------------" << endl;
		command_lab1(rectangle_1);
		cout << "---------------------------- Circle ----------------------------" << endl;
		command_lab1(circle_1);
	}
	catch (MyErrorInfo& err)
	{
		cout << err.what() << endl;
	}
}