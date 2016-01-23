#pragma  once
#include "btree.h"
char btree<char>::endFlag = '#';

TEMP inline T Max(T const &a, T const &b)
{
	return a > b ? a : b;
}

TEMP
btree<T>::btree(btree<T> const & other)
{
	if (&other == NULL) return;
	data = other.data;
	nodeNum = other.nodeNum;
	height = other.height;
	left = new btree(*other.left);
	right = new btree(*other.right);
}

TEMP
btree<T>& btree<T>::operator=(btree<T> const & other)
{
	if (this == NULL || this == &other)return *this;
	this->del();
	data = other.data;
	nodeNum = other.nodeNum;
	height = other.height;
	left = new btree<T>(*other.left);
	right = new btree<T>(*other.right);
}

TEMP void btree<T>::del()
{
	if (left)
	{
		left->del();
		delete left;
		left = NULL;
	}
	if (right)
	{
		right->del();
		delete right;
		right = NULL;
	}
}

TEMP btree<T>::~btree()
{
	this->del();
}

TEMP void btree<T>::pre()const
{
	if (this == NULL)return;
	std::cout << data << " ";
	left->pre();
	right->pre();
}
TEMP void btree<T>::mid()const
{
	if (this == NULL)return;
	left->mid();
	std::cout << data << " ";
	right->mid();
}
TEMP void btree<T>::back()const
{
	if (this == NULL)return;
	left->back();
	right->back();
	std::cout << data << " ";
}
TEMP void btree<T>::print()const
{
	const btree<T>* temp;
	queue<const btree<T>*> Queue;
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
const btree<T>* btree<T>::find(T const &x)const
{
	btree<T>* temp;
	queue<btree<T>*> Queue;
	Queue.push(const_cast<btree*>(this));
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

