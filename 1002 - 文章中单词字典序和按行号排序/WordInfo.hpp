
/*
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