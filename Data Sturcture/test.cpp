#pragma  once
#include "btree.h"
#include "ALL.h"
#include "normal.h"
#include "normal.cpp"
#include "normal2.h"
#include "normal2.cpp"
#include <algorithm>
#include <math.h>
using namespace std;

void TestOfQueue()//�޸ĺ���ͨ���ú������в��ԡ�
{
	srand(unsigned(time(NULL)));
	queue<int> a, b;
	unsigned int SizeOfTest = 10000;
	re(i, SizeOfTest)
		a.push(rand() % 1000);
	queue<int> c = a;
	re(i, 1000)
	{
		while (!a.isEmpty())
			b.push(a.pop());
		while (!b.isEmpty())
			a.push(b.pop());
	}
	re(i, SizeOfTest)
		cout << a.pop() << " ";
	cout << endl;
	re(i, SizeOfTest)
		cout << c.pop() << " ";
	cout << endl;
}

void TestOfStack()
{
	srand(unsigned(time(NULL)));
	stack<int> a, b;
	unsigned int n = 10100;
	re(i, n)
		a.push(rand() % 1000);
	cout << a;
	while (!a.isEmpty())
		b.push(a.pop());
	a = b;
	re(i, n)
		cout << b.pop() << " ";
	cout << endl << a << endl;
}

void TestOfList()
{
	srand(int(time(NULL)));
	int a[1000];
	unsigned int SizeOfTest = 100;
	re(i, SizeOfTest)
		a[i] = rand() % 10;
	list<int> one(a, SizeOfTest);
	Qsort(a, 0, SizeOfTest - 1);
	re(i, SizeOfTest)//earse test
	{
		one.delNode(a[i]);
		//cout << one << endl;
	}
	cout << one;
	re(i, SizeOfTest)
		one.RearInsert(rand() % 1000);
	cout << one;
	re(i, SizeOfTest)
		one.HeadInsert(rand() % 1000);
	cout << one;
	list<int> two = one;
	cout << two;
	two = one;
	cout << two<< endl;
	one.resetPointer();
	while (!one.pointer.isEnd())
	{
		cout << *one.pointer << " ";
		++one.pointer;
	}


}


void TestOfBstree()
{
	srand(int(time(NULL)));
	int a[100000];
	unsigned int SizeOfTest =10000;
	re(i, SizeOfTest)
		a[i] = rand() % 100000;
	bstree<int> one(a, SizeOfTest);
	bstree<int> two;
	Swap(&one, &two);
	Swap(&two, &one);
	one.pre();
	one.mid();
	one.post();
	//bstree<int> another = one;
	//another.mid();
	//one = another;
	//one.mid();
	re(i, SizeOfTest)
	{
		treeNode<int>* temp = one.find(a[i]);
		if (temp == NULL)
			cout << "�޷��ҵ���" << endl;
	}
	cout << one.height() << endl;
	re(i, SizeOfTest)
		one.insert(a[i]);
	re(i, SizeOfTest)
	{
		//cout << a[i] << endl;
		one.DelNode(a[i]);
		//cout << one.NodeNum() << " ";
	}
}

void TestOfAVLTree()
{
	srand(int(time(NULL)));
	int a[100000];

	unsigned int SizeOfTest = 10000;
	re(i, SizeOfTest)
		a[i] = rand() % 10000;
	Qsort(a, 0, SizeOfTest - 1);
	AVLtree<int> one(a, SizeOfTest);
	AVLtree<int> two(one);
	one = two;
	//one.pre();
	//one.mid();
	//one.post();
	//one.print();
	re(i, SizeOfTest)
	{
		treeNode<int>* temp = one.find(a[i]);
		if (temp == NULL)
			cout << "�޷��ҵ���" << endl;
	}
	cout << "���߶ȣ�" << one.H() << endl;
	cout << "���߶ȣ�" << maxHeight_bbtree(SizeOfTest) << endl;
	cout << "��͸߶ȣ�" << minHeight_bbtree(SizeOfTest) << endl;
	cout << "�ڵ�����" << one.NodeNum() << endl;
	cout << "��ǰ�߶ȵ����ٽڵ㣺" << Fibonacci(one.height()+2)-1 << endl;
	cout << endl;
	//re(i, SizeOfTest)
	//	one.insert(rand() % 10000);
	//cout << "���߶ȣ�" << one.Height() << endl;
	//cout << "�ڵ�����" << one.NodeNum() << endl;
	re(i, SizeOfTest)
		one.insert(a[i]);
	re(i, SizeOfTest)
	{
		one.DelNode(a[i]);
		//if (one.NodeNum() != SizeOfTest - i - 1)
			//cout << "���ˣ�" << endl;
	}
	//cout << endl;
	//cout << "���߶ȣ�" << one.Height() << endl;
	//cout << "�ڵ�����" << one.NodeNum() << endl;
}

void TestOfIterator()
{
	srand(int(time(NULL)));
	int a[10000];
	unsigned int SizeOfTest = 1000;
	re(i, SizeOfTest)
		a[i] = rand() % 10000;
	bstree<int> one(a, SizeOfTest);
	Pre_iterator<int> iterP(&one);
	Mid_iterator<int> iterM(&one);
	Post_iterator<int> iterPost(&one);
	Level_iterator<int> iterL(&one);
	Qsort(a, 0, SizeOfTest - 1);
	re(i, SizeOfTest)
		cout << a[i] << " ";
	cout << endl;
	one.pre();
	while (!iterP.isEnd())
	{
		cout << *iterP << " ";
		++iterP;
	}
	cout << endl;
	iterP.goFirst();
	while (!iterP.isEnd())
	{
		cout << *iterP << " ";
		++iterP;
	}
	cout << endl;
	one.mid();
	while (!iterM.isEnd())
	{
		cout << *iterM << " ";
		++iterM;
	}
	cout << endl;
	iterM.goFirst();
	while (!iterM.isEnd())
	{
		cout << *iterM << " ";
		++iterM;
	}
	cout << endl;
	one.post();
	while (!iterPost.isEnd())
	{
		cout << *iterPost << " ";
		++iterPost;
	}
	cout << endl;
	iterPost.goFirst();
	while (!iterPost.isEnd())
	{
		cout << *iterPost << " ";
		++iterPost;
	}
	cout << endl;
	one.print();
	while (!iterL.isEnd())
	{
		cout << *iterL << " ";
		++iterL;
	}
	cout << endl;
	iterL.goFirst();
	while (!iterL.isEnd())
	{
		cout << *iterL << " ";
		++iterL;
	}
}

void TestOfHeap()
{
	unsigned int SizeOfTest= 1800;
	int abc[10000] = { 0 }, bcd[10000] = { 0 };
	re(i, SizeOfTest)
	{
		abc[i] = rand() % 10000;
		//cout << abc[i] << " ";
	}
	cout << endl;
	memcpy(bcd, abc, SizeOfTest*sizeof(int));
	heapSort(abc, SizeOfTest);
	Qsort_MaxToMin(bcd, 0, SizeOfTest - 1);
	re(k, SizeOfTest)
	{
		if (bcd[k] != abc[k])
		{
			re(i, SizeOfTest)
				cout << abc[i] << ' ';
			cout << endl;
			re(i, SizeOfTest)
				cout << bcd[i] << ' ';
			cout << endl;
			break;
		}
	}
}

void Test()
{
	try{
		//cout << "����ջ" << endl;
		//TestOfStack();
		//cout << "���Զ���" << endl;
		//TestOfQueue();
		//cout << "��������" << endl;
		//TestOfList();
		cout << "\n�������������" << endl;
		TestOfBstree();
		cout << "\n����ƽ�������" << endl;
		TestOfAVLTree();
		//cout << "\n���Ե�����" << endl;
		//TestOfIterator();
		cout << "\n���Զ�" << endl;
		TestOfHeap();

	}
	catch (const char *a){
		cout << a << endl;
	}
}
