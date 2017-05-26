#include "DocWord.h"



DocWord::DocWord()
{
	word = "";
	next = nullptr;
}


DocWord::~DocWord()
{
}
DocWord::DocWord(string word)
{
	this->word = word;
}

void DocWord::setWord(string word)
{
	this->word = word;
}

string DocWord::getWord() const
{
	return word;
}

void DocWord::set_line_number(int number)
{
	lineNumber = number;
}

int DocWord::get_line_number()
{
	return lineNumber;
}
void DocWord::printWord() const
{
	cout << "\n\t\t" << word;
}
void DocWord::print_line_number()
{
	cout << "\n\t\t" << lineNumber;
}