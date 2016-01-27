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
#include "SegmentTree.h"
using namespace std;
#undef re
#define re(i,n) for(unsigned int i=0;i<n;i++)
#define DEBUG
	unsigned int num[1000000];
void test()
{
	unsigned int SizeOfTest=30000;
	SegmentTree one(0,SizeOfTest);
	//one.print();
	re(i, SizeOfTest)
	{
		int a = rand()%SizeOfTest;
		int b = rand() % SizeOfTest;
		if (a > b)Swap(a, b);
		Segment Seg(a, b);
		one.insert(Seg);	
		num[i] = one.count();
		//printf("Count: %d\n", one.count());
	}	

	re(i, SizeOfTest)
	{
		int a = rand() % SizeOfTest;
		int b = rand() % SizeOfTest;
		if (a > b)Swap(a, b);
		Segment Seg(a, b);
		one.del(Seg);	
		num[i] = one.count();
		//printf("Count: %d\n", one.count());
	}

}

int main()
{
	clock_t BeginTime = clock();
	srand(unsigned(time(NULL)));
#ifdef DEBUG
	FILE *input, *output; //û�õ�ָ��... ...
	freopen_s(&input, "in.txt", "r", stdin);
	freopen_s(&output, "out.txt", "w", stdout);
#endif
	test();
	cout << endl << "����ʱ�䣺" << clock() - BeginTime << endl;
#ifndef DEBUG
	system("pause");
#endif // !DEBUG
	return 0;
}