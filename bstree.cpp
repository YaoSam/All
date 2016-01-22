#include "bstree.h"

TEMP
bstree<T>::bstree(T const a[]/* =NULL */, unsigned int n/* =0 */)
{
	re(i, n)
		this->insert(a[i]);
}

TEMP
bstree<T>::~bstree()
{
	this->del();
}