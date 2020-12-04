#include<iostream>
using namespace std;

// 首先要把所需要的数据信息结构定义下来
struct DynamicArray
{
	// 数组储存元素的空间首地址
	void** addr;

	// 存储数据的内存中最大能够容纳多少元素
	int capacity;

	// 当前存储数据的内存中有多少个元素
	int size;
};


// 初始化数组
DynamicArray* Init_DynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}

	DynamicArray* arr_dy = new DynamicArray;
	if (NULL == arr_dy)
	{
		return NULL;
	}

	arr_dy->capacity = capacity;
	arr_dy->addr = new void*[arr_dy->capacity];
	arr_dy->size = 0;

	return arr_dy;
}


// 插入元素
void Inset_DynamicArray(DynamicArray* arr, int pos, void* data)
{
	if (NULL == data || NULL == arr) { return; }

	if (pos<0 || pos>arr->size)
	{
		pos = arr->size;
	}

	//判断空间是否足够
	if (arr->size >= arr->capacity)
	{

		//1. 申请一块更大的内存空间
		int newcapacity = arr->capacity * 2; // 可以优化
		void** newspace =new void*[newcapacity];

		//2. 将原来空间的数据拷贝到新空间
		memcpy(newspace, arr->addr, sizeof(void*) * arr->capacity);

		//3. 释放原来空间的内存
		delete arr->addr;

		//4. 更新addr指向
		arr->addr = newspace;
		arr->capacity = newcapacity;
	}


	//移动元素，给pos位置空出位置来
	for (int i = arr->size - 1; i >= pos; --i)
	{
		arr->addr[i + 1] = arr->addr[i];
	}

	//将新元素插入到pos位置
	arr->addr[pos] = data;
	arr->size++;
}


// 遍历 
void Foreach_DynamicArray(DynamicArray* arr, void(*_callback)(void*)) // 回调函数
{
	if (NULL == arr || NULL == _callback) { return; }
	for (int i = 0; i < arr->size; i++)
	{
		_callback(arr->addr[i]);
	}

}
