/*------------------------------------------------------------
����һ����Food���࣬���а�����
	1. ����
	2. ��·�CAL��
	3. �������ࣨ��������
	4. ���ʱ�� 

�뷨��
	����һ�� ��Food���࣬���ݴ��ļ�������
	����һ���������ڹ���Food����
------------------------------------------------------------*/

#include"foodHeader.h"

int NODE_SUM = 0;

inline void _ERROUT(int err_)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	if (err_ == 0){cerr << "��ERROR�� --- Can't open the file ---" << endl << endl;}
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
		throw MyOutOfRangeException(string("ERROR ! Scope exception!")); // ��Χ�쳣
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
	//���� ������Ϣ
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

//ǰ��++����
Food& Food::operator++()
{
	this->_insignificance++;
	return *this;
}

//����++ ����
Food Food::operator++(int)
{
	Food tmp = *this;
	_insignificance++;
	return tmp;
}

//ǰ��-- ����
Food& Food::operator--()
{
	this->_insignificance--;
	return *this;
}

//����-- ����
Food Food::operator--(int)
{
	Food tmp = *this;
	_insignificance--;
	return tmp;
}

// ���֧�֧ԧ��٧ܧ� "<<"
ostream& operator<<(ostream& cout, LinkNode* pCurrent)
{
	// �����ǰ�ڵ��������
	cout << "Name : " << pCurrent->data->getName() << endl; 
	cout << "Type : " << pCurrent->data->getType() << endl;
	cout << "CAL  : " << pCurrent->data->getCAL() << "K" << endl;
	cout << "Time : " << pCurrent->data->getTimeCook() << endl << endl;
	return cout; // ע�⣬����һ�� cout
}

// ���֧�֧ԧ��٧ܧ� "<<"
ofstream& operator<<(ofstream& ofs, LinkNode* pCurrent)
{
	// �����ǰ�ڵ��������
	ofs << "Name : " << pCurrent->data->getName() << endl;
	ofs << "Type : " << pCurrent->data->getType() << endl;
	ofs << "CAL  : " << pCurrent->data->getCAL() << "K" << endl;
	ofs << "Time : " << pCurrent->data->getTimeCook() << endl << endl;
	return ofs; // ע�⣬����һ�� ofs
}

// ���֧�֧ԧ��٧ܧ� ">>"
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

	return ifs; // ע�⣬����һ�� ifs
}
//===============================
smartPointer::smartPointer(Food* food)
{
	this->m_food = food;
}

//����->
Food* smartPointer::operator->()
{
	return this->m_food;
}

//���� * 
Food& smartPointer::operator*()
{
	return *this->m_food;
}

smartPointer::~smartPointer()
{
	cout << "/*����ָ��������*/The smart pointer has been used." << endl;
	if (this->m_food != NULL)
	{
		delete this->m_food;
		this->m_food = NULL;
	}
}
//===============================

// ��ʼ��
LinkNode* LinkNodeList::Init_LinkListFood(string fileName)
{
	// ������
	string temp;
	ifstream ifs;
	NODE_SUM = 0; // δ����ᵼ�¶�γ�ʼ��ʱ������ݶѻ�
	ifs.open(fileName, ios::in);

	// �Ƿ�򿪳ɹ�
	if (!ifs.is_open()) {
		_ERROUT(0);
		return NULL; // �޸ģ��ڴ˴��׳��쳣��=====================
	}
	ifs >> temp;

	// ����ͷ�ڵ�
	LinkNode* header = new LinkNode;
	header->data = NULL;
	header->next = NULL;
	
	// β��(��ʱ����)ָ��
	LinkNode* pRearCurrent = header;

	//string nameFood;
	//unsigned int CAL;
	//string typeFood;
	//string timeCook;

	while (!ifs.eof())
	{

		// �ȴ��� �½ڵ�
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

		ifs >> newNode; // ���֧�֧ԧ��٧ܧ� ">>"

		// �½ڵ� ���뵽������
		pRearCurrent->next = newNode; 

		// ����β��(��ʱ����)ָ��ָ��
		pRearCurrent = newNode; // newNode �൱�� temp
	}
	ifs.close();
	cout << endl << "Successful data import ! Number of nodes : " << NODE_SUM << endl << endl;

	return header;
}

// ����
void LinkNodeList::ForEach_LinkListFood(LinkNode* header)
{
	if (NULL == header)
	{
		_ERROUT(1);
		return;
	}

	// ����ָ�����
	LinkNode* pCurrent = header->next;

	while (pCurrent != NULL)
	{
		// �����ǰ�ڵ��������
		cout << pCurrent; // ���� - ���֧�֧ԧ��٧ܧ� <<
		pCurrent = pCurrent->next;
	}
}

// ð�����򣨸��� CAL ������٧���ܧ�ӧѧ� �����ڧ��ӧܧ� (�ڧ� CAL)
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
	cout << "�� Please select the action to be performed : "; cin >> choiceSort;

	for (int i = 0; i < NODE_SUM; ++i) // Ҫע�⣺�ֶ���������(����ɾ��)��ʧЧ��ԭ������Ϊ NODE_SUM û�� + 1 ���� -1�������� ѭ����������
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

			pCurFront/*->next*/ = pCurBehind; // �� ->next �ᵼ�½ڵ㶪ʧ��
			pCurBehind = pCurBehind->next;

			if (pCurBehind == NULL)
			{
				pCurFront = header->next; // �������ˣ�����ʹ���������ð������ʱ��Ҫע�⽫�ڵ�����Ϊͷ��δ���ûᵼ�����ѭ��ʧЧ��
				pCurBehind = pCurFront->next;
				//break; // ���±���ѭ��ʧЧ��
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

// ����ֵѡ��
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

	// ����ָ�����
	LinkNode* pCurrent = header->next;

	while (pCurrent != NULL)
	{
		if ((pCurrent->data->getCAL() >= minCAL) && (pCurrent->data->getCAL() <= maxCAL))
		{
			check++;
			// �����ǰ�ڵ��������
			//cout << "Name : " << pCurrent->data->getName() << endl;
			//cout << "Type : " << pCurrent->data->getType() << endl;
			//cout << "CAL  : " << pCurrent->data->getCAL() << "K" << endl;
			//cout << "Time : " << pCurrent->data->getTimeCook() << endl << endl;
			cout << endl;
			cout << pCurrent; // ���֧�֧ԧ��٧ܧ� "<<"

		}
		pCurrent = pCurrent->next;
	}
	if (check == NULL)
	{
		cout << "No Data !" << endl << endl;
	}
}


// ������ļ� �ӧ�ӧ�� �� ��ѧۧݧ�
void LinkNodeList::OutPutInFile_LinkNodeFood(LinkNode* header)
{
	ofstream ofs;
	int num = 0;
	ofs.open("./Output.txt", ios::out);

	// �Ƿ�򿪳ɹ�
	if (!ofs.is_open()) {
		_ERROUT(0);
		return; // �޸ģ��ڴ˴��׳��쳣��=====================
	}

	if (NULL == header)
	{
		_ERROUT(1);
		return;
	}

	// ����ָ�����
	LinkNode* pCurrent = header->next;

	ofs << "Number of food : " << NODE_SUM << endl << endl;
	while (pCurrent != NULL)
	{
		// �����ǰ�ڵ��������
		ofs << "-----------  �� " << ++num << " -----------"<< endl;
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

// �� ֵΪ old_CAL �������һ���µ����� new_CAL
// �����ѧӧڧ�� �ߧ�ӧ�� �էѧߧߧ�� new_CAL ����ݧ� �٧ߧѧ�֧ߧڧ� old_CAL
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
	
	if (cin.fill() == 1) // ��־λ�Ƿ���
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
	// ����������ʱָ�������һ��ָ��ǰһ����һ��ָ���һ��
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

	// ���� new_val ���½ڵ�
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

// ɾ��ֵΪcal�Ľڵ�
// ���էѧݧڧ�� ��էߧ� Node 
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
	// ����������ʱָ�������һ��ָ��ǰ��һ��ָ���
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


// ��� ���էѧݧڧ�� �ӧ��
void LinkNodeList::Clear_LinkListFood(LinkNode* header)
{
	if (NULL == header)
	{
		_ERROUT(1);
		return;
	}
	LinkNode* pCurrent = header->next;

	// ��Ҫ���浱ǰ�ڵ����һ�ڵ�
	LinkNode* pNext;

	while (pCurrent != NULL)
	{
		pNext = pCurrent->next;

		delete pCurrent;

		pCurrent = pNext;

	}
	cout << "ALL data have cleaned" << endl;
	header->next = NULL; // ��������
}

// ���� Destroy
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
		cout << " �� �� ��Destroy nades may cause the program to CRASH �� �� ��\n\n-------Sure to continue ?-------\n\n 0 - Cancel \n 1 - Continue\n";
		for (int i = 0; i < 6; ++i) { system("color 4C");	system("color 0C"); }
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << "�� Please select the action to be performed >>> ";

		cin >> choice01;
		if (choice01 == 0)
		{
			cout << "Destroy have quit" << endl << endl;
			return;
		}
		else if(choice01 == 1)
		{
			int temp = 0;
			// ������ʱָ��
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
				cout << "IP  distroy��" << pCurrent->data << endl << endl;;
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
		cout << "�� Please select the action to be performed >>> ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cin >> numChoice;
		system("cls");
		cout << endl;
		switch (numChoice)
		{
		case exit:
			return;
		case init:
			cout << "�� Please enter the required file name : "; cin >> fileName;
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

