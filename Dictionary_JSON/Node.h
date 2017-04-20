#pragma once
#include<string>
#include<iostream>
using namespace std;
class CNode
{
public:
	CNode();
	~CNode();
	void printNode();
	void setNodeData();
	void setNodeData(string term);
	string getNodeData();
	string getKey();
	string text;
	CNode * next;
};

