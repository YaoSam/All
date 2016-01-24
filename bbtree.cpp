#pragma once
#include "bbtree.h"

TEMP
void AVLTree<T>::RotateLL()//由于头节点不能动。所以只能通过交换data来替换头节点
{
	Tree<T> *templ = left, *tempr = right;
	leftLink(left->left);
	rightLink(templ);
	right->leftLink(right->right);
	right->rightLink(tempr);
	////left现在就是BL
	//left = left->left;
	////right现在就是B
	//right = templ;
	////指派B的left和right。现在right->right还没变
	//right->left = right->right;
	//right->right = tempr;
	////交换A，B数据
	Swap(data, right->data);
	//更新高度
	right->CheckHeight();
	CheckHeight();
}

TEMP
void AVLTree<T>::RotateRR()//跟LL基本一致。只是左右反了
{
	Tree<T> *templ = left, *tempr = right;
	rightLink(right->right);
	leftLink(tempr);
	left->rightLink(left->left);
	left->leftLink(templ);
	//right = right->right;
	//left = tempr;
	//left->right = left->left;
	//left->left = templ;
	Swap(data, left->data);
	left->CheckHeight();
	CheckHeight();
}

TEMP
void AVLTree<T>::RotateLR()
{
	AVLTree<T>* L(static_cast<AVLTree<T>*>(left)), *R(static_cast<AVLTree<T>*>(right));
	L->RotateRR();
	RotateLL();
}

TEMP
void AVLTree<T>::RotateRL()
{
	AVLTree<T>* L(static_cast<AVLTree<T>*>(left)), *R(static_cast<AVLTree<T>*>(right));
	R->RotateLL();
	RotateRR();
}

TEMP
void AVLTree<T>::insert(T const & x)
{
	AVLTree<T>* L(static_cast<AVLTree<T>*>(left)), *R(static_cast<AVLTree<T>*>(right));
	if (height == 0)
	{
		data = x;
	}
	else if (x < data)
	{
		if (left == NULL)
			left = new Tree<T>(x,this);
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
			right = new Tree<T>(x,this);
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
	CheckHeight();
	return;
}

TEMP
AVLTree<T>::AVLTree(T const a[] /* = NULL */, unsigned int n /* = 0 */) :BSTree<T>()
{
	re(i, n)
		insert(a[i]);
	return;
}

TEMP
AVLTree<T>::~AVLTree()
{
	this->del();
}
