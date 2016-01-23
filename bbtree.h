#pragma once
#include "bstree.h"

TEMP
class bbtree :public bstree < T > 
{
protected:
	void RotateLL();
	void RotateRR();
	void RotateLR();
	void RotateRL();
public:
	void insert(T const & x);
	bbtree(T const a[] = NULL, int n = 0);
	~bbtree();
};