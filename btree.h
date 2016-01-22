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
public:
	static T endFlag;
	btree() :nodeNum(0),left(NULL), right(NULL){}
	btree(T const &x) :data(x),nodeNum(1),left(NULL), right(NULL){}
	btree(btree<T> const & other);
	~btree();
	unsigned int Height()const;
	unsigned int NodeNum()const;
	void pre()const;
	void mid()const;
	void back()const;
	void print()const;
	void insert(T const &x);
	friend std::istream& operator>>(std::istream& in, btree<T> &other)
	{
		//TODO
		in >> other.data;
		if (other.data == endFlag) return in;
		else
		{
			other.left = new btree< T > ;
			other.right = new btree < T > ;
			in >> (*other.left) >> (*other.right);
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
		return in;
	}
};
