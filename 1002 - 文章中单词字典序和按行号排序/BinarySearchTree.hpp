
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
		string temp_word, temp_line;
		ifstream ifs_word, ifs_row;

		ifs_row.open(file_name, ios::in);
		if (!ifs_row.is_open()) throw MyErrorInfo("cant_open_the_file_ifs_row_in_addRowNum()"); // 是否打开成功

		ifs_word.open(file_name, ios::in);
		if (!ifs_word.is_open()) throw MyErrorInfo("cant_open_the_file_ifs_word_in_addRowNum()"); // 是否打开成功

		ofstream ofs;
		ofs.open("./output.txt", ios::app);	 // ::out
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


			while (!ifs_word.eof())
			{
				ifs_word >> temp_word;
				changeCaseAndClearSign(temp_word);
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