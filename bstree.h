#pragma once
#include "btree.cpp"

TEMP
class bstree : public btree < T >
{
public:
	void insert(T const &x);
	bstree(T const a[]=NULL,unsigned int n=0);
	~bstree();
	btree<T>* find(T const &x);
};