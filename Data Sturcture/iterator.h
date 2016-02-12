#pragma once
#include "btree.cpp"

TEMP
class m_iterator
{
protected:
	treeNode<T>* pCurrent, *m_root;
public:
	m_iterator(treeNode<T>* P, treeNode<T>* R) :pCurrent(P), m_root(R){}
	virtual ~m_iterator(){}
	virtual T operator*()const;
	virtual bool isEnd(){ return pCurrent == NULL; }
	virtual treeNode<T>* operator()()const{ return pCurrent; }
	virtual void goFirst()=0;
	virtual treeNode<T>* operator++()=0;
};

TEMP
class Pre_iterator :public m_iterator < T >
{
	stack<treeNode<T>*> Stack;
public:
	Pre_iterator(NormalTree<T> *tree) :m_iterator(tree->root, tree->root){}
	void goFirst(){ pCurrent = m_root; Stack.clear(); }
	treeNode<T>* operator++();
};

TEMP 
class Mid_iterator :public m_iterator < T >
{
	stack<treeNode<T>*> Stack;
public:
	Mid_iterator(NormalTree<T>* tree);
	void goFirst();
	treeNode<T>* operator++();
	bool isEnd(){ return Stack.isEmpty(); }
	T operator*()const;
	treeNode<T>* operator()()const;
};

TEMP 
class Level_iterator :public m_iterator < T >
{
	queue<treeNode<T>*> Queue;
public:
	Level_iterator(NormalTree<T>* tree) :m_iterator(tree->root, tree->root){}
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