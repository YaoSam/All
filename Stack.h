#pragma once

#include <iostream>
#include <time.h>
#define TEMP template <class T>
#define re(i,n) for(unsigned int i=0;i<n;i++)
const int OriginSize = 10000;
TEMP
class stack//不能用于动态分配内存的元素。
{
	int top,size;
	T *data;
	void applyMem();
public: 
	stack() :top(-1),size(OriginSize),data(new T[size]){}
	stack(const stack<T>&other);
	stack<T>& operator=(const stack<T>& other);
	~stack(){ delete[] data; }
	void push(T const & x);
	T pop();
	void Empty()const{ top = -1; }
	T topData()const;//返回顶端元素
	int Top()const{ return top; }//返回栈大小
	bool isEmpty()const{ return top < 0; }
	T& operator[](unsigned int n);//用来遍历元素。没事就别用这个了。
	const T& operator[](unsigned int n)const;
	friend std::ostream& operator<<(std::ostream &out, stack<T> const & other)
	{
		re(i, unsigned(other.top))
			out << other.data[i] << " ";
		return out << std::endl;
	}
};
