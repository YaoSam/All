#include "bstree.h"

TEMP 
void bstree<T>::insert(T const &x)
{
	if (root == NULL)
	{
		root = new treeNode<T>(x, 1);
		return;
	}
	treeNode<T>* temp = root;
	while (temp)
	{
		if (x < temp->data)
		{
			if (temp->left == NULL)
			{
				temp->left = new treeNode<T>(x, 1, temp);
				break;
			}
			temp = temp->left;
		}
		else
		{
			if (temp->right == NULL)
			{
				temp->right = new treeNode<T>(x, 1, temp);
				break;
			}
			temp = temp->right;
		}
	}
	while (temp)
	{
		temp->CheckHeight();
		temp = temp->parent;
	}
}

TEMP
bstree<T>::bstree(T const a[] /* = NULL */, unsigned int n /* = 0 */)
{
	re(i, n)
		insert(a[i]);
}
TEMP 
treeNode<T>* bstree<T>::FindLeftNext(const treeNode<T>* a)const
{
	if (a == NULL)
		return NULL;
	treeNode<T>* temp = a->left;
	if (temp != NULL)
	{
		while (temp->right != NULL)
			temp = temp->right;
	}
	return temp;
}
TEMP
treeNode<T>* bstree<T>::FindRightNext(const treeNode<T>* a)const
{
	if (a == NULL)
		return NULL;
	treeNode<T>* temp = a->right;
	if (temp != NULL)
	{
		while (temp->left != NULL)
			temp = temp->left;
	}
	return temp;
}

TEMP
void bstree<T>::deleteLeave(treeNode<T>* other)
{
	treeNode<T>* P = other->parent;
	delete other;
	while (P != NULL)
	{
		P->CheckHeight();
		P = P->parent;
	}
}

TEMP
treeNode<T>* bstree<T>::find(T const &x)const
{
	treeNode<T>* temp = root;
	while (temp)
	{
		if (temp->data == x)
			return temp;
		else if (x < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return NULL;
}
TEMP
void bstree<T>::DelNode(T const &x)
{
	treeNode<T>* target = find(x);
	if (target == NULL) return;
	treeNode<T>* Next = FindLeftNext(target);
	if (Next != NULL)
	{
		Swap(Next->data, target->data);
		if (Next == target->left)
			target->leftlink(Next->left);
		else 
			Next->parent->rightlink(Next->left);
		deleteLeave(Next);//记住Next不是叶子……
	}
	else
	{
		Next = FindRightNext(target);
		if (Next != NULL)
		{
			Swap(Next->data, target->data);
			if (Next == target->right)
				target->rightlink(Next->right);
			else 
				Next->parent->leftlink(Next->right);
			deleteLeave(Next);
		}
		else
		{
			if (target->parent)
			{
				if (target->parent->left == target)
					target->parent->left = NULL;
				else
					target->parent->right = NULL;
			}
			else
				root = NULL;
			deleteLeave(target);
		}
	}
}
