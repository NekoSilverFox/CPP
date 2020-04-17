
/*
	ע�⡢��������Ӧ���������ʵ� ������Ϣ(����(row)    ��(col)��-��������)    ���ִ���(count)    ����(length)

	ʵ��˼·��
	1.1  �Ƚ����¶�ȡ����кţ�������µ��ĵ��� output.txt ��
	1.2  ���ͬʱͳ�������е������� & �ַ����� & ����

	2.1 �� ���ʶ�ȡ����ȡ֮�󽫵���ת��ΪСд �ڵ�����Ӧ���浥�ʵ� �кš�������������д��Сд��Ϊһ�������ַ��������ȣ������������еڼ�����
		  ���� key_ ֵΪ������
	2.2 ��ȡ��ת����Сд֮�� ���뵽������������
	2.3 ע�⣺��������ÿ���п��ܳ��ֶ�����ʺ� ���ʱ��Ҫʹ��������������Ϣ�������������Ҫ�ͳ��ִ�����Ӧ���Ա��ӡʱ�ظ���ӡ

	3.1  ��ɲ���󣬽��������Ȱ������������������
	3.2  ���к������������ ��ͬʱ����Ĺ��ܿ�����ͬһ�еİ��ֵ������С�

	��ӡ��ʽ��
	-Word-			-Row-			-Col-			-Count-			-Length-

*/
#pragma once
#include "LinkList.hpp"
#include "MyErrorInfo.hpp"
#include "BinarySearchTree.hpp"

class BinarySearchTree;
class WordInfo;
struct Node;

class WordInfo
{
	friend class BinarySearchTreeord;
	friend struct Node;
public:
	WordInfo() : count_same_word_(0), length_word_(0) {}
public:
	LinkList<pair<int, int>> header_; // save the row and col of the world
	unsigned int count_same_word_;
	unsigned int length_word_;
};