#pragma once
#include "heap.h"
#undef  re
#define re(i,n) for(unsigned int i=0;i<n;i++)

TEMP void Heap<T>::Down(int i)
{
	int next = 2 * i + 1;
	while (next <= Current)
	{
		//�������¸��ϴ�Ľڵ㽻����
		if (next + 1 <= Current&&compare(Data[next], Data[next + 1]))
			next++;
		if (!compare(Data[next], Data[i]))
			Swap(Data[next], Data[i]);
		else break;
		i = next;
		next = next * 2 + 1;
	}
	return;
}

TEMP void Heap<T>::Up(int i)
{
	if (i > Current)	throw "Խ��";
	while (i != 0 && compare(Data[(i - 1) >> 1], Data[i]))
	{
		//(i-1)/2�����丸�׽ڵ㡣
		Swap(Data[(i - 1) >> 1], Data[i]);
		//�������ϻ��ݷŵ�����λ�á�
		i = (i - 1) >> 1;
	}
}

TEMP void Heap<T>::expend()
{
	size *= 2;
	T* temp = new T[size];
	memcpy(temp, Data, (Current + 1)*sizeof(T));
	delete Data;
	Data = temp;
}

TEMP Heap<T>::Heap(T const *data, unsigned int n, bool(*cmp)(T const & a, T const &b)) :
Current(n - 1),
size(n),
Data(new T[size]),
compare(cmp)
{
	memcpy(Data, data, n*sizeof(T));
	re(i, n / 2 + 2) //��0 �� n/2+1
		Down(n / 2 + 1 - i); //��n/2+1 �� 0
}

TEMP Heap<T>& Heap<T>::operator=(Heap<T> const & other)
{
	if (this == &other)return *this;
	delete[] Data;
	size = other.size;
	Data = new T[other.size];
	Current = other.Current;
	memcpy(Data, other.Data, sizeof(T)*(Current+1));
	return *this;
}

TEMP void Swap(Heap<T>* a, Heap<T>* b)
{
	Swap(a->Current, b->Current);
	Swap(a->compare, b->compare);
	Swap(a->size, b->size);
	Swap(a->Data, b->Data);
	return;
}

TEMP void Heap<T>::push(T const &X)
{
	if (Current >= int(size - 1))
		expend();
	//ֱ�ӷ��ڵײ���
	Data[++Current] = X;
	//����ά���ѡ�
	Up(Current);
}

TEMP T Heap<T>::pop()
{
	if (Current == -1)	throw"��Ϊ�ա����ܵ�����";
	//�����Ѷ�
	T ans = Data[0];
	//ȡ���һ��Ԫ�ط��ڶѶ�
	Data[0] = Data[Current--];
	//����ά����
	Down(0);
	return ans;
}

//////////////////////////////////////////////////////////////////////////
TEMP MaxHeap<T>::MaxHeap(T const *data, unsigned int n) :Heap<T>(data, n, MaxHeapCmp) {}
TEMP MinHeap<T>::MinHeap(T const *data, unsigned int n) : Heap<T>(data, n, MinHeapCmp) {}
TEMP MaxHeap<T>::MaxHeap(MaxHeap<T> const & other) :Heap<T>(other){}
TEMP MinHeap<T>::MinHeap(MinHeap<T> const & other) : Heap<T>(other){}
TEMP MaxHeap<T>& MaxHeap<T>::operator=(MaxHeap<T> const & other){
	Heap<T>::operator =(other);
	return *this;
}
TEMP MinHeap<T>& MinHeap<T>::operator=(MinHeap<T> const & other){
	Heap<T>::operator =(other);
	return *this;
}
//����������һ�¶��ѡ��ѽ����˾����е��¡��Ӵ�С
TEMP void heapSort(T *a, unsigned int n)
{
	MaxHeap<T> one(a, n);
	re(i, n)a[i] = one.pop();
	return;
}
