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
	AVLTree<T>* L(static_cast<AVLTree<T>*>(left));
	L->RotateRR();
	RotateLL();
}

TEMP
void AVLTree<T>::RotateRL()
{
	AVLTree<T>*R(static_cast<AVLTree<T>*>(right));
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
	if (this == NULL)return;
	AVLTree<T>* L = static_cast<AVLTree<T>*>(this->left),*R=static_cast<AVLTree<T>*>(this->right);
	if (x < data)
	{
		if (!left)return;
		L->DelNode(x);
		if (differ() < -1)//因为是删除操作，所以基本都是反过来的。左边被删除就右旋
		{
			//右边肯定有两层。
			if (right->left!= NULL && right->right!=NULL&&((right->left->height) > (right->right->height)))
				RotateRL();
			else
				RotateRR();
		}
	}
	else if (x > data)
	{
		if (!right)return;
		R->DelNode(x);
		if (differ() >1)
		{
			if (left->right != NULL&&left->left!=NULL && (left->right->height) > (left->left->height))
				RotateLR();
			else
				RotateLL();
		}
	}
	else//这时要删除该节点了。
	{
		if (left&&right)
		{
			Tree<T>* temp = FindRightNext();//这里保证了不为空。
			data = temp->data;
			R->DelNode(data);//再一次的递归……卧槽……这是所有的点都不能活啊 
			if (differ() > 1)//右边的节点被删除。考虑左旋转。照抄上面就好。
			{
				if (left->right != NULL &&left->left!=NULL&& (left->right->height) > (left->left->height))
					RotateLR();
				else
					RotateLL();
			}
		}
		else if (left)
		{
			data = left->data;
			delete left;
			left = NULL;
		}
		else if (right)
		{
			data = right->data;
			delete right;
			right = NULL;
		}
		else
		{
			if (parent == NULL)
			{
				height = 0;
				return;
			}
			else if (parent->left == this)
				parent->left = NULL;
			else
				parent->right = NULL;
			delete const_cast<AVLTree<T>*>(this);
			return;
		}

	}
	CheckHeight();
}

TEMP
AVLTree<T>::AVLTree(T const a[] /* = NULL */, unsigned int n /* = 0 */) :BSTree<T>()
{
	re(i, n)
		insert(a[i]);
	return;
}
