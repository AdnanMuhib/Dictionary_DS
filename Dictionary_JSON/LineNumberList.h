#pragma once
#include"LineCNode.h"
class LineNumberList
{
public:
	LineNumberList();
	~LineNumberList();
	LineNumberList(LineCNode *& ptr);
	
	// copy constructor
	LineNumberList(const LineNumberList & src);
	LineCNode *head;
	int count;

	// insert new Node
	LineNumberList & insert(LineCNode *& ptr);

	// insert new node at given index
	LineNumberList & insert(LineCNode *& ptr, int index);

	// remove a Node from the List
	LineCNode* remove();

	// remove a Node at index
	LineCNode* remove(int index);

	// swap two nodes of the list
	LineNumberList& swapNodes(int index1, int index2);
	//function to print the data of all nodes
	void print();

	// check if the list is empty
	bool isEmpty();
	// check if the list is not empty
	bool isNotEmpty();
	// reverse the list
	LineNumberList & reverse();
	// find a string from the list
	LineCNode* find(int line);
	// find a node from the list 
	LineCNode* find(LineCNode *ptr);
	// sorting all line numbers 
	LineNumberList& sort();
};

