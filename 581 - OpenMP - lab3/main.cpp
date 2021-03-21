#include <iostream>
#include <omp.h>

const int CHUNK_SIZE = 50000;

void func()
{
	for (int i = 0; i < CHUNK_SIZE; i++)
	{
		rand();  // rand()��������������������ڲ�ʵ����������ͬ�෨ʵ�ֵ�
	}
}

int main()
{
	omp_lock_t dmax_lock;
	omp_init_lock(&dmax_lock);
	omp_set_num_threads(2);

	std::cout << ">>>> #pragma omp parallel��single��:" << std::endl;
	#pragma omp parallel
	for (int i = 0; i < 50; i++)
	{
		func();

		#pragma omp single  // �����⡿������ʱ��(single)��ֻ��һ�� ����/�߳� ��ִ��
		std::cout << "(��1 thread_num:" << omp_get_thread_num() << ") ";
		//std::cout << 5;
	}
	std::cout << std::endl << std::endl;



	std::cout << ">>>> #pragma omp parallel shared(share_a, share_b, share_c, share_d) private(private_a):" << std::endl;
	int share_a = 1;
	int share_b = 1;
	int share_c = 0;
	int share_d = 0;
	int private_i = 0;
	// ����ͬ�������Ϊ��ͬ�߳�
	#pragma omp parallel shared(share_a, share_b, share_c, share_d) private(private_i)
	{
		#pragma omp sections nowait
		{
			#pragma omp section
			for (private_i = 0; private_i < 10; private_i++)
			{
				share_c = share_a + share_b;
				std::cout << "\033[32mIn the end of part 1: i=" << private_i << " a=" << share_a << " b=" << share_b << " c=" << share_c << " \033[0m\n";
				share_a++;
				share_b++;
				func();
			}

			#pragma omp section
			for (private_i = 0; private_i < 10; private_i++)
			{
				share_d = share_a + share_b;
				std::cout << "\033[33mIn the end of part 2: i=" << private_i << " a=" << share_a << " b=" << share_b << " d=" << share_d << " \033[0m\n";
				share_a++;
				share_b++;
				func();
			}
		}  // end of sections
	}
	std::cout << std::endl << std::endl;



	/** �ϲ����й�������ṹ
	*      parallel for
	*      parallel sections
	*      parallel workshare (only for Fortran)
	*/
	std::cout << ">>>> #pragma omp parallel for (Part 1 critical):" << std::endl;
	#pragma omp parallel for
	for (int i = 0; i < 50; i++)
	{
		#pragma omp critical  // �����⡿������ʱ��(critical), ָ��ָ����һ��ֻ����һ���߳�ִ�еĴ�������
		{
			std::cout << "(��2 thread_num:" << omp_get_thread_num() << ") ";
			func();
		}
	}
	std::cout << std::endl << std::endl;



	std::cout << ">>>> #pragma omp parallel for (Part 2):" << std::endl;
	#pragma omp parallel for
	for (int i = 0; i < 50; i++)
	{
		std::cout << "(��3 thread_num:" << omp_get_thread_num() << ") ";
		func();
	}
	std::cout << std::endl << std::endl;



	std::cout << ">>>> #pragma omp sections nowait:" << std::endl
			  << "\t" << "#pragma omp section (WITH LOCK):" << std::endl;
	#pragma omp parallel
	{
#if 0
		��һ����ͬѧ����ʦ��д��
#endif
		#pragma omp sections nowait
		{
			#pragma omp section
			{
				omp_set_lock(&dmax_lock);
				for (int i = 0; i < 20; i++)
				{
					std::cout << "\033[32m(��4-1 thread_num:" << omp_get_thread_num() << ")\033[0m ";
					func();
				}
				omp_unset_lock(&dmax_lock);
			}

			#pragma omp section
			{
				for (int i = 0; i < 10; i++)
				{
					std::cout << "\033[33m(��4-2 thread_num:" << omp_get_thread_num() << ")\033[0m ";
					func();
				}
				if (omp_test_lock(&dmax_lock) == 0)
				{
					std::cout << "\033[31mLock has UNSET\033[0m";
				}
			}
		}
		//std::cout << std::endl << std::endl;

		/*
		* barrier ָ��ͬ���Ŷ��е������߳�
		* ������barrierָ��ʱ��һ���߳��ڸõ�ȴ���ֱ�����������̶߳�������barrierָ�Ȼ�������߳�ִ��barrier֮��Ĵ���
		*/
		//std::cout << ">>>> #pragma omp barrier:" << std::endl;
		#pragma omp barrier
		for (int i = 0; i < 10; i++)
		{
			std::cout << "��5 ";
			func();
		}
	}
	std::cout << std::endl << std::endl;

	std::cout << "\033[31mFINAL\033[0m" << std::endl;
}