#pragma once
#include "bbtree.h"

TEMP
void AVLTree<T>::RotateLL()//由于头节点不能动。所以只能通过交换data来替换头节点
{
	BTree<T> *templ = left, *tempr = right;
	//left现在就是BL
	leftLink(left->left);
	//right现在就是B
	rightLink(templ);
	//指派B的left和right。现在right->right还没变
	right->leftLink(right->right);
	right->rightLink(tempr);
	//交换A，B数据
	Swap(data, right->data);
	//更新高度
	right->CheckHeight();
	CheckHeight();
}

TEMP
void AVLTree<T>::RotateRR()//跟LL基本一致。只是左右反了
{
	BTree<T> *templ = left, *tempr = right;
	rightLink(right->right);
	leftLink(tempr);
	left->rightLink(left->left);
	left->leftLink(templ);
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
			leftLink(new BTree<T>(x));
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
			rightLink(new BTree<T>(x));
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
void AVLTree<T>::DelNode(T const &x)
{
	AVLTree<T>* L = static_cast<AVLTree<T>*>(this->left),*R=static_cast<AVLTree<T>*>(this->right);
	if (this == NULL)return;
	if (x > data)
	{
		L->DelNode(x);
		if (differ() < -1)//因为是删除操作，所以基本都是翻过来的。
		{
			if (left->right != NULL && ((right->left->height) > (right->right->height)))
				RotateLR();
			else
				RotateLL();
		}
	}
	else if (x < data)
	{
		R->DelNode(x);
		if (differ() >1)
		{
			if (left->right != NULL && (left->right->height) > (left->left->height))
				RotateRL();
			else
				RotateRR();
		}
	}
	else//此事要删除该节点了。
	{
		if (left&&right)
		{
			Tree<T>* temp = FindRightLeft();
			data = temp->data;
			right->DelNode(data);//再一次的递归……卧槽……这是所有的点都不能活啊 

		}
	}

}

TEMP
AVLTree<T>::AVLTree(T const a[] /* = NULL */, unsigned int n /* = 0 */) :BSTree<T>()
{
	re(i, n)
		insert(a[i]);
	return;
}
