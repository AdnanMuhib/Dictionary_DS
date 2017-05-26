#include "BinaryTree.h"



BinaryTree::BinaryTree()
{

}


BinaryTree::~BinaryTree()
{
}
bool BinaryTree::isEmpty()
{
	if (!root)
	{
		return true;
	}
	return false;
}

bool BinaryTree::isNotEmpty()
{
	if (root)
	{
		return true;
	}
	return false;
}


BinaryTree::BinaryTree(BTNode *& root)
{
	this->root = root;
	root = this->root->left = this->root->right = NULL;
}

void BinaryTree::insert(BTNode *& ptr)
{
	BTNode *rptr,*bptr;
	if (!root)
	{
		root = ptr;
	}
	else
	{
		rptr = root;
		bptr = rptr;
		while (rptr)
		{
			bptr = rptr;
			if (ptr->getword() == rptr->getword())
			{
				return;
			}
			if (ptr->getword() < rptr->getword())
			{
				rptr = rptr->left;
			}
			else
			{
				rptr = rptr->right;
			}
		}
		
		if (ptr->getword() < bptr->getword())
		{
			bptr->left = ptr;
		}
		else
		{
			bptr->right = ptr;
		}
		ptr = ptr->left = ptr->right = nullptr;
	}
}

BTNode* BinaryTree::find(string word)
{
	// runner pointer
	BTNode *rptr = this->root;
	while (rptr)
	{
		if (word == rptr->getword())
		{
			return rptr;
		}
		if (word < rptr->getword())
		{
			rptr = rptr->left;
		}
		else
		{
			rptr = rptr->right;
		}
	}
	return rptr;
}
void BinaryTree::post_order(BTNode *p)
{
	if (p)
	{
		if (p->left)
		{
			post_order(p->left);
		}
		if (p->right)
		{
			post_order(p->right);
		}
		cout << "\n" << p->getword();
	}
	else return;
}

void BinaryTree::print_tree()
{
	post_order(root);
}