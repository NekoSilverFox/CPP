#include<iostream>
using namespace std;
class abstractCaculator
{
public:
	void setVal(double val1, double val2)
	{
		this->val1 = val1;
		this->val2 = val2;
	}
	double getVal1()
	{
		return val1;
	}
	double getVal2()
	{
		return val2;
	}

	// virtual double getAnswer() { return 0; } //�麯��
	
	//���麯��
	//������������� ���麯��  ����̳и��࣬�ͱ���Ҫʵ�� ���麯��
	//��������� ���� ���麯�� ��������� ���޷�ʵ����������
	//��������˴��麯����ͨ���ֳ�Ϊ ������
	virtual double getAnswer() = 0;				// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
private:
	double val1;
	double val2;
};

// +
class PlusCaculator : public abstractCaculator
{
	virtual double getAnswer()
	{
		return getVal1() + getVal2();
	}
};

class SubCaculator : public abstractCaculator
{
	virtual double getAnswer()
	{
		return getVal1() - getVal2();
	}
};

class ChengCaculator : public abstractCaculator
{
	virtual double getAnswer()
	{
		return getVal1() * getVal2();
	}
};

class ChuCaculator : public abstractCaculator
{
	virtual double getAnswer()
	{
		return getVal1() / getVal2();
	}
};

//������������� ���麯��  ����̳и��࣬�ͱ���Ҫʵ�� ���麯��
class test : public abstractCaculator
{
	virtual double getAnswer()
	{
		return 0;
	}
};

int main()
{
	abstractCaculator* t1 = new PlusCaculator;

	t1->setVal(10, 20);
	cout << t1->getAnswer() << endl;
	delete t1;

	t1 = new SubCaculator;
	t1->setVal(10, 20);
	cout << t1->getAnswer() << endl;
	delete t1;

	t1 = new ChengCaculator;
	t1->setVal(10, 20);
	cout << t1->getAnswer() << endl;
	delete t1;

	t1 = new ChuCaculator;
	t1->setVal(10, 20);
	cout << t1->getAnswer() << endl;
	delete t1;

	test t1; //������������� ���麯��  ����̳и��࣬�ͱ���Ҫʵ�� ���麯��


	//����������˴��麯��������ʵ����������
	abstractCaculator sba1;
	abstractCaculator* abs2 = new abstractCaculator;
}