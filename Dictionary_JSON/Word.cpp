#include "Word.h"

// default constructor 
// defination object will be created using constructor intitilizer list
// and passing an anonymous object dynamically created.
CWord::CWord():defination(CDefination())
{
	next = NULL;
	word = "";
}

// One parameter constructor to set the value of this word...
CWord::CWord(string word)
{
	this->word = word;
}

void CWord::setWord()
{
	cin.ignore();
	cout << "\n\tEnter Word : ";
	getline(cin, this->word, '\n');
}

void CWord::setWord(string word)
{
	this->word = word;
}

string CWord::getWord()
{
	return this->word;
}

void CWord::printWord()
{
	cout << "\n\t" << this->word;
	if (defination.isNotEmpty())
	{
		this->defination.print();
	}
}

string CWord::getKey()
{
	return this->word;
}