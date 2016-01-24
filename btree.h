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
	unsigned int CheckHeight()//���¸߶�
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
	virtual void pre()const=0;//ǰ�����
	virtual void mid()const=0;//�������
	virtual void back()const=0;//�������
	virtual void print()const=0;//��α������
	virtual BTree<T>* find(T const &x)const=0;//Ŀǰ�ǳ����������
};

TEMP
class BTree :public Tree < T >
{
	void del();
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
public:
	static T endFlag;//��ͨ����������ʱ��Ľ�������
	BTree(const T &x) :Tree(x){}
	BTree(BTree<T> const & other, BTree<T>* P = NULL);
	BTree<T>& operator=(BTree<T> const & other);
	BTree() :Tree(){}
	virtual ~BTree();
	void pre()const;//ǰ�����
	void mid()const;//�������
	void back()const;//�������
	void print()const;//��α������
	BTree<T>* find(T const &x)const;//Ŀǰ�ǳ����������
	Tree<T>* insert(T const &x);
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