#include "Node.h"



CNode::CNode()
{
	text = "";
	next = nullptr;
}


CNode::~CNode()
{
}

void CNode::setNodeData()
{
	cout << "\n\t\tEnter Meaning : ";
	getline(cin,text,'\n');
}

void CNode::setNodeData(string term)
{
	text = term;
}

string CNode::getNodeData()
{
	return text;
}
void CNode::printNode()
{
	cout << "\n\t\t" << text;
}
string CNode::getKey()
{
	return text;
}