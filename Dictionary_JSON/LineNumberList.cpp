#include "LineNumberList.h"
// copy constructor
LineNumberList::LineNumberList(const LineNumberList & src)
{
	this->count = src.count;
	this->head = src.head;
	if (head)
	{
		// if head node exists then two pointers are created
		// one as source pointer and other as destination
		LineCNode *sptr, *dptr;
		// source pointer points to the head node of the source list
		sptr = src.head;
		// pointer of destination will point to the head node of
		// destination linked list which is created  by copying the head node
		// of the source linked list
		dptr = head = new LineCNode(*sptr);
		// source pointer now points to the next node of source linked list
		sptr = sptr->next;
		// untill the source pointer does not points to the last node
		// the loop will keep iterating and adding nodes to
		// the destination linked list
		while (sptr)
		{
			dptr->next = new LineCNode(*sptr);
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
LineNumberList::LineNumberList() :head(new LineCNode())
{
	head = nullptr;
	count = 0;
}
// constructor with A node as parameter
LineNumberList::LineNumberList(LineCNode *& ptr)
{
	head = ptr;
	count = 1;
	ptr = head->next = nullptr;
}
// insert node
LineNumberList & LineNumberList::insert(LineCNode *& ptr)
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
LineNumberList & LineNumberList::insert(LineCNode *& ptr, int index)
{
	// input the value to be stored in the Node
	//ptr->setNodeData();
	// index correction
	if (index <= 0)
		index = 0;
	if (index >= count)
		index = count;
	if (index == 0)
		return insert(ptr);
	else
	{
		LineCNode *rptr = head;
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
LineCNode * LineNumberList::remove()
{

	if (head)
	{
		LineCNode* ptr = head;
		head = head->next;
		ptr->next = nullptr;
		--count;
		return ptr;
	}
	return NULL;
}
// remove a node at given index
LineCNode * LineNumberList::remove(int index)
{
	// index correction 
	if (index < 0)
		index = 0;
	if (index >= count)
		index = count - 1;
	if (index == 0)
		return remove();


	LineCNode *ptr, *rptr = head;
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
LineNumberList & LineNumberList::swapNodes(int index1, int index2)
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
	LineCNode *ptr;
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
void LineNumberList::print()
{
	LineCNode *rptr = head;
	for (int i = 0; i < count; i++)
	{
		rptr->printNode();
		rptr = rptr->next;
	}
}
// returns true if the list is empty
bool LineNumberList::isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	return false;
}
// returns true if the list is not empty
bool LineNumberList::isNotEmpty()
{
	if (head != nullptr)
	{
		return true;
	}
	return false;
}
// reverse the list
LineNumberList & LineNumberList::reverse()
{
	if (count<2)
	{
		return *this;
	}
	LineCNode *rptr = head;
	LineCNode **arr = new LineCNode *[count];
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
LineCNode* LineNumberList::find(int line)
{
	LineCNode*ptr = head;
	for (int i = 0; i < count; i++)
	{
		if (line == ptr->lineNo)
			return ptr;
		else
			ptr = ptr->next;
	}
	return nullptr;
}
// find a node from the list and return nodes
LineCNode * LineNumberList::find(LineCNode * ptr)
{
	LineCNode *rptr = head;
	for (int i = 0; i < count; i++)
	{
		if (ptr->lineNo == rptr->lineNo)
			return new LineCNode(*rptr);
		else
		{
			rptr = rptr->next;
		}
	}
	return nullptr;
}
// sorting the whole linked list on the basis of the line number
LineNumberList & LineNumberList::sort()
{
	if(this->isNotEmpty())
	{
		LineCNode * ptr = head;
		// creating array of words 
		LineCNode **lines_arr = new LineCNode *[count];
		// copying every word node address in the words array
		for (int i = 0; i < count; i++)
		{
			lines_arr[i] = ptr;
			ptr = ptr->next;
		}
		// sorting line Numbers  Ascending
		bool swap = true;
		while (swap)
		{
			swap = false;
			for (int i = 0; i < count - 1; i++)
			{
				if (lines_arr[i]->lineNo < lines_arr[i + 1]->lineNo)
				{
					swap = true;
					// swapping two words
					ptr = lines_arr[i];
					lines_arr[i] = lines_arr[i + 1];
					lines_arr[i + 1] = ptr;
				}
			}
		}

		// creating list again from the array
		for (int i = 0, j = 1; j < count; i++, j++)
		{
			lines_arr[i]->next = lines_arr[j];
		}
		head = lines_arr[0];
		if (lines_arr)
		{
			delete[] lines_arr;
		}
	}
		return *this;
}
// destructor
LineNumberList::~LineNumberList()
{
	if (this->isNotEmpty())
	{
		LineCNode *ptr = head->next;
		head->next = nullptr;
		while (ptr)
		{
			delete head;
			head = ptr;
			ptr = ptr->next;
		}
	}
}
