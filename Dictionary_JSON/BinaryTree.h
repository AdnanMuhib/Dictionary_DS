#pragma once

#include"BTNode.h"
#include<iostream>
using namespace std;
class BinaryTree
{
private:
	BTNode *root;
public:
	BinaryTree();
	~BinaryTree();
	BinaryTree(BTNode *& root);
	void insert(BTNode *&  ptr);
	BTNode* find(string word);
	bool isEmpty();
	bool isNotEmpty();
	void post_order(BTNode*root);
	void print_tree();
};

