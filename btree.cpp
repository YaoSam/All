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
	data = other.data;
	nodeNum = other.nodeNum;
	height = other.height;
	if (other.left)
		left = new btree(*other.left);
	if (other.right)
		right = new btree(*other.right);
}
TEMP
void btree<T>::del()
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

TEMP
btree<T>::~btree()
{
	this->del();
}

TEMP
void btree<T>::pre()const
{
	if (this == NULL)return;
	std::cout << data << " ";
	left->pre();
	right->pre();
}

TEMP
void btree<T>::mid()const
{
	if (this == NULL)return;
	left->mid();
	std::cout << data << " ";
	right->mid();
}

TEMP
void btree<T>::back()const
{
	if (this == NULL)return;
	left->back();
	right->back();
	std::cout << data << " ";
}

TEMP
void btree<T>::print()const
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
btree<T>* btree<T>::find(T const &x)const
{
	const btree<T>* temp;
	queue<const btree<T>*> Queue;
	Queue.push(this);
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
unsigned int btree<T>::CheckHeight()
{
	height=Max((left ? left->height : 0),(right ? right->height : 0)) + 1;
	return height;
}

TEMP
void btree<T>::insert(T const &x)
{
	if (nodeNum == 0)
	{
		data = x;
		nodeNum = 1;
		height = 1;
		return;
	}
	else if (x > data)
	{
		if (right == NULL)
			right = new btree<T>(x);
		else
			right->insert(x);
	}
	else
	{
		if (left == NULL)
			left = new btree<T>(x);
		else
			left->insert(x);
	}
	nodeNum++;
	CheckHeight();
}


TEMP
void btree<T>::RotateLL()
{
	btree<T> *templ = left, *tempr = right;
	//left现在就是BL
	left = left->left;
	//right现在就是B
	right = templ;
	//指派B的left和right。现在right->right还没变
	right->left = right->right;
	right->right = tempr;
	//交换A，B数据
	Swap(data, right->data);
	right->CheckHeight();
	CheckHeight();
}

TEMP
void btree<T>::RotateRR()
{
	btree<T> *templ = left, *tempr = right;
	right = right->right;
	left = tempr;
	left->right = left->left;
	left->left = templ;
	Swap(data, left->data);
	left->CheckHeight();
	CheckHeight();
}

TEMP
void btree<T>::RotateLR()
{
	left->RotateRR();
	RotateLL();
}

TEMP
void btree<T>::RotateRL()
{
	right->RotateLL();
	RotateRR();
}


TEMP
void btree<T>::RotateInsert(T const & x)
{
	if (nodeNum == 0)
	{
		data = x;
	}
	else if (x < data)
	{
		if (left == NULL)
			left = new btree<T>(x);
		else
		{
			left->RotateInsert(x);
			if (differ() > 1)
			{
				if (x < left->data)
					RotateLL();
				else
					RotateLR();
			}
		}
	}
	else
	{
		if (right == NULL)
			right = new btree<T>(x);
		else
		{
			right->RotateInsert(x);
			if (differ() < -1)
			{
				if (x >= right->data)
					RotateRR();
				else
					RotateRL();
			}
		}
	}
	nodeNum++;
	CheckHeight();
	return;
}