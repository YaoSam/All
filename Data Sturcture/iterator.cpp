#pragma once
#include "iterator.h"

TEMP
T tree_iterator<T>::operator*()const
{
	if (Pcurrent)
		return Pcurrent->data;
	else
		throw "\niterator range error\n";
}

TEMP
Tree<T>* tree_iterator<T>::operator()()const
{
	if (Pcurrent)
		return Pcurrent;
	else
		throw "\niterator range error\n";
}
//////////////////////////////////////////////////////////////////////////
TEMP
tree_iterator<T>& PreOrder_iterator<T>::operator++()
{
	if (Pcurrent == NULL)	throw "\niterator range error\n";
	Stack.push(Pcurrent);
	Pcurrent = Pcurrent->left;
	if (Pcurrent)//可以向左走。退出
		return *this;
	//此时P为空
	while (Pcurrent == NULL&&!Stack.isEmpty())//能否回去
	{
		Pcurrent = Stack.pop();
		Pcurrent = Pcurrent->right;
		if (Pcurrent)return *this;
	}
	return *this;
	//此时不能回去且P为空。结束。
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
		throw "\niterator range error\n";
	Pcurrent = Stack.pop();//输出中间。
	if (Pcurrent->right != NULL)
	{
		Tree<T>* temp = Pcurrent->right;//接下来输出右边
		while (temp != NULL)//将右边的左边放进去。
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
	if (Pcurrent==NULL)
		throw "\niterator range error\n";
	if (Pcurrent->left)
		Queue.push(Pcurrent->left);
	if (Pcurrent->right)
		Queue.push(Pcurrent->right);
	if (!Queue.isEmpty())
		Pcurrent = Queue.pop();
	else
		Pcurrent = NULL;
	return *this;
}
/************************************************************************/
/*                                                                      */
/************************************************************************/
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
	while (pCurrent == NULL&&!Stack.isEmpty())//能否回去
	{
		pCurrent = Stack.pop();
		pCurrent = pCurrent->right;
		if (pCurrent)
			break;
	}
	return pCurrent;//可以向左走。退出，或者此时不能回去且P为空。结束。
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
	pCurrent = Stack.pop();//输出中间。
	if (pCurrent->right != NULL)
	{
		treeNode<T>* temp = pCurrent->right;//接下来输出右边
		while (temp != NULL)//将右边的左边放进去。
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