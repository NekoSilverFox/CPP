#include<iostream>
using namespace std;

// ���ȥ����һ��ָ������ָ��
int myFun(int a, char b)
{
	cout << "===== void myFun(int a, char b) =====" << endl;
	return 0;
}

int main()
{
	// 1. ���庯�����ͣ�ͨ�����������庯��ָ��
	typedef int (Fun_TYPE)(int, char);

	Fun_TYPE* pFun = myFun;
	myFun(4, 'o');
	pFun(3, 'b'); // ϵͳ��Ĭ�ϼ� ��*����
	(*pFun)(3, 'v'); // ��ЧΪ myFun(3, 'v');

	// 2. ֱ�Ӷ��庯��ָ������
	typedef int(*Fun_p)(int, char);
	Fun_p pFun2 = myFun;
	pFun(12, 'l');

	// ����ָ��Ҫָ��ͬ���ͣ�


	// 3. ֱ�Ӷ��庯��ָ����� ���
	// ����ָ����ʵ  int(*)(�����б�)
	// ��ָ��ת��Ϊָ������  int(*)(�����б�)
	int(*pFun3_)(int, char) = (int(*)(int, char))NULL;
	int(*pFun3)(int, char) = NULL;
	pFun3 = myFun;

	// ���߽� 3 ����Ϊһ�仰��
	int(*pFun4)(int, char) = myFun;

	pFun4(1, 'f');
}