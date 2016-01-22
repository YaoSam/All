#include "bstree.h"

//TEMP
//void bstree<T>::insert(T const &x)
//{
//	if (nodeNum == 0)
//	{
//		data = x;
//	}
//	else if (x > data)
//	{
//		if (right == NULL)
//			right = new btree<T>(x);
//		else
//			right->insert(x);
//	}
//	else
//	{
//		if (left == NULL)
//			left = new btree<T>(x);
//		else
//			left->insert(x);
//	}
//	nodeNum++;
//}

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