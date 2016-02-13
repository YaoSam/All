#pragma once
#include <iostream>
#include <time.h>
#include "Stack.cpp"
#include <math.h>
#define re(i,n) for(unsigned int i=0;i<n;i++)


TEMP class NormalTree;
TEMP class bstree;
TEMP class AVLtree;
TEMP class m_iterator;
TEMP class Pre_iterator;
TEMP class Mid_iterator;
TEMP class Level_iterator;
TEMP class Post_iterator;
class SegmentTree;
TEMP
class treeNode
{
	friend class NormalTree < T > ;
	friend class bstree < T > ;
	friend class AVLtree < T > ;
	friend class m_iterator < T > ;
	friend class Pre_iterator < T > ;
	friend class Mid_iterator < T > ;
	friend class Level_iterator < T > ;
	friend class Post_iterator < T > ;
	friend class SegmentTree;
protected:
	T data;
	unsigned int height;
	treeNode<T>* left, *right,*parent;
	unsigned int CheckHeight()//更新高度
	{
		return height = Max((left ? left->height : 0), (right ? right->height : 0)) + 1;
	}
	void leftlink(treeNode<T>* other);
	void rightlink(treeNode<T>* other);
	void Copy(treeNode<T>*& root,treeNode<T>* const other,treeNode<T>* P=NULL);
	void Del();
public:
	treeNode<T>(T const &x, unsigned int h = 0,treeNode<T>*p = NULL, treeNode<T>* l = NULL, treeNode<T>* r = NULL ) :
		data(x),height(h),left(l),right(r),parent(p){}
};

TEMP
class NormalTree//这东西用来继承吧！
{
	friend class bstree < T > ;
	friend class AVLtree < T > ;
	friend class m_iterator < T > ;
	friend class Pre_iterator < T > ;
	friend class Mid_iterator < T > ;
	friend class Level_iterator < T > ;
	friend class Post_iterator < T > ;
protected:
	treeNode<T>* root;
public:
	NormalTree(T const & x) :root(new treeNode<T>(x, 1)){}
	NormalTree(treeNode<T>* r = NULL) :root(r){}
	NormalTree(NormalTree<T> const & other);
	NormalTree<T>& operator=(NormalTree<T> const & other);
	virtual ~NormalTree();
	unsigned int height(){ return root->height; }
	unsigned int NodeNum()const;
	void pre()const;
	void mid()const;
	void post()const;
	void print()const;
	virtual treeNode<T>* find(T const & x)const;
	virtual void insert(T const & x) = 0;
};
