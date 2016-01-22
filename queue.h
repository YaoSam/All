#pragma once
#include <iostream>
#include <time.h>
#define TEMP template <class T>
#define re(i,n) for(int i=0;i<n;i++)
const int QueueSize = 10000;

TEMP
class queue
{
	unsigned int front, rear;
	T data[QueueSize];
public:
	queue() :front(0), rear(0){}
	void push(T const &x);
	T pop();
	bool isEmpty(){ return front == rear; }
	bool isFull(){ return (rear + 1) % QueueSize == front; }
};
