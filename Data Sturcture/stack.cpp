#pragma once
#include "Stack.h"

TEMP 
void stack<T>::applyMem()
{
	size *= 2;
	T *temp = new T[size];
	//re(i, top + 1)
		//temp[i] = data[i];
	memcpy(temp, data, sizeof(T)*(top+1));
	delete [] data;
	data = temp;
	return;
}

TEMP
stack<T>::stack(const stack<T>&other):
top(other.top),
size(other.size),
data(new T[other.size])
{
	//re(i, other.top+1) //��ʱ�Ȳ����Ƕ�̬�����ڴ�������ˡ�
		//data[i] = other.data[i];
	memcpy(data, other.data, sizeof(T)*other.top);
}

TEMP
stack<T>& stack<T>::operator=(const stack<T>& other)
{
	if (this == &other)return *this;
	delete[] data;
	top = other.top;
	size = other.size;
	data = new T[other.size];
	//re(i, other.top+1)
		//data[i] = other.data[i];
	memcpy(data, other.data, sizeof(T)*other.top);
	return *this;
}

TEMP
T stack<T>::pop()
{
	if (top < 0)
		throw "Empty stack��failed stack.pop()";
	return data[top--];
}

TEMP
void stack<T>::push(T const & x)
{
	if (top == size-1)
		applyMem();
	data[++top] = x;
}

TEMP 
T stack<T>::topData()const
{
	if (top < 0)
		throw "Empty stack��failed stack.topData()";
	return data[top];
}
TEMP 
T& stack<T>::operator[](unsigned int n)
{
	if (n > top)
		throw "Subscript out of range��faile stack.push()";
	return data[n];
}
TEMP
const T& stack<T>::operator[](unsigned int n)const
{
	if (n > top)
		throw "Subscript out of range��faile stack.push()";
	return data[n];
}
