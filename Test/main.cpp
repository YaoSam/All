/*
*������������������������������+ +
*�������������������ߩ��������ߩ� + +
*�������������������������������� ��
*�������������������������������� ++ + + +
*������������ ������������������ ��+
*�������������������������������� +
*�����������������������ߡ�������
*�������������������������������� + +
*��������������������������������
*��������������������������������������������������
*���������������������������� + + + +
*������������������������������������Code is far away from bug with the animal protecting��������������
*���������������������������� + �����������ޱ���,������bug����
*����������������������������
*��������������������������������+������������������
*���������������������� �������������� + +
*�������������������� ���������������ǩ�
*�������������������� ������������������
*�����������������������������ש����� + + + +
*�����������������������ϩϡ����ϩ�
*�����������������������ߩ������ߩ�+ + + +
*/
#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>
#include "../Data Sturcture/normal.cpp"
#include "../Data Sturcture/normal2.h"
#include "../Data Sturcture/heap.cpp"
#include <math.h>

using namespace std;
#undef re
#define re(i,n) for(unsigned int i=0;i<n;i++)
#define DEBUG

const int MaxSize = 10000;

int Partition(int a[], int p, int r)         //һ�λ���
{
	int i = p, j = r + 1;
	int x = a[p];
	while (true)
	{
		while (a[++i]<x && i<r);   //��>=x��Ԫ�ؽ������ұ�����
		while (a[--j]>x);         //��<=x��Ԫ�ؽ������������
		if (i >= j) break;
		Swap(a[i], a[j]);
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}

int Partition(int a[], int p, int r, int x)    //����ֵx����
{
	int i = p;
	while (a[i] != x) i++;
	Swap(a[p], a[i]);
	int j = Partition(a, p, r);
	return j;
}

void QuickSort(int a[], int p, int r)          //��������
{
	if (p<r)
	{
		int q = Partition(a, p, r);
		QuickSort(a, p, q - 1);
		QuickSort(a, q + 1, r);
	}
}

int Select(int a[], int p, int r, int k)
{
	if (r - p<75)
	{
		QuickSort(a, p, r);
		return a[p + k - 1];
	}
	for (int i = 0; i <= (r - p - 4) / 5; i++)
	{
		QuickSort(a, p + 5 * i, p + 5 * i + 4);
		Swap(a[p + 5 * i + 2], a[p + i]);
	}
	int x = Select(a, p, p + (r - p - 4) / 5, (r - p + 1) / 10 + 1);
	int i = Partition(a, p, r, x);
	int m = i;
	for (int j = p; j<i; j++)           //������x��Ԫ�ؼ��е�i��m
		if (a[j] == x)
		{
			Swap(a[--i], a[j]);
			j--;
		}
	for (int j = r; j>m; j--)
		if (a[j] == x)
		{
			Swap(a[++m], a[j]);
			j++;
		}
	if (k - 1 + p<i) return Select(a, p, i - 1, k);       //����kλ��iǰʱ
	else if (k - 1 + p >= i && k - 1 + p <= m) return a[i];  //����kλ��i��mʱ������a[i]
	else return Select(a, m + 1, r, k - 1 + p - m);       //����kλ��m��ʱ
}

int random(int m)                              //����0--m������
{
	return rand() % m + 1;
}

int test(int n, int m)      //���Թ�ģn,��������ɷ�Χ0--m  
{
	int a[MaxSize];
	for (int i = 0; i<n; i++)
		a[i] = random(m);   //������ɼ�������
	int b[MaxSize];
	for (int i = 0; i<n; i++)
		b[i] = a[i];
	QuickSort(b, 0, n - 1);                    //��a��copy�������Լ���Select
	int x;
	for (int k = 1; k <= n; k++)
	{
		x = Select(a, 0, n - 1, k);
		cout << x << ' ';
		if (x != b[k - 1])
		{
			cout << "���鲻��ȷ" << endl;
			return 0;                     //��Selectѡ�еĵ�k�����������ĵ�k��������ȣ���Select��������ȷ
		}
	}
	cout << "������ȷ" << endl;               //��Selectѡ�еĵ�k�����������ĵ�k��������ȣ���Select������ȷ
	return 1;
}

TEMP
T Select(T a[],int size,int k)
{
	MinHeap<T> one(a, size);
	re(i, k - 1)
		one.pop();
	return one.pop();
}

struct point
{
	float x, y;
	static point point1, point2;
	bool flag;
	float dis(const point &a, const point &b)const
	{
		float one = abs(a.x - b.x), two = abs(a.y - b.y);
		return one*one + two*two;
	}
	bool operator>(point const & other)const
	{
		if (flag)
		{
			return dis(*this, point1) > dis(other, point1);
		}
		else
		{
			return dis(*this, point2) > dis(other, point2);
		}
	}
	bool operator==(point const & other)const
	{
		if (flag)
		{
			return dis(*this, point1) == dis(other, point1);
		}
		else
		{
			return dis(*this, point2) == dis(other, point2);
		}
	}
	point(float X = 0, float Y = 0) :x(X), y(Y)
	{
		float dis1 = dis(*this, point1),dis2=dis(*this,point2);
		flag = dis1 < dis2;
	}
};

ostream& operator<<(ostream& out, const point &other)
{
	return out<<'('<<other.x<<','<<other.y<<')';
}

point point::point1(0, 0);
point point::point2(1, 1);

//point static::point1 = point();
int main()
{
	clock_t BeginTime = clock();
	srand(unsigned(time(NULL)));
#ifdef DEBUG
	FILE *input, *output; //û�õ�ָ��... ...
	freopen_s(&input, "in.txt", "r", stdin);
	freopen_s(&output, "out.txt", "w", stdout);
#endif
	int j1=0, j2=0;
	float size = 10;
	point L1[10000],L2[10000];
	int n=10000;
	re(i, n)
	{
		float x = float(rand())/float(RAND_MAX);
		float y = float(rand()) / float(RAND_MAX);
		point one(x, y);
		if (one.flag)
			L1[j1++] = one;
		else
			L2[j2++] = one;
	}
	int k = 10;
	point y1 = Select(L1, j1, k);
	point y2 = Select(L2, j2, k);
	cout << j1 << " " << j2 << endl;
	re(i, j1)
		cout << L1[i] << " ";
	cout << endl;
	re(i, j2)
		cout<<L2[i]<<" ";
	cout << endl;
	Qsort(L1, 0, j1 - 1);
	Qsort(L2, 0, j2 - 1);
	cout << "ʵ�ʵĵ�"<<k<<"���㣺" << endl;
	cout << L1[k - 1] << " " << L2[k - 1] << endl ;
	cout << "����������ĵ�"<<k<<"���㣺" << endl;
	cout<< y1 << " " << y2 << endl;
	cout << endl << "����ʱ�䣺" << clock() - BeginTime << endl;
#ifndef DEBUG
	system("pause");
#endif // !DEBUG
	return 0;
}