//#include<iostream>
//using namespace std;
//
//class Animal
//{
//public:
//	Animal() :m_age(0) {}
//public:
//	int m_age;
//};
//
//class Sheep : public Animal
//{
//
//};
//
//class Tuo : public Animal
//{
//
//};
//
//class SheepTuo : public Sheep, public Tuo
//{
//
//};
//
//int main2()
//{
//	SheepTuo st;
//	st.Sheep::m_age = 10;
//	st.Tuo::m_age = 20;
//
//	// cout << st.m_age << endl; Жўвхад
//	cout << st.Sheep::m_age << endl;
//	cout << st.Tuo::m_age << endl;
//
//	return 0;
//}