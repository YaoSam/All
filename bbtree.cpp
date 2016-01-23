#pragma once
#include "bbtree.h"




TEMP
bbtree<T>::bbtree(T const a[] /* = NULL */, int n /* = 0 */) :btree()
{
	re(i, n)
		RotateInsert(a[i]);
	return;
}


TEMP
bbtree<T>::~bbtree()
{
	this->del();
}