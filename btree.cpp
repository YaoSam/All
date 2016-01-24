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
	if (other.left)
		left = new BTree<T>(*other.left,this);
	if (other.right)
		right = new BTree<T>(*other.right,this);
}
TEMP
BTree<T>& BTree<T>::operator=(BTree<T> const & other)
{
	if (this == NULL || this == &other)return *this;
	this->del();
	data = other.data;
	height = other.height;
	parent = NULL;//这里并不是递归进入=，而是复制构造函数。所以这里一直是this
	if(other.left)leftLink(new BTree<T>(*other.left));
	if(other.right)rightLink(new BTree<T>(*other.right));
	return *this;
}

//由于动态绑定。所以函数的调用不能用空指针啊！！！！！！
TEMP void BTree<T>::pre()const
{
	if (height==0)return;
	std::cout << data << " ";
	if(left)left->pre();
	if(right)right->pre();
}
TEMP void BTree<T>::mid()const
{
	if (height==0)return;
	if(left)left->mid();
	std::cout << data << " ";
	if(right)right->mid();
}
TEMP void BTree<T>::back()const
{
	if (height==0)return;
	if(left)left->back();
	if(right)right->back();
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
Tree<T>* BTree<T>::find(T const &x)const
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