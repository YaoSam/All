#pragma once
#include "normal.h"

TEMP bool operator<	(T const & a, T const &b)	{ return	b > a; }
TEMP bool operator>=	(T const & a, T const &b)	{ return	a > b || !(b > a); }
TEMP bool operator<=	(T const & a, T const &b)	{ return	!(a > b); }
TEMP bool operator!=	(T const & a, T const &b)	{ return	a > b || b > a; }
TEMP bool operator==	(T const & a, T const &b)	{ return	!(a > b) && !(b > a); }

TEMP void Swap(T & a, T &b)
{
	T temp = a; a = b; b = temp;
}


TEMP inline T Max(T const &a, T const &b)
{
	return a > b ? a : b;
}

TEMP
void Qsort(T a[], int left, int right)
{
	T mid = a[(left + right) / 2];
	int l = left, r = right;
	do
	{
		while (a[l] < mid)l++;
		while (a[r] > mid)r--;
		if (l <= r)
			Swap(a[l++], a[r--]);
	} while (l <= r);
	if (r > left)		Qsort(a, left, r);
	if (l < right)	Qsort(a, l, right);
	return;
}