#pragma once
#include <iostream>
#include <time.h>
#define TEMP template <class T>
#define re(i,n) for(unsigned int i=0;i<n;i++)

TEMP
class btree
{
protected:
	T data;
	btree<T> *left, *right;
	unsigned int nodeNum;
	void del();
	unsigned int height;
public:
	static T endFlag;
	btree() :nodeNum(0),height(0),left(NULL), right(NULL){}
	btree(T const &x) :data(x),height(1),nodeNum(1),left(NULL), right(NULL){}
	btree(btree<T> const & other);
	~btree();
	unsigned int Height()const{ return height; }
	unsigned int NodeNum()const{ return nodeNum; }
	void pre()const;
	void mid()const;
	void back()const;
	void print()const;
	virtual void insert(T const &x);
	friend std::istream& operator>>(std::istream& in, btree<T> &other)
	{
		//TODO
		int leftH = 0, rightH = 0;
		in >> other.data;
		other.height++;
		if (other.data == endFlag) return in;
		else
		{
			other.left = new btree < T > ;
			other.right = new btree < T > ;
			in >> (*other.left) >> (*other.right);
			leftH = other.left->height; rightH = other.right->height;
			if ((*other.left).data == endFlag)
			{
				delete other.left;
				other.left = NULL;
				leftH = 0;
			}
			if ((*other.right).data == endFlag)
			{
				delete other.right;
				other.right = NULL;
				rightH = 0;
			}
		}
		other.nodeNum = (other.left ? other.left->nodeNum : 0) + (other.right ? other.right->nodeNum : 0) + 1;
		other.height += (leftH > rightH ? leftH : rightH);
		return in;
	}
};
