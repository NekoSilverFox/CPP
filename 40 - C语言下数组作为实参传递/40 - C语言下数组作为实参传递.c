#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int judgePrize(int mark)
{
	if (mark > 90 && mark <= 100)
	{
		return 1;
	}	
	else if (mark <= 90 && mark >80)
	{
		return 2;
	}
	else if (mark <= 80 && mark >= 60)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}


int main()
{
	int mark = 0, temp;
	int arr_mark[9];
	for (int i = 0; i < 10; i++)
	{
		printf("��%d��ѧ���ĳɼ���", i + 1);
		scanf("%d", &mark);
		arr_mark[i] = mark;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("\n---------------------------------\n");
		printf("��%d��ѧ���ĳɼ���%d	", i + 1, arr_mark[i]);
		temp = judgePrize(arr_mark[i]);
		if (temp == 1)
		{
			printf("һ�Ƚ�\n");
		}
		else if (temp == 2)
		{
			printf("���Ƚ�\n");
		}
		else if (temp == 3)
		{
			printf("���Ƚ�\n");
		}
		else
		{
			printf("δ�ý�\n");
		}
	}
	
	 system("pause");
	return EXIT_SUCCESS;
}