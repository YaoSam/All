#pragma once
#include <iostream>
#include <time.h>
#define TEMP template <class T>
#define re(i,n) for(unsigned int i=0;i<n;i++)
const int OriginQueueSize = 20;
TEMP class queue;
TEMP void Swap(queue<T> &a, queue<T>& b);
TEMP
class queue//�����ö�̬�����ڴ��Ԫ��
{
	unsigned int front, rear,size;//front��ָ�����ݣ�rearָ��λ�á�
	T *data;
	void ApplyMem();
public:
	queue() :front(0), rear(0),size(OriginQueueSize),data(new T[size]){}
	queue(const queue<T>&other);
	queue<T>& operator=(const queue<T>&other);
	~queue(){ delete[] data; }
	void push(T const &x);
	T pop();
	void clear(){ front = rear = 0; }
	bool isEmpty()const{ return front == rear; }
	TEMP friend void Swap(queue<T> &a, queue<T>& b);
};
