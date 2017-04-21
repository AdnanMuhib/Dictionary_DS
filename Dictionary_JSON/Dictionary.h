#pragma once
#include"Word.h"
class CDictionary
{
public:
	// default constructor
	CDictionary();
	~CDictionary();
	CDictionary(CWord *& ptr);
	CWord *head;
	// copy constructor
	CDictionary(const CDictionary & src);
	int count;

	// insert new Node
	CDictionary & insert(CWord *& ptr);

	// insert new node at given index
	CDictionary & insert(CWord *& ptr, int index);

	// remove a Node from the List
	CWord* remove();

	// remove a Node at index
	CWord* remove(int index);

	// swap two nodes of the list
	CDictionary& swapNodes(int index1, int index2);
	//function to print the data of all nodes
	void print();

	// check if the list is empty
	bool isEmpty();
	// check if the list is not empty
	bool isNotEmpty();
	// reverse the list
	CDictionary & reverse();
	// find a string from the list
	CWord* find(string word);
	// find a node from the list 
	CWord* find(CWord *ptr);
	// all attributes print using Dictionary Object
	void printDictionary();
	// write to JSON File
	void writeToJson();
	// read from JSON File
	CDictionary& readFromJson();
	// create Distionary from text file
	CDictionary& dictFromTxtFile();
	// some friend Functions

	friend string convertToUpperCase(string);
	friend string convertToLowerCase(string);
	friend string removeDoubleQuotes(string);

};

