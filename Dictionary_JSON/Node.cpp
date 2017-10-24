#include "Node.h"


// Constructor....
CNode::CNode()
{
	this->text = "";
	this->next = nullptr;
}

// Destructor...
CNode::~CNode()
{
}

// Setting the node of the node...
void CNode::setNodeData()
{
	cout << "\n\t\tEnter Meaning : ";
	getline(cin,this->text,'\n');
}

// Setting node data by taking value as a parameter...
void CNode::setNodeData(string term)
{
	this->text = term;
}

// Getting the data of a node...
string CNode::getNodeData()
{
	return this->text;
}

// Printing the value of the node...
void CNode::printNode()
{
	cout << "\n\t\t" << this->text;
}

// Getting the value of node as key...
string CNode::getKey()
{
	return this->text;
}