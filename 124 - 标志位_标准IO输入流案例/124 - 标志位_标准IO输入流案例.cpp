// Ŀ�ģ��ж����� �����Ƿ�Ϊ 0 - 10�������������ѭ�����룡
// ע�� �������ĸ���뵽 int �����У��ᵼ�±�־λ����
// cin.fail() - �鿴��־λ   0 - ����  |  1 - ��
// cin.clear() - ���ñ�־λ
// cin.sync() - ��ջ�����

#include<iostream>
using namespace std;

int main()
{
	while (true)
	{
		int num;
		cout << "������һ�� 0 - 10֮������֣�";
		cin >> num;
		if (num >= 0 && num < 11 && cin.fail() == 0)
		{
			cout << "�����������Ϊ��" << num;
			break;
		}
		//���ñ�־λ
		cin.clear();

		// 2015 �汾�� vs �� �� ignore ���� 
		cin.ignore();

		cin.sync(); // ��ջ�����


		cout << "��־λ: " << cin.fail() << endl; //��־λ 0 ������  1 ������
		cout << "��������������������룺";
	}

}