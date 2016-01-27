#pragma  once
#include "queue.cpp"
#include "stack.cpp"
#include "list.cpp"
#include "btree.cpp"
#include "btree.h"
#include "bstree.cpp"
#include "bbtree.cpp"
#include "heap.cpp"
#include "normal.cpp"
#include "iterator.cpp"
#include <algorithm>
#include <math.h>
using namespace std;

void TestOfQueue()//�޸ĺ���ͨ���ú������в��ԡ�
{
	srand(unsigned(time(NULL)));
	queue<int> a, b;
	unsigned int SizeOfTest = 100;
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

void TestOfBtree()
{
	//����ɲο�
	//a b c # # d # # e f # # g # #
	BTree<char> one; 
	cin >> one;
	cout << endl;
	one.pre();
	cout << endl;
	one.mid();
	cout << endl;
	one.post();
	cout << endl;
	one.print();
	cout << endl;
	cout << "���߶ȣ�" << one.Height() << endl;
	cout << "�ڵ�����" << one.NodeNum() << endl;
	return;
}

void TestOfBstree()
{
	srand(int(time(NULL)));
	int a[10000];
	unsigned int SizeOfTest = 100;
	re(i, SizeOfTest)
		a[i] = rand() % 10000;
	//re(i, SizeOfTest)
	//	cout << a[i] << " ";
	cout << endl;
	BSTree<int> one(a, SizeOfTest);
	BSTree<int> two(one);
	two.pre();
	cout << endl;
	one.pre();
	cout << endl;
	one.mid();
	cout << endl;
	one.post();
	cout << endl;
	one.print();
	cout << endl;
	cout << "���߶ȣ�" << one.Height() << endl;
	cout << "�ڵ�����" << one.NodeNum() << endl;
	//Qsort(a, 0, SizeOfTest - 1);
	re(i, SizeOfTest)
	{
		const Tree<int>* temp = one.find(a[i]);
		if (temp == NULL)
			cout << "�޷��ҵ���" << endl;
	}
	re(i, SizeOfTest)
		one.DelNode(a[i]);
	cout << "���߶ȣ�" << one.Height() << endl;
	cout << "�ڵ�����" << one.NodeNum() << endl;
	//cin >> SizeOfTest;//�����ڴ��ͷ�
	//re(j, SizeOfTest)
	//	a[j] = rand() % 10000;
	//re(j, SizeOfTest)
	//{
	//	BSTree<int> two(a, SizeOfTest);
	//	cout << "�ڵ�����" << two.NodeNum() << " ";
	//}
	return;

}

void TestOfBbtree()
{
	srand(int(time(NULL)));
	int a[10000];
	unsigned int SizeOfTest = 100;
	re(i, SizeOfTest)
		//a[i] = i;
		a[i] = rand() % 10000;
	//Qsort(a, 0, SizeOfTest-1); //��ʱ�������һ���������߶��ˡ�
	AVLTree<int> one(a, SizeOfTest); Tree<int>* three = &one;
	//cout << endl;
	//one.pre();
	//cout << endl;
	//one.mid();
	//cout << endl;
	//one.post();
	//cout << endl;
	//one.print();
	re(i, SizeOfTest)
	{
		const Tree<int>* temp = one.find(a[i]);
		if (temp == NULL)
			cout << "�޷��ҵ���" << endl;
	}
	cout << "���߶ȣ�" << one.Height() << endl;
	cout << "���߶ȣ�" << maxHeight_bbtree(SizeOfTest) << endl;
	cout << "��͸߶ȣ�" << minHeight_bbtree(SizeOfTest) << endl;
	cout << "�ڵ�����" << one.NodeNum() << endl;
	cout << "��ǰ�߶ȵ����ٽڵ㣺" << Fibonacci(one.Height()+2)-1 << endl;
	cout << endl;
	//re(i, SizeOfTest)
	//	one.insert(rand() % 10000);
	cout << "���߶ȣ�" << one.Height() << endl;
	cout << "�ڵ�����" << one.NodeNum() << endl;
	re(i, SizeOfTest)
		one.DelNode(a[i]);
	one.mid();
	cout << endl;
	cout << "���߶ȣ�" << one.Height() << endl;
	cout << "�ڵ�����" << one.NodeNum() << endl;
}

void TestOfIterator()
{
	srand(int(time(NULL)));
	int a[10000];
	unsigned int SizeOfTest = 100;
	re(i, SizeOfTest)
		a[i] = rand() % 10000;
	BSTree<int> one(a, SizeOfTest);
	PreOrder_iterator<int> iterA(&one);
	InOrder_iterator<int> iterB(&one);
	//one.pre();
	//cout << endl;
	//while (!iterA.isEnd())
	//{
	//	cout << *iterA << " ";
	//	++iterA;
	//}
	one.mid();
	cout << endl;
	while (!iterB.isEnd())
	{
		cout << *iterB << " ";
		++iterB;
	}
	iterB.gotoFirst();
	cout << endl;
	while (!iterB.isEnd())
	{
		cout << *iterB << " ";
		++iterB;
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
	Qsort(bcd, 0, SizeOfTest - 1);
	re(i, SizeOfTest)
		cout << abc[i] << ' ';
	cout << endl;
	re(i, SizeOfTest)
		cout << bcd[i] << ' ';
	cout << endl;
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
		//cout << "���Զ�" << endl;
		//TestOfQueue();
		//cout << "��������" << endl;
		//TestOfList();
		//cout << "\n���Զ�����" << endl;
		//TestOfBtree();
		cout << "\n�������������" << endl;
		TestOfBstree();
		//cout << "\n����ƽ�������" << endl;
		//TestOfBbtree();
		cout << "\n���Ե�����" << endl;
		TestOfIterator();
		//cout << "\n���Զ�" << endl;
		//TestOfHeap();

	}
	catch (const char *a){
		cout << a << endl;
	}
}
