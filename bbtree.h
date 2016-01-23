#pragma once
#include "bstree.h"

TEMP
class bbtree :public bstree < T > 
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
	bbtree(T const a[] = NULL, int n = 0);
	~bbtree();
};