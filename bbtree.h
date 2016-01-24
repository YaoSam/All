#pragma once
#include "bstree.h"

TEMP
class AVLTree :public BSTree < T > 
{
	int differ()const//������߸߶�-�ұߡ�ƽ��������á�
	{
		return int(left ? left->height : 0) - int(right ? right->height : 0);
	}
	void RotateLL();
	void RotateRR();
	void RotateLR();
	void RotateRL();
public:
	void insert(T const & x);
	AVLTree(T const a[] = NULL, unsigned int n = 0);
	~AVLTree(){}
};