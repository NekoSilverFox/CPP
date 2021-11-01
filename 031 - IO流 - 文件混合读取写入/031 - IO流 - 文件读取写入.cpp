// 031 - IO流 - 文件读取写入.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <codecvt>

// 主函数
int main(void)
{
	// 创建文件输入流 C:\Users\mi\Desktop
	std::ifstream fir_ifs;
	std::ifstream sec_isf;
	std::ofstream output;

	// 打开文件
	fir_ifs.open("C:\\Users\\mi\\Desktop\\account.sql", std::ios::in);
	sec_isf.open("C:\\Users\\mi\\Desktop\\TEMP.sql", std::ios::in);
	output.open("C:\\Users\\mi\\Desktop\\output.sql", std::ios::out | std::ios::trunc);

	std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;

	// 判断是否打开成功
	if (!fir_ifs.is_open())
	{
		std::cerr << "account.sql 文件打开失败！";
		return 1;
	}
	if (!sec_isf.is_open())
	{
		std::cerr << "TEMP.sql 文件打开失败！";
		return 1;
	}
	if (!output.is_open())
	{
		std::cerr << "output.sql 文件打开失败！";
		return 1;
	}

	char buffer[1024];
	std::string str;
	while (!fir_ifs.eof() || !sec_isf.eof())
	{
		fir_ifs.getline(buffer, sizeof(buffer));
		str = buffer;
		output << str << "\n";



		sec_isf.getline(buffer, sizeof(buffer));
		str = buffer;
		output << str << "\n\n";
	}

	fir_ifs.close();
	sec_isf.close();
	output.close();

}
