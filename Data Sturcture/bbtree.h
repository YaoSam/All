#pragma once
#include "bstree.h"
#include "normal.cpp"

TEMP
class AVLtree :public bstree < T >
{
	int differ(treeNode<T>* node)const//������߸߶�-�ұߡ�ƽ��������á�
	{
		return int(node->left ? node->left->height : 0) - int(node->right ? node->right->height : 0);
	}
	void RotateLL(treeNode<T>* node);
	void RotateRR(treeNode<T>* node);
	void RotateLR(treeNode<T>* node);
	void RotateRL(treeNode<T>* node);
	void Maintain(treeNode<T>* node, T const &x);
	int Height(const treeNode<T>* node)const{//����Debug�ġ�����height��ά��
		return Max(((node->left) ? Height(node->left) : 0), ((node->right) ? Height(node->right) : 0)) +1;
	}
public:
	int H()const
	{
		return Height(root);
	}
	void insert(T const & x);
	void DelNode(T const &x);
	AVLtree(T const a[] = NULL, unsigned int n = 0);
	virtual ~AVLtree(){}
};