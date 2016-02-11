#pragma once
#include "bstree.h"

TEMP
class AVLTree :public BSTree < T > 
{
	int differ()const//计算左边高度-右边。平衡二叉树用。
	{
		return int(left ? left->height : 0) - int(right ? right->height : 0);
	}
	void RotateLL();
	void RotateRR();
	void RotateLR();
	void RotateRL();
public:
	void insert(T const & x);
	void DelNode(T const &x);
	AVLTree(T const a[] = NULL, unsigned int n = 0);
	virtual ~AVLTree(){}
};

TEMP
class AVLtree :public bstree < T >
{
	int differ(treeNode<T>* node)const//计算左边高度-右边。平衡二叉树用。
	{
		return int(node->left ? node->left->height : 0) - int(node->right ? node->right->height : 0);
	}
	void RotateLL(treeNode<T>* node);
	void RotateRR(treeNode<T>* node);
	void RotateLR(treeNode<T>* node);
	void RotateRL(treeNode<T>* node);
	void Maintain(treeNode<T>* node,T const &x);
	int Height(treeNode<T>* node){
		return Max(((node->left) ? Height(node->left) : 0), ((node->right) ? Height(node->right) : 0)) +1;
	}
public:
	int H()
	{
		return Height(root);
	}
	void insert(T const & x);
	void DelNode(T const &x);
	AVLtree(T const a[] = NULL, unsigned int n = 0);
	virtual ~AVLtree(){}
};