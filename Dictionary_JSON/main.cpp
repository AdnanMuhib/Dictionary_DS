#include"Dictionary.h"
#include"WordList.h"
//#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	CDictionary myDictionary;
	WordList myWordlist;
	myWordlist.remove_trivial_from_document();
	myWordlist.loadDocument();
	myWordlist.compute_redundancy();
	myWordlist.printDictionary();
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
	cout << "\n\t7- Sort Dictionary ";
	cout << "\n\t8- Binary Searching ";
	cout << "\n\te- Exit";
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
		// converting the word to Lower Case
		word = convertToLowerCase(word);
		newWord = new CWord(word);
	insertMeaning:
		cout << "\n\t\tEnter Meaning : ";
		getline(cin, mean, '\n');
		mean = convertToLowerCase(mean);
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
	case '3': // find the meaning of a word
	{
		system("cls");
		cout << "\n\tType a word to Find it's meanings : ";
		getline(cin, word, '\n');
		// converting word to uppercase
		word = convertToLowerCase(word);
		newWord=myDictionary.find(word);
		if (newWord)
		{
			newWord->printWord();
		}
		else
		{
			cout << "\n\t\tWord not Found...";
		}
		newWord = nullptr;
		cout << "\n";
		goto menu;
		break;
	}
	case '4': // Load Dictionary From a TXT File
	{
		system("cls");
		myDictionary.dictFromTxtFile();
		cout << "\n\t\t********Dictionary Successfully Loaded From TEXT File********* \n";
		goto menu;
		break;
	}
	case '5': // Load Dictionary From a JSON File
	{
		system("cls");
		myDictionary.readFromJson();
		cout << "\n\t\t********Dictionary Successfully Loaded From JSON File********* \n";
		goto menu;
		break;
	}
	case '6': // Write Dictionary in JSON Format
	{
		system("cls");
		// write to JSON
		myDictionary.writeToJson();
		cout << "\n\t\t********Dictionary Successfully written in JSON*********\n\n ";
		goto menu;
		break;
	}
	
	case '7': // sorting Dictionary
	{
		system("cls");
		myDictionary.sort();
		cout << "\n\t\t******* Dictionary Sorted Successfully*********";
		goto menu;
		break;
	}
	case '8': //binary searching 
	{
		system("cls");
		cout << "\n\t\t Enter Word to Find : ";
		getline(cin, word, '\n');
		newWord = myDictionary.binarySearch(word);
		if (newWord)
		{
			newWord->printWord();
		}
		else
			cout << "\n\tWord Not Found ";
		goto menu;
		break;
	}
	case 'e': // Exit the Program
	{
		system("cls");
		break;
	}
	default: // in case of wrong user input
		system("cls");
		cout << "\n\t\t Wrong Input Try Again : ";
		goto menu;
		break;
	}
}