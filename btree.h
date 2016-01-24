#pragma once
#include <iostream>
#include <time.h>
#include <math.h>
#define TEMP template <class T>
#define re(i,n) for(unsigned int i=0;i<n;i++)
TEMP class AVLTree ;
TEMP class BSTree;
TEMP
class Tree
{
protected: 
	T data;
	Tree<T> *right,*left,*parent;
	unsigned int height;
	unsigned int CheckHeight()//更新高度
	{
		return height = Max((left ? left->height : 0), (right ? right->height : 0)) + 1;
	}
	//下面为平衡二叉树要用的插入操作
	friend class BSTree<T> ;
	friend class AVLTree<T>;
	void del();
	unsigned int Height_()const//递归计算高度。
	{
		return Max(left ? left->Hei() : 0, right ? right->Hei() : 0) + 1;
	}
	void deleteNode();
	void leftLink(Tree<T>* Left = NULL)
	{
		if (Left == this)
			throw "链接错误！循环连接！rightLink()";
		left = Left;
		if (Left)Left->parent = this;
	}
	void rightLink(Tree<T>* Right = NULL)
	{
		if (Right == this)
			throw "链接错误！循环连接！rightLink()";
		right = Right;
		if (Right)Right->parent = this;
	}
public:
	static T endFlag;//普通二叉树输入时候的结束符。
	Tree() :height(0),parent(NULL),left(NULL), right(NULL){}
	Tree(T const &x,Tree<T> *P=NULL) :data(x),parent(P),height(1),left(NULL), right(NULL){}
	Tree(Tree<T> const & other,Tree<T>* P=NULL);
	virtual ~Tree();
	Tree<T>& operator=(Tree<T> const & other);
	unsigned int NodeNum()const;
	unsigned int Height()const{ return height; }
	void pre()const;//前序输出
	void mid()const;//中序输出
	void back()const;//后序输出
	void print()const;//层次遍历输出
	Tree<T>* find(T const &x)const;//目前是程序遍历查找
	friend std::istream& operator>>(std::istream& in, Tree<T> &other)//通过endFlag来输入
	{
		in >> other.data;
		if (other.data == endFlag) return in;
		else
		{
			other.left = new Tree < T > ;
			other.right = new Tree < T > ;
			in >> (*other.left) >> (*other.right);
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
