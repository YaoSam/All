#pragma once
#include "btree.cpp"

TEMP
class Tree_iterator
{
protected:
	treeNode<T>* pCurrent, *m_root;
public:
	Tree_iterator(treeNode<T>* P, treeNode<T>* R) :pCurrent(P), m_root(R){}
	virtual ~Tree_iterator(){}
	virtual T operator*()const;
	virtual bool isEnd(){ return pCurrent == NULL; }
	virtual treeNode<T>* operator()()const{ return pCurrent; }
	virtual void goFirst()=0;
	virtual treeNode<T>* operator++()=0;
};

TEMP
class Preorder_iterator :public Tree_iterator < T >
{
	stack<treeNode<T>*> Stack;
public:
	Preorder_iterator(NormalTree<T> *tree) :Tree_iterator(tree->root, tree->root){}
	void goFirst(){ pCurrent = m_root; Stack.clear(); }
	treeNode<T>* operator++();
};

TEMP 
class Inorder_iterator :public Tree_iterator < T >
{
	stack<treeNode<T>*> Stack;
public:
	Inorder_iterator(NormalTree<T>* tree);
	void goFirst();
	treeNode<T>* operator++();
	bool isEnd(){ return Stack.isEmpty(); }
	T operator*()const;
	treeNode<T>* operator()()const;
};

TEMP 
class Levelorder_iterator :public Tree_iterator < T >
{
	queue<treeNode<T>*> Queue;
public:
	Levelorder_iterator(NormalTree<T>* tree) :Tree_iterator(tree->root, tree->root){}
	void goFirst()
	{
		pCurrent = m_root;
		Queue.clear(); 
	}
	bool isEnd()
	{
		return pCurrent->left==NULL&&
				pCurrent->right==NULL&&
				Queue.isEmpty();
	}
	treeNode<T>* operator++();
};