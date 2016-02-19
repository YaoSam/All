#pragma once
#include <iostream>
#include <string>
#include "normal.h"
#undef  TEMP
#define TEMP template <class T>
#undef  re
#define re(i,n) for(unsigned int i=0;i<n;i++)
//只需要定义>

const int OriginalHeapSize = 100;
TEMP
class MaxHeap
{
	//记录最后一个节点
	int Current;
	unsigned int size;
	T *Heap;
	//向下调整i节点。
	void Down(int i);
	//向上调整节点
	void Up(int i);
	void expend();//扩大两倍吧。
public:
	MaxHeap() :size(OriginalHeapSize), Heap(new T[size]), Current(-1){}
	//构造函数。通过不断向下调整节点实现。
	MaxHeap(T const *data, unsigned int n);
	//动态分配内存惯例要打以下三个函数。
	MaxHeap(MaxHeap<T> const & other) :
		Current(other.Current), 
		size(other.size),
		Heap(new T[size])
	{
		memcpy(Heap, other.Heap, sizeof(T)*(Current+1));
	}
	MaxHeap<T>& operator=(MaxHeap<T> const & other);
	~MaxHeap(){ delete[] Heap; }
	//插入
	void push(T const &X);
	//弹出节点。即删除
	T pop();
	bool isEmpty()const{ return Current < 0; }
};
TEMP
void heapSort(T a[], unsigned int n);
