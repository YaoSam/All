#pragma once
#include "heap.h"
#undef  re
#define re(i,n) for(unsigned int i=0;i<n;i++)

TEMP void MaxHeap<T>::Down(int i)
{
	int next = 2 * i + 1;
	while (next <= Current)
	{
		//�������¸��ϴ�Ľڵ㽻����
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
	if (i > Current)	throw "Խ��";
	while (i != 0 && Heap[(i - 1) >> 1] < Heap[i])
	{
		//(i-1)/2�����丸�׽ڵ㡣
		Swap(Heap[(i - 1) >> 1], Heap[i]);
		//�������ϻ��ݷŵ�����λ�á�
		i = (i - 1) >> 1;
	}
}

TEMP MaxHeap<T>::MaxHeap(T const *data = NULL, unsigned int n = 0) :Current(n - 1), Heap(new T[HeapSize])
{
	memcpy(Heap, data, n*sizeof(T));
	re(i, n / 2 + 2) //��0 �� n/2+1
		Down(n / 2 + 1 - i); //��n/2+1 �� 0
}

TEMP MaxHeap<T>& MaxHeap<T>::operator=(MaxHeap<T> const & other)
{
	if (this == &other)return *this;
	delete[] Heap;
	Heap = new T[HeapSize];
	memcpy(Heap, other.Heap, sizeof(T)*Current);
	return *this;
}

TEMP void MaxHeap<T>::push(T const &X)
{
	if (Current >= HeapSize - 1)	throw "�������";
	//ֱ�ӷ��ڵײ���
	Heap[++Current] = X;
	//����ά���ѡ�
	Up(Current);
}

TEMP T MaxHeap<T>::pop()
{
	if (Current == -1)	throw"Empty";
	//�����Ѷ�
	T ans = Heap[0];
	//ȡ���һ��Ԫ�ط��ڶѶ�
	Heap[0] = Heap[Current--];
	//����ά����
	Down(0);
	return ans;
}

//����������һ�¶��ѡ��ѽ����˾����е��¡�
TEMP void heapSort(T *a, unsigned int n)
{
	MaxHeap<T> one(a, n);
	re(i, n)a[i] = one.pop();
	return;
}