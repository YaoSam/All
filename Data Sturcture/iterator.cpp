#pragma once
#include "iterator.h"

TEMP
T tree_iterator<T>::operator*()const
{
	if (Pcurrent)
		return Pcurrent->data;
	else
		throw "\niterator range erreor\n";
}

TEMP
Tree<T>* tree_iterator<T>::operator()()const
{
	if (Pcurrent)
		return Pcurrent;
	else
		throw "\niterator range erreor\n";
}
//////////////////////////////////////////////////////////////////////////
TEMP
tree_iterator<T>& PreOrder_iterator<T>::operator++()
{
	if (Pcurrent == NULL)	throw "\niterator range erreor\n";
	Stack.push(Pcurrent);
	Pcurrent = Pcurrent->left;
	if (Pcurrent)//���������ߡ��˳�
		return *this;
	//��ʱPΪ��
	while (Pcurrent == NULL&&!Stack.isEmpty())//�ܷ��ȥ
	{
		Pcurrent = Stack.pop();
		Pcurrent = Pcurrent->right;
		if (Pcurrent)return *this;
	}
	return *this;
	//��ʱ���ܻ�ȥ��PΪ�ա�������
}

//////////////////////////////////////////////////////////////////////////

TEMP
InOrder_iterator<T>::InOrder_iterator(Tree<T>* P) :tree_iterator<T>(P)
{
	while (P != NULL)
	{
		Stack.push(P);
		P = P->left;
	}
	return;
}
TEMP
void InOrder_iterator<T>::gotoFirst()
{
	Pcurrent = root;
	while (Pcurrent != NULL)
	{
		Stack.push(Pcurrent);
		Pcurrent = Pcurrent->left;
	}
	return;
}
TEMP
T InOrder_iterator<T>::operator*()const
{
	return Stack.topData()->data;
}

TEMP
Tree<T>* InOrder_iterator<T>::operator()()const
{
	return Stack.topData();
}

TEMP
tree_iterator<T>& InOrder_iterator<T>::operator++()
{
	if (Stack.isEmpty())
		throw "\niterator range erreor\n";
	Pcurrent = Stack.pop();//����м䡣
	if (Pcurrent->right != NULL)
	{
		Tree<T>* temp = Pcurrent->right;//����������ұ�
		while (temp != NULL)//���ұߵ���߷Ž�ȥ��
		{
			Stack.push(temp);
			temp = temp->left;
		}
	}
	return *this;
}

//////////////////////////////////////////////////////////////////////////
 
TEMP 
tree_iterator<T>& LevelOrder_iterator<T>::operator++()
{
	if (Pcurrent->left)
		Queue.push(Pcurrent->left);
	if (Pcurrent->right)
		Queue.push(Pcurrent->right);
	if (!Queue.isEmpty())
	{
		Pcurrent = Queue.pop();
		return *this;
	}
	else 
		throw "\niterator range erreor\n";
}
