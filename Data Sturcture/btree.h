#pragma once
#include <iostream>
#include <time.h>
#include "Stack.h"
#include <math.h>
#define TEMP template <class T>
#define re(i,n) for(unsigned int i=0;i<n;i++)

TEMP class BTree;
TEMP class AVLTree ;
TEMP class BSTree;
TEMP class tree_iterator;
TEMP class PreOrder_iterator;
TEMP class InOrder_iterator;
TEMP class LevelOrder_iterator;
TEMP
class Tree
{
	friend class BTree < T > ;
	friend class BSTree < T > ;
	friend class AVLTree < T > ; 
	friend class tree_iterator < T > ;
	friend class PreOrder_iterator < T > ;
	friend class LevelOrder_iterator < T > ;
	friend class InOrder_iterator < T > ;
protected:
	T data;
	BTree<T> *right,*left,*parent;
	unsigned int height;
	unsigned int CheckHeight()//���¸߶�
	{
		return height = Max((left ? left->height : 0), (right ? right->height : 0)) + 1;
	}
public:
	~Tree() {};
	Tree() :height(0),parent(NULL),left(NULL), right(NULL){}
	Tree(T const &x,BTree<T>* P,int h=0) :data(x),height(h),parent(P),left(NULL), right(NULL){}
	unsigned int NodeNum()const;
	unsigned int Height()const{ return height; }
	void pre()const;//ǰ�����
	void mid()const;//�������
	void post()const;//�������
	void print()const;//��α������
	virtual Tree<T>* find(T const &x)const=0;//Ŀǰ�ǳ����������
};

TEMP
class BTree :public Tree < T >
{
public:
	void del();//�ؼ�����Ȼ�޷��ͷ��ڴ档
	void leftLink(BTree<T>* Left = NULL)
	{
		if (Left == this)
			throw "���Ӵ���ѭ�����ӣ�rightLink()";
		left = Left;
		if (Left)Left->parent = this;
	}
	void rightLink(BTree<T>* Right = NULL)
	{
		if (Right == this)
			throw "���Ӵ���ѭ�����ӣ�rightLink()";
		right = Right;
		if (Right)Right->parent = this;
		void del();//�����ͷ��ڴ�ġ���������
	}
	friend class BSTree < T > ;
	friend class AVLTree < T > ;
	friend class PreOrder_iterator<T>;
	friend class LevelOrder_iterator < T > ;
	friend class InOrder_iterator < T > ;
public:
	static T endFlag;//��ͨ����������ʱ��Ľ�������
	BTree() :Tree<T>(){}
	BTree(const T &x,BTree<T>* P=NULL,int h=1) :Tree<T>(x,P,h){}
	BTree(BTree<T> const & other);
	BTree<T>& operator=(BTree<T> const & other);
	virtual ~BTree();
	virtual Tree<T>* find(T const &x)const;//Ŀǰ�ǳ����������
	friend std::istream& operator>>(std::istream& in, BTree<T> &other)//ͨ��endFlag������
	{
		in >> other.data;
		if (other.data == endFlag) return in;
		else
		{
			other.left = new BTree < T > ;
			other.right = new BTree < T > ;
			std::cin >> (*other.left) >> (*other.right);
			other.left->parent = other.right->parent = &other;
			if ((*other.left).data == endFlag)
			{
				delete other.left;//����ײ㲢����Ӱ����ȡ�
				other.left = NULL;
			}
			if ((*other.right).data == endFlag)
			{
				delete other.right;
				other.right = NULL;
			}
		}
		other.CheckHeight();
		return in;
	}
};
