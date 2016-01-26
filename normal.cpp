#pragma once
#include "normal.h"



long long Fibonacci(int n)
{
	if (FIB[n] > 0) return FIB[n];
	return FIB[n] = (n == 1 || n == 0) ? n : Fibonacci(n - 1) + Fibonacci(n - 2);
}

int minHeight_bbtree(int n)
{
	int i = 0;
	for (; n > 0; i++)
		n -= (1 << i);
	return i;
}
int maxHeight_bbtree(int n)
{
	int height = 0;
	while ((Fibonacci(height + 2) - 1) < n)	height++;
	return height;
}
