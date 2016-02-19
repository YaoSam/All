#pragma once

#undef TEMP
#define TEMP template<class T>


TEMP bool operator<	(T const & a, T const &b);
TEMP bool operator>=	(T const & a, T const &b);
TEMP bool operator<=	(T const & a, T const &b);
TEMP bool operator!=	(T const & a, T const &b);
TEMP bool operator==	(T const & a, T const &b);

TEMP void Swap(T & a, T &b);

TEMP inline T Max(T const &a, T const &b);

TEMP void Qsort(T a[], int left, int right);
TEMP void Qsort_MaxToMin(T a[], int left, int right);