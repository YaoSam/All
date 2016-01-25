#pragma once
#include <iostream>
#include <string>
#include "normal.h"
#undef  TEMP
#define TEMP template <class T>
#undef  re
#define re(i,n) for(unsigned int i=0;i<n;i++)
//只需要定义>

const int HeapSize = 100000;
TEMP
class MaxHeap
{
	//记录最后一个节点
	int Current;
	T *Heap;
	//向下调整i节点。
	void Down(int i);
	//向上调整节点
	void Up(int i);
public:
	//构造函数。通过不断向下跳着节点实现。
	MaxHeap(T const *data = NULL, unsigned int n = 0);
	//动态分配内存惯例要打以下三个函数。
	MaxHeap(MaxHeap<T> const & other) :Current(other.Current), Heap(new T[HeapSize])
	{
		memcpy(Heap, other.Heap, sizeof(T)*Current);
	}
	MaxHeap<T>& operator=(MaxHeap<T> const & other);
	~MaxHeap(){ delete[] Heap; }
	//插入
	void push(T const &X);
	//弹出节点。即删除
	T pop();
	bool isEmpty()const{ return Current < 0; }
	//用作输出堆的。
	friend std::ostream & operator<<(std::ostream& out, MaxHeap<T>const &other)
	{
		if (other.Current < 0)return out;
		unsigned int level = 0;
		re(i, other.Current + 1)
		{
			if (i == ((1 << level) - 1))
			{
				out << std::endl;
				level++;
			}
			out << other.Heap[i] << " ";
		}
		return out << std::endl;
	}
};
TEMP
void heapSort(T a[], unsigned int n);
