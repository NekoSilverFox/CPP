#include <iostream>
#include <string>
#include <exception>

using std::cout;
using std::endl;


std::string SPACE = "  ";


//  ������������ֽ���ASCII��ʽת������string��ʽ��ӡ
std::string make_string(const int num, const int row)
{
	return 0;
}

void print_string(const int num)
{

}

std::string num_0(const int row, std::string& line)
{
	const std::string row_1 =  "�X�T�T�T�[";
	const std::string row_2 = "�U�X�T�[�U";
	const std::string row_3 = "�U�U�U�U�U";
	const std::string row_4 = "�U�U�U�U�U";
	const std::string row_5 = "�U�^�T�a�U";
	const std::string row_6 = "�^�T�T�T�a";

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
	const std::string row_1 = "���X�[��";
	const std::string row_2 = "�X�a�U��";
	const std::string row_3 = "�^�[�U��";
	const std::string row_4 = "���U�U��";
	const std::string row_5 = "�X�a�^�[";
	const std::string row_6 = "�^�T�T�a";

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
	const std::string row_1 = "�X�T�T�T�[";
	const std::string row_2 = "�U�X�T�[�U";
	const std::string row_3 = "�^�a�X�a�U";
	const std::string row_4 = "�X�T�a�X�a";
	const std::string row_5 = "�U�U�^�T�[";
	const std::string row_6 = "�^�T�T�T�a";

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
	const std::string row_1 = "�X�T�T�T�[";
	const std::string row_2 = "�U�X�T�[�U";
	const std::string row_3 = "�^�a�X�a�U";
	const std::string row_4 = "�X�[�^�[�U";
	const std::string row_5 = "�U�^�T�a�U";
	const std::string row_6 = "�^�T�T�T�a";

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
	const std::string row_1 = "�X�[���X�[";
	const std::string row_2 = "�U�U���U�U";
	const std::string row_3 = "�U�^�T�a�U";
	const std::string row_4 = "�^�T�T�[�U";
	const std::string row_5 = "�������U�U";
	const std::string row_6 = "�������^�a";

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
	const std::string row_1 = "�X�T�T�T�[";
	const std::string row_2 = "�U�X�T�T�a";
	const std::string row_3 = "�U�^�T�T�[";
	const std::string row_4 = "�^�T�T�[�U";
	const std::string row_5 = "�X�T�T�a�U";
	const std::string row_6 = "�^�T�T�T�a";

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
	const std::string row_1 = "�X�T�T�T�[";
	const std::string row_2 = "�U�X�T�T�a";
	const std::string row_3 = "�U�^�T�T�[";
	const std::string row_4 = "�U�X�T�[�U";
	const std::string row_5 = "�U�^�T�a�U";
	const std::string row_6 = "�^�T�T�T�a";

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
	const std::string row_1 = "�X�T�T�T�[";
	const std::string row_2 = "�U�X�T�[�U";
	const std::string row_3 = "�^�a�X�a�U";
	const std::string row_4 = "�����U�X�a";
	const std::string row_5 = "�����U�U��";
	const std::string row_6 = "�����^�a��";

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
	const std::string row_1 = "�X�T�T�T�[";
	const std::string row_2 = "�U�X�T�[�U";
	const std::string row_3 = "�U�^�T�a�U";
	const std::string row_4 = "�U�X�T�[�U";
	const std::string row_5 = "�U�^�T�a�U";
	const std::string row_6 = "�^�T�T�T�a";

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
	const std::string row_1 = "�X�T�T�T�[";
	const std::string row_2 = "�U�X�T�[�U";
	const std::string row_3 = "�U�^�T�a�U";
	const std::string row_4 = "�^�T�T�[�U";
	const std::string row_5 = "�X�T�T�a�U";
	const std::string row_6 = "�^�T�T�T�a";

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
