#pragma once
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
