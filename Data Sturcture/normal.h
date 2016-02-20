#pragma once
#undef  re
#define re(i,n) for(unsigned int i=0;i<n;i++)
#define TEMP template<class T>

//要定义>和!=
TEMP bool operator<	(T const & a, T const &b);
TEMP bool operator>=	(T const & a, T const &b);
TEMP bool operator<=	(T const & a, T const &b);
TEMP bool operator!=	(T const & a, T const &b);

TEMP void Swap(T & a, T &b);

TEMP inline T Max(T const &a, T const &b);

TEMP void Qsort(T a[], int left, int right);
TEMP void Qsort_MaxToMin(T a[], int left, int right);