#pragma  once
#include "btree.h"
char Tree<char>::endFlag = '#';

TEMP inline T Max(T const &a, T const &b)
{
	return a > b ? a : b;
}

TEMP
Tree<T>::Tree(Tree<T> const & other, Tree<T>* P/* =NULL */) 
{
	if (&other == NULL)return;
	data = other.data;
	height = other.height;
	parent = P;
	leftLink(new Tree<T>(*other.left));
	rightLink(new Tree<T>(*other.right));
}
TEMP
Tree<T>& Tree<T>::operator=(Tree<T> const & other)
{
	if (this == NULL || this == &other)return *this;
	this->del();
	data = other.data;
	height = other.height;
	parent = NULL;//这里并不是递归进入=，而是复制构造函数。所以这里一直是this
	leftLink(new Tree<T>(*other.left));
	rightLink(new Tree<T>(*other.right));
	return *this;
}

TEMP void Tree<T>::del()
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

TEMP Tree<T>::~Tree()
{
	this->del();
}

TEMP void Tree<T>::pre()const
{
	if (this == NULL||height==0)return;
	std::cout << data << " ";
	left->pre();
	right->pre();
}
TEMP void Tree<T>::mid()const
{
	if (this == NULL||height==0)return;
	left->mid();
	std::cout << data << " ";
	right->mid();
}
TEMP void Tree<T>::back()const
{
	if (this == NULL||height==0)return;
	left->back();
	right->back();
	std::cout << data << " ";
}
TEMP void Tree<T>::print()const
{
	if (height == 0)return;
	const Tree<T>* temp;
	queue<const Tree<T>*> Queue;
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

TEMP
Tree<T>* Tree<T>::find(T const &x)const
{
	if (height == 0)return;
	Tree<T>* temp;
	queue<Tree<T>*> Queue;
	Queue.push(const_cast<Tree*>(this));
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
void Tree<T>::deleteNode()
{
	Tree<T>* P = this->parent;
	Tree<T>* THIS = const_cast<Tree<T>*>(this);
	if (P == NULL)//P是头节点，不能删除。
		throw "Error\n";
	THIS->right = NULL;
	THIS->left = NULL;
	delete THIS;
	//一直向上维护高度以及节点数目
	while (P!= NULL)
	{
		P->CheckHeight();
		P = P->parent;
	}
}