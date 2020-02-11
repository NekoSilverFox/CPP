#include<iostream>
#include<exception>
using namespace std;

//========================================================================
// §¬§Ý§Ñ§ã§ã§í StackOverflow §Ú StackUnderflow §á§â§Ö§Õ§ã§ä§Ñ§Ó§Ý§ñ§ð§ä §Õ§Ó§Ö §à§ã§ß§à§Ó§ß§í§Ö
// §Ú§ã§Ü§Ý§ð§é§Ú§ä§Ö§Ý§î§ß§í§Ö §ã§Ú§ä§å§Ñ§è§Ú§Ú, §Ü§à§ä§à§â§í§Ö §Þ§à§Ô§å§ä §Ó§à§Ù§ß§Ú§Ü§ß§å§ä§î §á§â§Ú §â§Ñ§Ò§à§ä§Ö §ã§à §ã§ä§Ö§Ü§à§Þ
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
//  §º§Ñ§Ò§Ý§à§ß §Ü§Ý§Ñ§ã§ã§Ñ Stack §á§â§Ö§Õ§ã§ä§Ñ§Ó§Ý§ñ§Ö§ä §á§à§ß§ñ§ä§Ú§Ö §Ñ§Ò§ã§ä§â§Ñ§Ü§ä§ß§à§Ô§à §ã§ä§Ö§Ü§Ñ
//==============================================================

template <class T>
class Stack
{
public:
	virtual ~Stack() {}// §£§Ú§â§ä§å§Ñ§Ý§î§ß§í§Û - §Õ§Ý§ñ §á§Ö§â§Ö§à§á§â§Ö§Õ§Ö§Ý§Ö§ß§Ú§ñ

	// §¡§Ò§ã§ä§â§Ñ§Ü§ä§ß§í§Ö §à§á§Ö§â§Ñ§è§Ú§Ú §ã§à §ã§ä§Ö§Ü§à§Þ

	virtual void push(const T& e) = 0; // §¥§à§Ò§Ñ§Ó§Ý§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §Ó §ã§ä§Ö§Ü 

	virtual const T& pop() = 0;// §µ§Õ§Ñ§Ý§Ö§ß§Ú§Ö §Ú §Ó§à§Ù§Ó§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ö§â§ç§ß§Ö§Ô§à §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ. 
								// §¦§ã§Ý§Ú §ï§Ý§Ö§Þ§Ö§ß§ä§à§Ó §ß§Ö§ä, §Þ§à§Ø§Ö§ä §Ó§à§Ù§ß§Ú§Ü§ß§å§ä§î StackUnderflow 

	virtual bool isEmpty() = 0; // §±§â§à§Ó§Ö§â§Ü§Ñ §ã§ä§Ö§Ü§Ñ §ß§Ñ §á§å§ã§ä§à§ä§å 

};

//==============================================================
// §ª§ã§Ü§Ý§ð§é§Ú§ä§Ö§Ý§î§ß§Ñ§ñ §ã§Ú§ä§å§Ñ§è§Ú§ñ WrongStackSize §Þ§à§Ø§Ö§ä §Ó§à§Ù§ß§Ú§Ü§ß§å§ä§î,
// §Ö§ã§Ý§Ú §Ó §Ü§à§ß§ã§ä§â§å§Ü§ä§à§â§Ö §ã§ä§Ö§Ü§Ñ §ß§Ö§á§â§Ñ§Ó§Ú§Ý§î§ß§à §Ù§Ñ§Õ§Ñ§ß §â§Ñ§Ù§Þ§Ö§â.
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
// §º§Ñ§Ò§Ý§à§ß §Ü§Ý§Ñ§ã§ã§Ñ StackArray - §â§Ö§Ñ§Ý§Ú§Ù§Ñ§è§Ú§ñ §à§Ô§â§Ñ§ß§Ú§é§Ö§ß§ß§à§Ô§à §ã§ä§Ö§Ü§Ñ.
// §¿§Ý§Ö§Þ§Ö§ß§ä§í §ã§ä§Ö§Ü§Ñ §á§à§Þ§Ö§ë§Ñ§ð§ä§ã§ñ §Ó §Þ§Ñ§ã§ã§Ú§Ó.
//==============================================================

template <class T>
class StackArray : public Stack<T>
{
public:
	StackArray(int size = 100);   // size §Ù§Ñ§Õ§Ñ§Ö§ä §â§Ñ§Ù§Þ§Ö§â §ã§ä§Ö§Ü§Ñ "§á§à §å§Þ§à§Ý§é§Ñ§ß§Ú§ð"
	StackArray(const StackArray<T>& src);
	virtual ~StackArray() { delete[] array_; }

	void push(const T& e);
	const T& pop();
	bool isEmpty() { return top_ == 0; }

private:
	T* array_;     // §Þ§Ñ§ã§ã§Ú§Ó §ï§Ý§Ö§Þ§Ö§ß§ä§à§Ó §ã§ä§Ö§Ü§Ñ:
	int top_ = 0;  // §Ó§Ö§â§ê§Ú§ß§Ñ §ã§ä§Ö§Ü§Ñ, §ï§Ý§Ö§Þ§Ö§ß§ä, §Ù§Ñ§ß§Ö§ã§Ö§ß§ß§í§Û §Ó §ã§ä§Ö§Ü §á§à§ã§Ý§Ö§Õ§ß§Ú§Þ
	int size_;     // §â§Ñ§Ù§Þ§Ö§â §ã§ä§Ö§Ü§Ñ
};

template <class T>
StackArray<T>::StackArray(int size) {
	try {
		array_ = new T[size_ = size];// §á§í§ä§Ñ§Ö§Þ§ã§ñ §Ù§Ñ§Ü§Ñ§Ù§Ñ§ä§î §á§Ñ§Þ§ñ§ä§î §á§à§Õ §ï§Ý§Ö§Þ§Ö§ß§ä§í §ã§ä§Ö§Ü§Ñ...
	}
	catch (...) {                // §Ö§ã§Ý§Ú §é§ä§à-§ä§à §ã§Ý§å§é§Ú§Ý§à§ã§î (§ß§Ñ§á§â§Ú§Þ§Ö§â, §â§Ñ§Ù§Þ§Ö§â §ã§Ý§Ú§ê§Ü§à§Þ §Ò§à§Ý§î§ê§à§Û
		throw WrongStackSize();  // §Ú§Ý§Ú §à§ä§â§Ú§è§Ñ§ä§Ö§Ý§î§ß§í§Û) - §Ó§à§Ù§ß§Ú§Ü§Ñ§Ö§ä §Ú§ã§Ü§Ý§ð§é§Ú§ä§Ö§Ý§î§ß§Ñ§ñ §ã§Ú§ä§å§Ñ§è§Ú§ñ
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
	// §Ü§à§á§Ú§â§à§Ó§Ñ§ß§Ú§Ö §Þ§Ñ§ã§ã§Ú§Ó§Ñ 	
	for (int i = 0; i < src.top_; i++) {
		array_[i] = src.array_[i];
	}
	top_ = src.top_;
}
template <class T>
void StackArray<T>::push(const T& e)
{
	if (top_ == size_)
		throw StackOverflow(); // §ß§Ö§ä §Þ§Ö§ã§ä§Ñ §Õ§Ý§ñ §ß§à§Ó§à§Ô§à §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ
	top_++;
	array_[top_] = e;         // §Ù§Ñ§ß§Ö§ã§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §Ó §ã§ä§Ö§Ü
}

template <class T>
const T& StackArray<T>::pop()
{
	if (top_ == 0)
		throw StackUnderflow(); // §ã§ä§Ö§Ü §á§å§ã§ä
	return array_[top_--];  // §¿§Ý§Ö§Þ§Ö§ß§ä §æ§Ú§Ù§Ú§é§Ö§ã§Ü§Ú §à§ã§ä§Ñ§Ö§ä§ã§ñ §Ó §ã§ä§Ö§Ü§Ö, §ß§à §Ò§à§Ý§î§ê§Ö "§ß§Ö §Õ§à§ã§ä§å§á§Ö§ß"
}


//==============================================================
// §¶§å§ß§Ü§è§Ú§ñ §Ñ§ß§Ñ§Ý§Ú§Ù§Ñ §á§â§Ñ§Ó§Ú§Ý§î§ß§à§ã§ä§Ú §â§Ñ§ã§ã§ä§Ñ§ß§à§Ó§Ü§Ú §ã§Ü§à§Ò§à§Ü.
// §£§à§Ù§Ó§â§Ñ§ë§Ñ§Ö§ä §Ú§ã§ä§Ú§ß§å, §Ö§ã§Ý§Ú §Ü§à§Ý§Ú§é§Ö§ã§ä§Ó§à §à§ä§Ü§â§í§Ó§Ñ§ð§ë§Ú§ç §Ú §Ù§Ñ§Ü§â§í§Ó§Ñ§ð§ë§Ú§ç 
// §ã§Ü§à§Ò§à§Ü §à§Õ§ß§à§Ô§à §ä§Ú§á§Ñ §ã§à§Ó§á§Ñ§Õ§Ñ§Ö§ä, §Ú §à§ß§Ú §Ú§Þ§Ö§ð§ä §á§â§Ñ§Ó§Ú§Ý§î§ß§å§ð §Ó§Ý§à§Ø§Ö§ß§ß§à§ã§ä§î.
// §²§Ñ§ã§ã§Þ§Ñ§ä§â§Ú§Ó§Ñ§ð§ä§ã§ñ §ä§â§Ú §Ó§Ú§Õ§Ñ §ã§Ü§à§Ò§à§Ü: §Ü§â§å§Ô§Ý§í§Ö, §Ü§Ó§Ñ§Õ§â§Ñ§ä§ß§í§Ö §Ú §æ§Ú§Ô§å§â§ß§í§Ö.
// §¡§â§Ô§å§Þ§Ö§ß§ä§í:
// - text - §Ú§ã§ç§à§Õ§ß§í§Û §ä§Ö§Ü§ã§ä, §ã§à§Õ§Ö§â§Ø§Ñ§ë§Ú§Û §ã§Ü§à§Ò§Ü§Ú.
// - maxDeep - §Þ§Ñ§Ü§ã§Ú§Þ§Ñ§Ý§î§ß§à §Ó§à§Ù§Þ§à§Ø§ß§í§Û §å§â§à§Ó§Ö§ß§î §Ó§Ý§à§Ø§Ö§ß§ß§à§ã§ä§Ú §ã§Ü§à§Ò§à§Ü.
//==============================================================

bool testBalanceBrackets(const char* text, int maxDeep = 30)
{

	StackArray<char>* stack = new StackArray<char>(maxDeep);

	bool isBalanceBrackets = true; //  §Ú§Ù§Þ§Ö§ß§Ú§Þ §ß§Ñ false §á§â§Ú §à§Ò§ß§Ñ§â§å§Ø§Ö§ß§Ú§Ú §à§ê§Ú§Ò§Ü§Ú

	// §Ö§ã§Ý§Ú §Ó §ã§ä§â§å§Ü§ä§å§â§Ö §ã§Ü§à§Ò§à§Ü §Ö§ã§ä§î §à§ê§Ú§Ò§Ü§Ú,
	// §Þ§à§Ø§Ö§ä §Ó§à§Ù§ß§Ú§Ü§ß§å§ä§î §á§â§Ö§â§í§Ó§Ñ§ß§Ú§Ö §á§â§Ú §â§Ñ§Ò§à§ä§Ö §ã§à §ã§ä§Ö§Ü§à§Þ
	try {
		char cText = '\0';    // §à§é§Ö§â§Ö§Õ§ß§à§Û §ã§Ú§Þ§Ó§à§Ý §ä§Ö§Ü§ã§ä§Ñ

		// §¸§Ú§Ü§Ý §Ñ§ß§Ñ§Ý§Ú§Ù§Ñ §ä§Ö§Ü§ã§ä§Ñ: §å§é§Ú§ä§í§Ó§Ñ§ð§ä§ã§ñ §ä§à§Ý§î§Ü§à §ã§Ü§à§Ò§Ü§Ú, §à§ã§ä§Ñ§Ý§î§ß§í§Ö §ã§Ú§Þ§Ó§à§Ý§í - §á§â§à§á§å§ã§Ü§Ñ§ð§ä§ã§ñ.
		// §¸§Ú§Ü§Ý §Ù§Ñ§Ó§Ö§â§ê§Ñ§Ö§ä§ã§ñ §á§â§Ú §Õ§à§ã§ä§Ú§Ø§Ö§ß§Ú§Ú §Ü§à§ß§è§Ñ §ä§Ö§Ü§ã§ä§Ñ §Ú§Ý§Ú §à§Ò§ß§Ñ§â§å§Ø§Ö§ß§Ú§Ú §á§Ö§â§Ó§à§Ô§à §ß§Ö§ã§à§à§ä§Ó§Ö§ä§ã§ä§Ó§Ú§ñ §ã§Ü§à§Ò§à§Ü.
		for (int i = 0; ((cText = text[i]) != '\0') && (isBalanceBrackets == true); i++) {

			switch (cText) {

			case '(': case '[': case '{':

				stack->push(cText);    // §Ý§ð§Ò§Ñ§ñ §Ý§Ö§Ó§Ñ§ñ §ã§Ü§à§Ò§Ü§Ñ §á§à§Þ§Ö§ë§Ñ§Ö§ä§ã§ñ §Ó §ã§ä§Ö§Ü
				break;

			case ')': // §á§â§Ñ§Ó§Ñ§ñ §ã§Ü§à§Ò§Ü§Ñ §á§â§à§Ó§Ö§â§ñ§Ö§ä§ã§ñ §ß§Ñ §ã§à§à§ä§Ó§Ö§ä§ã§ä§Ó§Ú§Ö §ã§à §ã§Ü§à§Ò§Ü§à§Û §Ó §Ó§Ö§â§ê§Ú§ß§Ö §ã§ä§Ö§Ü§Ñ
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
		// §¥§à§ã§ä§Ú§Ô§ß§å§ä §Ü§à§ß§Ö§è §ä§Ö§Ü§ã§ä§Ñ. §£§ã§Ö §Ó §á§à§â§ñ§Õ§Ü§Ö, §Ö§ã§Ý§Ú §ã§ä§Ö§Ü §á§å§ã§ä §Ú §Ö§ã§ä§î §Ò§Ñ§Ý§Ñ§ß§ã §ã§Ü§à§Ò§à§Ü
		isBalanceBrackets = isBalanceBrackets && stack->isEmpty();

	}
	catch (StackUnderflow) {
		isBalanceBrackets = false;     // §°§Ò§ß§Ñ§â§å§Ø§Ö§ß§Ñ §Ý§Ú§ê§ß§ñ§ñ §á§â§Ñ§Ó§Ñ§ñ §ã§Ü§à§Ò§Ü§Ñ
	}

	catch (StackOverflow) {
		isBalanceBrackets = false;  // §£§Ý§à§Ø§Ö§ß§ß§à§ã§ä§î §ã§Ü§à§Ò§à§Ü §Ò§à§Ý§î§ê§Ö §Õ§à§á§å§ã§ä§Ú§Þ§à§Û maxDeep 
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



