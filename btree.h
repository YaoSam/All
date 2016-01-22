#pragma once
#include <iostream>
#include <time.h>
#define TEMP template <class T>
#define re(i,n) for(unsigned int i=0;i<n;i++)

TEMP
class btree
{
	T data;
	btree<T> *left, *right;
	void del();
public:
	static T endFlag;
	btree() :left(NULL), right(NULL){}
	btree(btree<T> const & other);
	~btree();
	void pre()const;
	void mid()const;
	void back()const;
	void print()const;
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