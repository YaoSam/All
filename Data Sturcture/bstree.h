#pragma once
#include "btree.cpp"



TEMP
class BStree :public NormalTree < T >
{
protected:
	treeNode<T>* FindRightNext(const treeNode<T>* a)const;
	treeNode<T>* FindLeftNext(const treeNode<T>* a)const;
	void deleteLeave(treeNode<T>* other);
public:
	virtual void insert(T const & x);
	BStree(T const a[] = NULL, unsigned int n = 0);
	virtual ~BStree(){}
	treeNode<T>* find(T const &x)const;
	void DelNode(T const &x);
	//void erase(T const & x);
};