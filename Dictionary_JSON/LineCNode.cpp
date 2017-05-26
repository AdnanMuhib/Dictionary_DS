#include "LineCNode.h"

LineCNode::LineCNode()
{
	lineNo = 0;
	next = nullptr;
}

LineCNode::LineCNode(int data)
{
	this->lineNo = data;
}
LineCNode::~LineCNode()
{
}

void LineCNode::setNodeData(int data)
{
	lineNo = data;
}
int LineCNode::getNodeData()const 
{
	return lineNo;
}
void LineCNode::printNode()
{
	cout << "\n\t\t" << lineNo;
}
