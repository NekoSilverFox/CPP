#include<iostream>
using namespace std;

// ����Ҫ������Ҫ��������Ϣ�ṹ��������
struct DynamicArray
{
	// ���鴢��Ԫ�صĿռ��׵�ַ
	void** addr;

	// �洢���ݵ��ڴ�������ܹ����ɶ���Ԫ��
	int capacity;

	// ��ǰ�洢���ݵ��ڴ����ж��ٸ�Ԫ��
	int size;
};


// ��ʼ������
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


// ����Ԫ��
void Inset_DynamicArray(DynamicArray* arr, int pos, void* data)
{
	if (NULL == data || NULL == arr) { return; }

	if (pos<0 || pos>arr->size)
	{
		pos = arr->size;
	}

	//�жϿռ��Ƿ��㹻
	if (arr->size >= arr->capacity)
	{

		//1. ����һ�������ڴ�ռ�
		int newcapacity = arr->capacity * 2; // �����Ż�
		void** newspace =new void*[newcapacity];

		//2. ��ԭ���ռ�����ݿ������¿ռ�
		memcpy(newspace, arr->addr, sizeof(void*) * arr->capacity);

		//3. �ͷ�ԭ���ռ���ڴ�
		delete arr->addr;

		//4. ����addrָ��
		arr->addr = newspace;
		arr->capacity = newcapacity;
	}


	//�ƶ�Ԫ�أ���posλ�ÿճ�λ����
	for (int i = arr->size - 1; i >= pos; --i)
	{
		arr->addr[i + 1] = arr->addr[i];
	}

	//����Ԫ�ز��뵽posλ��
	arr->addr[pos] = data;
	arr->size++;
}


// ���� 
void Foreach_DynamicArray(DynamicArray* arr, void(*_callback)(void*)) // �ص�����
{
	if (NULL == arr || NULL == _callback) { return; }
	for (int i = 0; i < arr->size; i++)
	{
		_callback(arr->addr[i]);
	}

}