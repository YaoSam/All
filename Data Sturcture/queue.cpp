#pragma once
#include "queue.h"

TEMP 
void queue<T>::push(T const &x)
{
	if ((rear+1)%QueueSize == front)//ֻ������һ��λ���ˡ�
		throw "Subscript out of range��failed queue.push()";
	data[rear] = x;
	rear = (rear + 1) % QueueSize;
}

TEMP 
T queue<T>::pop()
{
	if (front == rear)
		throw "Empty Queue, failed queue.pop()";
	int tempfront = front;
	front = (front + 1) % QueueSize;
	return data[tempfront];
}