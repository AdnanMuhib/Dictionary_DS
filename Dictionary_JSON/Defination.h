#pragma once
#include"Node.h"
class CDefination
{
public:
	CDefination();
	CDefination(CNode *& ptr);
	// copy constructor
	CDefination(const CDefination & src);
	~CDefination();
	CNode *head;
	int count;
	
	// insert new Node
	CDefination & insert(CNode *& ptr);
	
	// insert new node at given index
	CDefination & insert(CNode *& ptr, int index);
	
	// remove a Node from the List
	CNode* remove();
	
	// remove a Node at index
	CNode* remove(int index);

	// swap two nodes of the list
	CDefination& swapNodes(int index1, int index2);
	//function to print the data of all nodes
	void print();

	// check if the list is empty
	bool isEmpty();
	// check if the list is not empty
	bool isNotEmpty();
	// reverse the list
	CDefination & reverse();
	// find a string from the list
	CNode* find(string word);
	// find a node from the list 
	CNode* find(CNode *ptr);
};

