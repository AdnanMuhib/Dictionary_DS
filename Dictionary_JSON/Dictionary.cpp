#include "Dictionary.h"
#include<fstream>
#include<sstream>

// default constructor
// head object of CWord class is created dynamically 
// using constructor initializer list
CDictionary::CDictionary():head(new CWord())
{
	head = nullptr;
	count = 0;
}
// copy constructor
CDictionary::CDictionary(const CDictionary & src)
{
	this->count = src.count;
	this->head = src.head;
	if (head)
	{
		// if head node exists then two pointers are created
		// one as source pointer and other as destination
		CWord *sptr, *dptr;
		// source pointer points to the head node of the source list
		sptr = src.head;
		// pointer of destination will point to the head node of
		// destination linked list which is created  by copying the head node
		// of the source linked list
		dptr = head = new CWord(*sptr);
		// source pointer now points to the next node of source linked list
		sptr = sptr->next;
		// untill the source pointer does not points to the last node
		// the loop will keep iterating and adding nodes to
		// the destination linked list
		while (sptr)
		{
			dptr->next = new CWord(*sptr);
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
// destructor
CDictionary::~CDictionary()
{
	if (this->isNotEmpty())
	{
		CWord *ptr = head->next;
		head->next = nullptr;
		while (ptr)
		{
			delete head;
			head = ptr;
			ptr = ptr->next;
		}
	}
}

// constructor with A node as parameter
CDictionary::CDictionary(CWord *& ptr)
{
	head = ptr;
	count = 1;
	ptr = head->next = nullptr;
}
// insert node
CDictionary & CDictionary::insert(CWord *& ptr)
{
	// input the value to be stored in the Node
//	ptr->setWord();

	ptr->next = head;
	head = ptr;
	ptr = nullptr;
	++count;
	return *this;
}
// inser node at index
CDictionary & CDictionary::insert(CWord *& ptr, int index)
{
	// input the value to be stored in the Node
	ptr->setWord();
	// index correction
	if (index <= 0)
		index = 0;
	if (index >= count)
		index = count;
	if (index == 0)
		return insert(ptr);
	else
	{
		CWord *rptr = head;
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
// remove a node
CWord * CDictionary::remove()
{

	if (head)
	{
		CWord* ptr = head;
		head = head->next;
		ptr->next = nullptr;
		--count;
		return ptr;
	}
	else 
		return nullptr;
}
// remove a node at given index
CWord * CDictionary::remove(int index)
{
	// index correction 
	if (index < 0)
		index = 0;
	if (index >= count)
		index = count - 1;
	if (index == 0)
		return remove();


	CWord *ptr, *rptr = head;
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
// swap two nodes of the list
CDictionary & CDictionary::swapNodes(int index1, int index2)
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
	CWord *ptr;
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

// print all nodes in the list
void CDictionary::print()
{
	
		CWord *rptr = head;
		for (int i = 0; i < count; i++)
		{
			rptr->printWord();
			rptr = rptr->next;
		}

}
// returns true if the list is empty
bool CDictionary::isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	return false;
}
// returns true if the list is not empty
bool CDictionary::isNotEmpty()
{
	if (head != nullptr)
	{
		return true;
	}
	return false;
}
// reverse the list
CDictionary & CDictionary::reverse()
{
	if (count<2)
	{
		return *this;
	}
	CWord *rptr = head;
	CWord **arr = new CWord *[count];
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
// find a word from the list and get the Word
CWord* CDictionary::find(string key)
{
	CWord*ptr = head;
	for (int i = 0; i < count; i++)
	{
		if (key == ptr->getKey())
			return ptr;
		else
			ptr = ptr->next;
	}
	return nullptr;
}
// find a node from the list and return nodes
CWord * CDictionary::find(CWord * ptr)
{
	CWord *rptr = head;
	for (int i = 0; i < count; i++)
	{
		if (ptr->getKey() == rptr->getKey())
			return new CWord(*rptr);
		else
		{
			rptr = rptr->next;
		}
	}
	return nullptr;
}
// print from Dictionary Class
void CDictionary::printDictionary()
{
	CWord *ptr = head;
	CNode *rptr;
	for (int i = 0; i < count; i++)
	{
		cout << "\n\t" << ptr->word;
		 rptr = ptr->defination.head;
		for (int j = 0; j < ptr->defination.count ; j++)
		{
			cout<<"\n\t\t"<<rptr->text;
			rptr = rptr->next;
		}
		ptr = ptr->next;
	}
}

void CDictionary::writeToJson()
{
	
	ofstream json("jsonfile.json");
	CWord *ptr = head;
	CNode *rptr;
	for (int i = 0; i < count; i++)
	{
		json << "{ \"" << ptr->word << "\" : {";
		rptr = ptr->defination.head;
		for (int j = 0; j < ptr->defination.count; j++)
		{
			if (j == ptr->defination.count - 1)
			{
				json << "\"" << rptr->text << "\"";
			}
			else
			{
				json << "\"" << rptr->text << "\",";
				rptr = rptr->next;
			}
			
		}
		if (i == count-1)
		{
			json << "}\n}";
		}
		else
		{
			json << "}\n},\n";
			ptr = ptr->next;
		}
	}
	json.close();
}
// read from JSON File and Create a Dictionary
CDictionary * CDictionary::readFromJson()
{
	CDictionary *myDictionary=new CDictionary();
	CWord *newWord;
	CNode *term;
	string word;
	ifstream json("jsonfile.json");
	while (!json.eof())
	{
		json >> word;
		cout << "\n" << word;
	}
	json.close();
	return myDictionary;
}

// dictionary from the wordlist of text file
CDictionary& CDictionary::dictFromTxtFile()
{
	CWord *word;
	CNode *term;
	string line;
	string feeder;
	stringstream str;
	ifstream file("wordlist.txt");

	while (getline(file,line))
	{
		str.clear();
		str<<line;
		int i = 0;
		word = new CWord();
		while (getline(str,feeder,','))
		{
			// removing commas in the string
			if (feeder[feeder.length() - 1] == ',')
				feeder.pop_back();
			// converting to upper case
			for (int i = 0; i <(feeder.length()); i++)
			{
				feeder[i] = toupper(feeder[i]);
			}
			
			if (i == 0)
			{
				word->setWord(feeder);
				i += 1;
			}
			else
			{
				term = new CNode();
				term->setNodeData(feeder);
				word->defination.insert(term);
			}	
		}
		this->insert(word);
	}
	file.close();
	return *this;
}