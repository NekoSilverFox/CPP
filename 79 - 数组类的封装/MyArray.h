#pragma  once
#include <iostream>
using namespace std;

class MyArray
{
public:
	MyArray(); //Ĭ�Ϲ���  Ĭ��100����
	MyArray(int capacity);
	MyArray(const MyArray& array);

	~MyArray();


	//β�巨
	void push_Back(int val);

	//����������ȡֵ
	int getData(int index);

	//������������ֵ
	void setData(int index, int val);

	//��ȡ�����С
	int getSize();

	//��ȡ��������
	int getCapacity();

	//[]���������
	int& operator[](int index );

private:
	int * pAddress; //ָ�������洢���ݵ�ָ��
	int m_Size; //�����С
	int m_Capacity; //��������

};