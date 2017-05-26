#include "WordList.h"

#include<fstream>
#include<sstream>


WordList::WordList()
{

	head = nullptr;
	count = 0;
	load_trivial_words();
	dictionary.dictFromTxtFile();
	dictionary.sort();
}


WordList::~WordList()
{
	if (this->isNotEmpty())
	{
		DocWord *ptr = head->next;
		head->next = nullptr;
		while (ptr)
		{
			delete head;
			head = ptr;
			ptr = ptr->next;
		}
	}
}

WordList::WordList(DocWord *& ptr)
{
	head = ptr;
	count = 1;
	ptr = head->next = nullptr;
}

WordList::WordList(const WordList & src)
{
	this->count = src.count;
	this->head = src.head;
	if (head)
	{
		// if head node exists then two pointers are created
		// one as source pointer and other as destination
		DocWord *sptr, *dptr;
		// source pointer points to the head node of the source list
		sptr = src.head;
		// pointer of destination will point to the head node of
		// destination linked list which is created  by copying the head node
		// of the source linked list
		dptr = head = new DocWord(*sptr);
		// source pointer now points to the next node of source linked list
		sptr = sptr->next;
		// untill the source pointer does not points to the last node
		// the loop will keep iterating and adding nodes to
		// the destination linked list
		while (sptr)
		{
			dptr->next = new DocWord(*sptr);
			sptr = sptr->next;
			// destination pointer will tell the place of new node
			// in destination linked list to be copied from the 
			// source linked list
			dptr = dptr->next;
		}
		// finally destination pointer's last node will become NUll
		dptr->next = nullptr;

	}
}
WordList & WordList::insert(DocWord *& ptr)
{
	ptr->next = head;
	head = ptr;
	ptr = nullptr;
	++count;
	return *this;
}
WordList & WordList::insert(DocWord *& ptr, int index)
{
	// index correction
	if (index <= 0)
		index = 0;
	if (index >= count)
		index = count;
	if (index == 0)
		return insert(ptr);
	else
	{
		DocWord *rptr = head;
		for (int i = 0; i < index; i++)
		{
			rptr = rptr->next;
		}
		ptr->next = rptr->next;
		rptr->next = ptr;
		ptr = nullptr;
		count++;
		return *this;
	}
	return *this;
}

DocWord * WordList::remove()
{

	if (head)
	{
		DocWord* ptr = head;
		head = head->next;
		ptr->next = nullptr;
		--count;
		return ptr;
	}
	else
		return nullptr;
}
DocWord * WordList::remove(int index)
{
	// index correction 
	if (index < 0)
		index = 0;
	if (index >= count)
		index = count - 1;
	if (index == 0)
		return remove();


	DocWord *ptr, *rptr = head;
	for (int i = 1; i < index; i++)
	{
		rptr = rptr->next;
	}
	ptr = rptr->next;
	rptr->next = ptr->next;
	ptr->next = nullptr;
	--count;
	return ptr;
}
WordList & WordList::swapNodes(int index1, int index2)
{
	// index correction for both nodes
	if (index1 < 0)
		index1 = 0;
	if (index1 >= count)
		index1 = count - 1;
	if (index2 < 0)
		index2 = 0;
	if (index2 >= count)
		index2 = count - 1;
	if (index1 == index2)
		return *this;
	DocWord *ptr;
	if (index1<index2)
	{
		ptr = remove(index2);
		insert(ptr, index1);
		ptr = remove(index1 + 1);
		insert(ptr, index2);
	}
	else
	{
		ptr = remove(index1);
		insert(ptr, index2);
		ptr = remove(index2 + 1);
		insert(ptr, index1);
	}
	return *this;
}
void WordList::print()
{
	DocWord *rptr = head;
	for (int i = 0; i < count; i++)
	{
		rptr->printWord();
		rptr = rptr->next;
	}
}
bool WordList::isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	return false;
}
bool WordList::isNotEmpty()
{
	if (head != nullptr)
	{
		return true;
	}
	return false;
}
WordList & WordList::reverse()
{
	if (count<2)
	{
		return *this;
	}
	DocWord *rptr = head;
	DocWord **arr = new DocWord *[count];
	// saving the pointers address of each node in array of nodes
	for (int i = 0; i < count; i++)
	{
		arr[i] = rptr;
		rptr = rptr->next;
	}
	// reversing each node next pointer to previous node
	for (int i = 0, j = 1; j < count; ++i, ++j)
		arr[j]->next = arr[i];
	// making last node in the array as head node
	head = arr[count - 1];
	// making first node's next pointer null
	arr[0]->next = nullptr;
	// releasing dynamically allocated memory
	delete[] arr;
	return *this;
}
DocWord * WordList::find(string word)
{
	DocWord* ptr = head;
	for (int i = 0; i < count; i++)
	{
		if (word == ptr->word)
			return ptr;
		else
			ptr = ptr->next;
	}
	return nullptr;
}
DocWord * WordList::find(DocWord * ptr)
{
	DocWord *rptr = head;
	for (int i = 0; i < count; i++)
	{
		if (ptr->word == rptr->word)
			return new DocWord(*rptr);
		else
		{
			rptr = rptr->next;
		}
	}
	return nullptr;
}

void WordList::printDictionary()
{
	DocWord *ptr = head;
	LineCNode *rptr;
	cout << "\n\tWord |\tLine Number \tRepeating on Lines";
	for (int i = 0; i < count; i++)
	{
		cout << "\n\t" << ptr->word<<"\t\t"<<ptr->get_line_number();
		rptr = ptr->lines.head;
		for (int j = 0; j < ptr->lines.count; j++)
		{
			cout << "\n\t\t\t" << rptr->lineNo;
			rptr = rptr->next;
		}
		ptr = ptr->next;
	}
}
void WordList::writeToJson()
{
	ofstream json("DocumentAnalyzed.json");
	DocWord *ptr = head;
	LineCNode *rptr;
	json << "{\n";
	for (int i = 0; i < count; i++)
	{
		json << "\"" << ptr->word << "\":{ ";
		rptr = ptr->lines.head;
		for (int j = 0; j < ptr->lines.count; j++)
		{
			if (j == ptr->lines.count - 1)
			{
				json << "\"" << rptr->lineNo << "\"";
			}
			else
			{
				json << "\"" << rptr->lineNo << "\",";
				rptr = rptr->next;
			}

		}
		if (i == count - 1)
		{
			json << " }\n";
		}
		else
		{
			json << " },\n";
			ptr = ptr->next;
		}
	}
	json << "}";
	json.close();
}
WordList & WordList::readFromJson()
{
	DocWord *word;
	LineCNode *term;
	string line = "", feeder = "", dummy = "";// dummy is for special case (last definition of word)
	char * lineNumber;											  // string stream object for tokenization
	stringstream str;
	int len;
	ifstream file("DocumentAnalyzed.json");
	int i = 0;
	while (getline(file, line))
	{
		i += 1;
		// if it is start and end of the dictionary
		if (line == "{" || line == "}")
		{
			// continues to next iteration
			continue;
		}
		else
		{
			str.clear();
			str << line;
			// take the first double quoted word into term feeder
			getline(str, feeder, ':');
			// removing doulbe quotes around the  word
			//feeder = removeDoubleQuotes(feeder);
			word = new DocWord();
			// setting up the word to the word object
			word->setWord(feeder);
			// ignoring the next : and the opening curly bracket of definitions
			str >> feeder; // for {

						   // tokenizing the remaining definitions on commas
			while (getline(str, feeder, ','))
			{
				dummy = "";

				// cheking if it is not the end of definitions
				// last word of the line in JSON becomes " "word" }"
				if (feeder[feeder.length() - 1] == '}' && feeder[feeder.length() - 2] == ' ')
				{
					for (int i = 0; i < (feeder.length() - 2); i++)
					{
						dummy += feeder[i];
					}
					feeder = dummy;
				}

				//feeder = removeSpaceFirstIndex(feeder);
				// removing double Quotes around the word
				//feeder = removeDoubleQuotes(feeder);
				// converting to lower case
				// = convertToLowerCase(feeder);
				// creating new node to store definition
				term = new LineCNode();
				len = feeder.length();
				lineNumber = new char[len + 1];
				lineNumber[len] = '\0';
				for (int i = 0; i < len; i++)
				{
					lineNumber[i] = feeder[i];
				}
				term->setNodeData(atoi(lineNumber));
				word->lines.insert(term);
				delete[] lineNumber;
			}
			// inserting the whole word in the dictionary
			this->insert(word);
		}
	}
	file.close();
	return *this;
}
// read document into wordlist
WordList & WordList::loadDocument()
{
	DocWord *word;
	LineCNode *term;
	string line;
	string feeder;
	stringstream str,sstr;
	char temp;
	ifstream file("trivialFree.txt");
	char* lineNumber;
	int counter = 1;
	while (getline(file, line))
	{
		str.clear();
		str << line;
		
		while (getline(str, feeder, '.'))
		{
			cout << feeder<<endl;
			sstr.clear();
			sstr << feeder;
			while (sstr >> feeder)
			{
				feeder = convertToLowerCase(feeder);
				word = new DocWord();
				word->setWord(feeder);
				word->set_line_number(counter);
				this->insert(word);
			}
			counter++;
		}
		
	}
	file.close();
	this->reverse();
	return *this;
}

DocWord* WordList::binarySearch(string str)
{
	DocWord * ptr = head;
	// creating array of words 
	DocWord **words_arr = new DocWord *[count];

	// sorting the Dictionary
	sort();
	// copying every word node address in the words array
	for (int i = 0; i < count; i++)
	{
		words_arr[i] = ptr;
		ptr = ptr->next;
	}
	// applying binary Search Algorithm on Words array

	// left index
	int left = 0;

	// rigth index
	int right = count - 1;
	// center of the array (left+right)/2
	int m;

	while (left <= right)
	{
		m = (left + right) / 2;
		if (str == words_arr[m]->word)
		{
			//memory release before getting out of the function
			// return the copy of found word
			return  words_arr[m];
		}

		if (str < words_arr[m]->word)
			right = m - 1;
		else
		{
			left = m + 1;
		}
	}

}
WordList & WordList::sort()
{
	DocWord * ptr = head;
	// creating array of words 
	DocWord **words_arr = new DocWord *[count];
	// copying every word node address in the words array
	for (int i = 0; i < count; i++)
	{
		words_arr[i] = ptr;
		ptr = ptr->next;
	}
	// sorting words Alphabetically
	bool swap = true;
	while (swap)
	{
		swap = false;
		for (int i = 0; i < count - 1; i++)
		{
			if (words_arr[i]->word > words_arr[i + 1]->word)
			{
				swap = true;
				// swapping two words
				ptr = words_arr[i];
				words_arr[i] = words_arr[i + 1];
				words_arr[i + 1] = ptr;
			}
		}
	}

	// creating list again from the array
	for (int i = 0, j = 1; j < count; i++, j++)
	{
		words_arr[i]->next = words_arr[j];
	}
	head = words_arr[0];
	if (words_arr)
	{
		delete[] words_arr;
	}
	return *this;
}
// loading trivial words from the file
void WordList::load_trivial_words()
{
	ifstream file("Trivial_Words.txt");
	string term;
	if (file)
	{
		while (getline(file,term))
		{
			BTNode *ptr = new BTNode();
			ptr->setword(term);
			this->trivial_words.insert(ptr);
		}
	}
	file.close();
}
// printing trivial words in post order form
void WordList::print_trivial_words()
{
	if(trivial_words.isNotEmpty())
	this->trivial_words.print_tree();
}
// punctuations remove
string removePunctuation(string str)
{
	char puncs[] = ",\"():;0123456789-?";
	for (int i = 0; i < strlen(puncs); i++)
	{

		if ((str[str.length()-1] == puncs[i] ))
		{
			str.pop_back();
			break;
		}
		if ((str[0] == puncs[i]))
		{
			string temp = "";
			for (int i = 1; i < str.length(); i++)
			{
				temp += str[i];
			}
			str = temp;
			break;
		}
	}
	return str;
}
// checks whether word is trivialof not
bool WordList::isTrivial(string term)
{
	if (trivial_words.find(term))
		return true;
	return false;
}
// trivials remove
void WordList::remove_trivial_from_document()
{
	string str;
	ifstream paraFile("paragraph.txt");
	ofstream file("trivialFree.txt");

	if (paraFile)
	{
		while (!paraFile.eof())
		{
			paraFile >> str;
			str = removePunctuation(str);
			if(!isTrivial(str))
			file << str << " ";
		}
	}
	paraFile.close();
	file.close();
}
// computing redundancy 
void WordList::compute_redundancy()
{
	
	DocWord *ptr = head, *ptr_two = head;
	CWord *wptr;
	LineCNode *line_no;
	for (int i = 0; i < count; i++)
	{
		ptr_two = head;
		wptr = this->find_word(ptr->getWord());
		if (wptr)
		{
			while (ptr_two)
			{
				if (ptr_two->getWord() == wptr->getWord())
				{
					line_no = new LineCNode(ptr_two->get_line_number());
					ptr->lines.insert(line_no);
				}
				else
				{
					CNode *defptr = wptr->defination.head;
					for (int i = 0; i < wptr->defination.count; i++)
					{
						if (ptr_two->getWord() == defptr->getKey())
						{
							line_no = new LineCNode(ptr_two->get_line_number());
							ptr->lines.insert(line_no);
							break;
						}
						defptr = defptr->next;
					}
				}
				ptr_two = ptr_two->next;
			}

		}
		ptr = ptr->next;
	}
}
// Finding a word from tree
CWord* WordList::find_word(string str)
{
	return dictionary.find(str);
}