#pragma once
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Data Sturcture/ALL.h"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void debug(const char * errorInfo)
{
	Logger::WriteMessage(errorInfo);
	Assert::Fail();
}
namespace UnitTest
{		
	TEST_CLASS(UnitTest_Tree)
	{
	public:
		TEST_METHOD(Test_AVLtree)
		{
			try
			{
				srand(int(time(NULL)));
				int a[10000];
				unsigned int SizeOfTest = 100;
				re(i, SizeOfTest)
					a[i] = rand() % 10;
				AVLtree<int> one(a, SizeOfTest);
				Qsort(a, 0, SizeOfTest - 1);
				Mid_iterator<int> iterM(&one);
				re(i, SizeOfTest)
				{
					if (*iterM != a[SizeOfTest - i - 1])
						debug("��һ��");
					++iterM;
				}
				re(i, SizeOfTest - 5)
				{
					one.DelNode(a[i]);
					if (one.NodeNum() != SizeOfTest - i - 1)
						debug("ɾ����ڵ㲻��");
					if ((int)one.height() > maxHeight_bbtree(SizeOfTest - i - 1))
						debug("�߶Ȳ���");
				}
			}
			catch (const char *err){ debug(err); }
		}
		TEST_METHOD(Test_BStree)
		{
			try
			{
				srand(int(time(NULL)));
				int a[10000];
				unsigned int SizeOfTest = 200;
				re(i, SizeOfTest)
					a[i] = rand() % (SizeOfTest / 2);
				bstree<int> one(a, SizeOfTest);
				Qsort(a, 0, SizeOfTest - 1);
				Mid_iterator<int> iterM(&one);
				re(i, SizeOfTest)
				{
					if (*iterM != a[SizeOfTest - i - 1])
						debug("���Բ���˳��\n");
					++iterM;
				}
				re(i, SizeOfTest)
				{
					one.DelNode(a[i]);
					if (SizeOfTest - i - 1 != one.NodeNum())
						debug("����ɾ���ڵ��ڵ���Ŀ����");
				}
			}
			catch (const char *err){ debug(err); }
		}
	};
	TEST_CLASS(UnitTest2)
	{
		TEST_METHOD(Test_Stack)
		{
			try
			{
				srand(int(time(NULL)));
				int a[10000];
				unsigned int SizeOfTest = 2000;
				stack<int> one, two;
				re(i, SizeOfTest)
					one.push(rand() % SizeOfTest);
				two = one;
				re(i, SizeOfTest)
					a[i] = one.pop();
				re(i, SizeOfTest)
					if (a[i] != two.pop())
						debug("�Բ���");
			}
				catch (const char *err){ debug(err); }
		}
		TEST_METHOD(Test_Queue)
		{
			try
			{
				srand(unsigned(time(NULL)));
				queue<int> a, b;
				unsigned int SizeOfTest = 1000;
				re(i, SizeOfTest)
					a.push(rand() % SizeOfTest);
				queue<int> c = a;
				re(i, 2)
				{
					while (!a.isEmpty())
						b.push(a.pop());
					while (!b.isEmpty())
						a.push(b.pop());
				}
				re(i, SizeOfTest)
					if (a.pop() != c.pop())
						debug("�Բ�����");
			}
			catch (const char *err){ debug(err); }
		}
		TEST_METHOD(Test_List)
		{
			try
			{
				srand(int(time(NULL)));
				int a[1000];
				unsigned int SizeOfTest = 100;
				re(i, SizeOfTest)
					a[i] = rand() % SizeOfTest;
				list<int> one(a, SizeOfTest);
				Qsort(a, 0, SizeOfTest - 1);
				re(i, SizeOfTest)//earse test
					one.delNode(a[i]);
				re(i, SizeOfTest)
					one.RearInsert(a[i]);
				re(i, SizeOfTest)
					one.HeadInsert(a[i]);
				list<int> two = one;
				one = two;
				one.resetPointer();
				std::stringstream ss;
				std::string str;
				re(i, SizeOfTest)
				{
					if (*one.pointer != a[SizeOfTest - i - 1])
						debug("ǰ��������");
					++one.pointer;
				}
				re(i, SizeOfTest)
				{
					if (*one.pointer != a[i])
						debug("����������");
					++one.pointer;
				}
			}
			catch (const char * err){ debug(err); }
		}
	};
}