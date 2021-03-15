#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;

void test1() {

	string test1; // Ĭ�Ϲ���
	test1 = "Hello World";
	cout << test1 << endl;

	string test2(test1); // ��������
	cout << test2 << endl;

	string test3 = test1; // ��������
	cout << test3 << endl;

	string test4 = "ʹ���ַ�����ʼ�� - test4"; // ʹ���ַ�����ʼ��
	cout << test4 << endl;

	string test5(20, '-'); // ʹ�� n ��   �ַ�  ��ʼ��
	cout << test5 << endl;


	// ������ֵ
	test4 = test3;
	cout << test4 << endl;

	test4 = "������ֵ";
	cout << test4 << endl;

	// ���ز���
	string test6;
	test6.assign("���Ĳ���������", 6);  // ���ַ�����ǰ n �� �ַ����¸�ֵ���ַ���
	cout << test6 << endl;

	string test7;
	test7.assign(test2, 1, 6); // �� test2 ���ӵ� 1 ���ַ���ע�⣺�� 0 ��ʼ������������� n ����ֵ�� string test7;
	cout << test7 << endl;
}


void test2() {

	/*
		string��ȡ�ַ�����
		char& operator[](int n);//ͨ��[]��ʽȡ�ַ�
		char& at(int n);//ͨ��at������ȡ�ַ�
	*/

	string str1;
	str1 = "Nick Wilde";

	for (int i = 0; i < str1.size() /*ע���������� .size()  - ����ȡ�ַ�����С*/ ; i++) {
		// cout << str1[i];
		cout << str1.at(i);
		// ���ֵ�����
		// ���������Խ�磬ֱ�ӹҵ�
		

		try {
			//cout << str1[100] << endl;     // ���������Խ�磬ֱ�ӹҵ�
			cout << str1.at(100) << endl;     // at ���׳��쳣
		}

		// ϵͳ��׼ out_of_range -  Խ���쳣           ʹ�� a - ����(���һ���ַ�)       ��ΪϵͳҪ���ò�������쳣����Ҫ����Ҫ��ͷ�ļ� #include<stdexcept>
		catch (out_of_range & a) {
			cout << a.what()  /*����*/ << endl;
		}
		catch(...){
			cout << "Խ���쳣" << endl;
		}
	}
}


void test3() {
	/*stringƴ�Ӳ���
			string& operator+=(const string& str);//����+=������
			string& operator+=(const char* str);//����+=������
			string& operator+=(const char c);//����+=������
			string& append(const char *s);//���ַ���s���ӵ���ǰ�ַ�����β
			string& append(const char *s, int n);//���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
			string& append(const string &s);//ͬoperator+=()
			string& append(const string &s, int pos, int n);//���ַ���s�д�pos��ʼ��n���ַ����ӵ���ǰ�ַ�����β
			string& append(int n, char c);//�ڵ�ǰ�ַ�����β���n���ַ�c
	*/

	string str1 = "���ߧ� ";
	string str2 = "�ߧѧ��ӧڧ��� ���ѧߧܧ�-���֧�֧�ҧ���";
	str1 += str2;
	cout << str1 << endl;

	str1.append("�ߧѧ��ӧڧ��� ���ѧߧܧ�-���֧�֧�ҧ���");
	cout << str1 << endl;
}


void test4() {
	/*string���Һ��滻

			find - ����������		rfind - ����������

			int find(const string& str, int pos = 0) const; //����str��һ�γ���λ��,��pos��ʼ����
			int find(const char* s, int pos = 0) const;  //����s��һ�γ���λ��,��pos��ʼ����
			int find(const char* s, int pos, int n) const;  //��posλ�ò���s��ǰn���ַ���һ��λ��
			int find(const char c, int pos = 0) const;  //�����ַ�c��һ�γ���λ��
			int rfind(const string& str, int pos = npos) const;//����str���һ��λ��,��pos��ʼ����
			int rfind(const char* s, int pos = npos) const;//����s���һ�γ���λ��,��pos��ʼ����
			int rfind(const char* s, int pos, int n) const;//��pos����s��ǰn���ַ����һ��λ��
			int rfind(const char c, int pos = 0) const; //�����ַ�c���һ�γ���λ��
			string& replace(int pos, int n, const string& str); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
			string& replace(int pos, int n, const char* s); //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
	*/

	string test1 = "a.bc.def..ghi..jbc...k";
	int pos = test1.find("bc"); // �Ҳ���Ϊ -1
	int num_dot = count(test1.begin(), test1.end(), '.');  // ���� ���������ֵĴ��������������� �ص㣡
	cout << "num_dot = " << num_dot << endl;
	num_dot++;
	cout << "num_dot = " << num_dot << endl;
	cout << "pos = " << pos << endl;

	int pos2 = test1.rfind("bc"); // ��������飬���Ǳ���Ǵ������ң�������
	cout << "pos2 = " << pos2 << endl;



	// �滻
	string test2 = "Zootopia";
	test2.replace(1, 3, "���а�"); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
	cout << test2 << endl;
}


void test7() {
	/*string�����ɾ������
		string& insert(int pos, const char* s); //�����ַ���
		string& insert(int pos, const string& str); //�����ַ���
		string& insert(int pos, int n, char c);//��ָ��λ�ò���n���ַ�c
		string& erase(int pos, int n = npos);//ɾ����Pos��ʼ��n���ַ� 
*/

}


int main() {

	test4();

	cin.get();
	return 0;
}