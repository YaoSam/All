#include "bstree.h"

TEMP void BSTree<T>::insert(T const &x)
{
	BSTree<T> *L(static_cast<BSTree<T>*>(left)), *R(static_cast<BSTree<T>*>(right));
	if (height==0)//头节点不用申请内存
	{
		data = x;
	}
	else if (x < data)
	{
		if (left == NULL)
			leftLink(new BTree<T>(x));
		else
			L->insert(x);
	}
	else
	{
		if (right == NULL)
			rightLink(new BTree<T>(x));
		else
			R->insert(x);
	}
	CheckHeight();
}


TEMP
BSTree<T>::BSTree(T const a[]/* =NULL */, unsigned int n/* =0 */) 
{
	re(i, n)
		this->insert(a[i]);
}

TEMP
Tree<T>* BSTree<T>::find(T const &x)
{
	if (this == NULL)return NULL;
	BSTree<T> *L(static_cast<BSTree<T>*>(left)), *R(static_cast<BSTree<T>*>(right));
	if (height == 0||this==NULL)
		return NULL;
	if (data == x)
		return static_cast<Tree<T>*>(this);
	else
	if (x < data)
		return L->find(x);
	else
		return R->find(x);
}

TEMP 
Tree<T>* BSTree<T>::FindRightNext()const
{
	if (this == NULL)
		throw "FindRightNext() NULL Error\n";
	Tree<T>* ans = this->right;
	if (ans != NULL)
		while (ans->left != NULL)
			ans = ans->left;
	return ans;
}

TEMP
Tree<T>* BSTree<T>::FindLeftNext()const
{
	if (this == NULL)
		throw "FIndLeftNext() NULL Error.";
	Tree<T>* ans = this->left;
	if (ans != NULL)
		while (ans->right != NULL)
			ans = ans->right;
	return ans;
}

TEMP
void BSTree<T>::deleteNode()
{
	BTree<T>* P = this->parent;
	BSTree<T>* BSthis = const_cast<BSTree<T>*>(this);
	BTree<T>* Bthis = const_cast<BTree<T>*>(static_cast<BTree<T>*>(this));
	if (P == NULL)//P是头节点，不能删除。
		throw "Error\n";
	BSthis->right = NULL;
	BSthis->left = NULL;
	delete Bthis;
	//一直向上维护高度以及节点数目
	while (P != NULL)
	{
		P->CheckHeight();
		P = P->parent;
	}
}

TEMP
void BSTree<T>::DelNode(T const &x)
{
	BSTree<T> *target = static_cast<BSTree<T>*>(find(x));
	if (target == NULL)return;
	Tree<T> *Next = target->FindRightNext();
	if (Next != NULL)
	{
		target->data = Next->data;
		if (Next == target->right)
			target->rightLink(Next->right);
		else
			Next->parent->leftLink(Next->right);
		BSTree<T>* temp = static_cast<BSTree<T>*>(Next);
		temp->deleteNode();
	}
	else
	{
		Next = target->FindLeftNext();
		if (Next != NULL)
		{
			target->data = Next->data;
			if (Next == target->left)
				target->leftLink(Next->left);
			else
				Next->parent->rightLink(Next->left);
			BSTree<T>* temp = static_cast<BSTree<T>*>(Next);
			temp->deleteNode();
		}
		else
		{
			if (target->parent == 0)
			{
				height = 0;
				left = right = 0;
			}
			else {
				if (target->parent->left == target)
					target->parent->left = NULL;
				else
					target->parent->right = NULL;
				BSTree<T>* temp = static_cast<BSTree<T>*>(target);
				temp->deleteNode();
			}
		}
	}
	return;
}

