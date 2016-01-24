#pragma  once
#include "btree.h"
#include "queue.cpp"
char BTree<char>::endFlag = '#';

TEMP inline T Max(T const &a, T const &b)
{
	return a > b ? a : b;
}

TEMP
BTree<T>::BTree(BTree<T> const & other, BTree<T>* P/* =NULL */) 
{
	if (&other == NULL)return;
	data = other.data;
	height = other.height;
	parent = P;
	leftLink(new BTree<T>(*other.left));
	rightLink(new BTree<T>(*other.right));
}
TEMP
BTree<T>& BTree<T>::operator=(BTree<T> const & other)
{
	if (this == NULL || this == &other)return *this;
	this->del();
	data = other.data;
	height = other.height;
	parent = NULL;//这里并不是递归进入=，而是复制构造函数。所以这里一直是this
	leftLink(new BTree<T>(*other.left));
	rightLink(new BTree<T>(*other.right));
	return *this;
}


TEMP void BTree<T>::pre()const
{
	if (this == NULL||height==0)return;
	std::cout << data << " ";
	left->pre();
	right->pre();
}
TEMP void BTree<T>::mid()const
{
	if (this == NULL||height==0)return;
	left->mid();
	std::cout << data << " ";
	right->mid();
}
TEMP void BTree<T>::back()const
{
	if (this == NULL||height==0)return;
	left->back();
	right->back();
	std::cout << data << " ";
}
TEMP void BTree<T>::print()const
{
	if (height == 0)return;
	const BTree<T>* temp;
	queue<const BTree<T>*> Queue;
	Queue.push(this);
	while (!Queue.isEmpty())
	{
		temp = Queue.pop();
		if (temp->left)
			Queue.push(temp->left);
		if (temp->right)
			Queue.push(temp->right);
		std::cout << (temp->data) << " ";
	}
	std::cout << std::endl;
}

TEMP 
unsigned int Tree<T>::NodeNum()const
{
	if (height == 0)
		return 0;
	return (left ? left->NodeNum() : 0) + (right ? right->NodeNum() : 0) + 1;
}

/************************************************************************/
/*                                                                      */
/************************************************************************/
TEMP
BTree<T>* BTree<T>::find(T const &x)const
{
	if (height == 0)return NULL;
	BTree<T>* temp;
	queue<BTree<T>*> Queue;
	Queue.push(const_cast<BTree*>(this));
	while (!Queue.isEmpty())
	{
		temp = Queue.pop();
		if (temp->data == x)
			return temp;
		if (temp->left)
			Queue.push(temp->left);
		if (temp->right)
			Queue.push(temp->right);
	}
	return NULL;
}

TEMP
void BTree<T>::del()
{
	Tree<T>* L = static_cast<Tree<T>*>(left), *R = static_cast<Tree<T>*>(right);
	if (left)
	{
		left->del();
		delete L;
		left = NULL;
	}
	if (right)
	{
		right->del();
		delete R;
		right = NULL;
	}
}

TEMP
BTree<T>::~BTree()
{
	this->del();
}