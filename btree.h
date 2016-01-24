#pragma once
#include <iostream>
#include <time.h>
#include <math.h>
#define TEMP template <class T>
#define re(i,n) for(unsigned int i=0;i<n;i++)

TEMP class BTree;
TEMP class AVLTree ;
TEMP class BSTree;

TEMP
class Tree
{
protected: 
	T data;
	BTree<T> *right,*left,*parent;
	unsigned int height;
	unsigned int CheckHeight()//更新高度
	{
		return height = Max((left ? left->height : 0), (right ? right->height : 0)) + 1;
	}
	void deleteNode();
	friend class BTree<T> ;
	friend class BSTree<T> ;
	friend class AVLTree<T>;
public:
	//virtual ~Tree()=0;
	Tree() :height(0),parent(NULL),left(NULL), right(NULL){}
	Tree(T const &x,BTree<T> *P=NULL) :data(x),parent(P),height(1),left(NULL), right(NULL){}
	unsigned int NodeNum()const;
	unsigned int Height()const{ return height; }
	virtual void pre()const=0;//前序输出
	virtual void mid()const=0;//中序输出
	virtual void back()const=0;//后序输出
	virtual void print()const=0;//层次遍历输出
	virtual BTree<T>* find(T const &x)const=0;//目前是程序遍历查找
};

TEMP
class BTree :public Tree < T >
{
	void del();
	void leftLink(BTree<T>* Left = NULL)
	{
		if (Left == this)
			throw "链接错误！循环连接！rightLink()";
		left = Left;
		if (Left)Left->parent = this;
	}
	void rightLink(BTree<T>* Right = NULL)
	{
		if (Right == this)
			throw "链接错误！循环连接！rightLink()";
		right = Right;
		if (Right)Right->parent = this;
		void del();//用来释放内存的……唉……
	}
	friend class BSTree < T > ;
	friend class AVLTree < T > ;
public:
	static T endFlag;//普通二叉树输入时候的结束符。
	BTree(const T &x) :Tree(x){}
	BTree(BTree<T> const & other, BTree<T>* P = NULL);
	BTree<T>& operator=(BTree<T> const & other);
	BTree() :Tree(){}
	virtual ~BTree();
	void pre()const;//前序输出
	void mid()const;//中序输出
	void back()const;//后序输出
	void print()const;//层次遍历输出
	BTree<T>* find(T const &x)const;//目前是程序遍历查找
	Tree<T>* insert(T const &x);
	friend std::istream& operator>>(std::istream& in, BTree<T> &other)//通过endFlag来输入
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
				delete other.left;
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