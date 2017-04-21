#include"Dictionary.h"
//#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	CDictionary myDictionary;
	CWord *newWord;
	CNode *term;
	char ch;
	string word;
	menu:
	cout << "\n\t1- Insert New Word in the Dictionatry ";
	cout << "\n\t2- print Dictionary";
	cout << "\n\t3- Find a Word From Dictionary ";
	cout << "\n\t4- Create Dictionary From Text File ";
	cout << "\n\t5- Create Dictionary From JSON File ";
	cout << "\n\t6- Write Dictionary To JSON ";
	cout << "\n\t7- Exit";
	cout << "\nchoose a number from menu: ";
	ch = _getche();
	switch (ch)
	{
	case '1': // insert new word and its multiple meanings 
	{
		system("cls");
		string mean;
		cout << "\n\t\t\tType the Word to Insert : ";
		getline(cin, word, '\n');
		// converting the word to Upper Case
		word = convertToUpperCase(word);
		newWord = new CWord(word);
	insertMeaning:
		cout << "\n\t\tEnter Meaning : ";
		getline(cin, mean, '\n');
		mean = convertToUpperCase(mean);
		term = new CNode();
		term->setNodeData(mean);
		newWord->defination.insert(term);
	submenu:
		cout << "\n\t\t\ta. Insert Another meaning ";
		cout << "\n\t\t\tb. main Menu\n: ";

		ch = _getche();
		switch (ch)
		{
			case 'a':
			{
				system("cls");
				goto insertMeaning;
				break;
			}
			case 'b':
			{
				system("cls");
				myDictionary.insert(newWord);
				goto menu;
				break;
			}
			default:
			{
				cout << "\nWrong input Try Again :";
				goto submenu;
				break;
			}

				
		}
		goto menu;
		break;
	}
	case '2': // print disctionary
	{
		system("cls");
		if (myDictionary.isNotEmpty())
		{
			//myDictionary.print();
			myDictionary.printDictionary();
			//myDictionary.readFromJson();
		}
		goto menu;
		break;
	}
	case '3':
	{
		system("cls");
		cout << "\n\tType a word to Find it's meanings : ";
		getline(cin, word, '\n');
		// converting word to uppercase
		for (int i = 0; i < word.length(); i++)
		{
			word[i] = toupper(word[i]);
		}
		newWord=myDictionary.find(word);
		newWord->printWord();
		goto menu;
		break;
	}
	case '4':
	{
		system("cls");
		myDictionary.dictFromTxtFile();
		cout << "\n\t\t********Dictionary Successfully Loaded From TEXT File********* ";
		goto menu;
		break;
	}
	case '5':
	{
		system("cls");
		myDictionary.readFromJson();
		cout << "\n\t\t********Dictionary Successfully Loaded From JSON File********* ";
		goto menu;
		break;
	}
	case '6':
	{
		system("cls");
		// write to JSON
		myDictionary.writeToJson();
		cout << "\n\t\t********Dictionary Successfully written in JSON********* ";
		goto menu;
		break;
	}
	case '7':
	{
		system("cls");
		break;
	}
	default:
		break;
	}


}