#pragma once
#include "btree.cpp"

TEMP
class BSTree : public Tree < T >
{
	void del();
	Tree<T>* FindRightNext()const;
	Tree<T>* FindLeftNext()const;
public:
	void insert(T const &x);
	BSTree(T const a[]=NULL,unsigned int n=0);
	virtual ~BSTree();
	Tree<T>* find(T const &x);
	void delNode(T const &x);
};