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

void TestOfQueue()//修改后请通过该函数进行测试。
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

void TestOfBtree()
{
	//输入可参考
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
	cout << "树高度：" << one.Height() << endl;
	cout << "节点数：" << one.NodeNum() << endl;
	return;
}

void TestOfBstree()
{
	srand(int(time(NULL)));
	int a[10000];
	unsigned int SizeOfTest = 100;
	re(i, SizeOfTest)
		a[i] = rand() % 10000;
	Qsort(a, 0, SizeOfTest - 1);
	bstree<int> one(a, SizeOfTest);
	one.pre();
	one.mid();
	one.post();
	re(i, SizeOfTest)
	{
		//cout << a[i] << endl;
		one.DelNode(a[i]);
		cout << one.NodeNum() << " ";
	}
	cout << endl;
	re(i, SizeOfTest)
		cout << a[i] << " ";
	cout << endl;
	BSTree<int> two(a, SizeOfTest);
	//cout << "树高度：" << one.Height() << endl;
	//cout << "节点数：" << one.NodeNum() << endl;
	//BSTree<int> two(one);
	//one.pre();
	//cout << endl;
	two.mid();
	cout << endl;
	//one.mid();
	//cout << endl;
	//one.post();
	//cout << endl;
	//one.print();
	//cout << endl;
	//cout << "树高度：" << two.Height() << endl;
	//cout << "节点数：" << two.NodeNum() << endl;
	////Qsort(a, 0, SizeOfTest - 1);
	//re(i, SizeOfTest)
	//{
	//	const Tree<int>* temp = one.find(a[i]);
	//	if (temp == NULL)
	//		cout << "无法找到！" << endl;
	//}
	//re(i, SizeOfTest)
	//	one.DelNode(a[i]);
	//cout << "树高度：" << one.Height() << endl;
	//cout << "节点数：" << one.NodeNum() << endl;
	////cin >> SizeOfTest;//测试内存释放
	////re(j, SizeOfTest)
	////	a[j] = rand() % 10000;
	////re(j, SizeOfTest)
	////{
	////	BSTree<int> two(a, SizeOfTest);
	////	cout << "节点数：" << two.NodeNum() << " ";
	////}
	//return;

}

void TestOfAVLTree()
{
	srand(int(time(NULL)));
	int a[10000];
	unsigned int SizeOfTest = 100;
	re(i, SizeOfTest)
		//a[i] = i;
		a[i] = rand() % 10000;
	//Qsort(a, 0, SizeOfTest-1); //这时候出来的一般就是理想高度了。
	AVLTree<int> one(a, SizeOfTest); Tree<int>* three = &one;
	AVLTree<int> two(one);
	cout << endl;
	two.pre();
	cout << endl;
	two.mid();
	cout << endl;
	two.post();
	cout << endl;
	two.print();
	re(i, SizeOfTest)
	{
		const Tree<int>* temp = one.find(a[i]);
		if (temp == NULL)
			cout << "无法找到！" << endl;
	}
	cout << "树高度：" << one.Height() << endl;
	cout << "最大高度：" << maxHeight_bbtree(SizeOfTest) << endl;
	cout << "最低高度：" << minHeight_bbtree(SizeOfTest) << endl;
	cout << "节点数：" << one.NodeNum() << endl;
	cout << "当前高度的最少节点：" << Fibonacci(one.Height()+2)-1 << endl;
	cout << endl;
	//re(i, SizeOfTest)
	//	one.insert(rand() % 10000);
	cout << "树高度：" << one.Height() << endl;
	cout << "节点数：" << one.NodeNum() << endl;
	re(i, SizeOfTest)
		one.DelNode(a[i]);
	one.mid();
	cout << endl;
	cout << "树高度：" << one.Height() << endl;
	cout << "节点数：" << one.NodeNum() << endl;
}

void TestOfIterator()
{
	srand(int(time(NULL)));
	int a[10000];
	unsigned int SizeOfTest = 1000;
	re(i, SizeOfTest)
		a[i] = rand() % 10000;
	BSTree<int> one(a, SizeOfTest);
	PreOrder_iterator<int> iterP(&one);
	InOrder_iterator<int> iterI(&one);
	LevelOrder_iterator<int> iterL(&one);
	one.pre();
	cout << endl;
	while (!iterP.isEnd())
	{
		cout << *iterP << " ";
		++iterP;
	}
	cout << endl;
	one.mid();
	cout << endl;
	while (!iterI.isEnd())
	{
		cout << *iterI << " ";
		++iterI;
	}
	cout << endl;
	one.print();
	cout << endl;
	while (!iterL.isEnd())
	{
		cout << *iterL << " ";
		++iterL;
	}
	iterL.gotoFirst();
	cout << endl;
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
		//cout << "测试栈" << endl;
		//TestOfStack();
		//cout << "测试队列" << endl;
		//TestOfQueue();
		//cout << "测试链表" << endl;
		//TestOfList();
		//cout << "\n测试二叉树" << endl;
		//TestOfBtree();
		cout << "\n测试排序二叉树" << endl;
		TestOfBstree();
		cout << "\n测试平衡二叉树" << endl;
		TestOfAVLTree();
		//cout << "\n测试迭代器" << endl;
		//TestOfIterator();
		//cout << "\n测试堆" << endl;
		//TestOfHeap();

	}
	catch (const char *a){
		cout << a << endl;
	}
}
