#pragma once
#include"DocWord.h"
#include"BinaryTree.h"
#include"Dictionary.h"
class WordList
{
	CDictionary dictionary;
public:
	// default constructor
	WordList();
	~WordList();
	WordList(DocWord *& ptr);
	DocWord *head;
	// copy constructor
	WordList(const WordList & src);
	int count;
	// binary tree to store the trivial words
	BinaryTree trivial_words;

	// function to load trivial_words from file
	void load_trivial_words();
	// printing trivial words in post order form
	void print_trivial_words();
	friend string removePunctuation(string str);
	// remove trivial words from the document
	void remove_trivial_from_document();
	// is trivial word
	bool isTrivial(string term);
	// friend function to findWord
	CWord* find_word(string str);

	// compute redundancy of the document
	void compute_redundancy();
	// insert new Node
	WordList & insert(DocWord *& ptr);

	// insert new node at given index
	WordList & insert(DocWord *& ptr, int index);

	// remove a Node from the List
	DocWord* remove();

	// remove a Node at index
	DocWord* remove(int index);

	// swap two nodes of the list
	WordList& swapNodes(int index1, int index2);
	//function to print the data of all nodes
	void print();

	// check if the list is empty
	bool isEmpty();
	// check if the list is not empty
	bool isNotEmpty();
	// reverse the list
	WordList & reverse();
	// find a line from the list
	DocWord* find(string word);
	// find a node from the list 
	DocWord* find(DocWord *ptr);
	// all attributes print using Dictionary Object
	void printDictionary();
	// write to JSON File
	void writeToJson();
	// read from JSON File
	WordList& readFromJson();
	// create Distionary from text file
	WordList& loadDocument();
	// binary Searching 
	DocWord* binarySearch(string str);
	//sorting dictionary
	WordList& sort();
};

