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
void bbtree<T>::RotateLL()//����ͷ�ڵ㲻�ܶ�������ֻ��ͨ������data���滻ͷ�ڵ�
{
	btree<T> *templ = left, *tempr = right;
	//left���ھ���BL
	left = left->left;
	//right���ھ���B
	right = templ;
	//ָ��B��left��right������right->right��û��
	right->left = right->right;
	right->right = tempr;
	//����A��B����
	Swap(data, right->data);
	//���¸߶�
	right->CheckHeight();
	CheckHeight();
}

TEMP
void bbtree<T>::RotateRR()//��LL����һ�¡�ֻ�����ҷ���
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