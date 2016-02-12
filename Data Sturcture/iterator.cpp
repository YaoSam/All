#pragma once
#include "iterator.h"

TEMP
T m_iterator<T>::operator*()const
{
	if (pCurrent == NULL)
		throw "iterator range error\n";
	else
		return pCurrent->data;
}

TEMP
treeNode<T>* Pre_iterator<T>::operator++()
{
	if (pCurrent == NULL)	throw "Pre_iterator range error\n";
	Stack.push(pCurrent);
	pCurrent = pCurrent->left;
	while (pCurrent == NULL&&!Stack.isEmpty())//�ܷ��ȥ
	{
		pCurrent = Stack.pop();
		pCurrent = pCurrent->right;
		if (pCurrent)
			break;
	}
	return pCurrent;//���������ߡ��˳������ߴ�ʱ���ܻ�ȥ��PΪ�ա�������
}

TEMP
void Mid_iterator<T>::goFirst()
{
	pCurrent = m_root;
	while (pCurrent != NULL)
	{
		Stack.push(pCurrent);
		pCurrent = pCurrent->left;
	}
	return;
}

TEMP
Mid_iterator<T>::Mid_iterator(NormalTree<T>* tree) :m_iterator<T>(tree->root,tree->root)
{
	goFirst();
}

TEMP 
T Mid_iterator<T>::operator*()const
{
	if (Stack.isEmpty())
		throw "Mid_iterator range error\n";
	else
		return Stack.topData()->data;
}

TEMP
treeNode<T>* Mid_iterator<T>::operator()()const
{
	if (Stack.isEmpty())
		throw "Mid_iterator range error\n";
	else
		return Stack.topData();
}

TEMP 
treeNode<T>* Mid_iterator<T>::operator++()
{
	if (Stack.isEmpty())
		throw "Mid_iterator range error\n";
	pCurrent = Stack.pop();//����м䡣
	if (pCurrent->right != NULL)
	{
		treeNode<T>* temp = pCurrent->right;//����������ұ�
		while (temp != NULL)//���ұߵ���߷Ž�ȥ��
		{
			Stack.push(temp);
			temp = temp->left;
		}
	}
	return pCurrent;
}

TEMP
treeNode<T>* Level_iterator<T>::operator++()
{
	if (pCurrent->left)
		Queue.push(pCurrent->left);
	if (pCurrent->right)
		Queue.push(pCurrent->right);
	if (!Queue.isEmpty())
		pCurrent = Queue.pop();
	else
		throw "Level_iterator range error\n";
	return pCurrent;
}