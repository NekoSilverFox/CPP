#include "header.h"
#include <iostream>
#include <exception>

int main()
{

	//lab1();
	try
	{
		lab2();

	}
	catch (const std::exception& exc)
	{
		std::cout << "Some thing going wrong!\n";
	}

	std::cout << "Output success!\n";

	//lab3();

	return 0;
}