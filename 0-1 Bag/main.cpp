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
#include "bag.h"
using namespace std;
#undef re
#define re(i,n) for(unsigned int i=0;i<n;i++)
#define DEBUG

int main()
{
	clock_t BeginTime = clock();
	srand(unsigned(time(NULL)));
#ifdef DEBUG
	FILE *input, *output; //û�õ�ָ��... ...
	freopen_s(&input, "in.txt", "r", stdin);
	freopen_s(&output, "out.txt", "w", stdout);
#endif
	try{
		unsigned int n = 0;
		double Limit = 0;
		//����
		cout << "������������Ŀ��"; cin >> n;
		cout << "�����뱳����С��"; cin >> Limit;
		object *thing = new object[n + 1];
		cout << "�����뱳����" << endl;
		re(i, n/2)
			cin >> thing[i];
		re(i, n / 2)
			thing[i + n / 2] = object(rand() % 10 + 10, rand() % 10 + 7);
		//����
		BagState bestSolution = Solve(n, Limit, thing);
		//���
		cout << "����ı�����" << endl;
		re(i, n)
			cout << thing[i];
		cout << endl;
		cout << "The max sum_value is: " << endl << bestSolution.value() << endl;
		cout << "The optimum solution is :" << endl << bestSolution << endl;
	}
	catch (char const * a){ cout << a << endl; }
	cout << endl << "����ʱ�䣺" << clock() - BeginTime << endl;
#ifndef DEBUG
	system("pause");
#endif // !DEBUG
	return 0;
}