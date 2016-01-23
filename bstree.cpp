#include "bstree.h"


TEMP
bstree<T>::~bstree()
{
	this->del();
}

TEMP
void bstree<T>::insert(T const &x)
{
	bstree<T> *L(static_cast<bstree<T>*>(left)), *R(static_cast<bstree<T>*>(right));
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

TEMP
bstree<T>::bstree(T const a[]/* =NULL */, unsigned int n/* =0 */)
{
	re(i, n)
		this->insert(a[i]);
}

TEMP
btree<T>* bstree<T>::find(T const &x)
{
	bstree<T> *L(static_cast<bstree<T>*>(left)), *R(static_cast<bstree<T>*>(right));
	if (this == NULL || data == x)
		return static_cast<bstree<T>*>(this);
	else
		if (x < data)
			return L->find(x);
		else
			return R->find(x);
}