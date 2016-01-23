#pragma once
#include "btree.cpp"

TEMP
class bstree : public btree < T >
{
public:
	bstree(T const a[]=NULL,unsigned int n=0);
	bstree<T>* find(T const &x);
	~bstree();
};