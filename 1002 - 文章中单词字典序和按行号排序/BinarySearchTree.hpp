
/*
	【---13.4.2020---lab 1.2.1 --】
	注意、：数据域应包含：单词的 行列信息(【行(row)    列(col)】-对组链表)    出现次数(count)    长度(length) 

	实现思路：
	1.1  先将文章读取添加行号，输出到新的文档中 output.txt 中
	1.2  输出同时统计文章中单词数量 & 字符数量 & 行数

	2.1 按 单词读取，读取之后将单词转化为小写 在单词中应保存单词的 行号、出现数量（大写与小写视为一个）、字符数（长度）、列数（本行第几个）
		  其中 key_ 值为本单词
	2.2 读取并转换大小写之后 插入到搜索二叉树中
	2.3 注意：文章甚至每行中可能出现多个单词和 这个时候要使用链表保存行列信息，链表结点的数量要和出现次数对应，以便打印时重复打印

	3.1  完成插入后，将二叉树先按中序遍历输出到表格中
	3.2  按行号正序排列输出 【同时补充的功能可以是同一行的按字典序排列】

	打印格式：
	-Word-			-Row-			-Col-			-Count-			-Length-

	注意：
	4.1 如果行的长度（去除空格）等于 累加单词的长度 ，那么代表本行读取结束。 进行断行
	4.2 如果为空行，直接跳过，计数器不进行累加
	4.3 操作ASCII码更改大小写,将所有单词转化为小写，剔除，. ‘s ''
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
		cout << "◆ Please enter the required file name : "; cin >> this->file_name;

		ifs_row.open(file_name, ios::in);
		if (!ifs_row.is_open()) throw MyErrorInfo("cant_open_the_file_ifs_row_in_addRowNum()"); // 是否打开成功

		ifs_word.open(file_name, ios::in);
		if (!ifs_word.is_open()) throw MyErrorInfo("cant_open_the_file_ifs_word_in_addRowNum()"); // 是否打开成功

		ofstream ofs;
		ofs.open("./output.txt", ios::out);	 // ::out
		if (!ofs.is_open()) throw MyErrorInfo("cant_open_the_file_output_in_addRowNum()"); // 是否打开成功
		
		unsigned int row_length = 0, row_num = 1, count_word_text = 0, count_word_row = 0;
		while (getline(ifs_row, temp_line))
		{
			row_length = 0;
			count_word_row = 0;
			ofs << row_num++ << " - " << temp_line;
			clearAllSpace(temp_line); 
			// row_length = temp_line.length();
			
			// 如果为空行，直接跳过，计数器不进行累加
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
				if (temp_line.length() == row_length) // 如果行的长度（去除空格）等于 累加单词的长度 ，那么代表本行读取结束。 进行断行
				{
					ofs << "【Words in this row : " << count_word_row << "】" << endl;
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
		if (!ifs_row.is_open()) throw MyErrorInfo("cant_open_the_file_ifs_row_in_makeWordTree()"); // 是否打开成功

		ifs_word.open(file_name, ios::in);
		if (!ifs_word.is_open()) throw MyErrorInfo("cant_open_the_file_ifs_word_in_makeWordTree()"); // 是否打开成功

		string temp_word, temp_line;
		unsigned int row_word = 0, col_word = 0, row_length = 0, count_word_text = 0;
		while (getline(ifs_row, temp_line))
		{
			row_word++;
			col_word = 0;
			row_length = 0;

			// 如果为空行，直接跳过，计数器不进行累加
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

				/*添加到二叉树*/
				if (!isHaveSameWord(this->root_, temp_word, row_col_word))
				{
					// 此为没有重复单词的情况，还需先判断是否有重复的单词
					WordInfo* newWordInfo = new WordInfo;					
					newWordInfo->header_.insert(row_col_word);
					newWordInfo->count_same_word_ = 1;
					newWordInfo->length_word_ = temp_word.length();

					Node* newNode = new Node;				
					newNode->key_ = temp_word;
					newNode->info_ = newWordInfo;
					insertNode(newNode, count_word_text);
				}
				if (temp_line.length() == row_length) // 如果行的长度（去除空格）等于 累加单词的长度 ，那么代表本行读取结束。 进行断行
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
			word.at(0) += 32; // 操作ASCII码更改大小写
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

	// 创建栈中的结点 - Creat element in stack
	BinTreeStackNode* CreatBinTreeStackNode(Node* node, bool flag)
	{
		BinTreeStackNode* newNode = new BinTreeStackNode;
		newNode->root = node;
		newNode->flag = false;
		return newNode;
	}

	// 树中是否存在相同的单词，如果有传入更新 WordInfo中的header_.insert(pair)
	bool isHaveSameWord(Node* root, string word, pair<unsigned int, unsigned int> row_col_word)
	{
		if (nullptr == root) return false;

		// Make a Stack
		LinkStack<BinTreeStackNode*> stack;

		// 将根结点放到栈中 - first, make the root of the tree in the stack
		stack.push(CreatBinTreeStackNode(root, false));

		while (stack.size() > 0)
		{
			// 先弹出栈顶元素 - Pop the element, which is on the top of the stack
			BinTreeStackNode* node = (BinTreeStackNode*)stack.top();
			stack.pop();

			// 判断，如果为 nullptr 直接重新循环
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