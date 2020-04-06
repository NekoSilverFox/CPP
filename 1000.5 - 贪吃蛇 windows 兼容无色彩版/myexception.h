#pragma once
#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception // !!!!!! �Լ���д���쳣Ҫ�̳��� exception �࣡������
{
public:
	MyException(string errorInfo) // 1. Ҫ��д�вι��캯��
	{
		this->m_error = errorInfo;
	}
	~MyException() {}

	virtual const char* what() // 2. Ҫ��д���ڴ�ӡ������Ϣ�� what() ����
	{
		//���� ������Ϣ
		return this->m_error.c_str(); // �� string תΪ char*        stringxxxx.c_str()
	}

private:
	string m_error;
};
