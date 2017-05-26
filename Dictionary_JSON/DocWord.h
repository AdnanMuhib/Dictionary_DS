#pragma once
#include"LineNumberList.h"
class DocWord
{
	int lineNumber;
public:
	DocWord();
	~DocWord();
	DocWord(string word);
	void set_line_number(int number);
	int get_line_number();
	void print_line_number();
	string word;
	LineNumberList lines;
	void setWord(string word);
	string getWord() const;
	void printWord()const;
	DocWord *next;
};

