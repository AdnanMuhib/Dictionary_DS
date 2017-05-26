#include "BTNode.h"



BTNode::BTNode()
{
	word = "";
	arr = nullptr;
	count = 0;
	left = nullptr;
	right = nullptr;
}


BTNode::~BTNode()
{
	if (arr != nullptr)
	{
		delete[] arr;
	}
}
void BTNode::setword(string word)
{
	this->word = word;
}
string BTNode::getword()const
{
	return this->word;
}
