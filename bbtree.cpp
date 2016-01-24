#pragma once
#include "bbtree.h"

TEMP
void AVLTree<T>::RotateLL()//����ͷ�ڵ㲻�ܶ�������ֻ��ͨ������data���滻ͷ�ڵ�
{
	BTree<T> *templ = left, *tempr = right;
	//left���ھ���BL
	leftLink(left->left);
	//right���ھ���B
	rightLink(templ);
	//ָ��B��left��right������right->right��û��
	right->leftLink(right->right);
	right->rightLink(tempr);
	//����A��B����
	Swap(data, right->data);
	//���¸߶�
	right->CheckHeight();
	CheckHeight();
}

TEMP
void AVLTree<T>::RotateRR()//��LL����һ�¡�ֻ�����ҷ���
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
		if (differ() < -1)//��Ϊ��ɾ�����������Ի������Ƿ������ġ�
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
	else//����Ҫɾ���ýڵ��ˡ�
	{
		if (left&&right)
		{
			Tree<T>* temp = FindRightLeft();
			data = temp->data;
			right->DelNode(data);//��һ�εĵݹ顭���Բۡ����������еĵ㶼���ܻ 

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
