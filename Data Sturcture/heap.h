#pragma once
#include <iostream>
#include <string>
#include "normal.h"
#undef  TEMP
#define TEMP template <class T>
#undef  re
#define re(i,n) for(unsigned int i=0;i<n;i++)
//ֻ��Ҫ����>

const int OriginalHeapSize = 100;
TEMP
class MaxHeap
{
	//��¼���һ���ڵ�
	int Current;
	unsigned int size;
	T *Heap;
	//���µ���i�ڵ㡣
	void Down(int i);
	//���ϵ����ڵ�
	void Up(int i);
	void expend();//���������ɡ�
public:
	MaxHeap() :size(OriginalHeapSize), Heap(new T[size]), Current(-1){}
	//���캯����ͨ���������µ����ڵ�ʵ�֡�
	MaxHeap(T const *data, unsigned int n);
	//��̬�����ڴ����Ҫ����������������
	MaxHeap(MaxHeap<T> const & other) :
		Current(other.Current), 
		size(other.size),
		Heap(new T[size])
	{
		memcpy(Heap, other.Heap, sizeof(T)*(Current+1));
	}
	MaxHeap<T>& operator=(MaxHeap<T> const & other);
	~MaxHeap(){ delete[] Heap; }
	//����
	void push(T const &X);
	//�����ڵ㡣��ɾ��
	T pop();
	bool isEmpty()const{ return Current < 0; }
};
TEMP
void heapSort(T a[], unsigned int n);
