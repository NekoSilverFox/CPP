
/*
	��---13.4.2020---lab 1.2.1 --��
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

	ע�⣺
	4.1 ����еĳ��ȣ�ȥ���ո񣩵��� �ۼӵ��ʵĳ��� ����ô�����ж�ȡ������ ���ж���
	4.2 ���Ϊ���У�ֱ���������������������ۼ�
	4.3 ����ASCII����Ĵ�Сд,�����е���ת��ΪСд���޳���. ��s ''
	4.4 
*/

#pragma once
#include "MyErrorInfo.hpp"
#include"WordInfo.hpp"
#include <iostream>
#include <string>
#include <fstream>

class BinarySearchTree;

class BinarySearchTree
{
	
private:
	/**************************************Struct - Node**************************************/
	struct Node
	{
		Node() {}
		Node(string key, WordInfo info) : key_(key), info_(info), left_(nullptr), right_(nullptr), p_(nullptr) {}
		Node(string key, WordInfo info, Node* left, Node* right, Node* p) : key_(key), info_(info), left_(left), right_(right), p_(p) {}

		string key_; // word
		WordInfo info_;
		Node* left_;
		Node* right_;
		Node* p_;
	};

private:
	Node* root_;
	string file_name;

public:

	void addRowNum()
	{
		// read data(text)
		string temp_word, temp_line;
		ifstream ifs_word, ifs_row;
		cout << "�� Please enter the required file name : "; cin >> this->file_name;

		ifs_row.open(file_name, ios::in);
		if (!ifs_row.is_open()) throw MyErrorInfo("cant_open_the_file_ifs_row_in_addRowNum()"); // �Ƿ�򿪳ɹ�

		ifs_word.open(file_name, ios::in);
		if (!ifs_word.is_open()) throw MyErrorInfo("cant_open_the_file_ifs_word_in_addRowNum()"); // �Ƿ�򿪳ɹ�

		ofstream ofs;
		ofs.open("./output.txt", ios::out);	 // ::out
		if (!ofs.is_open()) throw MyErrorInfo("cant_open_the_file_output_in_addRowNum()"); // �Ƿ�򿪳ɹ�
		
		unsigned int row_length = 0, row_num = 1, count_word_text = 0, count_word_row = 0;
		while (getline(ifs_row, temp_line))
		{
			row_length = 0;
			count_word_row = 0;
			ofs << row_num++ << " - " << temp_line;
			clearAllSpace(temp_line); 
			// row_length = temp_line.length();
			
			// ���Ϊ���У�ֱ���������������������ۼ�
			if (0 == temp_line.length())
			{
				ofs << endl << flush;
				continue;
			}

			while (!ifs_word.eof())
			{
				ifs_word >> temp_word;
				count_word_row++;
				row_length += temp_word.length();
				if (temp_line.length() == row_length) // ����еĳ��ȣ�ȥ���ո񣩵��� �ۼӵ��ʵĳ��� ����ô�����ж�ȡ������ ���ж���
				{
					ofs << "��Words in this row : " << count_word_row << "��" << endl;
					break;
				}
			}
			count_word_text += count_word_row;
		}

		ofs << endl
			<< "=====================================" << endl
			<< " Amount of words in the article : " << count_word_text << endl
			<< " Amount of row in the article : " << row_num - 1 << endl
			<< "=====================================" << endl << endl;
		ifs_row.close();
		ifs_word.close();
		ofs.close();
	}

	void makeWordTree()
	{
		// read data(text)
		string temp_word, temp_line;
		ifstream ifs_word, ifs_row;

		ifs_row.open(file_name, ios::in);
		if (!ifs_row.is_open()) throw MyErrorInfo("cant_open_the_file_ifs_row_in_addRowNum()"); // �Ƿ�򿪳ɹ�

		ifs_word.open(file_name, ios::in);
		if (!ifs_word.is_open()) throw MyErrorInfo("cant_open_the_file_ifs_word_in_addRowNum()"); // �Ƿ�򿪳ɹ�

		ofstream ofs;
		ofs.open("./output.txt", ios::app);	 // ::out
		if (!ofs.is_open()) throw MyErrorInfo("cant_open_the_file_output_in_addRowNum()"); // �Ƿ�򿪳ɹ�

		unsigned int row_length = 0, row_num = 1, count_word_text = 0, count_word_row = 0;
		while (getline(ifs_row, temp_line))
		{
			row_length = 0;
			count_word_row = 0;
			ofs << row_num++ << " - " << temp_line;
			clearAllSpace(temp_line);
			// row_length = temp_line.length();

			// ���Ϊ���У�ֱ���������������������ۼ�


			while (!ifs_word.eof())
			{
				ifs_word >> temp_word;
				changeCaseAndClearSign(temp_word);
				count_word_row++;
				row_length += temp_word.length();
				if (temp_line.length() == row_length) // ����еĳ��ȣ�ȥ���ո񣩵��� �ۼӵ��ʵĳ��� ����ô�����ж�ȡ������ ���ж���
				{
					ofs << "��Words in this row : " << count_word_row << "��" << endl;
					break;
				}
			}
			count_word_text += count_word_row;
		}

		ofs << endl
			<< "=====================================" << endl
			<< " Amount of words in the article : " << count_word_text << endl
			<< " Amount of row in the article : " << row_num - 1 << endl
			<< "=====================================" << endl;
		ifs_row.close();
		ifs_word.close();
		ofs.close();
	}

private:

	void insertNode(Node* nodeInsert)
	{
		if (nullptr == root_ || nullptr == nodeInsert) throw MyErrorInfo("nullptr_root_or_nodeInsert_in_insertNode()");

		Node* pCurrent = root_;

		while (true)
		{
			while (pCurrent->key_ > nodeInsert->key_ && pCurrent->left_ != nullptr)
			{
				pCurrent = pCurrent->left_;
			}
			while (pCurrent->key_ < nodeInsert->key_ && pCurrent->right_ != nullptr)
			{
				pCurrent = pCurrent->right_;
			}

			if (pCurrent->key_ > nodeInsert->key_ && pCurrent->left_ == nullptr) break;
			else if (pCurrent->key_ < nodeInsert->key_ && pCurrent->right_ == nullptr) break;
			else if (pCurrent->key_ == nodeInsert->key_) break;
		}

		if (pCurrent->key_ > nodeInsert->key_)
		{
			pCurrent->left_ = nodeInsert;
		}
		else if (pCurrent->key_ < nodeInsert->key_)
		{
			pCurrent->right_ = nodeInsert;
		}
		else
		{
			throw MyErrorInfo("error_insert_in_insertNode()");
		}
	}

	void changeCaseAndClearSign(string& word)
	{
		if (word.empty()) throw MyErrorInfo("null_string");
		if (word.at(0) > 64 && word.at(0) < 91)
		{
			word.at(0) += 32; // ����ASCII����Ĵ�Сд
		}

		int index = 0;
		while (word.find(',', index) != string::npos)
		{
			index = word.find(',', index);
			word.erase(index, 1);
		}

		while (word.find('.', index) != string::npos)
		{
			index = word.find('.', index);
			word.erase(index, 1);
		}

		while (word.find("'s", index) != string::npos)
		{
			index = word.find("'s", index);
			word.erase(index, 2);
		}
	}

	string& clearAllSpace(string& str)
	{
		int index = 0;
		if (!str.empty())
		{
			while ((index = str.find(' ', index)) != string::npos)
			{
				str.erase(index, 1);
			}
		}
		return str;
	}

};