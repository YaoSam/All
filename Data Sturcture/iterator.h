#pragma once
#include "btree.cpp"

TEMP
class tree_iterator//抽象基类
{
protected:
	Tree<T>* Pcurrent;
	Tree<T>* root;
	friend class Tree < T > ;
	friend class PreOrder_iterator < T > ;
	friend class InOrder_iterator < T > ;
	friend class LevelOrder_iterator < T > ;
public:
	tree_iterator(Tree<T>* r) :
		root(r),
		Pcurrent(r)
	{}
	tree_iterator(const tree_iterator & other) :
		Pcurrent(other.Pcurrent),
		root(other.root)
	{}
	~tree_iterator(){}
	virtual T operator*()const;
	virtual Tree<T>* operator()()const;
	virtual void gotoFirst()
	{
		Pcurrent = root;
	}
	virtual bool isEnd(){ return Pcurrent == NULL; }
	virtual tree_iterator<T>& operator++() = 0;
};
TEMP
class PreOrder_iterator :public tree_iterator < T >
{
	stack<Tree<T>*> Stack;
public:
	PreOrder_iterator(Tree<T> *Pone) :tree_iterator<T>(Pone){}
	PreOrder_iterator(const tree_iterator<T>& other) :
		tree_iterator<T>(other.root, other.Pcurrent),
		Stack(other.Stack)
	{}
	virtual tree_iterator<T>&  operator++();
};

TEMP
class InOrder_iterator :public tree_iterator < T >
{
	stack<Tree<T>*> Stack;
public:
	InOrder_iterator(Tree<T>* P);//在最左边开始。
	InOrder_iterator(const tree_iterator< T >& other) :
		tree_iterator<T>(other.root, other.Pcurrent),
		Stack(other.Stack){}
	virtual T operator*()const;
	virtual Tree<T>* operator()()const;
	virtual void gotoFirst();
	virtual bool isEnd(){ return Stack.isEmpty(); }
	virtual tree_iterator<T>&operator++();
};

TEMP 
class LevelOrder_iterator :public tree_iterator < T >
{
	queue<Tree<T>*> Queue;
public:
	LevelOrder_iterator(Tree<T>* P) :tree_iterator<T>(P){}
	LevelOrder_iterator(const tree_iterator<T>&other):
		tree_iterator<T>(other.root,other.Pcurrent),
		Queue(other.Queue){}
	void gotoFirst(){ Pcurrent = root; Queue.clear(); }
	tree_iterator<T>& operator++();
};


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