#pragma once

#include <iostream>
#include <time.h>
#define TEMP template <class T>
#define re(i,n) for(unsigned int i=0;i<n;i++)
const int StackSize = 10000;
TEMP
class stack
{
	int top;
	T data[StackSize];
public: 
	stack() :top(-1){}
	void push(T const & x);
	T pop();
	bool isEmpty()const{ return top < 0; }
	T& operator[](unsigned int n);
	const T& operator[](unsigned int n)const;
	friend std::ostream& operator<<(std::ostream &out, stack<T> const & other)
	{
		re(i, unsigned(other.top))
			out << other.data[i] << " ";
		return out << std::endl;
	}
};


