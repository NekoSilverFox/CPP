/*
	【---13.4.2020---lab 1.2.1 --】
	注意、：数据域应包含：单词的 行列信息(【行(row)    列(col)】-对组链表)    出现次数(count)    长度(length) 

	实现思路：
	1.1  先将文章读取添加行号，输出到新的文档中 output.txt 中
	1.2  输出同时统计文章中单词数量 & 字符数量 & 行数

	2.1 按 单词读取，读取之后将单词转化为小写 在单词中应保存单词的 行号、出现数量（大写与小写视为一个）、字符数（长度）、列数（本行第几个）
		  其中 key_ 值为本单词
	2.2 读取并转换大小写之后 插入到搜索二叉树中
	2.3 注意：文章甚至每行中可能出现多个单词和 这个时候要使用链表保存行列信息，链表结点的数量要和出现次数对应（可以通过传递一个bool值确认
		是否需要重复打印相同单词），以便打印时重复打印

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
#include "WordInfo.hpp"
#include "LinkStack.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

class BinarySearchTree;
struct Node;
class WordInfo;

class BinarySearchTree
{
private:
	/**************************************Struct - Node**************************************/
	struct Node
	{
		Node() : key_("null"), p_(nullptr), left_(nullptr), right_(nullptr), info_(nullptr) {}
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

	Node* root_;
	string file_name_;

public:

	BinarySearchTree()
	{
		this->root_ = new Node;
	}

	~BinarySearchTree()
	{
		_freeSpaceBinaryTree_(this->root_);
	}

	void openFile(string file_name)
	{
		this->file_name_ = file_name;
	}

	void printTextWithRowNum()
	{
		_addRowNum_();
	}

	void makeTree()
	{
		_makeWordTree_();
	}

	/*
	** print the words on screen
	** true - print same word;
	** false - do not print same word
	*/
	void printDictionaryOrder(bool repetitive_word)
	{
		if (nullptr == this->root_) throw MyErrorInfo("nullptr_root_in_foreachDictionaryOrder()");

		{
			cout.width(15); cout << "|Word|";
			cout.width(9); cout << "|Row|";
			cout.width(9); cout << "|Col|";
			cout.width(10); cout << "|Count|";
			cout.width(10); cout << "|Length|";
			cout << endl;
		}

		_inOrderOnScreen_(this->root_, repetitive_word);
	}

	/*
	** out put the word by Dictionary order in to the file "output.txt"
	*/
	void outputDictionaryOrderInFile(bool repetitive_word)
	{
		if (nullptr == this->root_) throw MyErrorInfo("nullptr_root_in_outputDictionaryOrderInFile(bool repetitive_word)");

		ofstream ofs;
		ofs.open("./output.txt", ios::app);	 // ::app
		if (!ofs.is_open()) throw MyErrorInfo("cant_open_the_file_output_in_outputDictionaryOrderInFile(bool repetitive_word)");

		{
			ofs.width(15); ofs << "|Word|";
			ofs.width(9); ofs << "|Row|";
			ofs.width(9); ofs << "|Col|";
			ofs.width(10); ofs << "|Count|";
			ofs.width(10); ofs << "|Length|";
			ofs << endl;
		}

		_inOrderOutputInFile_(this->root_, ofs, repetitive_word);
		cout << endl << "Successful output in 【output.txt】!" << endl;
	}

	/*
	** Seach word by cin
	*/
	void searchWord(string word_search)
	{
		Node* searchWord = _searchWordInTree_(word_search);
		if (nullptr == searchWord)
		{
			cout << endl
				<< "======Search Word======" << endl
				<< "\033[31m" << " Don't  have word 【" << word_search << "】!" << "\033[0m" << endl <<endl;
		}
		else
		{
			cout << endl 
				<< "======Search Word======" << endl
				<< "\033[32m" << "Word : " << searchWord->key_ << endl
				<< "Row : " << searchWord->info_->header_.header_->next_->data_.first << endl
				<< "Col : " << searchWord->info_->header_.header_->next_->data_.second << endl
				<< "\033[0m" << endl;
		}
	}

	/*
	** Delete word by cin
	*/
	void deleteWord(string dele_word)
	{
		bool is_dele = _deleteNodeBinarySearchTree_(dele_word);
		
		cout << "======Delete Word======" << endl;
		if (true == is_dele)
		{
			cout << endl 
				<<  "\033[32m" 
				<< "Succeed delete word 【" << dele_word << "】!" 
				<< "\033[0m" 
				<< endl;
		}
		else
		{
			cout << endl 
				<< "\033[31m" 
				<< "Delete fail, don't have word 【" << dele_word << "】!" 
				<< "\033[0m" 
				<< endl;
		}
	}

	// ===================================================================================

private:

	/*
	** Insert one word into the binary search tree
	*/
	void _insertNode_(Node* nodeInsert, unsigned int count_word_text)
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

	/*
	** Insert all word into the binary search tree
	*/
	void _makeWordTree_()
	{
		// read data(text)
		ifstream ifs_word, ifs_row;

		ifs_row.open(file_name_, ios::in);
		if (!ifs_row.is_open()) throw MyErrorInfo("cant_open_the_file_ifs_row_in_makeWordTree()"); 

		ifs_word.open(file_name_, ios::in);
		if (!ifs_word.is_open()) throw MyErrorInfo("cant_open_the_file_ifs_word_in_makeWordTree()"); 

		string temp_word, temp_line;
		unsigned int row_word = 0, col_word = 0, row_length = 0, count_word_text = 0;
		while (getline(ifs_row, temp_line))
		{
			row_word++;
			col_word = 0;
			row_length = 0;

			/*
			** If a blank line, skip, the counter does not accumulate
			*/ 
			if (0 == temp_line.length())
			{
				continue;
			}
			_clearAllSpace_(temp_line);

			while (!ifs_word.eof())
			{
				ifs_word >> temp_word;
				col_word++;
				count_word_text++;
				row_length += temp_word.length();
				_changeCaseAndClearSign_(temp_word);
				pair<unsigned int, unsigned int> row_col_word = make_pair(row_word, col_word);

				/*
				** Insert to binary search tree
				*/
				if (!_isHaveSameWord_( temp_word, row_col_word)) // First determine if there are identical words in tree
				{
					WordInfo* newWordInfo = new WordInfo;
					newWordInfo->header_.insert(row_col_word);
					newWordInfo->count_same_word_ = 1;
					newWordInfo->length_word_ = temp_word.length();

					Node* newNode = new Node;
					newNode->key_ = temp_word;
					newNode->info_ = newWordInfo;
					_insertNode_(newNode, count_word_text);
				}
				if (temp_line.length() == row_length) // Broken line
				{
					break;
				}
			}
		}
		ifs_row.close();
		ifs_word.close();
	}

	void _addRowNum_()
	{
		/*
		** read data(text)
		*/
		string temp_word, temp_line;
		ifstream ifs_word, ifs_row;

		ifs_row.open(file_name_, ios::in);
		if (!ifs_row.is_open()) throw MyErrorInfo("cant_open_the_file_ifs_row_in_addRowNum()"); 

		ifs_word.open(file_name_, ios::in);
		if (!ifs_word.is_open()) throw MyErrorInfo("cant_open_the_file_ifs_word_in_addRowNum()"); 

		ofstream ofs;
		ofs.open("./output.txt", ios::out);	 // ::out
		if (!ofs.is_open()) throw MyErrorInfo("cant_open_the_file_output_in_addRowNum()");

		unsigned int row_length = 0, row_num = 1, count_word_text = 0, count_word_row = 0;
		while (getline(ifs_row, temp_line))
		{
			row_length = 0;
			count_word_row = 0;
			ofs << row_num++ << " - " << temp_line;
			_clearAllSpace_(temp_line);
			// row_length = temp_line.length();

			/*
			** If a blank line, skip, the counter does not accumulate
			*/
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
				if (temp_line.length() == row_length)  // Broken line
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

	/*
	**  print on screen
	*/
	void _inOrderOnScreen_(Node* root, bool repetitive_word)
	{
		if (nullptr == root) return;

		_inOrderOnScreen_(root->left_, repetitive_word);

		if (true == repetitive_word)
		{
			// ------------------------print same word
			if (1 == root->info_->count_same_word_)
			{
				cout.width(15); cout << root->key_;
				cout.width(9); cout << root->info_->header_.header_->next_->data_.first; // first - row
				cout.width(9); cout << root->info_->header_.header_->next_->data_.second; // secound - col
				cout.width(10); cout << root->info_->count_same_word_;
				cout.width(10); cout << root->info_->length_word_;
				cout << endl;
			}
			else
			{
				LinkNode<pair<int, int>>* pCurrent = root->info_->header_.header_->next_;
				for (int i = 0; i < root->info_->count_same_word_; i++)
				{
					cout.width(15); cout << root->key_;
					cout.width(9); cout << pCurrent->data_.first;
					cout.width(9); cout << pCurrent->data_.second;
					cout.width(10); cout << root->info_->count_same_word_;
					cout.width(10); cout << root->info_->length_word_;
					cout << endl;
					pCurrent = pCurrent->next_;
				}
			}
			// ------------------------
		}
		else
		{
			cout.width(15); cout << root->key_;
			cout.width(9); cout << root->info_->header_.header_->next_->data_.first;
			cout.width(9); cout << root->info_->header_.header_->next_->data_.second;
			cout.width(10); cout << root->info_->count_same_word_;
			cout.width(10); cout << root->info_->length_word_;
			cout << endl;
		}
		_inOrderOnScreen_(root->right_, repetitive_word);
	}

	/*
	**  output in file [output.txt]
	*/
	void _inOrderOutputInFile_(Node* root, ofstream& ofs, bool repetitive_word)
	{
		if (nullptr == root) return;

		_inOrderOutputInFile_(root->left_, ofs, repetitive_word);

		if (true == repetitive_word)
		{
			// ------------------------
			if (1 == root->info_->count_same_word_)
			{
				ofs << setw(15) << root->key_
					<< setw(9) << root->info_->header_.header_->next_->data_.first // first - row
					<< setw(9) << root->info_->header_.header_->next_->data_.second // secound - col
					<< setw(10) << root->info_->count_same_word_
					<< setw(10) << root->info_->length_word_
					<< endl;
			}
			else
			{
				LinkNode<pair<int, int>>* pCurrent = root->info_->header_.header_->next_;
				for (int i = 0; i < root->info_->count_same_word_; i++)
				{
					ofs << setw(15) << root->key_
						<< setw(9) << pCurrent->data_.first
						<< setw(9) << pCurrent->data_.second
						<< setw(10) << root->info_->count_same_word_
						<< setw(10) << root->info_->length_word_
						<< endl;
					pCurrent = pCurrent->next_;
				}
			}
			// ------------------------
		}
		else
		{
			ofs << setw(15) << root->key_
				<< setw(9) << root->info_->header_.header_->next_->data_.first
				<< setw(9) << root->info_->header_.header_->next_->data_.second
				<< setw(10) << root->info_->count_same_word_
				<< setw(10) << root->info_->length_word_
				<< endl;
		}
		_inOrderOutputInFile_(root->right_, ofs, repetitive_word);
	}

	/*
	** Delete all the " "(space), (,), (.), ('s)
	** Change case " Student -> student"
	** If have word : "Student's" change it to "student"
	*/
	void _changeCaseAndClearSign_(string& word)
	{
		if (word.empty()) throw MyErrorInfo("null_string_in_changeCaseAndClearSign(string& word)");
		if (word.at(0) > 64 && word.at(0) < 91)
		{
			word.at(0) += 32; // use ASCII to change case
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

	/*
	**  Creat element in stack
	*/
	BinTreeStackNode* _CreatBinTreeStackNode_(Node* node, bool flag)
	{
		BinTreeStackNode* newNode = new BinTreeStackNode;

		newNode->root = node;
		newNode->flag = false;
		return newNode;
	}

	/*
	**  【Use Stack】Does the same word exist in the tree, if have change "header_.insert(pair)" in WordInfo
	*/
	bool _isHaveSameWord_(string word, pair<unsigned int, unsigned int> row_col_word)
	{
		if (nullptr == root_) return false;

		// Make a Stack
		LinkStack<BinTreeStackNode*> stack;

		// first, make the root of the tree in the stack
		stack.push(_CreatBinTreeStackNode_(root_, false));

		while (stack.size() > 0)
		{
			// Pop the element, which is on the top of the stack
			BinTreeStackNode* node = (BinTreeStackNode*)stack.top();
			stack.pop();

			// if nullptr in stack ->continue
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
				stack.push(_CreatBinTreeStackNode_(node->root->right_, false));
				stack.push(_CreatBinTreeStackNode_(node->root->left_, false));
				node->flag = true;
				stack.push(node);
			}
		}
		return false;
	}

	Node* _searchWordInTree_(string word_search)
	{
		if (nullptr == root_) return nullptr;

		Node* pCurrent = this->root_;

		while (nullptr != pCurrent)
		{
			if (word_search == pCurrent->key_)
			{
				return pCurrent;
			}

			while (nullptr != pCurrent && word_search < pCurrent->key_)
			{
				pCurrent = pCurrent->left_;
			}

			while (nullptr != pCurrent && word_search > pCurrent->key_)
			{
				pCurrent = pCurrent->right_;
			}
		}

		return nullptr;
	}

	/*
	** Delete all the " "(space)
	*/
	string& _clearAllSpace_(string& str)
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

	bool _deleteNodeBinarySearchTree_(string dele_key)
	{
		if (nullptr == root_) throw MyErrorInfo("nullptr_root_in_DeleteNodeBinarySearchTree(string key_del)");

		// First of all, need to find the node, which need to delete
		Node* pCurrent = root_;
		Node* pParent = pCurrent;

		while (true)
		{
			if (pCurrent->key_ > dele_key)
			{
				pParent = pCurrent;
				pCurrent = pCurrent->left_;
			}
			else if (pCurrent->key_ < dele_key)
			{
				pParent = pCurrent;
				pCurrent = pCurrent->right_;
			}
			else if (pCurrent->key_ == dele_key)
			{
				break;
			}

			if (pCurrent == nullptr)
			{			
				return false;
			}
		}

#if 0
		cout << "pParent : " << pParent->key_ << endl;
		 cout << "pCurrent : " << pCurrent->key_ << endl;
#endif

		// if delete node is the leaf
		if (pCurrent->left_ == nullptr && pCurrent->right_ == nullptr)
		{
			if (pParent->left_ == pCurrent)
			{
				pParent->left_ = nullptr;
			}
			else pParent->right_ = nullptr;

			delete pCurrent;
			pCurrent = nullptr;
			return true;
		}

		/*********************
							 S  <-- pParent
						   /  \
		DELETE-> E      X
					  /   \
					A    null
				   /  \
				  *    *
		*********************/
		if (pCurrent->left_ != nullptr && pCurrent->right_ == nullptr && pCurrent == pParent->left_)
		{
			Node* deleNode = pCurrent;

			pParent->left_ = deleNode->right_;
			delete deleNode;
			deleNode = nullptr;
			return true;
		}


		/*********************
							S  <-- pParent
						   /  \
		DELETE-> E      X
					  /   \
				  null    R
						   /  \
						  *    *
		*********************/
		else if (pCurrent->left_ == nullptr && pCurrent->right_ != nullptr && pCurrent == pParent->left_)
		{
			Node* deleNode = pCurrent;

			pParent->left_ = pCurrent->right_;
			delete deleNode;
			deleNode = nullptr;
			return true;
		}


		/*********************
							S  <-- pParent
						   /  \
						 E      X <-DELETE
							   /  \
							  Q   null
		*********************/
		else if (pCurrent->left_ != nullptr && pCurrent->right_ == nullptr && pCurrent == pParent->right_)
		{
			Node* deleNode = pCurrent;

			pParent->right_ = deleNode->left_;
			delete deleNode;
			deleNode = nullptr;
			return true;
		}


		/*********************
							S  <-- pParent
						   /  \
						 E      X <-DELETE
							   /  \
							null  Z
		*********************/
		else if (pCurrent->left_ == nullptr && pCurrent->right_ != nullptr && pCurrent == pParent->right_)
		{
			Node* deleNode = pCurrent;

			pParent->right_ = deleNode->right_;
			delete deleNode;
			deleNode = nullptr;
			return true;
		}


		// 最复杂的情况 - The WORST situation 
		else if (pCurrent->left_ != nullptr && pCurrent->right_ != nullptr)
		{
			Node* deleNode = pCurrent;

			pCurrent = pCurrent->right_;

			/*********************
								S  <-- pParent
							   /  \
			DELETE-> E      X
						  /   \
						A     R  <- pCurrent
					   /  \
					  *    *
			*********************/
			if (pCurrent->left_ == nullptr && pCurrent->right_ == nullptr)
			{
				deleNode->key_ = pCurrent->key_;
				deleNode->right_ = nullptr;

				delete pCurrent;
				pCurrent = nullptr;
				return true;
			}


			/*********************
								S  <-- pParent
							   /  \
			DELETE-> E      X
						  /     \
						A        R <- pCurrent
					   /  \     /   \
					  *    *  H      *
							 /   \
	 pParent --->  *      *  ( pParent after "while")
						 /
					   G <---- pCurrent  (之后的pCurrent - pCurrent after "while")
					 /   \
				  null   *
			*********************/
			if (pCurrent->left_ != nullptr)
			{
				while (pCurrent->left_ != nullptr)
				{
					pParent = pCurrent;
					pCurrent = pCurrent->left_;
				}

				deleNode->key_ = pCurrent->key_;
				pParent->left_ = pCurrent->right_;
				delete pCurrent;
				pCurrent = nullptr;
			}
			return true;
		}
	}

	/*
	** Delete all the nodes in tree
	*/
	void _freeSpaceBinaryTree_(Node* root)
	{
		if (nullptr == root) return;
		_freeSpaceBinaryTree_(root->left_);
		_freeSpaceBinaryTree_(root->right_);
		delete root;
	}

};