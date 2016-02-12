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
	AVLTree<T>* L = static_cast<AVLTree<T>*>(left),*R=static_cast<AVLTree<T>*>(right);
	if (x < data)
	{
		if (!left)return;
		L->DelNode(x);
		if (differ() < -1)//��Ϊ��ɾ�����������Ի������Ƿ������ġ���߱�ɾ��������
		{
			//�ұ߿϶������㡣
			if (right->right == NULL || (right->left != NULL && ((right->left->height) > (right->right->height))))
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
			if (left->left == NULL || (left->right != NULL && (left->right->height) > (left->left->height)))
				RotateLR();
			else
				RotateLL();
		}
	}
	else//��ʱҪɾ���ýڵ��ˡ�
	{
		if (left&&right)
		{
			Tree<T>* temp = FindRightNext();//���ﱣ֤��Ϊ�ա�
			data = temp->data;
			R->DelNode(data);//��һ�εĵݹ顭���Բۡ���
			if (differ() > 1)//�ұߵĽڵ㱻ɾ������������ת���ճ�����ͺá�
			{
				if (left->left == NULL || (left->right != NULL && (left->right->height) > (left->left->height)))
					RotateLR();
				else
					RotateLL();
			}
		}
		else if (left)//������ƽ�������������left�߶ȿ϶���>2
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
				height = 0;
			else
			{
				if (parent->left == this)
					parent->left = NULL;
				else
					parent->right = NULL;
				delete const_cast<AVLTree<T>*>(this);
			} 	
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

//////////////////////////////////////////////////////////////////////////
TEMP
void AVLtree<T>::RotateLL(treeNode<T>* node)
{
	treeNode<T>* Root = node->left,*P=node->parent;
	if (node->parent == NULL)
		root = Root;
	if (P != NULL)
	{
		if (P->left == node)
			P->leftlink(Root);
		else
			P->rightlink(Root);
	}
	else Root->parent = NULL;
	node->leftlink(Root->right);
	Root->rightlink(node);
	node->CheckHeight();
	Root->CheckHeight();
}

TEMP
void AVLtree<T>::RotateRR(treeNode<T>* node)
{
	treeNode<T>* Root = node->right, *P = node->parent;
	if (node->parent == NULL)
		root = Root;
	if (P != NULL)
	{
		if (P->left == node)
			P->leftlink(Root);
		else
			P->rightlink(Root);
	}
	else Root->parent = NULL;
	node->rightlink(Root->left);
	Root->leftlink (node);
	node->CheckHeight();
	Root->CheckHeight();
}

TEMP
void AVLtree<T>::RotateLR(treeNode<T>* node)
{
	RotateRR(node->left);
	RotateLL(node);
}

TEMP
void AVLtree<T>::RotateRL(treeNode<T>* node)
{
	RotateLL(node->right);
	RotateRR(node);
}

TEMP
void AVLtree<T>::Maintain(treeNode<T>* node, T const &x)
{
	while (node)
	{
		node->CheckHeight();
		if (differ(node) == 2)
		{
			if (differ(node->left)>=0)
				RotateLL(node);
			else
				RotateLR(node);
			break;	

		}
		else if (differ(node) == -2)
		{
			if (differ(node->right)<=0)
				RotateRR(node);
			else
				RotateRL(node);
			break;
		}
		node = node->parent;
	}
}

TEMP
void AVLtree<T>::insert(T const & x)
{
	treeNode<T>* target = root,*P=NULL;
	if (target == NULL)
		root = new treeNode<T>(x,1);
	else
	{
		while (1)
		{
			if (x < target->data)
			{
				if (target->left) target = target->left;
				else
				{
					target->left = new treeNode<T>(x, 1, target);
					target->CheckHeight();
					Maintain(target->parent, x);
					break;
				}
			}
			else
			{
				if (target->right)target = target->right;
				else
				{
					target->right = new treeNode<T>(x, 1, target);
					target->CheckHeight();
					Maintain(target->parent, x);
					break;
				}
			}
		}
	}

}

TEMP 
AVLtree<T>::AVLtree(T const a[] /* = NULL */, unsigned int n /* = 0 */)
{
	re(i, n)
		insert(a[i]);
}

TEMP
void AVLtree<T>::DelNode(T const &x)
{
	//TODO, ��������Swap��
	treeNode<T>* target = find(x);
	if (target == NULL)return;
	treeNode<T>* Next = FindLeftNext(target),*P=NULL;
	if (Next)
	{
		Swap(Next->data, target->data);
		P = Next->parent;
		if (P == target)
			P->leftlink(Next->left);
		else
			P->rightlink(Next->right);
		delete Next;
		Maintain(P, x);
	}
	else
	{
		Next = FindRightNext(target);
		if (Next)
		{
			Swap(Next->data, target->data);
			P = Next->parent;
			if (P == target)
				P->rightlink(Next->right);
			else
				P->leftlink(Next->right);
			delete Next;
			Maintain(P, x);
		}
		else
		{
			P = target->parent;
			if (P)
			{
				if (P->left == target)
					P->left = NULL;
				else
					P->right = NULL;
				delete target;
				Maintain(P, x);
			}
			else
				root = NULL;
		}
	}
}
