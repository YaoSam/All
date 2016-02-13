#pragma once
#include "heap.h"
#undef  re
#define re(i,n) for(unsigned int i=0;i<n;i++)

TEMP void MaxHeap<T>::Down(int i)
{
	int next = 2 * i + 1;
	while (next <= Current)
	{
		//不断向下跟较大的节点交换。
		if (next + 1 <= Current&&Heap[next] < Heap[next + 1])
			next++;
		if (Heap[next] > Heap[i])
			Swap(Heap[next], Heap[i]);
		else break;
		i = next;
		next = next * 2 + 1;
	}
	return;
}

TEMP void MaxHeap<T>::Up(int i)
{
	if (i > Current)	throw "越界";
	while (i != 0 && Heap[(i - 1) >> 1] < Heap[i])
	{
		//(i-1)/2代表其父亲节点。
		Swap(Heap[(i - 1) >> 1], Heap[i]);
		//不断向上回溯放到合适位置。
		i = (i - 1) >> 1;
	}
}

TEMP MaxHeap<T>::MaxHeap(T const *data = NULL, unsigned int n = 0) :Current(n - 1), Heap(new T[HeapSize])
{
	memcpy(Heap, data, n*sizeof(T));
	re(i, n / 2 + 2) //从0 到 n/2+1
		Down(n / 2 + 1 - i); //从n/2+1 到 0
}

TEMP MaxHeap<T>& MaxHeap<T>::operator=(MaxHeap<T> const & other)
{
	if (this == &other)return *this;
	delete[] Heap;
	Heap = new T[HeapSize];
	memcpy(Heap, other.Heap, sizeof(T)*(Current+1));
	return *this;
}

TEMP void MaxHeap<T>::push(T const &X)
{
	if (Current >= HeapSize - 1)	throw "堆溢出。";
	//直接放在底部。
	Heap[++Current] = X;
	//向上维护堆。
	Up(Current);
}

TEMP T MaxHeap<T>::pop()
{
	if (Current == -1)	throw"Empty";
	//弹出堆顶
	T ans = Heap[0];
	//取最后一个元素放在堆顶
	Heap[0] = Heap[Current--];
	//向下维护堆
	Down(0);
	return ans;
}

//堆排序，随便打一下而已。堆建好了就两行的事。
TEMP void heapSort(T *a, unsigned int n)
{
	MaxHeap<T> one(a, n);
	re(i, n)a[i] = one.pop();
	return;
}
