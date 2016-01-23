#pragma once
#include "bbtree.h"

TEMP
bbtree<T>::bbtree(T const a[] /* = NULL */, int n /* = 0 */) :bstree()
{
	re(i, n)
		insert(a[i]);
	return;
}

TEMP
bbtree<T>::~bbtree()
{
	this->del();
}

TEMP
void bbtree<T>::RotateLL()//由于头节点不能动。所以只能通过交换data来替换头节点
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
	//更新高度
	right->CheckHeight();
	CheckHeight();
}

TEMP
void bbtree<T>::RotateRR()//跟LL基本一致。只是左右反了
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
void bbtree<T>::RotateLR()
{
	bbtree<T>* L(static_cast<bbtree<T>*>(left)), *R(static_cast<bbtree<T>*>(right));
	L->RotateRR();
	RotateLL();
}

TEMP
void bbtree<T>::RotateRL()
{
	bbtree<T>* L(static_cast<bbtree<T>*>(left)), *R(static_cast<bbtree<T>*>(right));
	R->RotateLL();
	RotateRR();
}

TEMP
void bbtree<T>::insert(T const & x)
{
	bbtree<T>* L(static_cast<bbtree<T>*>(left)), *R(static_cast<bbtree<T>*>(right));
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
			L->insert(x);
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
			R->insert(x);
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