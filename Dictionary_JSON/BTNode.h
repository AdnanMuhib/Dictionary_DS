#pragma once
#include<string>
using namespace std;
class BTNode
{
private:
	string word;
public:
	BTNode();
	~BTNode();
	BTNode **arr;
	BTNode *left, *right;
	int count;
	void setword(string word);
	string getword()const;
};

