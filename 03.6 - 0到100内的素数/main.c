#include <stdio.h>

int main()
{
	/*
	** 1. 定义两个计数器
	** count_prime 统计当前数(i) 能被几个数整除(范围：2到i - 1)
	** count_five 统计是否输出了5个数，如果输出了5个数则换行
	*/
	int count_prime = 0;
	int count_five = 0;

	for (int i = 2; i < 100; i++)
	{

		for (int j = 2; j < i - 1; j++)
		{
			/*
			** 如果 i % j == 0，则计数器加一
			*/
			if (0 == i % j) count_prime++;
		}

		/*
		** 上面为循环部分
		** ===================================================================
		** 下面为判断部分，注意，判断部分也是包含在第一个for循环中
		*/


		/*
		** 如果计数器count_prime == 0 则代表 从 2 到 i - 1范围中，i不能被任何数整除。此数为素数
		*/
		if (0 == count_prime)
		{
			printf("%d ", i);

			/*
			** 每输出一个数字，计数器count_five加一
			*/
			count_five++;

			/*
			** 计数器count_five == 5，则代表已经打印了5个数字
			** 打印换行
			** 计数器清零
			*/
			if (5 == count_five)
			{
				printf("\n");
				count_five = 0;
			}
		}

		else
		{
			/*
			** 如果计数器count_prime == 0 则代表 从 2 到 i - 1范围中，i不能被多个数整除。此数不为素数
			** 计数器清零
			*/
			count_prime = 0;
		}
	}
}