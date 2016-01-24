#pragma once
#include "bbtree.h"

TEMP
void AVLTree<T>::RotateLL()//����ͷ�ڵ㲻�ܶ�������ֻ��ͨ������data���滻ͷ�ڵ�
{
	Tree<T> *templ = left, *tempr = right;
	leftLink(left->left);
	rightLink(templ);
	right->leftLink(right->right);
	right->rightLink(tempr);
	////left���ھ���BL
	//left = left->left;
	////right���ھ���B
	//right = templ;
	////ָ��B��left��right������right->right��û��
	//right->left = right->right;
	//right->right = tempr;
	////����A��B����
	Swap(data, right->data);
	//���¸߶�
	right->CheckHeight();
	CheckHeight();
}

TEMP
void AVLTree<T>::RotateRR()//��LL����һ�¡�ֻ�����ҷ���
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
