/*------------------------------------------------------------
创建一个“Food”类，其中包含：
	1. 名称
	2. 卡路里（CAL）
	3. 菜肴种类（生产国）
	4. 烹饪时间 

想法：
	创建一个 “Food”类，数据从文件中输入
	创建一个链表，用于管理“Food”类
------------------------------------------------------------*/

#include"foodHeader.h"

int NODE_SUM = 0;

inline void _ERROUT(int err_)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	if (err_ == 0){cerr << "！ERROR！ --- Can't open the file ---" << endl << endl;}
	else if (err_ == 1)	{cerr << "ERROR! --- Don't have data ---" << endl << endl;}
	else if (err_ == 2)	{cerr << "Please import the data at first !" << endl << endl;}
	else{	cerr << "ERROR" << endl << endl;}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

MyString::MyString()
{
	this->s_string = (char*)malloc(sizeof(char) * 100);
}
MyString::MyString(const char* s)
{
	strcpy(s_string, s);
}

void InfoTe()
{
	MyString* str = new MyString;
	cin >> str->s_string;
}

// ===================================
Food::Food() : m_NameFood("None"), m_CAL(0), m_Type("None"), m_TimeCook("None")
{
	if (m_CAL < 0)
	{
		throw MyOutOfRangeException(string("ERROR ! Scope exception!")); // 范围异常
	}
}
Food::Food(string name, unsigned int CAL, string typeFood, string timeCook) : m_NameFood(name), m_CAL(CAL), m_Type(typeFood), m_TimeCook(timeCook)
{}
Food::Food(const Food& food)
{
	//food.getCAL()
	//this->setCAL() = food.getCAL();
	//m_NameFood = food.getName();
	//strcpy(m_Name, p.m_Name);
}
Food::~Food()
{}
//===============================
LinkNode::LinkNode()
{
	data = new Food;
}
//===============================
LinkNodeList::LinkNodeList()
{
	header = nullptr;
}
LinkNodeList::~LinkNodeList()
{}
//===============================
MyOutOfRangeException::MyOutOfRangeException(string errorInfo)
{
	this->m_ErrorInfo = errorInfo;
}

MyOutOfRangeException::~MyOutOfRangeException()
{}
const char* MyOutOfRangeException::what() const
{
	//返回 错误信息
	return this->m_ErrorInfo.c_str();
}
//=======================================================================

// Food:: name
void Food::setName(string name) const
{
	this->m_NameFood = name;
	// strcpy(m_NameFood, name);
}
string Food::getName()
{
	return this->m_NameFood;
}

// CAL
void Food::setCAL(unsigned int CAL) const
{
	this->m_CAL = CAL;
}
unsigned int Food::getCAL()
{
	return this->m_CAL;
}

// Type of food
void Food::setType(string typeFood) const
{
	this->m_Type = typeFood;
}
string Food::getType()
{
	return this->m_Type;
}

// Cooking time
void Food::setTimeCook(string timeCook) const
{
	this->m_TimeCook = timeCook;
}
string Food::getTimeCook()
{
	return this->m_TimeCook;
}

//前置++重载
Food& Food::operator++()
{
	this->_insignificance++;
	return *this;
}

//后置++ 重载
Food Food::operator++(int)
{
	Food tmp = *this;
	_insignificance++;
	return tmp;
}

//前置-- 重载
Food& Food::operator--()
{
	this->_insignificance--;
	return *this;
}

//后置-- 重载
Food Food::operator--(int)
{
	Food tmp = *this;
	_insignificance--;
	return tmp;
}

// Перегрузку "<<"
ostream& operator<<(ostream& cout, LinkNode* pCurrent)
{
	// 输出当前节点的数据域
	cout << "Name : " << pCurrent->data->getName() << endl; 
	cout << "Type : " << pCurrent->data->getType() << endl;
	cout << "CAL  : " << pCurrent->data->getCAL() << "K" << endl;
	cout << "Time : " << pCurrent->data->getTimeCook() << endl << endl;
	return cout; // 注意，返回一个 cout
}

// Перегрузку "<<"
ofstream& operator<<(ofstream& ofs, LinkNode* pCurrent)
{
	// 输出当前节点的数据域
	ofs << "Name : " << pCurrent->data->getName() << endl;
	ofs << "Type : " << pCurrent->data->getType() << endl;
	ofs << "CAL  : " << pCurrent->data->getCAL() << "K" << endl;
	ofs << "Time : " << pCurrent->data->getTimeCook() << endl << endl;
	return ofs; // 注意，返回一个 ofs
}

// Перегрузку ">>"
ifstream& operator>>(ifstream& ifs, LinkNode* newNode)
{
	string nameFood;
	unsigned int CAL;
	string typeFood;
	string timeCook;
	string temp;

	ifs >> nameFood;// cout << nameFood << endl;
	newNode->data->setName(nameFood);
	ifs >> temp; CAL = stoi(temp); //cout << CAL << endl;
	if (stoi(temp) < 0)
	{
		newNode->data->setTimeCook("ERROR - The CAL should biger than 0 !");
	}
	newNode->data->setCAL(CAL);
	ifs >> typeFood; //cout << typeFood << endl;
	newNode->data->setType(typeFood);
	ifs >> timeCook;//cout << timeCook << endl;
	newNode->data->setTimeCook(timeCook);
	newNode->next = NULL;
	if (stoi(timeCook) < 0)
	{
		newNode->data->setTimeCook("ERROR - The time should biger than 0 !");
	}
	ifs >> temp;

	return ifs; // 注意，返回一个 ifs
}
//===============================
smartPointer::smartPointer(Food* food)
{
	this->m_food = food;
}

//重载->
Food* smartPointer::operator->()
{
	return this->m_food;
}

//重载 * 
Food& smartPointer::operator*()
{
	return *this->m_food;
}

smartPointer::~smartPointer()
{
	cout << "/*智能指针析构了*/The smart pointer has been used." << endl;
	if (this->m_food != NULL)
	{
		delete this->m_food;
		this->m_food = NULL;
	}
}
//===============================

// 初始化
LinkNode* LinkNodeList::Init_LinkListFood(string fileName)
{
	// 读数据
	string temp;
	ifstream ifs;
	NODE_SUM = 0; // 未清零会导致多次初始化时造成数据堆积
	ifs.open(fileName, ios::in);

	// 是否打开成功
	if (!ifs.is_open()) {
		_ERROUT(0);
		return NULL; // 修改：在此处抛出异常！=====================
	}
	ifs >> temp;

	// 创建头节点
	LinkNode* header = new LinkNode;
	header->data = NULL;
	header->next = NULL;
	
	// 尾部(临时辅助)指针
	LinkNode* pRearCurrent = header;

	//string nameFood;
	//unsigned int CAL;
	//string typeFood;
	//string timeCook;

	while (!ifs.eof())
	{

		// 先创建 新节点
		LinkNode* newNode = new LinkNode;
		++NODE_SUM;
		//ifs >> nameFood;// cout << nameFood << endl;
		//newNode->data->setName(nameFood);
		//ifs >> temp; CAL = stoi(temp); //cout << CAL << endl;
		//newNode->data->setCAL(CAL);
		//ifs >> typeFood; //cout << typeFood << endl;
		//newNode->data->setType(typeFood);
		//ifs >> timeCook;//cout << timeCook << endl;
		//newNode->data->setTimeCook(timeCook);
		//newNode->next = NULL;
		//ifs >> temp;

		ifs >> newNode; // Перегрузку ">>"

		// 新节点 插入到链表中
		pRearCurrent->next = newNode; 

		// 更新尾部(临时辅助)指针指向
		pRearCurrent = newNode; // newNode 相当于 temp
	}
	ifs.close();
	cout << endl << "Successful data import ! Number of nodes : " << NODE_SUM << endl << endl;

	return header;
}

// 遍历
void LinkNodeList::ForEach_LinkListFood(LinkNode* header)
{
	if (NULL == header)
	{
		_ERROUT(1);
		return;
	}

	// 辅助指针变量
	LinkNode* pCurrent = header->next;

	while (pCurrent != NULL)
	{
		// 输出当前节点的数据域
		cout << pCurrent; // 重载 - Перегрузку <<
		pCurrent = pCurrent->next;
	}
}

// 冒泡排序（根据 CAL ）Пузырьковая сортировка (из CAL)
void LinkNodeList::BubbleSort_LinkListFood(LinkNode* header)
{
	if (NULL == header)
	{
		_ERROUT(1);
		return;
	}
	int choiceSort;
	LinkNode* pCurFront = header->next;
	LinkNode* pCurBehind = pCurFront->next;
	LinkNode* tempDate = new LinkNode;

	cout << "1 - Min -> Max\n2 - Max -> Min\n";
	cout << "◆ Please select the action to be performed : "; cin >> choiceSort;

	for (int i = 0; i < NODE_SUM; ++i) // 要注意：手动输入数据(或者删除)后，失效的原因是因为 NODE_SUM 没有 + 1 或者 -1，导致了 循环次数不足
	{
		for (int j = 0; j < NODE_SUM - i ; ++j)
		{
			if (choiceSort == 1)
			{
				if (pCurFront->data->getCAL() > pCurBehind->data->getCAL())
				{
					//	cout << pCurFront->data->getName() << endl;
					//	cout << pCurBehind->data->getName() << endl;
					tempDate->data = pCurFront->data;
					pCurFront->data = pCurBehind->data;
					pCurBehind->data = tempDate->data;
				}
			}

			else if (choiceSort == 2)
			{
				if (pCurFront->data->getCAL() < pCurBehind->data->getCAL())
				{
					tempDate->data = pCurFront->data;
					pCurFront->data = pCurBehind->data;
					pCurBehind->data = tempDate->data;
				}
			}
			else
			{
				cerr << "No corresponding operation ! " << endl;
			}

			pCurFront/*->next*/ = pCurBehind; // 加 ->next 会导致节点丢失！
			pCurBehind = pCurBehind->next;

			if (pCurBehind == NULL)
			{
				pCurFront = header->next; // 别再忘了！！！使用链表进行冒泡排序时，要注意将节点重置为头！未重置会导致外层循环失效！
				pCurBehind = pCurFront->next;
				//break; // 导致本层循环失效！
			}
		}
	}

	// Max and Min:
	LinkNode* pCurrent = header->next;
	if (choiceSort == 1)	{cout << endl << "------------ Min CAL ------------" << endl;}
	else{	cout << "------------ Max CAL ------------" << endl;}
	cout << pCurrent;
	while (pCurrent != NULL)
	{
		if (pCurrent->next == NULL)
		{
			if (choiceSort == 1)	{cout << "------------ Max CAL ------------" << endl;}
			else{	cout << endl << "------------ Min CAL ------------" << endl;}
			cout << pCurrent << "---------------------------------" << endl;
		}
		pCurrent = pCurrent->next; 
	}
}

// 按热值选择
void LinkNodeList::ChoiceCAL_LinkListFood(LinkNode* header)
{
	unsigned int minCAL, maxCAL, check = 0;
	cout << "The minnimun of CAL : "; cin >> minCAL;
	cout << "The maximun of CAL : "; cin >> maxCAL;

	if (NULL == header)
	{
		_ERROUT(1);
		return;
	}

	// 辅助指针变量
	LinkNode* pCurrent = header->next;

	while (pCurrent != NULL)
	{
		if ((pCurrent->data->getCAL() >= minCAL) && (pCurrent->data->getCAL() <= maxCAL))
		{
			check++;
			// 输出当前节点的数据域
			//cout << "Name : " << pCurrent->data->getName() << endl;
			//cout << "Type : " << pCurrent->data->getType() << endl;
			//cout << "CAL  : " << pCurrent->data->getCAL() << "K" << endl;
			//cout << "Time : " << pCurrent->data->getTimeCook() << endl << endl;
			cout << endl;
			cout << pCurrent; // Перегрузку "<<"

		}
		pCurrent = pCurrent->next;
	}
	if (check == NULL)
	{
		cout << "No Data !" << endl << endl;
	}
}


// 输出到文件 вывод в файле
void LinkNodeList::OutPutInFile_LinkNodeFood(LinkNode* header)
{
	ofstream ofs;
	int num = 0;
	ofs.open("./Output.txt", ios::out);

	// 是否打开成功
	if (!ofs.is_open()) {
		_ERROUT(0);
		return; // 修改：在此处抛出异常！=====================
	}

	if (NULL == header)
	{
		_ERROUT(1);
		return;
	}

	// 辅助指针变量
	LinkNode* pCurrent = header->next;

	ofs << "Number of food : " << NODE_SUM << endl << endl;
	while (pCurrent != NULL)
	{
		// 输出当前节点的数据域
		ofs << "-----------  № " << ++num << " -----------"<< endl;
		//ofs << "Name : " << pCurrent->data->getName() << endl;
		//ofs << "Type : " << pCurrent->data->getType() << endl;
		//ofs << "CAL  : " << pCurrent->data->getCAL() << "K" << endl;
		//ofs << "Time : " << pCurrent->data->getTimeCook() << endl << endl;
		ofs << pCurrent;
		pCurrent = pCurrent->next;
	}

	ofs.close();
	cout << "Has been output to the file - \"Output.txt\"" << endl << endl;
}

// 在 值为 old_CAL 后面插入一个新的数据 new_CAL
// Вставить новые данные new_CAL после значения old_CAL
void LinkNodeList::InSetByCAL_LinkListFood(LinkNode* header)
{
	if (header == nullptr)
	{
		_ERROUT(2);
		return;
	}
	unsigned int old_CAL;
	MyString* str = new MyString;
	cout << " - If there have corresponding CAL, the new data will INSERT before this bar\n - If not, insert to the END \n 0 - Exit\n\n";
	cout << "Please enter which CAL to insert before : "; cin >> str->s_string;
	old_CAL = *str->s_string;
	
	if (cin.fill() == 1) // 标志位是否损坏
	{ 
		cin.clear();
		cout << endl <<"Have quit" << endl << endl;
		return; 
	}
	if (*str->s_string == '0') 
	{
		cout << endl << "Have quit" << endl << endl; 
		return;
	}
	// 定义两个临时指针变量，一个指向前一个，一个指向后一个
	LinkNode* pPrev = header;
	LinkNode* pCurrent = header->next;
	++NODE_SUM;
	while (pCurrent != NULL)
	{

		if (pCurrent->data->getCAL() == old_CAL)
		{
			break;
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}

	// 创建 new_val 的新节点
	LinkNode* newNode = new LinkNode;
	string temp;
	unsigned int new_CAL;
	cout << "Name : "; cin >> temp;
	newNode->data->setName(temp);
	cout << "CAL  : "; cin >> new_CAL;
	newNode->data->setCAL(new_CAL);
	cout << "Type : "; cin >> temp;
	newNode->data->setType(temp);
	cout << "Time : "; cin >> temp;
	newNode->data->setTimeCook(temp);

	newNode->next = pCurrent;

	pPrev->next = newNode;
	cout << "Data inserted successfully !" << endl << endl;
}

// 删除值为cal的节点
// Удалить одно Node 
void LinkNodeList::RemByCAL_LinkListFood(LinkNode* header)
{
	if (header == nullptr)
	{
		_ERROUT(2);
		return;
	}
	unsigned int del_CAL;
	cout << " - Press CAL to delete data \n\n";
	cout << "Please enter which CAL you want to delete : "; cin >> del_CAL;
	// 定义两个临时指针变量，一个指向前，一个指向后
	LinkNode* pRear = new LinkNode;
	LinkNode* pCurrent = new LinkNode;

	pRear = header;
	pCurrent = pRear->next;

	while (pCurrent != NULL)
	{
		if (header == NULL)
		{
			break;
		}
		if (pCurrent->data->getCAL() == del_CAL)
		{
			break;
		}
		else
		{
			pRear = pCurrent;
			pCurrent = pCurrent->next;
		}
	}
	if (pCurrent == NULL)
	{
		cout << "Can't find the food, which CAL = " << del_CAL << endl << endl;
		return;
	}
	else
	{
		pRear->next = pCurrent->next;
		delete pCurrent;
		--NODE_SUM;
		cout << "Data deleted successfully !" << endl << endl;
	}
	return;
}


// 清空 Удалить все
void LinkNodeList::Clear_LinkListFood(LinkNode* header)
{
	if (NULL == header)
	{
		_ERROUT(1);
		return;
	}
	LinkNode* pCurrent = header->next;

	// 先要缓存当前节点的下一节点
	LinkNode* pNext;

	while (pCurrent != NULL)
	{
		pNext = pCurrent->next;

		delete pCurrent;

		pCurrent = pNext;

	}
	cout << "ALL data have cleaned" << endl;
	header->next = NULL; // 勿忘！！
}

// 销毁 Destroy
void LinkNodeList::Destroy_LinkListFood(LinkNode* header)
{
	unsigned int choice01;
	if (NULL == header)
	{
		_ERROUT(1);
		return;
	}
	else
	{	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << " ！ ！ ！Destroy nades may cause the program to CRASH ！ ！ ！\n\n-------Sure to continue ?-------\n\n 0 - Cancel \n 1 - Continue\n";
		for (int i = 0; i < 6; ++i) { system("color 4C");	system("color 0C"); }
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << "◆ Please select the action to be performed >>> ";

		cin >> choice01;
		if (choice01 == 0)
		{
			cout << "Destroy have quit" << endl << endl;
			return;
		}
		else if(choice01 == 1)
		{
			int temp = 0;
			// 创建临时指针
			LinkNode* pCurrent = header;
			LinkNode* pNext;

			while (pCurrent != NULL)
			{
				pNext = pCurrent->next;

				if (temp != 0)
				{
					cout << "Destroy :" << pCurrent->data->getName() << endl;
				}
				else
				{
					cout << "Destroy : header"  << endl;
				}
				cout << "IP  distroy：" << pCurrent->data << endl << endl;;
				delete pCurrent;
				pCurrent = pNext;
				++temp;
			}
		}
		else
		{
			cout << "No corresponding operation ! " << endl << endl;
			return;
		}
	}
}


void UserChoice()
{
	LinkNodeList myList;
	int numChoice;
	string fileName = "./1.txt";
	enum kEnumFood
	{
		exit, init,manualInsertionByCAL, printForEach, choiceByCAL, bubbleSort, delByCAL, clear, destroy, outPutInFile
	};

	while (true)
	{
		cout << "--------------------------------------------------" << endl << endl;
		cout << "1 - Inserting data from a file\n2 - Inserting data manually\n3 - Print data\n4 - Choice food by CAL\n5 - Bubble sort\n6 - Delete the data from LinkNodeList\n7 - Clear ALL the data from LinkNodeList\n8 - Destroy the data Clear the data from LinkNodeList (If destroy data will be ERROR)\n9 - Output to file\n0 - Exit\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		cout << "◆ Please select the action to be performed >>> ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cin >> numChoice;
		system("cls");
		cout << endl;
		switch (numChoice)
		{
		case exit:
			return;
		case init:
			cout << "◆ Please enter the required file name : "; cin >> fileName;
			myList.header = myList.Init_LinkListFood(fileName);
			break;
		case manualInsertionByCAL:
			myList.InSetByCAL_LinkListFood(myList.header);
			break;
		case printForEach:
			myList.ForEach_LinkListFood(myList.header);
			break;
		case choiceByCAL:
			myList.ChoiceCAL_LinkListFood(myList.header);
			break;
		case bubbleSort:
			myList.BubbleSort_LinkListFood(myList.header);
			myList.ForEach_LinkListFood(myList.header);
			break;
		case delByCAL:
			myList.RemByCAL_LinkListFood(myList.header);
			break;
		case clear:
			myList.Clear_LinkListFood(myList.header);
			break;
		case destroy:
			myList.Destroy_LinkListFood(myList.header);
			break;
		case outPutInFile:
			myList.OutPutInFile_LinkNodeFood(myList.header);
			break;
		default:
			cout << "No corresponding operation ! " << endl;
			break;
		}
	}
}

int main()
{
	// InfoTe();
	UserChoice();
}

