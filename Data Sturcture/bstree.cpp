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
	BSTree<T> *L(static_cast<BSTree<T>*>(left)), *R(static_cast<BSTree<T>*>(right));
	if (height == 0)
		return NULL;
	if (data == x)
		return static_cast<Tree<T>*>(this);
	Tree<T>* LeftAns = NULL;
	if (x <= data&&left && (LeftAns = L->find(x)))
		return LeftAns;
	if (x>=data&&right)
		return R->find(x);
	return NULL;
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
		static_cast<BSTree<T>*>(Next)->deleteNode();
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
			static_cast<BSTree<T>*>(Next)->deleteNode();
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
				target->deleteNode();
			}
		}
	}
	return;
}

//////////////////////////////////////////////////////////////////////////


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
