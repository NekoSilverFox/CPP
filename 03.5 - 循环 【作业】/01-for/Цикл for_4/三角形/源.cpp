#include <iostream>
using namespace std;
int main(void) {

	int N, blank, for_blank, star, for_star = 0;				// N--Ϊ�����ֵ����Ϊ�����εı߳�; blank--ΪӦ����Ŀո�, for_blank Ϊ��������ո������

	cout << "N= "; cin >> N; cout << endl;
	for_blank = N;															// �� N ��ֵ���� for_star

	while (for_star != N) {

		for (blank = for_blank; blank > 0; blank--) {		//����ո�
			cout << " ";
		}

		for (star = 0; star <= for_star; star++) {			//��� "* " ;	star Ϊÿ�д�ӡ�����ǵ�����; for_star Ϊ������� "* " ������
			cout << "* ";
		}

		cout << endl;
		for_star++, for_blank--;
	}
}