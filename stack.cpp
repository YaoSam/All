#pragma once
#include "Stack.h"

TEMP
T stack<T>::pop()
{
	if (top < 0)
		throw "Empty stack£¬failed stack.pop()";
	return data[top--];
}

TEMP
void stack<T>::push(T const & x)
{
	if (top >= StackSize)
		throw "stack overflow£¬failed stack.push()";
	data[++top] = x;
}

TEMP 
T& stack<T>::operator[](unsigned int n)
{
	if (int(n) > top)
		throw "Subscript out of range£¬faile stack.push()";
	return data[n];
}
TEMP
const T& stack<T>::operator[](unsigned int n)const
{
	if (int(n) > top)
		throw "Subscript out of range£¬faile stack.push()";
	return data[n];
}
