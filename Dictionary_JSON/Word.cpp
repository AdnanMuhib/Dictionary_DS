#include "Word.h"


// default constructor 
// defination object will be created using constructor intitilizer list
// and passing an anonymous object dynamicall created
CWord::CWord():defination(CDefination())
{

	next = NULL;
	word = "";
}


CWord::~CWord()
{
}
CWord::CWord(string word)
{
	this->word = word;
}
void CWord::setWord()
{
	cin.ignore();
	cout << "\n\tEnter Word : ";
	getline(cin, word, '\n');

}

void CWord::setWord(string word)
{
	this->word = word;
}

string CWord::getWord()
{
	return word;
}

void CWord::printWord()
{
	cout << "\n\t" << word;
	if (defination.isNotEmpty())
	{
		this->defination.print();
	}
	
}
string CWord::getKey()
{
	return word;
}