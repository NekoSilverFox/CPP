#include <iostream>
#include <vector>

int main()
{
	const int ROW = 3;
	double dl[ROW][ROW] = {
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9},
	};

	double dl2[ROW][ROW] = {
	{4, 5, 6},
	{7, 8, 9},
	{1, 2, 3},
	};

	std::vector<double*> dv = { *dl, *dl2 }; // 使用单个指针的方法导入二维数组

	for (int i_vec = 0; i_vec < dv.size(); i_vec++)
	{
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < ROW; j++)
			{
				std::cout << dv.at(i_vec)[i * ROW + j] << "  ";
			}
			std::cout << std::endl;
		}
		std::cout << "===============" << std::endl;
	}
}