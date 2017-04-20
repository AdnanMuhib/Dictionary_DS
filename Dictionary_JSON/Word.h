#pragma once
#include"Defination.h"
using namespace std;
class CWord
{
public:
	CWord();
	~CWord();
	CWord(string);
	CDefination defination;
	CWord *next;
	string word;
	void setWord();
	void setWord(string word);
	string getWord();
	string getKey();
	void printWord();
};

