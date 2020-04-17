
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
#include "LinkStack.hpp"
#include <iostream>
#include <string>
#include <fstream>

class BinarySearchTree;
struct Node;
class WordInfo;

class BinarySearchTree
{
	friend class WordInfo;
private:
	/**************************************Struct - Node**************************************/
	struct Node
	{
		Node() : p_(nullptr), left_(nullptr), right_(nullptr), info_(nullptr) {}
		Node(string key, WordInfo* info) : key_(key), info_(info), left_(nullptr), right_(nullptr), p_(nullptr) {}
		Node(string key, WordInfo* info, Node* left, Node* right, Node* p) : key_(key), info_(info), left_(left), right_(right), p_(p) {}

		string key_; // word
		WordInfo* info_;
		Node* left_;
		Node* right_;
		Node* p_;
	};

	struct BinTreeStackNode
	{
		Node* root;
		bool flag;
	};

private:
	Node* root_;
	string file_name;

public:

	BinarySearchTree()
	{
		this->root_ = new Node;
		root_->info_ = nullptr;
		root_->key_ = "null";
		root_->p_ = nullptr;
		root_->left_ = nullptr;
		root_->right_ = nullptr;
	}

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
		ifstream ifs_word, ifs_row;

		ifs_row.open(file_name, ios::in);
		if (!ifs_row.is_open()) throw MyErrorInfo("cant_open_the_file_ifs_row_in_makeWordTree()"); // �Ƿ�򿪳ɹ�

		ifs_word.open(file_name, ios::in);
		if (!ifs_word.is_open()) throw MyErrorInfo("cant_open_the_file_ifs_word_in_makeWordTree()"); // �Ƿ�򿪳ɹ�

		string temp_word, temp_line;
		unsigned int row_word = 0, col_word = 0, row_length = 0, count_word_text = 0;
		while (getline(ifs_row, temp_line))
		{
			row_word++;
			col_word = 0;
			row_length = 0;

			// ���Ϊ���У�ֱ���������������������ۼ�
			if (0 == temp_line.length())
			{	
				continue;
			}
			clearAllSpace(temp_line);

			while (!ifs_word.eof())
			{
				ifs_word >> temp_word;
				col_word++;
				count_word_text++;
				row_length += temp_word.length();
				changeCaseAndClearSign(temp_word);
				pair<unsigned int, unsigned int> row_col_word = make_pair(row_word, col_word);

				/*��ӵ�������*/
				if (!isHaveSameWord(this->root_, temp_word, row_col_word))
				{
					// ��Ϊû���ظ����ʵ�������������ж��Ƿ����ظ��ĵ���
					WordInfo* newWordInfo = new WordInfo;					
					newWordInfo->header_.insert(row_col_word);
					newWordInfo->count_same_word_ = 1;
					newWordInfo->length_word_ = temp_word.length();

					Node* newNode = new Node;				
					newNode->key_ = temp_word;
					newNode->info_ = newWordInfo;
					insertNode(newNode, count_word_text);
				}
				if (temp_line.length() == row_length) // ����еĳ��ȣ�ȥ���ո񣩵��� �ۼӵ��ʵĳ��� ����ô�����ж�ȡ������ ���ж���
				{								
					break;
				}
			}
		}
		ifs_row.close();
		ifs_word.close();
	}

	void foreachDictionaryOrder()
	{
		if (nullptr == this->root_) throw MyErrorInfo("nullptr_root_in_foreachDictionaryOrder()");
		cout.width(15); cout << "|Word|";
		cout.width(9); cout << "|Row|";
		cout.width(9); cout << "|Col|";
		cout.width(10); cout << "|Count|";
		cout.width(10); cout << "|Length|";
		cout << endl;
		foreachTreeLDR(this->root_);
	}

private:

	void insertNode(Node* nodeInsert, unsigned int count_word_text)
	{
		if (nullptr == root_ || nullptr == nodeInsert) throw MyErrorInfo("nullptr_root_or_nodeInsert_in_insertNode()");

		if (1 == count_word_text)
		{
			root_->p_ = nullptr;
			root_->left_ = nullptr;
			root_->right_ = nullptr;
			root_->key_ = nodeInsert->key_;
			root_->info_ = nodeInsert->info_;
			return;
		}

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
			nodeInsert->p_ = pCurrent;
		}
		else if (pCurrent->key_ < nodeInsert->key_)
		{
			pCurrent->right_ = nodeInsert;
			nodeInsert->p_ = pCurrent;
		}
		else
		{
			throw MyErrorInfo("error_insert_in_insertNode()");
		}
	}

	void foreachTreeLDR(Node* root)
	{
		if (nullptr == root) return;

		foreachTreeLDR(root->left_);
		{
			cout.width(15); cout << root->key_;
			cout.width(9); cout << root->info_->header_.header_->next_->data_.first;
			cout.width(9); cout << root->info_->header_.header_->next_->data_.second;
			cout.width(10); cout << root->info_->count_same_word_;
			cout.width(10); cout << root->info_->length_word_;
			cout << endl;
		}
		foreachTreeLDR(root->right_);
	}

	void changeCaseAndClearSign(string& word)
	{
		if (word.empty()) throw MyErrorInfo("null_string_in_changeCaseAndClearSign(string& word)");
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

	// ����ջ�еĽ�� - Creat element in stack
	BinTreeStackNode* CreatBinTreeStackNode(Node* node, bool flag)
	{
		BinTreeStackNode* newNode = new BinTreeStackNode;
		newNode->root = node;
		newNode->flag = false;
		return newNode;
	}

	// �����Ƿ������ͬ�ĵ��ʣ�����д������ WordInfo�е�header_.insert(pair)
	bool isHaveSameWord(Node* root, string word, pair<unsigned int, unsigned int> row_col_word)
	{
		if (nullptr == root) return false;

		// Make a Stack
		LinkStack<BinTreeStackNode*> stack;

		// �������ŵ�ջ�� - first, make the root of the tree in the stack
		stack.push(CreatBinTreeStackNode(root, false));

		while (stack.size() > 0)
		{
			// �ȵ���ջ��Ԫ�� - Pop the element, which is on the top of the stack
			BinTreeStackNode* node = (BinTreeStackNode*)stack.top();
			stack.pop();

			// �жϣ����Ϊ nullptr ֱ������ѭ��
			if (node->root == nullptr) continue;

			if (node->flag == true)
			{
				if (word == node->root->key_)
				{
					node->root->info_->header_.insert(row_col_word);
					node->root->info_->count_same_word_++;
					return true;
				}
			}
			else {
				// put the child of the node in the stack
				stack.push(CreatBinTreeStackNode(node->root->right_, false));
				stack.push(CreatBinTreeStackNode(node->root->left_, false));
				node->flag = true;
				stack.push(node);
			}
		}
		return false;
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