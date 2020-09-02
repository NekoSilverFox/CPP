#include <iostream>
#include <string>
#include <exception>

using std::cout;
using std::endl;


std::string SPACE = "  ";


//  根据输入的数字进行ASCII样式转换，以string形式打印
std::string make_string(const int num, const int row)
{
	return 0;
}

void print_string(const int num)
{

}

std::string num_0(const int row, std::string& line)
{
	const std::string row_1 =  "╔═══╗";
	const std::string row_2 = "║╔═╗║";
	const std::string row_3 = "║║║║║";
	const std::string row_4 = "║║║║║";
	const std::string row_5 = "║╚═╝║";
	const std::string row_6 = "╚═══╝";

	switch (row)
	{
	case 1:
		line = line + row_1 + SPACE;
		break;

	case 2:
		line = line + row_2 + SPACE;
		break;

	case 3:
		line = line + row_3 + SPACE;
		break;

	case 4:
		line = line + row_4 + SPACE;
		break;

	case 5:
		line = line + row_5 + SPACE;
		break;

	case 6:
		line = line + row_6 + SPACE;
		break;

	default:
		throw std::domain_error("ERROR IN FUNCTION num_0");
		break;
	}
}

std::string num_1(const int row, std::string& line)
{
	const std::string row_1 = "─╔╗─";
	const std::string row_2 = "╔╝║─";
	const std::string row_3 = "╚╗║─";
	const std::string row_4 = "─║║─";
	const std::string row_5 = "╔╝╚╗";
	const std::string row_6 = "╚══╝";

	switch (row)
	{
	case 1:
		line = line + row_1 + SPACE;
		break;

	case 2:
		line = line + row_2 + SPACE;
		break;

	case 3:
		line = line + row_3 + SPACE;
		break;

	case 4:
		line = line + row_4 + SPACE;
		break;

	case 5:
		line = line + row_5 + SPACE;
		break;

	case 6:
		line = line + row_6 + SPACE;
		break;

	default:
		throw std::domain_error("ERROR IN FUNCTION num_1");
		break;
	}
}

std::string num_2(const int row, std::string& line)
{
	const std::string row_1 = "╔═══╗";
	const std::string row_2 = "║╔═╗║";
	const std::string row_3 = "╚╝╔╝║";
	const std::string row_4 = "╔═╝╔╝";
	const std::string row_5 = "║║╚═╗";
	const std::string row_6 = "╚═══╝";

	switch (row)
	{
	case 1:
		line = line + row_1 + SPACE;
		break;

	case 2:
		line = line + row_2 + SPACE;
		break;

	case 3:
		line = line + row_3 + SPACE;
		break;

	case 4:
		line = line + row_4 + SPACE;
		break;

	case 5:
		line = line + row_5 + SPACE;
		break;

	case 6:
		line = line + row_6 + SPACE;
		break;

	default:
		throw std::domain_error("ERROR IN FUNCTION num_1");
		break;
	}
}

std::string num_3(const int row, std::string& line)
{
	const std::string row_1 = "╔═══╗";
	const std::string row_2 = "║╔═╗║";
	const std::string row_3 = "╚╝╔╝║";
	const std::string row_4 = "╔╗╚╗║";
	const std::string row_5 = "║╚═╝║";
	const std::string row_6 = "╚═══╝";

	switch (row)
	{
	case 1:
		line = line + row_1 + SPACE;
		break;

	case 2:
		line = line + row_2 + SPACE;
		break;

	case 3:
		line = line + row_3 + SPACE;
		break;

	case 4:
		line = line + row_4 + SPACE;
		break;

	case 5:
		line = line + row_5 + SPACE;
		break;

	case 6:
		line = line + row_6 + SPACE;
		break;

	default:
		throw std::domain_error("ERROR IN FUNCTION num_1");
		break;
	}
}

std::string num_4(const int row, std::string& line)
{
	const std::string row_1 = "╔╗─╔╗";
	const std::string row_2 = "║║─║║";
	const std::string row_3 = "║╚═╝║";
	const std::string row_4 = "╚══╗║";
	const std::string row_5 = "───║║";
	const std::string row_6 = "───╚╝";

	switch (row)
	{
	case 1:
		line = line + row_1 + SPACE;
		break;

	case 2:
		line = line + row_2 + SPACE;
		break;

	case 3:
		line = line + row_3 + SPACE;
		break;

	case 4:
		line = line + row_4 + SPACE;
		break;

	case 5:
		line = line + row_5 + SPACE;
		break;

	case 6:
		line = line + row_6 + SPACE;
		break;

	default:
		throw std::domain_error("ERROR IN FUNCTION num_1");
		break;
	}
}

std::string num_5(const int row, std::string& line)
{
	const std::string row_1 = "╔═══╗";
	const std::string row_2 = "║╔══╝";
	const std::string row_3 = "║╚══╗";
	const std::string row_4 = "╚══╗║";
	const std::string row_5 = "╔══╝║";
	const std::string row_6 = "╚═══╝";

	switch (row)
	{
	case 1:
		line = line + row_1 + SPACE;
		break;

	case 2:
		line = line + row_2 + SPACE;
		break;

	case 3:
		line = line + row_3 + SPACE;
		break;

	case 4:
		line = line + row_4 + SPACE;
		break;

	case 5:
		line = line + row_5 + SPACE;
		break;

	case 6:
		line = line + row_6 + SPACE;
		break;

	default:
		throw std::domain_error("ERROR IN FUNCTION num_1");
		break;
	}
}

std::string num_6(const int row, std::string& line)
{
	const std::string row_1 = "╔═══╗";
	const std::string row_2 = "║╔══╝";
	const std::string row_3 = "║╚══╗";
	const std::string row_4 = "║╔═╗║";
	const std::string row_5 = "║╚═╝║";
	const std::string row_6 = "╚═══╝";

	switch (row)
	{
	case 1:
		line = line + row_1 + SPACE;
		break;

	case 2:
		line = line + row_2 + SPACE;
		break;

	case 3:
		line = line + row_3 + SPACE;
		break;

	case 4:
		line = line + row_4 + SPACE;
		break;

	case 5:
		line = line + row_5 + SPACE;
		break;

	case 6:
		line = line + row_6 + SPACE;
		break;

	default:
		throw std::domain_error("ERROR IN FUNCTION num_1");
		break;
	}
}

std::string num_7(const int row, std::string& line)
{
	const std::string row_1 = "╔═══╗";
	const std::string row_2 = "║╔═╗║";
	const std::string row_3 = "╚╝╔╝║";
	const std::string row_4 = "──║╔╝";
	const std::string row_5 = "──║║─";
	const std::string row_6 = "──╚╝─";

	switch (row)
	{
	case 1:
		line = line + row_1 + SPACE;
		break;

	case 2:
		line = line + row_2 + SPACE;
		break;

	case 3:
		line = line + row_3 + SPACE;
		break;

	case 4:
		line = line + row_4 + SPACE;
		break;

	case 5:
		line = line + row_5 + SPACE;
		break;

	case 6:
		line = line + row_6 + SPACE;
		break;

	default:
		throw std::domain_error("ERROR IN FUNCTION num_1");
		break;
	}
}

std::string num_8(const int row, std::string& line)
{
	const std::string row_1 = "╔═══╗";
	const std::string row_2 = "║╔═╗║";
	const std::string row_3 = "║╚═╝║";
	const std::string row_4 = "║╔═╗║";
	const std::string row_5 = "║╚═╝║";
	const std::string row_6 = "╚═══╝";

	switch (row)
	{
	case 1:
		line = line + row_1 + SPACE;
		break;

	case 2:
		line = line + row_2 + SPACE;
		break;

	case 3:
		line = line + row_3 + SPACE;
		break;

	case 4:
		line = line + row_4 + SPACE;
		break;

	case 5:
		line = line + row_5 + SPACE;
		break;

	case 6:
		line = line + row_6 + SPACE;
		break;

	default:
		throw std::domain_error("ERROR IN FUNCTION num_1");
		break;
	}
}

std::string num_9(const int row, std::string& line)
{
	const std::string row_1 = "╔═══╗";
	const std::string row_2 = "║╔═╗║";
	const std::string row_3 = "║╚═╝║";
	const std::string row_4 = "╚══╗║";
	const std::string row_5 = "╔══╝║";
	const std::string row_6 = "╚═══╝";

	switch (row)
	{
	case 1:
		line = line + row_1 + SPACE;
		break;

	case 2:
		line = line + row_2 + SPACE;
		break;

	case 3:
		line = line + row_3 + SPACE;
		break;

	case 4:
		line = line + row_4 + SPACE;
		break;

	case 5:
		line = line + row_5 + SPACE;
		break;

	case 6:
		line = line + row_6 + SPACE;
		break;

	default:
		throw std::domain_error("ERROR IN FUNCTION num_1");
		break;
	}
}
