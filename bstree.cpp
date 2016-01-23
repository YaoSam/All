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

TEMP
void bstree<T>::insert(T const &x)
{
	bstree<T> *L(reinterpret_cast<bstree<T>*>(left)), *R(reinterpret_cast<bstree<T>*>(right));
	if (nodeNum == 0)
	{
		data = x;
	}
	else if (x < data)
	{
		if (left == NULL)
			left = new btree<T>(x);
		else
			L->insert(x);
	}
	else
	{
		if (right == NULL)
			right = new btree<T>(x);
		else
			R->insert(x);
	}
	nodeNum++;
	CheckHeight();
}
