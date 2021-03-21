#include <iostream>
#include <omp.h>

const int N = 1000;
const int CHUNK_SIZE = 100;

int main()
{
	int tid;  // thread id
	int n_threads;

	// ��ʼ����ִ��
	#pragma omp parallel private(tid) //num_threads(16)
	{
		tid = omp_get_thread_num();
		std::cout << "Hello world from thread = " << tid << "\n";

		// ֻ�����߳���Ч�����̵߳�IDΪ0��
		if (tid == 0)
		{
			n_threads = omp_get_num_threads();
			std::cout << "Number of threads = " << n_threads << "\n";
		}
	}  // �������������ʱ���������̶߳��Ტ�����߳�

	std::cout << "========================\n";

	int i, chunk;
	float a[N], b[N], c[N];

	// init
	for (i = 0; i < N; i++)
	{
		a[i] = b[i] = i * 1.0;
	}
	chunk = CHUNK_SIZE;

	// ���� A, B, C �� ����chunk ���������̹߳���
	// ���� i ��ÿ���̶߳���˽�еģ�ÿ���̶߳����Լ�Ψһ�ĸ���
	// ѭ���������� CHUNK ��С�Ŀ��ж�̬�ֲ�
	// �߳�����ɸ��ԵĹ����󽫲���ͬ����NOWAIT��
#pragma omp parallel shared(a, b, c, chunk) private(i)
	{
#pragma omp for schedule(dynamic, chunk) nowait
		for (i = 0; i < N; i++)
		{
			c[i] = a[i] + b[i];
		}
	}

	std::cout << "========================\n";



	return 0;
}