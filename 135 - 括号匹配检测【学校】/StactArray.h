#pragma once
//==============================================================
// ���ѧҧݧ�� �ܧݧѧ��� StackArray - ��֧ѧݧڧ٧ѧ�ڧ� ��ԧ�ѧߧڧ�֧ߧߧ�ԧ� ���֧ܧ�.
// ���ݧ֧ާ֧ߧ�� ���֧ܧ� ���ާ֧�ѧ���� �� �ާѧ��ڧ�.
//==============================================================

template <class T>
class StackArray : public Stack<T>
{
public:
	StackArray(int size = 100);   // size �٧ѧէѧ֧� ��ѧ٧ާ֧� ���֧ܧ� "��� ��ާ�ݧ�ѧߧڧ�"
	StackArray(const StackArray<T>& src);
	virtual ~StackArray() { delete[] array_; }

	void push(const T& e);
	const T& pop();
	bool isEmpty() { return top_ == 0; }

private:
	T* array_;     // �ާѧ��ڧ� ��ݧ֧ާ֧ߧ��� ���֧ܧ�:
	int top_ = 0;  // �ӧ֧��ڧߧ� ���֧ܧ�, ��ݧ֧ާ֧ߧ�, �٧ѧߧ֧�֧ߧߧ�� �� ���֧� ����ݧ֧էߧڧ�
	int size_;     // ��ѧ٧ާ֧� ���֧ܧ�
};

template <class T>
StackArray<T>::StackArray(int size) {
	try {
		array_ = new T[size_ = size];// ����ѧ֧ާ�� �٧ѧܧѧ٧ѧ�� ��ѧާ��� ���� ��ݧ֧ާ֧ߧ�� ���֧ܧ�...
	}
	catch (...) {                // �֧�ݧ� ����-��� ��ݧ��ڧݧ��� (�ߧѧ��ڧާ֧�, ��ѧ٧ާ֧� ��ݧڧ�ܧ�� �ҧ�ݧ����
		throw WrongStackSize();  // �ڧݧ� ����ڧ�ѧ�֧ݧ�ߧ��) - �ӧ�٧ߧڧܧѧ֧� �ڧ�ܧݧ��ڧ�֧ݧ�ߧѧ� ��ڧ��ѧ�ڧ�
	}
	top_ = 0;
}

template <class T>
StackArray<T>::StackArray(const StackArray<T>& src) {
	try {
		array_ = new T[size_ = src.size_];
	}
	catch (...) {
		throw WrongStackSize();
	}
	// �ܧ��ڧ��ӧѧߧڧ� �ާѧ��ڧӧ� 	
	for (int i = 0; i < src.top_; i++) {
		array_[i] = src.array_[i];
	}
	top_ = src.top_;
}
template <class T>
void StackArray<T>::push(const T& e)
{
	if (top_ == size_)
		throw StackOverflow(); // �ߧ֧� �ާ֧��� �էݧ� �ߧ�ӧ�ԧ� ��ݧ֧ާ֧ߧ��
	top_++;
	array_[top_] = e;         // �٧ѧߧ֧�֧ߧڧ� ��ݧ֧ާ֧ߧ�� �� ���֧�
}

template <class T>
const T& StackArray<T>::pop()
{
	if (top_ == 0)
		throw StackUnderflow(); // ���֧� �����
	return array_[top_--];  // ���ݧ֧ާ֧ߧ� ��ڧ٧ڧ�֧�ܧ� ����ѧ֧��� �� ���֧ܧ�, �ߧ� �ҧ�ݧ��� "�ߧ� �է�����֧�"
}
