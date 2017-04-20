#include "Defination.h"

// copy constructor
CDefination::CDefination(const CDefination & src)
{
	this->count = src.count;
	this->head = src.head;
	if (head)
	{
		// if head node exists then two pointers are created
		// one as source pointer and other as destination
		CNode *sptr, *dptr;
		// source pointer points to the head node of the source list
		sptr = src.head;
		// pointer of destination will point to the head node of
		// destination linked list which is created  by copying the head node
		// of the source linked list
		dptr = head = new CNode(*sptr);
		// source pointer now points to the next node of source linked list
		sptr = sptr->next;
		// untill the source pointer does not points to the last node
		// the loop will keep iterating and adding nodes to
		// the destination linked list
		while (sptr)
		{
			dptr->next = new CNode (*sptr);
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
// default constructor
CDefination::CDefination():head(new CNode())
{
	head = nullptr;
	count = 0;
}
// constructor with A node as parameter
CDefination::CDefination(CNode *& ptr)
{
	head = ptr;
	count = 1;
	ptr = head->next = nullptr;
}
// insert node
CDefination & CDefination::insert(CNode *& ptr)
{
	// input the value to be stored in the Node
	//ptr->setNodeData();

	ptr->next = head;
	head = ptr;
	ptr = nullptr;
	++count;
	return *this;
}
// inser node at index
CDefination & CDefination::insert(CNode *& ptr, int index)
{
	// input the value to be stored in the Node
	ptr->setNodeData();
	// index correction
	if (index <= 0)
		index = 0;
	if (index >= count)
		index = count;
	if (index == 0)
		return insert(ptr);
	else
	{
		CNode *rptr = head;
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
CNode * CDefination::remove()
{
	
	if (head)
	{
		CNode* ptr = head;
		head = head->next;
		ptr->next = nullptr;
		--count;
		return ptr;
	}
	return NULL;
}
// remove a node at given index
CNode * CDefination::remove(int index)
{
	// index correction 
	if (index < 0)
		index = 0;
	if (index >= count)
		index = count-1;
	if (index == 0)
		return remove();
	
	
		CNode *ptr, *rptr = head;
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
CDefination & CDefination::swapNodes(int index1, int index2)
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
	CNode *ptr;
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
void CDefination::print()
{
		CNode *rptr = head;
		for (int i = 0; i < count; i++)
		{
			rptr->printNode();
			rptr = rptr->next;
		}
}
// returns true if the list is empty
bool CDefination::isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	return false;
}
// returns true if the list is not empty
bool CDefination::isNotEmpty()
{
	if (head != nullptr)
	{
		return true;
	}
	return false;
}
// reverse the list
CDefination & CDefination::reverse()
{
	if (count<2)
	{
		return *this;
	}
	CNode *rptr=head;
	CNode **arr = new CNode *[count];
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
// find a word from the list and get the node
CNode* CDefination::find(string key)
{
	CNode*ptr = head;
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
CNode * CDefination::find(CNode * ptr)
{
	CNode *rptr = head;
	for (int i = 0; i < count; i++)
	{
		if (ptr->getKey() == rptr->getKey())
			return new CNode(*rptr);
		else
		{
			rptr = rptr->next;
		}
	}
	return nullptr;
}
// destructor
CDefination::~CDefination()
{
	if (this->isNotEmpty())
	{
		CNode *ptr = head->next;
		head->next = nullptr;
		while (ptr)
		{
			delete head;
			head = ptr;
			ptr = ptr->next;
		}	
	}
}