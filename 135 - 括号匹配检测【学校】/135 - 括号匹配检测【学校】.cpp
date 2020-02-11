#include<iostream>
#include<exception>
using namespace std;

//========================================================================
// ���ݧѧ��� StackOverflow �� StackUnderflow ���֧է��ѧӧݧ��� �էӧ� ���ߧ�ӧߧ��
// �ڧ�ܧݧ��ڧ�֧ݧ�ߧ�� ��ڧ��ѧ�ڧ�, �ܧ������ �ާ�ԧ�� �ӧ�٧ߧڧܧߧ��� ���� ��ѧҧ��� ��� ���֧ܧ��
//========================================================================

class StackOverflow : public std::exception
{
public:
	StackOverflow() : reason("Stack Overflow") {}
	const char* what() const { return reason; }
private:
	const char* reason;  // ! const

};

class StackUnderflow : public std::exception
{
public:
	StackUnderflow() : reason("Stack Underflow") {}
	const char* what() const { return reason; }
private:
	const char* reason;  // ! const

};

// =============================================================
//  ���ѧҧݧ�� �ܧݧѧ��� Stack ���֧է��ѧӧݧ�֧� ���ߧ��ڧ� �ѧҧ���ѧܧ�ߧ�ԧ� ���֧ܧ�
//==============================================================

template <class T>
class Stack
{
public:
	virtual ~Stack() {}// ���ڧ���ѧݧ�ߧ�� - �էݧ� ��֧�֧���֧է֧ݧ֧ߧڧ�

	// ���ҧ���ѧܧ�ߧ�� ���֧�ѧ�ڧ� ��� ���֧ܧ��

	virtual void push(const T& e) = 0; // ����ҧѧӧݧ֧ߧڧ� ��ݧ֧ާ֧ߧ�� �� ���֧� 

	virtual const T& pop() = 0;// ���էѧݧ֧ߧڧ� �� �ӧ�٧ӧ�ѧ�֧ߧڧ� �ӧ֧��ߧ֧ԧ� ��ݧ֧ާ֧ߧ��. 
								// ����ݧ� ��ݧ֧ާ֧ߧ��� �ߧ֧�, �ާ�ا֧� �ӧ�٧ߧڧܧߧ��� StackUnderflow 

	virtual bool isEmpty() = 0; // �����ӧ֧�ܧ� ���֧ܧ� �ߧ� �������� 

};

//==============================================================
// ����ܧݧ��ڧ�֧ݧ�ߧѧ� ��ڧ��ѧ�ڧ� WrongStackSize �ާ�ا֧� �ӧ�٧ߧڧܧߧ���,
// �֧�ݧ� �� �ܧ�ߧ����ܧ���� ���֧ܧ� �ߧ֧��ѧӧڧݧ�ߧ� �٧ѧէѧ� ��ѧ٧ާ֧�.
//==============================================================

class WrongStackSize : public std::exception
{
public:
	WrongStackSize() : reason("Wrong Stack Size") {}
	const char* what() const { return reason; }
private:
	const char* reason;  // ! const

};

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


//==============================================================
// ����ߧܧ�ڧ� �ѧߧѧݧڧ٧� ���ѧӧڧݧ�ߧ���� ��ѧ���ѧߧ�ӧܧ� ��ܧ�ҧ��.
// ����٧ӧ�ѧ�ѧ֧� �ڧ��ڧߧ�, �֧�ݧ� �ܧ�ݧڧ�֧��ӧ� ���ܧ��ӧѧ��ڧ� �� �٧ѧܧ��ӧѧ��ڧ� 
// ��ܧ�ҧ�� ��էߧ�ԧ� ��ڧ�� ���ӧ�ѧէѧ֧�, �� ��ߧ� �ڧާ֧�� ���ѧӧڧݧ�ߧ�� �ӧݧ�ا֧ߧߧ����.
// ���ѧ��ާѧ��ڧӧѧ���� ���� �ӧڧէ� ��ܧ�ҧ��: �ܧ��ԧݧ��, �ܧӧѧէ�ѧ�ߧ�� �� ��ڧԧ��ߧ��.
// ����ԧ�ާ֧ߧ��:
// - text - �ڧ���էߧ�� ��֧ܧ��, ���է֧�اѧ�ڧ� ��ܧ�ҧܧ�.
// - maxDeep - �ާѧܧ�ڧާѧݧ�ߧ� �ӧ�٧ާ�اߧ�� ����ӧ֧ߧ� �ӧݧ�ا֧ߧߧ���� ��ܧ�ҧ��.
//==============================================================

bool testBalanceBrackets(const char* text, int maxDeep = 30)
{

	StackArray<char>* stack = new StackArray<char>(maxDeep);

	bool isBalanceBrackets = true; //  �ڧ٧ާ֧ߧڧ� �ߧ� false ���� ��ҧߧѧ��ا֧ߧڧ� ���ڧҧܧ�

	// �֧�ݧ� �� �����ܧ���� ��ܧ�ҧ�� �֧��� ���ڧҧܧ�,
	// �ާ�ا֧� �ӧ�٧ߧڧܧߧ��� ���֧��ӧѧߧڧ� ���� ��ѧҧ��� ��� ���֧ܧ��
	try {
		char cText = '\0';    // ���֧�֧էߧ�� ��ڧާӧ�� ��֧ܧ���

		// ���ڧܧ� �ѧߧѧݧڧ٧� ��֧ܧ���: ���ڧ��ӧѧ���� ���ݧ�ܧ� ��ܧ�ҧܧ�, ����ѧݧ�ߧ�� ��ڧާӧ�ݧ� - �������ܧѧ����.
		// ���ڧܧ� �٧ѧӧ֧��ѧ֧��� ���� �է���ڧا֧ߧڧ� �ܧ�ߧ�� ��֧ܧ��� �ڧݧ� ��ҧߧѧ��ا֧ߧڧ� ��֧�ӧ�ԧ� �ߧ֧����ӧ֧���ӧڧ� ��ܧ�ҧ��.
		for (int i = 0; ((cText = text[i]) != '\0') && (isBalanceBrackets == true); i++) {

			switch (cText) {

			case '(': case '[': case '{':

				stack->push(cText);    // �ݧ�ҧѧ� �ݧ֧ӧѧ� ��ܧ�ҧܧ� ���ާ֧�ѧ֧��� �� ���֧�
				break;

			case ')': // ���ѧӧѧ� ��ܧ�ҧܧ� ����ӧ֧��֧��� �ߧ� �����ӧ֧���ӧڧ� ��� ��ܧ�ҧܧ�� �� �ӧ֧��ڧߧ� ���֧ܧ�
				if (stack->pop() != '(') {
					isBalanceBrackets = false;
				}
				break;

			case ']':
				if (stack->pop() != '[') {
					isBalanceBrackets = false;
				}
				break;

			case '}':
				if (stack->pop() != '{') {
					isBalanceBrackets = false;
				}
				break;
			}
		}
		// ������ڧԧߧ�� �ܧ�ߧ֧� ��֧ܧ���. ����� �� �����էܧ�, �֧�ݧ� ���֧� ����� �� �֧��� �ҧѧݧѧߧ� ��ܧ�ҧ��
		isBalanceBrackets = isBalanceBrackets && stack->isEmpty();

	}
	catch (StackUnderflow) {
		isBalanceBrackets = false;     // ���ҧߧѧ��ا֧ߧ� �ݧڧ�ߧ�� ���ѧӧѧ� ��ܧ�ҧܧ�
	}

	catch (StackOverflow) {
		isBalanceBrackets = false;  // ���ݧ�ا֧ߧߧ���� ��ܧ�ҧ�� �ҧ�ݧ��� �է�����ڧާ�� maxDeep 
	}

	delete stack;

	return isBalanceBrackets;

}

bool testBalanceBrackets(const char* text, int);

int main()
{

	const char* text00 = " ok ";
	cout << text00 << ": " << (testBalanceBrackets(text00) ? "right" : "wrong") << endl;

	const char* text01 = "(  )  ok ";
	cout << text01 << ": " << (testBalanceBrackets(text01) ? "right" : "wrong") << endl;

	const char* text02 = "( ( [] ) )  ok ";
	cout << text02 << ": " << (testBalanceBrackets(text02) ? "right" : "wrong") << endl;

	const char* text03 = "( ( [ { } [ ] ( [ ] ) ] ) )   OK";
	cout << text03 << ": " << (testBalanceBrackets(text03) ? "right" : "wrong") << endl;

	const char* text04 = "( ( [ { } [ ] ( [ ] ) ] ) )  ) extra right parenthesis ";
	cout << text04 << ": " << (testBalanceBrackets(text04) ? "right" : "wrong") << endl;

	const char* text05 = "( ( [{ }[ ]([ ])] )  extra left  parenthesis ";
	cout << text05 << ": " << (testBalanceBrackets(text05) ? "right" : "wrong") << endl;

	const char* text06 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";
	cout << text06 << ": " << (testBalanceBrackets(text06) ? "right" : "wrong") << endl;

	return 0;

}



