#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<process.h>
#include<Windows.h>
using namespace std;
#ifndef H_FOOD
#define H_FOOD
/*--------------------------------------------------------------------
                                       Вариант 19
	Разработать класс «Блюдо», содержащий информацию : 
	▪ название, - m_name
	▪ количество калорий, m_CAL
	▪ тип кухни(страна изобретения), m_type
	▪ время приготовления - m_time
--------------------------------------------------------------------*/
class MyString
{
public:
	MyString(const char* s);
	MyString();
	char* s_string;
};

class Food
{
	Food& operator++();
	Food operator++(int);
	Food& operator--();
	Food operator--(int);

public:

	Food();
	explicit Food(string name, unsigned int CAL, string typeFood, string timeCook);
	Food(const Food& food);

	int _insignificance = 0.0; //псевдокод

	// Food name
	void setName(string name) const;
	string getName();

	// CAL
	void setCAL(unsigned int CAL) const;
	unsigned int getCAL();

	// Type of food
	void setType(string typeFood) const;
	string getType();

	// Cooking time
	void setTimeCook(string timeCook) const;
	string getTimeCook();

	~Food();

public:
	mutable string m_NameFood; // 10 ~ 20  内存对齐
	mutable string m_Type; // 5 ~ 20
	double _insignificance2 = 0; // 8 - Псевдокод
	mutable string m_TimeCook; // 3 ~ 6
	mutable unsigned int m_CAL; // 4
};

//智能指针
//用来托管自定义类型的对象，让对象进行自动的释放
class smartPointer
{
public:
	smartPointer(Food* food);

	//重载->
	Food* operator->();

	//重载 * 
	Food& operator*();

	~smartPointer();

private:
	Food* m_food;
};

// 定义节点数据类型 Связвный список
struct LinkNode
{
	friend ostream& operator<<(ostream& cout, LinkNode* pCurrent);
	friend ofstream& operator<<(ofstream& ofs, LinkNode* pCurrent);// Перегрузку
	friend ifstream& operator>>(ifstream& ifs, LinkNode* newNode);

	LinkNode();

	// 数据域
	Food* data;
	
	// 指针域
	LinkNode* next;

};

struct LinkNodeList
{
	LinkNode* header;
	LinkNodeList();
	~LinkNodeList();

	// 初始化链表 Инициализировать связанный список
	LinkNode* Init_LinkListFood(string fileName);

	// 在 值为 old_CAL 后面插入一个新的数据 new_CAL
	void InSetByCAL_LinkListFood(LinkNode* header);

	// 遍历 пересечение
	void ForEach_LinkListFood(LinkNode* header);

	// 销毁 уничтожить
	void Destroy_LinkListFood(LinkNode* header);

	// 删除值为cal的节点 Удалить одно Node 
	void RemByCAL_LinkListFood(LinkNode* header);

	// 清空 Удалить все
	void Clear_LinkListFood(LinkNode* header);

	// 按热值选择 Выберите по теплотворной способности
	void ChoiceCAL_LinkListFood(LinkNode* header);

	// 冒泡排序 Пузырьковая сортировка
	void BubbleSort_LinkListFood(LinkNode* header);

	// 输出到文件 вывод в файле
	void OutPutInFile_LinkNodeFood(LinkNode* header);

};

class MyOutOfRangeException :public exception
{
public:
	MyOutOfRangeException(string errorInfo);
	virtual  ~MyOutOfRangeException();
	virtual const char* what() const;
	string m_ErrorInfo;
};

// 用户选择
void UserChoice();

#endif // DEBUG