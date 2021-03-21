#include <iostream>
#include <omp.h>

const int N = 1000;
const int CHUNK_SIZE = 100;

int main()
{
	int tid;  // thread id
	int n_threads;

	// 开始并行执行
	#pragma omp parallel private(tid) //num_threads(16)
	{
		tid = omp_get_thread_num();
		std::cout << "Hello world from thread = " << tid << "\n";

		// 只对主线程生效（主线程的ID为0）
		if (tid == 0)
		{
			n_threads = omp_get_num_threads();
			std::cout << "Number of threads = " << n_threads << "\n";
		}
	}  // 当并行区域结束时，所有子线程都会并入主线程

	std::cout << "========================\n";

	int i, chunk;
	float a[N], b[N], c[N];

	// init
	for (i = 0; i < N; i++)
	{
		a[i] = b[i] = i * 1.0;
	}
	chunk = CHUNK_SIZE;

	// 数组 A, B, C 和 常量chunk 将由所有线程共享
	// 变量 i 对每个线程都是私有的；每个线程都有自己唯一的副本
	// 循环迭代将在 CHUNK 大小的块中动态分布
	// 线程在完成各自的工作后将不会同步（NOWAIT）
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