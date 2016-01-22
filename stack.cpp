#pragma once
#include "Stack.h"

TEMP
T stack<T>::pop()
{
	if (top < 0)
		throw "ջΪ�գ�popʧ��";
	return data[top--];
}

TEMP
void stack<T>::push(T const & x)
{
	if (top >= StackSize)
		throw "ջ�����pushʧ��";
	data[++top] = x;
}

TEMP 
T& stack<T>::operator[](unsigned int n)
{
	if (int(n) > top)
		throw "��ȡԽ�磬[]ʧ��";
	return data[n];
}
TEMP
const T& stack<T>::operator[](unsigned int n)const
{
	if (int(n) > top)
		throw "��ȡԽ�磬[]ʧ��";
	return data[n];
}

void TestOfStack()
{
	srand(unsigned(time(NULL)));
	stack<int> a, b;
	unsigned int n = 100;
	re(i, n)
		a.push(rand() % 1000);
	std::cout << a;
	while (!a.isEmpty())
		b.push(a.pop());
	re(i, n)
		std::cout << b.pop() << " ";
}
