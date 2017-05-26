#pragma once
#include<string>
#include<iostream>

using namespace std;
class LineCNode
{
public:
	LineCNode();
	LineCNode(int data);
	~LineCNode();
	void printNode();
	void setNodeData(int data);
	int getNodeData()const;
	int lineNo;
	LineCNode * next;

};

